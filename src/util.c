#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/cpuset.h>
#include <unistd.h>

#include "debug_log.h"
#include "util.h"

int sceKernelGetCurrentCpu();

int pin_to_core(int num)
{
    uint64_t mask[2] = {};
    mask[0] = (1 << num);
    return cpuset_setaffinity(3, 1, -1, 0x10, (const cpuset_t *) mask);
}

void pin_to_first_available_core()
{
    for (int i = 0; i < 16; i++) {
        if (pin_to_core(i) == 0) {
            break;
        }
    }
}

int get_cpu_core()
{
    return sceKernelGetCurrentCpu();
}

void DumpHex(const void* data, size_t size) {
    char hexbuf[0x4000];
    (void)memset(hexbuf, 0, sizeof(hexbuf));
    char *cur = (char *) &hexbuf;

    sprintf(cur, "hex:\n");
    cur += strlen(cur);

    char ascii[17];
    size_t i, j;
    ascii[16] = '\0';
    for (i = 0; i < size; ++i) {
        sprintf(cur, "%02X ", ((unsigned char*)data)[i]);
        cur += strlen(cur);

        if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') {
            ascii[i % 16] = ((unsigned char*)data)[i];
        } else {
            ascii[i % 16] = '.';
        }
        if ((i+1) % 8 == 0 || i+1 == size) {
            sprintf(cur, " ");
            cur += strlen(cur);

            if ((i+1) % 16 == 0) {
                sprintf(cur, "|  %s \n", ascii);
                cur += strlen(cur);
            } else if (i+1 == size) {
                ascii[(i+1) % 16] = '\0';
                if ((i+1) % 16 <= 8) {
                    sprintf(cur, " ");
                    cur += strlen(cur);
                }
                for (j = (i+1) % 16; j < 16; ++j) {
                    sprintf(cur, "   ");
                    cur += strlen(cur);
                }
                sprintf(cur, "|  %s \n", ascii);
                cur += strlen(cur);
            }
        }
    }

    SOCK_LOG("%s", hexbuf);
}
