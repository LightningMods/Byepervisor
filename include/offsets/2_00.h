#ifndef OFFSETS_2_00_H
#define OFFSETS_2_00_H

uint64_t g_sym_map_200[] = {
    0x4CB3B50,          // KERNEL_SYM_DMPML4I
    0x4CB3B54,          // KERNEL_SYM_DMPDPI
    0x4CB38AC,          // KERNEL_SYM_PML4PML4I
    0x4CB38C8,          // KERNEL_SYM_PMAP_STORE
    0x7C40000,          // KERNEL_SYM_DATA_CAVE
    0x0044000,          // KERNEL_SYM_CODE_CAVE
    0x1CDE4F0,          // KERNEL_SYM_PS4_SYSENT
    0x1CE6D10,          // KERNEL_SYM_PPR_SYSENT
    0x0042000,          // KERNEL_SYM_GADGET_JMP_PTR_RSI
};

uint64_t g_patch_map_200[] = {
    0x0580860,          // KERNEL_PATCH_HAS_MMAP_SELF_CAPABILITY
    0x0580870,          // KERNEL_PATCH_IS_ALLOWED_TO_MMAP_SELF
    0x09A5F49,          // KERNEL_PATCH_MMAP_SELF_CALL_IS_LOADABLE
    0x02A69B0,          // KERNEL_PATCH_SYS_GETGID
};

#endif // OFFSETS_2_00_H