savedcmd_i_tcp_vegas.o := gcc -Wp,-MMD,./.i_tcp_vegas.o.d -nostdinc -I/home/ns/linux-6.14.4/arch/x86/include -I/home/ns/linux-6.14.4/arch/x86/include/generated -I/home/ns/linux-6.14.4/include -I/home/ns/linux-6.14.4/include -I/home/ns/linux-6.14.4/arch/x86/include/uapi -I/home/ns/linux-6.14.4/arch/x86/include/generated/uapi -I/home/ns/linux-6.14.4/include/uapi -I/home/ns/linux-6.14.4/include/generated/uapi -include /home/ns/linux-6.14.4/include/linux/compiler-version.h -include /home/ns/linux-6.14.4/include/linux/kconfig.h -include /home/ns/linux-6.14.4/include/linux/compiler_types.h -D__KERNEL__ -std=gnu11 -fshort-wchar -funsigned-char -fno-common -fno-PIE -fno-strict-aliasing -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -fcf-protection=none -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel -Wno-sign-compare -fno-asynchronous-unwind-tables -mindirect-branch=thunk-extern -mindirect-branch-register -mindirect-branch-cs-prefix -mfunction-return=thunk-extern -fno-jump-tables -fpatchable-function-entry=16,16 -fno-delete-null-pointer-checks -O2 -fno-allow-store-data-races -fstack-protector-strong -fno-omit-frame-pointer -fno-optimize-sibling-calls -ftrivial-auto-var-init=zero -fno-stack-clash-protection -fzero-call-used-regs=used-gpr -pg -mrecord-mcount -mfentry -DCC_USING_FENTRY -falign-functions=16 -fstrict-flex-arrays=3 -fno-strict-overflow -fno-stack-check -fconserve-stack -fno-builtin-wcslen -Wall -Wundef -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Werror=strict-prototypes -Wno-format-security -Wno-trigraphs -Wno-frame-address -Wno-address-of-packed-member -Wmissing-declarations -Wmissing-prototypes -Wframe-larger-than=1024 -Wno-main -Wno-dangling-pointer -Wvla -Wno-pointer-sign -Wcast-function-type -Wno-stringop-overflow -Wno-array-bounds -Wno-alloc-size-larger-than -Wimplicit-fallthrough=5 -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -Wenum-conversion -Wextra -Wunused -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-packed-not-aligned -Wno-format-overflow -Wno-format-truncation -Wno-stringop-truncation -Wno-override-init -Wno-missing-field-initializers -Wno-type-limits -Wno-shift-negative-value -Wno-maybe-uninitialized -Wno-sign-compare -Wno-unused-parameter -g -gdwarf-5  -fsanitize=bounds-strict -fsanitize=shift -fsanitize=bool -fsanitize=enum  -fsanitize=signed-integer-overflow  -DMODULE  -DKBUILD_BASENAME='"i_tcp_vegas"' -DKBUILD_MODNAME='"i_tcp_vegas"' -D__KBUILD_MODNAME=kmod_i_tcp_vegas -c -o i_tcp_vegas.o i_tcp_vegas.c   ; /home/ns/linux-6.14.4/tools/objtool/objtool --hacks=jump_label --hacks=noinstr --hacks=skylake --retpoline --rethunk --stackval --static-call --uaccess --prefix=16   --module i_tcp_vegas.o

source_i_tcp_vegas.o := i_tcp_vegas.c

deps_i_tcp_vegas.o := \
  /home/ns/linux-6.14.4/include/linux/compiler-version.h \
    $(wildcard include/config/CC_VERSION_TEXT) \
  /home/ns/linux-6.14.4/include/linux/kconfig.h \
    $(wildcard include/config/CPU_BIG_ENDIAN) \
    $(wildcard include/config/BOOGER) \
    $(wildcard include/config/FOO) \
  /home/ns/linux-6.14.4/include/linux/compiler_types.h \
    $(wildcard include/config/DEBUG_INFO_BTF) \
    $(wildcard include/config/PAHOLE_HAS_BTF_TAG) \
    $(wildcard include/config/FUNCTION_ALIGNMENT) \
    $(wildcard include/config/CC_HAS_SANE_FUNCTION_ALIGNMENT) \
    $(wildcard include/config/X86_64) \
    $(wildcard include/config/ARM64) \
    $(wildcard include/config/LD_DEAD_CODE_DATA_ELIMINATION) \
    $(wildcard include/config/LTO_CLANG) \
    $(wildcard include/config/HAVE_ARCH_COMPILER_H) \
    $(wildcard include/config/CC_HAS_COUNTED_BY) \
    $(wildcard include/config/UBSAN_SIGNED_WRAP) \
    $(wildcard include/config/CC_HAS_ASM_INLINE) \
  /home/ns/linux-6.14.4/include/linux/compiler_attributes.h \
  /home/ns/linux-6.14.4/include/linux/compiler-gcc.h \
    $(wildcard include/config/MITIGATION_RETPOLINE) \
    $(wildcard include/config/ARCH_USE_BUILTIN_BSWAP) \
    $(wildcard include/config/SHADOW_CALL_STACK) \
    $(wildcard include/config/KCOV) \
  /home/ns/linux-6.14.4/include/linux/mm.h \
    $(wildcard include/config/NUMA) \
    $(wildcard include/config/SYSCTL) \
    $(wildcard include/config/HAVE_ARCH_MMAP_RND_BITS) \
    $(wildcard include/config/HAVE_ARCH_MMAP_RND_COMPAT_BITS) \
    $(wildcard include/config/SPARSEMEM) \
    $(wildcard include/config/SPARSEMEM_VMEMMAP) \
    $(wildcard include/config/MMU) \
    $(wildcard include/config/MEM_SOFT_DIRTY) \
    $(wildcard include/config/ARCH_USES_HIGH_VMA_FLAGS) \
    $(wildcard include/config/ARCH_HAS_PKEYS) \
    $(wildcard include/config/ARCH_PKEY_BITS) \
    $(wildcard include/config/X86_USER_SHADOW_STACK) \
    $(wildcard include/config/ARM64_GCS) \
    $(wildcard include/config/X86) \
    $(wildcard include/config/PPC64) \
    $(wildcard include/config/PARISC) \
    $(wildcard include/config/SPARC64) \
    $(wildcard include/config/ARM64_MTE) \
    $(wildcard include/config/HAVE_ARCH_USERFAULTFD_MINOR) \
    $(wildcard include/config/64BIT) \
    $(wildcard include/config/PPC32) \
    $(wildcard include/config/STACK_GROWSUP) \
    $(wildcard include/config/NUMA_BALANCING) \
    $(wildcard include/config/PER_VMA_LOCK) \
    $(wildcard include/config/SHMEM) \
    $(wildcard include/config/ZONE_DEVICE) \
    $(wildcard include/config/FS_DAX) \
    $(wildcard include/config/KASAN_SW_TAGS) \
    $(wildcard include/config/KASAN_HW_TAGS) \
    $(wildcard include/config/MIGRATION) \
    $(wildcard include/config/CMA) \
    $(wildcard include/config/ARCH_HAS_GIGANTIC_PAGE) \
    $(wildcard include/config/HIGHMEM) \
    $(wildcard include/config/SCHED_MM_CID) \
    $(wildcard include/config/ARCH_HAS_PTE_SPECIAL) \
    $(wildcard include/config/ARCH_SUPPORTS_PMD_PFNMAP) \
    $(wildcard include/config/ARCH_SUPPORTS_PUD_PFNMAP) \
    $(wildcard include/config/ARCH_HAS_PTE_DEVMAP) \
    $(wildcard include/config/SPLIT_PTE_PTLOCKS) \
    $(wildcard include/config/HIGHPTE) \
    $(wildcard include/config/SPLIT_PMD_PTLOCKS) \
    $(wildcard include/config/TRANSPARENT_HUGEPAGE) \
    $(wildcard include/config/DEBUG_VM_RB) \
    $(wildcard include/config/PAGE_POISONING) \
    $(wildcard include/config/INIT_ON_ALLOC_DEFAULT_ON) \
    $(wildcard include/config/INIT_ON_FREE_DEFAULT_ON) \
    $(wildcard include/config/DEBUG_PAGEALLOC) \
    $(wildcard include/config/MEMORY_HOTPLUG) \
    $(wildcard include/config/ARCH_WANT_OPTIMIZE_DAX_VMEMMAP) \
    $(wildcard include/config/MEMORY_FAILURE) \
    $(wildcard include/config/HUGETLBFS) \
    $(wildcard include/config/MAPPING_DIRTY_HELPERS) \
    $(wildcard include/config/ANON_VMA_NAME) \
    $(wildcard include/config/UNACCEPTED_MEMORY) \
  /home/ns/linux-6.14.4/include/linux/errno.h \
  /home/ns/linux-6.14.4/include/uapi/linux/errno.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/uapi/asm/errno.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/errno.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/errno-base.h \
  /home/ns/linux-6.14.4/include/linux/mmdebug.h \
    $(wildcard include/config/DEBUG_VM) \
    $(wildcard include/config/DEBUG_VM_IRQSOFF) \
    $(wildcard include/config/DEBUG_VIRTUAL) \
    $(wildcard include/config/DEBUG_VM_PGFLAGS) \
  /home/ns/linux-6.14.4/include/linux/bug.h \
    $(wildcard include/config/GENERIC_BUG) \
    $(wildcard include/config/PRINTK) \
    $(wildcard include/config/BUG_ON_DATA_CORRUPTION) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/bug.h \
    $(wildcard include/config/X86_32) \
    $(wildcard include/config/DEBUG_BUGVERBOSE) \
  /home/ns/linux-6.14.4/include/linux/stringify.h \
  /home/ns/linux-6.14.4/include/linux/instrumentation.h \
    $(wildcard include/config/NOINSTR_VALIDATION) \
  /home/ns/linux-6.14.4/include/linux/objtool.h \
    $(wildcard include/config/OBJTOOL) \
    $(wildcard include/config/FRAME_POINTER) \
    $(wildcard include/config/MITIGATION_UNRET_ENTRY) \
    $(wildcard include/config/MITIGATION_SRSO) \
  /home/ns/linux-6.14.4/include/linux/objtool_types.h \
  /home/ns/linux-6.14.4/include/linux/types.h \
    $(wildcard include/config/HAVE_UID16) \
    $(wildcard include/config/UID16) \
    $(wildcard include/config/ARCH_DMA_ADDR_T_64BIT) \
    $(wildcard include/config/PHYS_ADDR_T_64BIT) \
    $(wildcard include/config/ARCH_32BIT_USTAT_F_TINODE) \
  /home/ns/linux-6.14.4/include/uapi/linux/types.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/uapi/asm/types.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/types.h \
  /home/ns/linux-6.14.4/include/asm-generic/int-ll64.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/int-ll64.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/bitsperlong.h \
  /home/ns/linux-6.14.4/include/asm-generic/bitsperlong.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/bitsperlong.h \
  /home/ns/linux-6.14.4/include/uapi/linux/posix_types.h \
  /home/ns/linux-6.14.4/include/linux/stddef.h \
  /home/ns/linux-6.14.4/include/uapi/linux/stddef.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/posix_types.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/posix_types_64.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/posix_types.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/asm.h \
    $(wildcard include/config/KPROBES) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/extable_fixup_types.h \
  /home/ns/linux-6.14.4/include/asm-generic/bug.h \
    $(wildcard include/config/BUG) \
    $(wildcard include/config/GENERIC_BUG_RELATIVE_POINTERS) \
    $(wildcard include/config/SMP) \
  /home/ns/linux-6.14.4/include/linux/compiler.h \
    $(wildcard include/config/TRACE_BRANCH_PROFILING) \
    $(wildcard include/config/PROFILE_ALL_BRANCHES) \
  /home/ns/linux-6.14.4/arch/x86/include/generated/asm/rwonce.h \
  /home/ns/linux-6.14.4/include/asm-generic/rwonce.h \
  /home/ns/linux-6.14.4/include/linux/kasan-checks.h \
    $(wildcard include/config/KASAN_GENERIC) \
  /home/ns/linux-6.14.4/include/linux/kcsan-checks.h \
    $(wildcard include/config/KCSAN) \
    $(wildcard include/config/KCSAN_WEAK_MEMORY) \
    $(wildcard include/config/KCSAN_IGNORE_ATOMICS) \
  /home/ns/linux-6.14.4/include/linux/once_lite.h \
  /home/ns/linux-6.14.4/include/linux/panic.h \
    $(wildcard include/config/PANIC_TIMEOUT) \
  /home/ns/linux-6.14.4/include/linux/printk.h \
    $(wildcard include/config/MESSAGE_LOGLEVEL_DEFAULT) \
    $(wildcard include/config/CONSOLE_LOGLEVEL_DEFAULT) \
    $(wildcard include/config/CONSOLE_LOGLEVEL_QUIET) \
    $(wildcard include/config/EARLY_PRINTK) \
    $(wildcard include/config/PRINTK_INDEX) \
    $(wildcard include/config/DYNAMIC_DEBUG) \
    $(wildcard include/config/DYNAMIC_DEBUG_CORE) \
  /home/ns/linux-6.14.4/include/linux/stdarg.h \
  /home/ns/linux-6.14.4/include/linux/init.h \
    $(wildcard include/config/HAVE_ARCH_PREL32_RELOCATIONS) \
  /home/ns/linux-6.14.4/include/linux/build_bug.h \
  /home/ns/linux-6.14.4/include/linux/kern_levels.h \
  /home/ns/linux-6.14.4/include/linux/linkage.h \
    $(wildcard include/config/ARCH_USE_SYM_ANNOTATIONS) \
  /home/ns/linux-6.14.4/include/linux/export.h \
    $(wildcard include/config/MODVERSIONS) \
    $(wildcard include/config/GENDWARFKSYMS) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/linkage.h \
    $(wildcard include/config/CALL_PADDING) \
    $(wildcard include/config/MITIGATION_RETHUNK) \
    $(wildcard include/config/MITIGATION_SLS) \
    $(wildcard include/config/FUNCTION_PADDING_BYTES) \
    $(wildcard include/config/UML) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/ibt.h \
    $(wildcard include/config/X86_KERNEL_IBT) \
  /home/ns/linux-6.14.4/include/linux/ratelimit_types.h \
  /home/ns/linux-6.14.4/include/linux/bits.h \
  /home/ns/linux-6.14.4/include/linux/const.h \
  /home/ns/linux-6.14.4/include/vdso/const.h \
  /home/ns/linux-6.14.4/include/uapi/linux/const.h \
  /home/ns/linux-6.14.4/include/vdso/bits.h \
  /home/ns/linux-6.14.4/include/uapi/linux/bits.h \
  /home/ns/linux-6.14.4/include/uapi/linux/param.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/uapi/asm/param.h \
  /home/ns/linux-6.14.4/include/asm-generic/param.h \
    $(wildcard include/config/HZ) \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/param.h \
  /home/ns/linux-6.14.4/include/linux/spinlock_types_raw.h \
    $(wildcard include/config/DEBUG_SPINLOCK) \
    $(wildcard include/config/DEBUG_LOCK_ALLOC) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/spinlock_types.h \
  /home/ns/linux-6.14.4/include/asm-generic/qspinlock_types.h \
    $(wildcard include/config/NR_CPUS) \
  /home/ns/linux-6.14.4/include/asm-generic/qrwlock_types.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/byteorder.h \
  /home/ns/linux-6.14.4/include/linux/byteorder/little_endian.h \
  /home/ns/linux-6.14.4/include/uapi/linux/byteorder/little_endian.h \
  /home/ns/linux-6.14.4/include/linux/swab.h \
  /home/ns/linux-6.14.4/include/uapi/linux/swab.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/swab.h \
  /home/ns/linux-6.14.4/include/linux/byteorder/generic.h \
  /home/ns/linux-6.14.4/include/linux/lockdep_types.h \
    $(wildcard include/config/PROVE_RAW_LOCK_NESTING) \
    $(wildcard include/config/LOCKDEP) \
    $(wildcard include/config/LOCK_STAT) \
  /home/ns/linux-6.14.4/include/linux/dynamic_debug.h \
    $(wildcard include/config/JUMP_LABEL) \
  /home/ns/linux-6.14.4/include/linux/jump_label.h \
    $(wildcard include/config/HAVE_ARCH_JUMP_LABEL_RELATIVE) \
  /home/ns/linux-6.14.4/include/linux/cleanup.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/jump_label.h \
    $(wildcard include/config/HAVE_JUMP_LABEL_HACK) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/nops.h \
  /home/ns/linux-6.14.4/include/linux/gfp.h \
    $(wildcard include/config/ZONE_DMA) \
    $(wildcard include/config/ZONE_DMA32) \
    $(wildcard include/config/COMPACTION) \
    $(wildcard include/config/CONTIG_ALLOC) \
  /home/ns/linux-6.14.4/include/linux/gfp_types.h \
    $(wildcard include/config/SLAB_OBJ_EXT) \
  /home/ns/linux-6.14.4/include/linux/mmzone.h \
    $(wildcard include/config/ARCH_FORCE_MAX_ORDER) \
    $(wildcard include/config/MEMORY_ISOLATION) \
    $(wildcard include/config/ZSMALLOC) \
    $(wildcard include/config/IOMMU_SUPPORT) \
    $(wildcard include/config/SWAP) \
    $(wildcard include/config/HUGETLB_PAGE) \
    $(wildcard include/config/LRU_GEN) \
    $(wildcard include/config/LRU_GEN_STATS) \
    $(wildcard include/config/LRU_GEN_WALKS_MMU) \
    $(wildcard include/config/MEMCG) \
    $(wildcard include/config/FLATMEM) \
    $(wildcard include/config/PAGE_EXTENSION) \
    $(wildcard include/config/DEFERRED_STRUCT_PAGE_INIT) \
    $(wildcard include/config/HAVE_MEMORYLESS_NODES) \
    $(wildcard include/config/SPARSEMEM_EXTREME) \
    $(wildcard include/config/HAVE_ARCH_PFN_VALID) \
  /home/ns/linux-6.14.4/include/linux/spinlock.h \
    $(wildcard include/config/PREEMPTION) \
    $(wildcard include/config/PREEMPT_RT) \
  /home/ns/linux-6.14.4/include/linux/typecheck.h \
  /home/ns/linux-6.14.4/include/linux/preempt.h \
    $(wildcard include/config/PREEMPT_COUNT) \
    $(wildcard include/config/DEBUG_PREEMPT) \
    $(wildcard include/config/TRACE_PREEMPT_TOGGLE) \
    $(wildcard include/config/PREEMPT_NOTIFIERS) \
    $(wildcard include/config/PREEMPT_DYNAMIC) \
    $(wildcard include/config/PREEMPT_NONE) \
    $(wildcard include/config/PREEMPT_VOLUNTARY) \
    $(wildcard include/config/PREEMPT) \
    $(wildcard include/config/PREEMPT_LAZY) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/preempt.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/rmwcc.h \
  /home/ns/linux-6.14.4/include/linux/args.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/percpu.h \
    $(wildcard include/config/X86_64_SMP) \
    $(wildcard include/config/CC_HAS_NAMED_AS) \
    $(wildcard include/config/USE_X86_SEG_SUPPORT) \
  /home/ns/linux-6.14.4/include/asm-generic/percpu.h \
    $(wildcard include/config/HAVE_SETUP_PER_CPU_AREA) \
  /home/ns/linux-6.14.4/include/linux/threads.h \
    $(wildcard include/config/BASE_SMALL) \
  /home/ns/linux-6.14.4/include/linux/percpu-defs.h \
    $(wildcard include/config/DEBUG_FORCE_WEAK_PER_CPU) \
    $(wildcard include/config/AMD_MEM_ENCRYPT) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/current.h \
    $(wildcard include/config/MITIGATION_CALL_DEPTH_TRACKING) \
  /home/ns/linux-6.14.4/include/linux/cache.h \
    $(wildcard include/config/ARCH_HAS_CACHE_LINE_SIZE) \
  /home/ns/linux-6.14.4/include/uapi/linux/kernel.h \
  /home/ns/linux-6.14.4/include/uapi/linux/sysinfo.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/cache.h \
    $(wildcard include/config/X86_L1_CACHE_SHIFT) \
    $(wildcard include/config/X86_INTERNODE_CACHE_SHIFT) \
    $(wildcard include/config/X86_VSMP) \
  /home/ns/linux-6.14.4/include/linux/static_call_types.h \
    $(wildcard include/config/HAVE_STATIC_CALL) \
    $(wildcard include/config/HAVE_STATIC_CALL_INLINE) \
  /home/ns/linux-6.14.4/include/linux/irqflags.h \
    $(wildcard include/config/PROVE_LOCKING) \
    $(wildcard include/config/TRACE_IRQFLAGS) \
    $(wildcard include/config/IRQSOFF_TRACER) \
    $(wildcard include/config/PREEMPT_TRACER) \
    $(wildcard include/config/DEBUG_IRQFLAGS) \
    $(wildcard include/config/TRACE_IRQFLAGS_SUPPORT) \
  /home/ns/linux-6.14.4/include/linux/irqflags_types.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/irqflags.h \
    $(wildcard include/config/PARAVIRT) \
    $(wildcard include/config/PARAVIRT_XXL) \
    $(wildcard include/config/DEBUG_ENTRY) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/processor-flags.h \
    $(wildcard include/config/VM86) \
    $(wildcard include/config/MITIGATION_PAGE_TABLE_ISOLATION) \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/processor-flags.h \
  /home/ns/linux-6.14.4/include/linux/mem_encrypt.h \
    $(wildcard include/config/ARCH_HAS_MEM_ENCRYPT) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/mem_encrypt.h \
    $(wildcard include/config/X86_MEM_ENCRYPT) \
  /home/ns/linux-6.14.4/include/linux/cc_platform.h \
    $(wildcard include/config/ARCH_HAS_CC_PLATFORM) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/nospec-branch.h \
    $(wildcard include/config/CALL_THUNKS_DEBUG) \
    $(wildcard include/config/MITIGATION_IBPB_ENTRY) \
  /home/ns/linux-6.14.4/include/linux/static_key.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/alternative.h \
    $(wildcard include/config/CALL_THUNKS) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/cpufeatures.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/required-features.h \
    $(wildcard include/config/X86_MINIMUM_CPU_FAMILY) \
    $(wildcard include/config/MATH_EMULATION) \
    $(wildcard include/config/X86_PAE) \
    $(wildcard include/config/X86_CMPXCHG64) \
    $(wildcard include/config/X86_CMOV) \
    $(wildcard include/config/X86_P6_NOP) \
    $(wildcard include/config/MATOM) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/disabled-features.h \
    $(wildcard include/config/X86_UMIP) \
    $(wildcard include/config/X86_INTEL_MEMORY_PROTECTION_KEYS) \
    $(wildcard include/config/X86_5LEVEL) \
    $(wildcard include/config/ADDRESS_MASKING) \
    $(wildcard include/config/INTEL_IOMMU_SVM) \
    $(wildcard include/config/X86_SGX) \
    $(wildcard include/config/XEN_PV) \
    $(wildcard include/config/INTEL_TDX_GUEST) \
    $(wildcard include/config/X86_FRED) \
    $(wildcard include/config/KVM_AMD_SEV) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/msr-index.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/unwind_hints.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/orc_types.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/asm-offsets.h \
  /home/ns/linux-6.14.4/include/generated/asm-offsets.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/GEN-for-each-reg.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/segment.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/paravirt.h \
    $(wildcard include/config/PARAVIRT_SPINLOCKS) \
    $(wildcard include/config/X86_IOPL_IOPERM) \
    $(wildcard include/config/PGTABLE_LEVELS) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/paravirt_types.h \
    $(wildcard include/config/ZERO_CALL_USED_REGS) \
    $(wildcard include/config/PARAVIRT_DEBUG) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/desc_defs.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/pgtable_types.h \
    $(wildcard include/config/HAVE_ARCH_USERFAULTFD_WP) \
    $(wildcard include/config/PROC_FS) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/page_types.h \
    $(wildcard include/config/PHYSICAL_START) \
    $(wildcard include/config/PHYSICAL_ALIGN) \
    $(wildcard include/config/DYNAMIC_PHYSICAL_MASK) \
  /home/ns/linux-6.14.4/include/vdso/page.h \
    $(wildcard include/config/PAGE_SHIFT) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/page_64_types.h \
    $(wildcard include/config/KASAN) \
    $(wildcard include/config/DYNAMIC_MEMORY_LAYOUT) \
    $(wildcard include/config/RANDOMIZE_BASE) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/kaslr.h \
    $(wildcard include/config/RANDOMIZE_MEMORY) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/pgtable_64_types.h \
    $(wildcard include/config/KMSAN) \
    $(wildcard include/config/DEBUG_KMAP_LOCAL_FORCE_MAP) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/sparsemem.h \
  /home/ns/linux-6.14.4/include/linux/cpumask.h \
    $(wildcard include/config/FORCE_NR_CPUS) \
    $(wildcard include/config/HOTPLUG_CPU) \
    $(wildcard include/config/DEBUG_PER_CPU_MAPS) \
    $(wildcard include/config/CPUMASK_OFFSTACK) \
  /home/ns/linux-6.14.4/include/linux/kernel.h \
    $(wildcard include/config/PREEMPT_VOLUNTARY_BUILD) \
    $(wildcard include/config/HAVE_PREEMPT_DYNAMIC_CALL) \
    $(wildcard include/config/HAVE_PREEMPT_DYNAMIC_KEY) \
    $(wildcard include/config/PREEMPT_) \
    $(wildcard include/config/DEBUG_ATOMIC_SLEEP) \
    $(wildcard include/config/TRACING) \
    $(wildcard include/config/FTRACE_MCOUNT_RECORD) \
  /home/ns/linux-6.14.4/include/linux/align.h \
  /home/ns/linux-6.14.4/include/linux/array_size.h \
  /home/ns/linux-6.14.4/include/linux/limits.h \
  /home/ns/linux-6.14.4/include/uapi/linux/limits.h \
  /home/ns/linux-6.14.4/include/vdso/limits.h \
  /home/ns/linux-6.14.4/include/linux/container_of.h \
  /home/ns/linux-6.14.4/include/linux/bitops.h \
  /home/ns/linux-6.14.4/include/asm-generic/bitops/generic-non-atomic.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/barrier.h \
  /home/ns/linux-6.14.4/include/asm-generic/barrier.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/bitops.h \
  /home/ns/linux-6.14.4/include/asm-generic/bitops/sched.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/arch_hweight.h \
  /home/ns/linux-6.14.4/include/asm-generic/bitops/const_hweight.h \
  /home/ns/linux-6.14.4/include/asm-generic/bitops/instrumented-atomic.h \
  /home/ns/linux-6.14.4/include/linux/instrumented.h \
  /home/ns/linux-6.14.4/include/linux/kmsan-checks.h \
  /home/ns/linux-6.14.4/include/asm-generic/bitops/instrumented-non-atomic.h \
    $(wildcard include/config/KCSAN_ASSUME_PLAIN_WRITES_ATOMIC) \
  /home/ns/linux-6.14.4/include/asm-generic/bitops/instrumented-lock.h \
  /home/ns/linux-6.14.4/include/asm-generic/bitops/le.h \
  /home/ns/linux-6.14.4/include/asm-generic/bitops/ext2-atomic-setbit.h \
  /home/ns/linux-6.14.4/include/linux/hex.h \
  /home/ns/linux-6.14.4/include/linux/kstrtox.h \
  /home/ns/linux-6.14.4/include/linux/log2.h \
    $(wildcard include/config/ARCH_HAS_ILOG2_U32) \
    $(wildcard include/config/ARCH_HAS_ILOG2_U64) \
  /home/ns/linux-6.14.4/include/linux/math.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/div64.h \
  /home/ns/linux-6.14.4/include/asm-generic/div64.h \
    $(wildcard include/config/CC_OPTIMIZE_FOR_PERFORMANCE) \
  /home/ns/linux-6.14.4/include/linux/minmax.h \
  /home/ns/linux-6.14.4/include/linux/sprintf.h \
  /home/ns/linux-6.14.4/include/linux/instruction_pointer.h \
  /home/ns/linux-6.14.4/include/linux/wordpart.h \
  /home/ns/linux-6.14.4/include/linux/bitmap.h \
  /home/ns/linux-6.14.4/include/linux/find.h \
  /home/ns/linux-6.14.4/include/linux/string.h \
    $(wildcard include/config/BINARY_PRINTF) \
    $(wildcard include/config/FORTIFY_SOURCE) \
  /home/ns/linux-6.14.4/include/linux/err.h \
  /home/ns/linux-6.14.4/include/linux/overflow.h \
  /home/ns/linux-6.14.4/include/uapi/linux/string.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/string.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/string_64.h \
    $(wildcard include/config/ARCH_HAS_UACCESS_FLUSHCACHE) \
  /home/ns/linux-6.14.4/include/linux/fortify-string.h \
    $(wildcard include/config/CC_HAS_KASAN_MEMINTRINSIC_PREFIX) \
    $(wildcard include/config/GENERIC_ENTRY) \
  /home/ns/linux-6.14.4/include/linux/bitfield.h \
  /home/ns/linux-6.14.4/include/linux/bitmap-str.h \
  /home/ns/linux-6.14.4/include/linux/cpumask_types.h \
  /home/ns/linux-6.14.4/include/linux/atomic.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/atomic.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/cmpxchg.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/cmpxchg_64.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/atomic64_64.h \
  /home/ns/linux-6.14.4/include/linux/atomic/atomic-arch-fallback.h \
    $(wildcard include/config/GENERIC_ATOMIC64) \
  /home/ns/linux-6.14.4/include/linux/atomic/atomic-long.h \
  /home/ns/linux-6.14.4/include/linux/atomic/atomic-instrumented.h \
  /home/ns/linux-6.14.4/include/linux/numa.h \
    $(wildcard include/config/NODES_SHIFT) \
    $(wildcard include/config/NUMA_KEEP_MEMINFO) \
    $(wildcard include/config/HAVE_ARCH_NODE_DEV_GROUP) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/frame.h \
  /home/ns/linux-6.14.4/include/linux/thread_info.h \
    $(wildcard include/config/THREAD_INFO_IN_TASK) \
    $(wildcard include/config/ARCH_HAS_PREEMPT_LAZY) \
    $(wildcard include/config/HAVE_ARCH_WITHIN_STACK_FRAMES) \
    $(wildcard include/config/HARDENED_USERCOPY) \
    $(wildcard include/config/SH) \
  /home/ns/linux-6.14.4/include/linux/restart_block.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/thread_info.h \
    $(wildcard include/config/COMPAT) \
    $(wildcard include/config/IA32_EMULATION) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/page.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/page_64.h \
    $(wildcard include/config/X86_VSYSCALL_EMULATION) \
  /home/ns/linux-6.14.4/include/linux/range.h \
  /home/ns/linux-6.14.4/include/asm-generic/memory_model.h \
  /home/ns/linux-6.14.4/include/linux/pfn.h \
  /home/ns/linux-6.14.4/include/asm-generic/getorder.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/cpufeature.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/processor.h \
    $(wildcard include/config/X86_VMX_FEATURE_NAMES) \
    $(wildcard include/config/STACKPROTECTOR) \
    $(wildcard include/config/CPU_SUP_AMD) \
    $(wildcard include/config/XEN) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/math_emu.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/ptrace.h \
    $(wildcard include/config/X86_DEBUGCTLMSR) \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/ptrace.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/ptrace-abi.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/proto.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/ldt.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/sigcontext.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/cpuid.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/special_insns.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/fpu/types.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/vmxfeatures.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/vdso/processor.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/shstk.h \
  /home/ns/linux-6.14.4/include/linux/personality.h \
  /home/ns/linux-6.14.4/include/uapi/linux/personality.h \
  /home/ns/linux-6.14.4/include/linux/math64.h \
    $(wildcard include/config/ARCH_SUPPORTS_INT128) \
  /home/ns/linux-6.14.4/include/vdso/math64.h \
  /home/ns/linux-6.14.4/include/linux/bottom_half.h \
  /home/ns/linux-6.14.4/include/linux/lockdep.h \
    $(wildcard include/config/DEBUG_LOCKING_API_SELFTESTS) \
  /home/ns/linux-6.14.4/include/linux/smp.h \
    $(wildcard include/config/UP_LATE_INIT) \
    $(wildcard include/config/CSD_LOCK_WAIT_DEBUG) \
  /home/ns/linux-6.14.4/include/linux/list.h \
    $(wildcard include/config/LIST_HARDENED) \
    $(wildcard include/config/DEBUG_LIST) \
  /home/ns/linux-6.14.4/include/linux/poison.h \
    $(wildcard include/config/ILLEGAL_POINTER_VALUE) \
  /home/ns/linux-6.14.4/include/linux/smp_types.h \
  /home/ns/linux-6.14.4/include/linux/llist.h \
    $(wildcard include/config/ARCH_HAVE_NMI_SAFE_CMPXCHG) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/smp.h \
    $(wildcard include/config/DEBUG_NMI_SELFTEST) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/cpumask.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/asm/mmiowb.h \
  /home/ns/linux-6.14.4/include/asm-generic/mmiowb.h \
    $(wildcard include/config/MMIOWB) \
  /home/ns/linux-6.14.4/include/linux/spinlock_types.h \
  /home/ns/linux-6.14.4/include/linux/rwlock_types.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/spinlock.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/qspinlock.h \
  /home/ns/linux-6.14.4/include/asm-generic/qspinlock.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/qrwlock.h \
  /home/ns/linux-6.14.4/include/asm-generic/qrwlock.h \
  /home/ns/linux-6.14.4/include/linux/rwlock.h \
  /home/ns/linux-6.14.4/include/linux/spinlock_api_smp.h \
    $(wildcard include/config/INLINE_SPIN_LOCK) \
    $(wildcard include/config/INLINE_SPIN_LOCK_BH) \
    $(wildcard include/config/INLINE_SPIN_LOCK_IRQ) \
    $(wildcard include/config/INLINE_SPIN_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_SPIN_TRYLOCK) \
    $(wildcard include/config/INLINE_SPIN_TRYLOCK_BH) \
    $(wildcard include/config/UNINLINE_SPIN_UNLOCK) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_BH) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_IRQRESTORE) \
    $(wildcard include/config/GENERIC_LOCKBREAK) \
  /home/ns/linux-6.14.4/include/linux/rwlock_api_smp.h \
    $(wildcard include/config/INLINE_READ_LOCK) \
    $(wildcard include/config/INLINE_WRITE_LOCK) \
    $(wildcard include/config/INLINE_READ_LOCK_BH) \
    $(wildcard include/config/INLINE_WRITE_LOCK_BH) \
    $(wildcard include/config/INLINE_READ_LOCK_IRQ) \
    $(wildcard include/config/INLINE_WRITE_LOCK_IRQ) \
    $(wildcard include/config/INLINE_READ_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_WRITE_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_READ_TRYLOCK) \
    $(wildcard include/config/INLINE_WRITE_TRYLOCK) \
    $(wildcard include/config/INLINE_READ_UNLOCK) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK) \
    $(wildcard include/config/INLINE_READ_UNLOCK_BH) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_BH) \
    $(wildcard include/config/INLINE_READ_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_READ_UNLOCK_IRQRESTORE) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_IRQRESTORE) \
  /home/ns/linux-6.14.4/include/linux/list_nulls.h \
  /home/ns/linux-6.14.4/include/linux/wait.h \
  /home/ns/linux-6.14.4/include/linux/seqlock.h \
  /home/ns/linux-6.14.4/include/linux/mutex.h \
    $(wildcard include/config/DEBUG_MUTEXES) \
  /home/ns/linux-6.14.4/include/linux/osq_lock.h \
  /home/ns/linux-6.14.4/include/linux/debug_locks.h \
  /home/ns/linux-6.14.4/include/linux/mutex_types.h \
    $(wildcard include/config/MUTEX_SPIN_ON_OWNER) \
  /home/ns/linux-6.14.4/include/linux/seqlock_types.h \
  /home/ns/linux-6.14.4/include/linux/nodemask.h \
  /home/ns/linux-6.14.4/include/linux/nodemask_types.h \
  /home/ns/linux-6.14.4/include/linux/random.h \
    $(wildcard include/config/VMGENID) \
  /home/ns/linux-6.14.4/include/uapi/linux/random.h \
  /home/ns/linux-6.14.4/include/uapi/linux/ioctl.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/uapi/asm/ioctl.h \
  /home/ns/linux-6.14.4/include/asm-generic/ioctl.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/ioctl.h \
  /home/ns/linux-6.14.4/include/linux/irqnr.h \
  /home/ns/linux-6.14.4/include/uapi/linux/irqnr.h \
  /home/ns/linux-6.14.4/include/linux/pageblock-flags.h \
    $(wildcard include/config/HUGETLB_PAGE_SIZE_VARIABLE) \
  /home/ns/linux-6.14.4/include/linux/page-flags-layout.h \
  /home/ns/linux-6.14.4/include/generated/bounds.h \
  /home/ns/linux-6.14.4/include/linux/mm_types.h \
    $(wildcard include/config/HAVE_ALIGNED_STRUCT_PAGE) \
    $(wildcard include/config/HUGETLB_PMD_PAGE_TABLE_SHARING) \
    $(wildcard include/config/USERFAULTFD) \
    $(wildcard include/config/HAVE_ARCH_COMPAT_MMAP_BASES) \
    $(wildcard include/config/MEMBARRIER) \
    $(wildcard include/config/AIO) \
    $(wildcard include/config/MMU_NOTIFIER) \
    $(wildcard include/config/ARCH_WANT_BATCHED_UNMAP_TLB_FLUSH) \
    $(wildcard include/config/IOMMU_MM_DATA) \
    $(wildcard include/config/KSM) \
    $(wildcard include/config/CORE_DUMP_DEFAULT_ELF_HEADERS) \
  /home/ns/linux-6.14.4/include/linux/mm_types_task.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/tlbbatch.h \
  /home/ns/linux-6.14.4/include/linux/auxvec.h \
  /home/ns/linux-6.14.4/include/uapi/linux/auxvec.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/auxvec.h \
  /home/ns/linux-6.14.4/include/linux/kref.h \
  /home/ns/linux-6.14.4/include/linux/refcount.h \
  /home/ns/linux-6.14.4/include/linux/refcount_types.h \
  /home/ns/linux-6.14.4/include/linux/rbtree.h \
  /home/ns/linux-6.14.4/include/linux/rbtree_types.h \
  /home/ns/linux-6.14.4/include/linux/rcupdate.h \
    $(wildcard include/config/PREEMPT_RCU) \
    $(wildcard include/config/TINY_RCU) \
    $(wildcard include/config/RCU_STRICT_GRACE_PERIOD) \
    $(wildcard include/config/RCU_LAZY) \
    $(wildcard include/config/TASKS_RCU_GENERIC) \
    $(wildcard include/config/RCU_STALL_COMMON) \
    $(wildcard include/config/NO_HZ_FULL) \
    $(wildcard include/config/KVM_XFER_TO_GUEST_WORK) \
    $(wildcard include/config/RCU_NOCB_CPU) \
    $(wildcard include/config/TASKS_RCU) \
    $(wildcard include/config/TASKS_TRACE_RCU) \
    $(wildcard include/config/TASKS_RUDE_RCU) \
    $(wildcard include/config/TREE_RCU) \
    $(wildcard include/config/DEBUG_OBJECTS_RCU_HEAD) \
    $(wildcard include/config/PROVE_RCU) \
    $(wildcard include/config/ARCH_WEAK_RELEASE_ACQUIRE) \
  /home/ns/linux-6.14.4/include/linux/context_tracking_irq.h \
    $(wildcard include/config/CONTEXT_TRACKING_IDLE) \
  /home/ns/linux-6.14.4/include/linux/rcutree.h \
  /home/ns/linux-6.14.4/include/linux/maple_tree.h \
    $(wildcard include/config/MAPLE_RCU_DISABLED) \
    $(wildcard include/config/DEBUG_MAPLE_TREE) \
  /home/ns/linux-6.14.4/include/linux/rwsem.h \
    $(wildcard include/config/RWSEM_SPIN_ON_OWNER) \
    $(wildcard include/config/DEBUG_RWSEMS) \
  /home/ns/linux-6.14.4/include/linux/completion.h \
  /home/ns/linux-6.14.4/include/linux/swait.h \
  /home/ns/linux-6.14.4/include/linux/uprobes.h \
    $(wildcard include/config/UPROBES) \
  /home/ns/linux-6.14.4/include/linux/timer.h \
    $(wildcard include/config/DEBUG_OBJECTS_TIMERS) \
  /home/ns/linux-6.14.4/include/linux/ktime.h \
  /home/ns/linux-6.14.4/include/linux/jiffies.h \
  /home/ns/linux-6.14.4/include/linux/time.h \
    $(wildcard include/config/POSIX_TIMERS) \
  /home/ns/linux-6.14.4/include/linux/time64.h \
  /home/ns/linux-6.14.4/include/vdso/time64.h \
  /home/ns/linux-6.14.4/include/uapi/linux/time.h \
  /home/ns/linux-6.14.4/include/uapi/linux/time_types.h \
  /home/ns/linux-6.14.4/include/linux/time32.h \
  /home/ns/linux-6.14.4/include/linux/timex.h \
  /home/ns/linux-6.14.4/include/uapi/linux/timex.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/timex.h \
    $(wildcard include/config/X86_TSC) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/tsc.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/msr.h \
    $(wildcard include/config/TRACEPOINTS) \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/msr.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/shared/msr.h \
  /home/ns/linux-6.14.4/include/linux/percpu.h \
    $(wildcard include/config/MODULES) \
    $(wildcard include/config/MEM_ALLOC_PROFILING) \
    $(wildcard include/config/RANDOM_KMALLOC_CACHES) \
    $(wildcard include/config/PAGE_SIZE_4KB) \
    $(wildcard include/config/NEED_PER_CPU_PAGE_FIRST_CHUNK) \
  /home/ns/linux-6.14.4/include/linux/alloc_tag.h \
    $(wildcard include/config/MEM_ALLOC_PROFILING_DEBUG) \
    $(wildcard include/config/MEM_ALLOC_PROFILING_ENABLED_BY_DEFAULT) \
  /home/ns/linux-6.14.4/include/linux/codetag.h \
    $(wildcard include/config/CODE_TAGGING) \
  /home/ns/linux-6.14.4/include/linux/sched.h \
    $(wildcard include/config/VIRT_CPU_ACCOUNTING_NATIVE) \
    $(wildcard include/config/SCHED_INFO) \
    $(wildcard include/config/SCHEDSTATS) \
    $(wildcard include/config/SCHED_CORE) \
    $(wildcard include/config/FAIR_GROUP_SCHED) \
    $(wildcard include/config/RT_GROUP_SCHED) \
    $(wildcard include/config/RT_MUTEXES) \
    $(wildcard include/config/UCLAMP_TASK) \
    $(wildcard include/config/UCLAMP_BUCKETS_COUNT) \
    $(wildcard include/config/KMAP_LOCAL) \
    $(wildcard include/config/SCHED_CLASS_EXT) \
    $(wildcard include/config/CGROUP_SCHED) \
    $(wildcard include/config/BLK_DEV_IO_TRACE) \
    $(wildcard include/config/MEMCG_V1) \
    $(wildcard include/config/COMPAT_BRK) \
    $(wildcard include/config/CGROUPS) \
    $(wildcard include/config/BLK_CGROUP) \
    $(wildcard include/config/PSI) \
    $(wildcard include/config/PAGE_OWNER) \
    $(wildcard include/config/EVENTFD) \
    $(wildcard include/config/ARCH_HAS_CPU_PASID) \
    $(wildcard include/config/X86_BUS_LOCK_DETECT) \
    $(wildcard include/config/TASK_DELAY_ACCT) \
    $(wildcard include/config/ARCH_HAS_SCALED_CPUTIME) \
    $(wildcard include/config/VIRT_CPU_ACCOUNTING_GEN) \
    $(wildcard include/config/POSIX_CPUTIMERS) \
    $(wildcard include/config/POSIX_CPU_TIMERS_TASK_WORK) \
    $(wildcard include/config/KEYS) \
    $(wildcard include/config/SYSVIPC) \
    $(wildcard include/config/DETECT_HUNG_TASK) \
    $(wildcard include/config/IO_URING) \
    $(wildcard include/config/AUDIT) \
    $(wildcard include/config/AUDITSYSCALL) \
    $(wildcard include/config/UBSAN) \
    $(wildcard include/config/UBSAN_TRAP) \
    $(wildcard include/config/TASK_XACCT) \
    $(wildcard include/config/CPUSETS) \
    $(wildcard include/config/X86_CPU_RESCTRL) \
    $(wildcard include/config/FUTEX) \
    $(wildcard include/config/PERF_EVENTS) \
    $(wildcard include/config/RSEQ) \
    $(wildcard include/config/DEBUG_RSEQ) \
    $(wildcard include/config/FAULT_INJECTION) \
    $(wildcard include/config/LATENCYTOP) \
    $(wildcard include/config/KUNIT) \
    $(wildcard include/config/FUNCTION_GRAPH_TRACER) \
    $(wildcard include/config/BCACHE) \
    $(wildcard include/config/VMAP_STACK) \
    $(wildcard include/config/LIVEPATCH) \
    $(wildcard include/config/SECURITY) \
    $(wildcard include/config/BPF_SYSCALL) \
    $(wildcard include/config/GCC_PLUGIN_STACKLEAK) \
    $(wildcard include/config/X86_MCE) \
    $(wildcard include/config/KRETPROBES) \
    $(wildcard include/config/RETHOOK) \
    $(wildcard include/config/ARCH_HAS_PARANOID_L1D_FLUSH) \
    $(wildcard include/config/RV) \
    $(wildcard include/config/USER_EVENTS) \
  /home/ns/linux-6.14.4/include/uapi/linux/sched.h \
  /home/ns/linux-6.14.4/include/linux/pid_types.h \
  /home/ns/linux-6.14.4/include/linux/sem_types.h \
  /home/ns/linux-6.14.4/include/linux/shm.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/shmparam.h \
  /home/ns/linux-6.14.4/include/linux/kmsan_types.h \
  /home/ns/linux-6.14.4/include/linux/plist_types.h \
  /home/ns/linux-6.14.4/include/linux/hrtimer_types.h \
  /home/ns/linux-6.14.4/include/linux/timerqueue_types.h \
  /home/ns/linux-6.14.4/include/linux/timer_types.h \
  /home/ns/linux-6.14.4/include/linux/seccomp_types.h \
    $(wildcard include/config/SECCOMP) \
  /home/ns/linux-6.14.4/include/linux/resource.h \
  /home/ns/linux-6.14.4/include/uapi/linux/resource.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/uapi/asm/resource.h \
  /home/ns/linux-6.14.4/include/asm-generic/resource.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/resource.h \
  /home/ns/linux-6.14.4/include/linux/latencytop.h \
  /home/ns/linux-6.14.4/include/linux/sched/prio.h \
  /home/ns/linux-6.14.4/include/linux/sched/types.h \
  /home/ns/linux-6.14.4/include/linux/signal_types.h \
    $(wildcard include/config/OLD_SIGACTION) \
  /home/ns/linux-6.14.4/include/uapi/linux/signal.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/signal.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/signal.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/signal-defs.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/siginfo.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/siginfo.h \
  /home/ns/linux-6.14.4/include/linux/syscall_user_dispatch_types.h \
  /home/ns/linux-6.14.4/include/linux/netdevice_xmit.h \
    $(wildcard include/config/NET_EGRESS) \
  /home/ns/linux-6.14.4/include/linux/task_io_accounting.h \
    $(wildcard include/config/TASK_IO_ACCOUNTING) \
  /home/ns/linux-6.14.4/include/linux/posix-timers_types.h \
  /home/ns/linux-6.14.4/include/uapi/linux/rseq.h \
  /home/ns/linux-6.14.4/include/linux/kcsan.h \
  /home/ns/linux-6.14.4/include/linux/rv.h \
    $(wildcard include/config/RV_REACTORS) \
  /home/ns/linux-6.14.4/include/linux/livepatch_sched.h \
  /home/ns/linux-6.14.4/include/linux/uidgid_types.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/asm/kmap_size.h \
  /home/ns/linux-6.14.4/include/asm-generic/kmap_size.h \
    $(wildcard include/config/DEBUG_KMAP_LOCAL) \
  /home/ns/linux-6.14.4/include/linux/sched/ext.h \
    $(wildcard include/config/EXT_GROUP_SCHED) \
  /home/ns/linux-6.14.4/include/linux/tracepoint-defs.h \
  /home/ns/linux-6.14.4/include/vdso/time32.h \
  /home/ns/linux-6.14.4/include/vdso/time.h \
  /home/ns/linux-6.14.4/include/vdso/jiffies.h \
  /home/ns/linux-6.14.4/include/generated/timeconst.h \
  /home/ns/linux-6.14.4/include/vdso/ktime.h \
  /home/ns/linux-6.14.4/include/linux/timekeeping.h \
    $(wildcard include/config/GENERIC_CMOS_UPDATE) \
  /home/ns/linux-6.14.4/include/linux/clocksource_ids.h \
  /home/ns/linux-6.14.4/include/linux/debugobjects.h \
    $(wildcard include/config/DEBUG_OBJECTS) \
    $(wildcard include/config/DEBUG_OBJECTS_FREE) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/uprobes.h \
  /home/ns/linux-6.14.4/include/linux/notifier.h \
    $(wildcard include/config/TREE_SRCU) \
  /home/ns/linux-6.14.4/include/linux/srcu.h \
    $(wildcard include/config/TINY_SRCU) \
    $(wildcard include/config/NEED_SRCU_NMI_SAFE) \
  /home/ns/linux-6.14.4/include/linux/workqueue.h \
    $(wildcard include/config/DEBUG_OBJECTS_WORK) \
    $(wildcard include/config/FREEZER) \
    $(wildcard include/config/SYSFS) \
    $(wildcard include/config/WQ_WATCHDOG) \
  /home/ns/linux-6.14.4/include/linux/workqueue_types.h \
  /home/ns/linux-6.14.4/include/linux/rcu_segcblist.h \
  /home/ns/linux-6.14.4/include/linux/srcutree.h \
  /home/ns/linux-6.14.4/include/linux/rcu_node_tree.h \
    $(wildcard include/config/RCU_FANOUT) \
    $(wildcard include/config/RCU_FANOUT_LEAF) \
  /home/ns/linux-6.14.4/include/linux/percpu_counter.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/mmu.h \
    $(wildcard include/config/MODIFY_LDT_SYSCALL) \
  /home/ns/linux-6.14.4/include/linux/page-flags.h \
    $(wildcard include/config/PAGE_IDLE_FLAG) \
    $(wildcard include/config/ARCH_USES_PG_ARCH_2) \
    $(wildcard include/config/ARCH_USES_PG_ARCH_3) \
    $(wildcard include/config/HUGETLB_PAGE_OPTIMIZE_VMEMMAP) \
  /home/ns/linux-6.14.4/include/linux/local_lock.h \
  /home/ns/linux-6.14.4/include/linux/local_lock_internal.h \
  /home/ns/linux-6.14.4/include/linux/zswap.h \
    $(wildcard include/config/ZSWAP) \
  /home/ns/linux-6.14.4/include/linux/memory_hotplug.h \
    $(wildcard include/config/ARCH_HAS_ADD_PAGES) \
    $(wildcard include/config/MEMORY_HOTREMOVE) \
  /home/ns/linux-6.14.4/arch/x86/include/generated/asm/mmzone.h \
  /home/ns/linux-6.14.4/include/asm-generic/mmzone.h \
  /home/ns/linux-6.14.4/include/linux/topology.h \
    $(wildcard include/config/USE_PERCPU_NUMA_NODE_ID) \
    $(wildcard include/config/SCHED_SMT) \
  /home/ns/linux-6.14.4/include/linux/arch_topology.h \
    $(wildcard include/config/GENERIC_ARCH_TOPOLOGY) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/topology.h \
    $(wildcard include/config/X86_LOCAL_APIC) \
    $(wildcard include/config/SCHED_MC_PRIO) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/mpspec.h \
    $(wildcard include/config/EISA) \
    $(wildcard include/config/X86_MPPARSE) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/mpspec_def.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/x86_init.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/apicdef.h \
  /home/ns/linux-6.14.4/include/asm-generic/topology.h \
  /home/ns/linux-6.14.4/include/linux/cpu_smt.h \
    $(wildcard include/config/HOTPLUG_SMT) \
  /home/ns/linux-6.14.4/include/linux/pgalloc_tag.h \
  /home/ns/linux-6.14.4/include/linux/mmap_lock.h \
  /home/ns/linux-6.14.4/include/linux/percpu-refcount.h \
  /home/ns/linux-6.14.4/include/linux/bit_spinlock.h \
  /home/ns/linux-6.14.4/include/linux/shrinker.h \
    $(wildcard include/config/SHRINKER_DEBUG) \
  /home/ns/linux-6.14.4/include/linux/page_ext.h \
  /home/ns/linux-6.14.4/include/linux/stacktrace.h \
    $(wildcard include/config/ARCH_STACKWALK) \
    $(wildcard include/config/STACKTRACE) \
    $(wildcard include/config/HAVE_RELIABLE_STACKTRACE) \
  /home/ns/linux-6.14.4/include/linux/page_ref.h \
    $(wildcard include/config/DEBUG_PAGE_REF) \
  /home/ns/linux-6.14.4/include/linux/sizes.h \
  /home/ns/linux-6.14.4/include/linux/pgtable.h \
    $(wildcard include/config/ARCH_HAS_NONLEAF_PMD_YOUNG) \
    $(wildcard include/config/ARCH_HAS_HW_PTE_YOUNG) \
    $(wildcard include/config/GUP_GET_PXX_LOW_HIGH) \
    $(wildcard include/config/ARCH_WANT_PMD_MKWRITE) \
    $(wildcard include/config/HAVE_ARCH_TRANSPARENT_HUGEPAGE_PUD) \
    $(wildcard include/config/HAVE_ARCH_SOFT_DIRTY) \
    $(wildcard include/config/ARCH_ENABLE_THP_MIGRATION) \
    $(wildcard include/config/HAVE_ARCH_HUGE_VMAP) \
    $(wildcard include/config/X86_ESPFIX64) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/pgtable.h \
    $(wildcard include/config/DEBUG_WX) \
    $(wildcard include/config/PAGE_TABLE_CHECK) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/pkru.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/fpu/api.h \
    $(wildcard include/config/X86_DEBUG_FPU) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/coco.h \
  /home/ns/linux-6.14.4/include/asm-generic/pgtable_uffd.h \
  /home/ns/linux-6.14.4/include/linux/page_table_check.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/pgtable_64.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/fixmap.h \
    $(wildcard include/config/PROVIDE_OHCI1394_DMA_INIT) \
    $(wildcard include/config/X86_IO_APIC) \
    $(wildcard include/config/PCI_MMCONFIG) \
    $(wildcard include/config/ACPI_APEI_GHES) \
    $(wildcard include/config/INTEL_TXT) \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/vsyscall.h \
  /home/ns/linux-6.14.4/include/asm-generic/fixmap.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/pgtable-invert.h \
  /home/ns/linux-6.14.4/include/linux/kasan.h \
    $(wildcard include/config/KASAN_STACK) \
    $(wildcard include/config/KASAN_VMALLOC) \
  /home/ns/linux-6.14.4/include/linux/kasan-enabled.h \
  /home/ns/linux-6.14.4/include/linux/kasan-tags.h \
  /home/ns/linux-6.14.4/include/linux/memremap.h \
    $(wildcard include/config/DEVICE_PRIVATE) \
    $(wildcard include/config/PCI_P2PDMA) \
  /home/ns/linux-6.14.4/include/linux/ioport.h \
  /home/ns/linux-6.14.4/include/linux/slab.h \
    $(wildcard include/config/FAILSLAB) \
    $(wildcard include/config/KFENCE) \
    $(wildcard include/config/SLUB_TINY) \
    $(wildcard include/config/SLUB_DEBUG) \
    $(wildcard include/config/SLAB_FREELIST_HARDENED) \
    $(wildcard include/config/SLAB_BUCKETS) \
  /home/ns/linux-6.14.4/include/linux/hash.h \
    $(wildcard include/config/HAVE_ARCH_HASH) \
  /home/ns/linux-6.14.4/include/linux/cacheinfo.h \
    $(wildcard include/config/ACPI_PPTT) \
    $(wildcard include/config/ARM) \
    $(wildcard include/config/ARCH_HAS_CPU_CACHE_ALIASING) \
  /home/ns/linux-6.14.4/include/linux/cpuhplock.h \
  /home/ns/linux-6.14.4/include/linux/huge_mm.h \
    $(wildcard include/config/PGTABLE_HAS_HUGE_LEAVES) \
  /home/ns/linux-6.14.4/include/linux/fs.h \
    $(wildcard include/config/FANOTIFY_ACCESS_PERMISSIONS) \
    $(wildcard include/config/READ_ONLY_THP_FOR_FS) \
    $(wildcard include/config/FS_POSIX_ACL) \
    $(wildcard include/config/CGROUP_WRITEBACK) \
    $(wildcard include/config/IMA) \
    $(wildcard include/config/FILE_LOCKING) \
    $(wildcard include/config/FSNOTIFY) \
    $(wildcard include/config/FS_ENCRYPTION) \
    $(wildcard include/config/FS_VERITY) \
    $(wildcard include/config/EPOLL) \
    $(wildcard include/config/UNICODE) \
    $(wildcard include/config/QUOTA) \
    $(wildcard include/config/BLOCK) \
  /home/ns/linux-6.14.4/include/linux/wait_bit.h \
  /home/ns/linux-6.14.4/include/linux/kdev_t.h \
  /home/ns/linux-6.14.4/include/uapi/linux/kdev_t.h \
  /home/ns/linux-6.14.4/include/linux/dcache.h \
  /home/ns/linux-6.14.4/include/linux/rculist.h \
    $(wildcard include/config/PROVE_RCU_LIST) \
  /home/ns/linux-6.14.4/include/linux/rculist_bl.h \
  /home/ns/linux-6.14.4/include/linux/list_bl.h \
  /home/ns/linux-6.14.4/include/linux/lockref.h \
    $(wildcard include/config/ARCH_USE_CMPXCHG_LOCKREF) \
  /home/ns/linux-6.14.4/include/linux/stringhash.h \
    $(wildcard include/config/DCACHE_WORD_ACCESS) \
  /home/ns/linux-6.14.4/include/linux/path.h \
  /home/ns/linux-6.14.4/include/linux/stat.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/stat.h \
  /home/ns/linux-6.14.4/include/uapi/linux/stat.h \
  /home/ns/linux-6.14.4/include/linux/uidgid.h \
    $(wildcard include/config/MULTIUSER) \
    $(wildcard include/config/USER_NS) \
  /home/ns/linux-6.14.4/include/linux/highuid.h \
  /home/ns/linux-6.14.4/include/linux/list_lru.h \
  /home/ns/linux-6.14.4/include/linux/xarray.h \
    $(wildcard include/config/XARRAY_MULTI) \
  /home/ns/linux-6.14.4/include/linux/sched/mm.h \
    $(wildcard include/config/MMU_LAZY_TLB_REFCOUNT) \
    $(wildcard include/config/ARCH_HAS_MEMBARRIER_CALLBACKS) \
  /home/ns/linux-6.14.4/include/linux/sync_core.h \
    $(wildcard include/config/ARCH_HAS_SYNC_CORE_BEFORE_USERMODE) \
    $(wildcard include/config/ARCH_HAS_PREPARE_SYNC_CORE_CMD) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/sync_core.h \
  /home/ns/linux-6.14.4/include/linux/sched/coredump.h \
  /home/ns/linux-6.14.4/include/linux/radix-tree.h \
  /home/ns/linux-6.14.4/include/linux/pid.h \
  /home/ns/linux-6.14.4/include/linux/capability.h \
  /home/ns/linux-6.14.4/include/uapi/linux/capability.h \
  /home/ns/linux-6.14.4/include/linux/semaphore.h \
  /home/ns/linux-6.14.4/include/linux/fcntl.h \
    $(wildcard include/config/ARCH_32BIT_OFF_T) \
  /home/ns/linux-6.14.4/include/uapi/linux/fcntl.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/uapi/asm/fcntl.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/fcntl.h \
  /home/ns/linux-6.14.4/include/uapi/linux/openat2.h \
  /home/ns/linux-6.14.4/include/linux/migrate_mode.h \
  /home/ns/linux-6.14.4/include/linux/percpu-rwsem.h \
  /home/ns/linux-6.14.4/include/linux/rcuwait.h \
  /home/ns/linux-6.14.4/include/linux/sched/signal.h \
    $(wildcard include/config/SCHED_AUTOGROUP) \
    $(wildcard include/config/BSD_PROCESS_ACCT) \
    $(wildcard include/config/TASKSTATS) \
  /home/ns/linux-6.14.4/include/linux/signal.h \
    $(wildcard include/config/DYNAMIC_SIGFRAME) \
  /home/ns/linux-6.14.4/include/linux/sched/jobctl.h \
  /home/ns/linux-6.14.4/include/linux/sched/task.h \
    $(wildcard include/config/HAVE_EXIT_THREAD) \
    $(wildcard include/config/ARCH_WANTS_DYNAMIC_TASK_STRUCT) \
    $(wildcard include/config/HAVE_ARCH_THREAD_STRUCT_WHITELIST) \
  /home/ns/linux-6.14.4/include/linux/uaccess.h \
    $(wildcard include/config/ARCH_HAS_SUBPAGE_FAULTS) \
  /home/ns/linux-6.14.4/include/linux/fault-inject-usercopy.h \
    $(wildcard include/config/FAULT_INJECTION_USERCOPY) \
  /home/ns/linux-6.14.4/include/linux/nospec.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/uaccess.h \
    $(wildcard include/config/CC_HAS_ASM_GOTO_OUTPUT) \
    $(wildcard include/config/CC_HAS_ASM_GOTO_TIED_OUTPUT) \
    $(wildcard include/config/ARCH_HAS_COPY_MC) \
    $(wildcard include/config/X86_INTEL_USERCOPY) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/smap.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/extable.h \
    $(wildcard include/config/BPF_JIT) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/tlbflush.h \
  /home/ns/linux-6.14.4/include/linux/mmu_notifier.h \
  /home/ns/linux-6.14.4/include/linux/interval_tree.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/invpcid.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/pti.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/uaccess_64.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/runtime-const.h \
  /home/ns/linux-6.14.4/include/asm-generic/access_ok.h \
    $(wildcard include/config/ALTERNATE_USER_ADDRESS_SPACE) \
  /home/ns/linux-6.14.4/include/linux/cred.h \
  /home/ns/linux-6.14.4/include/linux/key.h \
    $(wildcard include/config/KEY_NOTIFICATIONS) \
    $(wildcard include/config/NET) \
  /home/ns/linux-6.14.4/include/linux/sysctl.h \
  /home/ns/linux-6.14.4/include/uapi/linux/sysctl.h \
  /home/ns/linux-6.14.4/include/linux/assoc_array.h \
    $(wildcard include/config/ASSOCIATIVE_ARRAY) \
  /home/ns/linux-6.14.4/include/linux/sched/user.h \
    $(wildcard include/config/VFIO_PCI_ZDEV_KVM) \
    $(wildcard include/config/IOMMUFD) \
    $(wildcard include/config/WATCH_QUEUE) \
  /home/ns/linux-6.14.4/include/linux/ratelimit.h \
  /home/ns/linux-6.14.4/include/linux/posix-timers.h \
  /home/ns/linux-6.14.4/include/linux/alarmtimer.h \
    $(wildcard include/config/RTC_CLASS) \
  /home/ns/linux-6.14.4/include/linux/hrtimer.h \
    $(wildcard include/config/HIGH_RES_TIMERS) \
    $(wildcard include/config/TIME_LOW_RES) \
    $(wildcard include/config/TIMERFD) \
  /home/ns/linux-6.14.4/include/linux/hrtimer_defs.h \
  /home/ns/linux-6.14.4/include/linux/timerqueue.h \
  /home/ns/linux-6.14.4/include/linux/rcuref.h \
  /home/ns/linux-6.14.4/include/linux/rcu_sync.h \
  /home/ns/linux-6.14.4/include/linux/delayed_call.h \
  /home/ns/linux-6.14.4/include/linux/uuid.h \
  /home/ns/linux-6.14.4/include/linux/errseq.h \
  /home/ns/linux-6.14.4/include/linux/ioprio.h \
  /home/ns/linux-6.14.4/include/linux/sched/rt.h \
  /home/ns/linux-6.14.4/include/linux/iocontext.h \
    $(wildcard include/config/BLK_ICQ) \
  /home/ns/linux-6.14.4/include/uapi/linux/ioprio.h \
  /home/ns/linux-6.14.4/include/linux/fs_types.h \
  /home/ns/linux-6.14.4/include/linux/mount.h \
  /home/ns/linux-6.14.4/include/linux/mnt_idmapping.h \
  /home/ns/linux-6.14.4/include/linux/rw_hint.h \
  /home/ns/linux-6.14.4/include/linux/file_ref.h \
  /home/ns/linux-6.14.4/include/linux/unicode.h \
  /home/ns/linux-6.14.4/include/uapi/linux/fs.h \
  /home/ns/linux-6.14.4/include/linux/quota.h \
    $(wildcard include/config/QUOTA_NETLINK_INTERFACE) \
  /home/ns/linux-6.14.4/include/uapi/linux/dqblk_xfs.h \
  /home/ns/linux-6.14.4/include/linux/dqblk_v1.h \
  /home/ns/linux-6.14.4/include/linux/dqblk_v2.h \
  /home/ns/linux-6.14.4/include/linux/dqblk_qtree.h \
  /home/ns/linux-6.14.4/include/linux/projid.h \
  /home/ns/linux-6.14.4/include/uapi/linux/quota.h \
  /home/ns/linux-6.14.4/include/linux/kobject.h \
    $(wildcard include/config/UEVENT_HELPER) \
    $(wildcard include/config/DEBUG_KOBJECT_RELEASE) \
  /home/ns/linux-6.14.4/include/linux/sysfs.h \
  /home/ns/linux-6.14.4/include/linux/kernfs.h \
    $(wildcard include/config/KERNFS) \
  /home/ns/linux-6.14.4/include/linux/idr.h \
  /home/ns/linux-6.14.4/include/linux/kobject_ns.h \
  /home/ns/linux-6.14.4/include/linux/vmstat.h \
    $(wildcard include/config/VM_EVENT_COUNTERS) \
    $(wildcard include/config/DEBUG_TLBFLUSH) \
    $(wildcard include/config/PER_VMA_LOCK_STATS) \
  /home/ns/linux-6.14.4/include/linux/vm_event_item.h \
    $(wildcard include/config/MEMORY_BALLOON) \
    $(wildcard include/config/BALLOON_COMPACTION) \
    $(wildcard include/config/DEBUG_STACK_USAGE) \
  /home/ns/linux-6.14.4/include/linux/module.h \
    $(wildcard include/config/MODULES_TREE_LOOKUP) \
    $(wildcard include/config/STACKTRACE_BUILD_ID) \
    $(wildcard include/config/ARCH_USES_CFI_TRAPS) \
    $(wildcard include/config/MODULE_SIG) \
    $(wildcard include/config/KALLSYMS) \
    $(wildcard include/config/BPF_EVENTS) \
    $(wildcard include/config/DEBUG_INFO_BTF_MODULES) \
    $(wildcard include/config/EVENT_TRACING) \
    $(wildcard include/config/MODULE_UNLOAD) \
    $(wildcard include/config/CONSTRUCTORS) \
    $(wildcard include/config/FUNCTION_ERROR_INJECTION) \
    $(wildcard include/config/ARCH_HAS_EXECMEM_ROX) \
  /home/ns/linux-6.14.4/include/linux/buildid.h \
    $(wildcard include/config/VMCORE_INFO) \
  /home/ns/linux-6.14.4/include/linux/kmod.h \
  /home/ns/linux-6.14.4/include/linux/umh.h \
  /home/ns/linux-6.14.4/include/linux/elf.h \
    $(wildcard include/config/ARCH_HAVE_EXTRA_ELF_NOTES) \
    $(wildcard include/config/ARCH_USE_GNU_PROPERTY) \
    $(wildcard include/config/ARCH_HAVE_ELF_PROT) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/elf.h \
    $(wildcard include/config/X86_X32_ABI) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/ia32.h \
  /home/ns/linux-6.14.4/include/linux/compat.h \
    $(wildcard include/config/ARCH_HAS_SYSCALL_WRAPPER) \
    $(wildcard include/config/COMPAT_OLD_SIGACTION) \
    $(wildcard include/config/ODD_RT_SIGACTION) \
  /home/ns/linux-6.14.4/include/linux/sem.h \
  /home/ns/linux-6.14.4/include/uapi/linux/sem.h \
  /home/ns/linux-6.14.4/include/linux/ipc.h \
  /home/ns/linux-6.14.4/include/linux/rhashtable-types.h \
  /home/ns/linux-6.14.4/include/uapi/linux/ipc.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/uapi/asm/ipcbuf.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/ipcbuf.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/sembuf.h \
  /home/ns/linux-6.14.4/include/linux/socket.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/uapi/asm/socket.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/socket.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/uapi/asm/sockios.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/sockios.h \
  /home/ns/linux-6.14.4/include/uapi/linux/sockios.h \
  /home/ns/linux-6.14.4/include/linux/uio.h \
  /home/ns/linux-6.14.4/include/uapi/linux/uio.h \
  /home/ns/linux-6.14.4/include/uapi/linux/socket.h \
  /home/ns/linux-6.14.4/include/uapi/linux/if.h \
  /home/ns/linux-6.14.4/include/uapi/linux/libc-compat.h \
  /home/ns/linux-6.14.4/include/uapi/linux/hdlc/ioctl.h \
  /home/ns/linux-6.14.4/include/uapi/linux/aio_abi.h \
  /home/ns/linux-6.14.4/include/uapi/linux/unistd.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/unistd.h \
  /home/ns/linux-6.14.4/arch/x86/include/uapi/asm/unistd.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/uapi/asm/unistd_64.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/asm/unistd_64_x32.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/asm/unistd_32_ia32.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/compat.h \
  /home/ns/linux-6.14.4/include/linux/sched/task_stack.h \
  /home/ns/linux-6.14.4/include/uapi/linux/magic.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/user32.h \
  /home/ns/linux-6.14.4/include/asm-generic/compat.h \
    $(wildcard include/config/COMPAT_FOR_U64_ALIGNMENT) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/syscall_wrapper.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/user.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/user_64.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/fsgsbase.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/vdso.h \
  /home/ns/linux-6.14.4/include/uapi/linux/elf.h \
  /home/ns/linux-6.14.4/include/uapi/linux/elf-em.h \
  /home/ns/linux-6.14.4/include/linux/moduleparam.h \
    $(wildcard include/config/ALPHA) \
  /home/ns/linux-6.14.4/include/linux/rbtree_latch.h \
  /home/ns/linux-6.14.4/include/linux/error-injection.h \
  /home/ns/linux-6.14.4/include/asm-generic/error-injection.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/module.h \
    $(wildcard include/config/UNWINDER_ORC) \
  /home/ns/linux-6.14.4/include/asm-generic/module.h \
    $(wildcard include/config/HAVE_MOD_ARCH_SPECIFIC) \
    $(wildcard include/config/MODULES_USE_ELF_REL) \
    $(wildcard include/config/MODULES_USE_ELF_RELA) \
  /home/ns/linux-6.14.4/include/linux/skbuff.h \
    $(wildcard include/config/NF_CONNTRACK) \
    $(wildcard include/config/BRIDGE_NETFILTER) \
    $(wildcard include/config/NET_TC_SKB_EXT) \
    $(wildcard include/config/MAX_SKB_FRAGS) \
    $(wildcard include/config/NET_SOCK_MSG) \
    $(wildcard include/config/SKB_EXTENSIONS) \
    $(wildcard include/config/NET_XGRESS) \
    $(wildcard include/config/WIRELESS) \
    $(wildcard include/config/IPV6_NDISC_NODETYPE) \
    $(wildcard include/config/IP_VS) \
    $(wildcard include/config/NETFILTER_XT_TARGET_TRACE) \
    $(wildcard include/config/NF_TABLES) \
    $(wildcard include/config/NET_SWITCHDEV) \
    $(wildcard include/config/NET_REDIRECT) \
    $(wildcard include/config/NETFILTER_SKIP_EGRESS) \
    $(wildcard include/config/SKB_DECRYPTED) \
    $(wildcard include/config/IP_SCTP) \
    $(wildcard include/config/NET_SCHED) \
    $(wildcard include/config/NET_RX_BUSY_POLL) \
    $(wildcard include/config/XPS) \
    $(wildcard include/config/NETWORK_SECMARK) \
    $(wildcard include/config/DEBUG_NET) \
    $(wildcard include/config/FAIL_SKB_REALLOC) \
    $(wildcard include/config/HAVE_EFFICIENT_UNALIGNED_ACCESS) \
    $(wildcard include/config/NETWORK_PHY_TIMESTAMPING) \
    $(wildcard include/config/XFRM) \
    $(wildcard include/config/MPTCP) \
    $(wildcard include/config/MCTP_FLOWS) \
    $(wildcard include/config/PAGE_POOL) \
  /home/ns/linux-6.14.4/include/linux/bvec.h \
  /home/ns/linux-6.14.4/include/linux/highmem.h \
  /home/ns/linux-6.14.4/include/linux/cacheflush.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/cacheflush.h \
  /home/ns/linux-6.14.4/include/asm-generic/cacheflush.h \
  /home/ns/linux-6.14.4/include/linux/kmsan.h \
  /home/ns/linux-6.14.4/include/linux/dma-direction.h \
  /home/ns/linux-6.14.4/include/linux/hardirq.h \
  /home/ns/linux-6.14.4/include/linux/context_tracking_state.h \
    $(wildcard include/config/CONTEXT_TRACKING_USER) \
    $(wildcard include/config/CONTEXT_TRACKING) \
  /home/ns/linux-6.14.4/include/linux/ftrace_irq.h \
    $(wildcard include/config/HWLAT_TRACER) \
    $(wildcard include/config/OSNOISE_TRACER) \
  /home/ns/linux-6.14.4/include/linux/vtime.h \
    $(wildcard include/config/VIRT_CPU_ACCOUNTING) \
    $(wildcard include/config/IRQ_TIME_ACCOUNTING) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/hardirq.h \
    $(wildcard include/config/KVM_INTEL) \
    $(wildcard include/config/KVM) \
    $(wildcard include/config/X86_THERMAL_VECTOR) \
    $(wildcard include/config/X86_MCE_THRESHOLD) \
    $(wildcard include/config/X86_MCE_AMD) \
    $(wildcard include/config/X86_HV_CALLBACK_VECTOR) \
    $(wildcard include/config/HYPERV) \
    $(wildcard include/config/X86_POSTED_MSI) \
  /home/ns/linux-6.14.4/include/linux/highmem-internal.h \
  /home/ns/linux-6.14.4/include/net/checksum.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/checksum.h \
    $(wildcard include/config/GENERIC_CSUM) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/checksum_64.h \
  /home/ns/linux-6.14.4/include/linux/dma-mapping.h \
    $(wildcard include/config/DMA_API_DEBUG) \
    $(wildcard include/config/HAS_DMA) \
    $(wildcard include/config/DMA_NEED_SYNC) \
    $(wildcard include/config/NEED_DMA_MAP_STATE) \
  /home/ns/linux-6.14.4/include/linux/device.h \
    $(wildcard include/config/HAS_IOMEM) \
    $(wildcard include/config/GENERIC_MSI_IRQ) \
    $(wildcard include/config/ENERGY_MODEL) \
    $(wildcard include/config/PINCTRL) \
    $(wildcard include/config/ARCH_HAS_DMA_OPS) \
    $(wildcard include/config/DMA_DECLARE_COHERENT) \
    $(wildcard include/config/DMA_CMA) \
    $(wildcard include/config/SWIOTLB) \
    $(wildcard include/config/SWIOTLB_DYNAMIC) \
    $(wildcard include/config/ARCH_HAS_SYNC_DMA_FOR_DEVICE) \
    $(wildcard include/config/ARCH_HAS_SYNC_DMA_FOR_CPU) \
    $(wildcard include/config/ARCH_HAS_SYNC_DMA_FOR_CPU_ALL) \
    $(wildcard include/config/DMA_OPS_BYPASS) \
    $(wildcard include/config/IOMMU_DMA) \
    $(wildcard include/config/PM_SLEEP) \
    $(wildcard include/config/OF) \
    $(wildcard include/config/DEVTMPFS) \
  /home/ns/linux-6.14.4/include/linux/dev_printk.h \
  /home/ns/linux-6.14.4/include/linux/energy_model.h \
    $(wildcard include/config/SCHED_DEBUG) \
  /home/ns/linux-6.14.4/include/linux/sched/cpufreq.h \
    $(wildcard include/config/CPU_FREQ) \
  /home/ns/linux-6.14.4/include/linux/sched/topology.h \
    $(wildcard include/config/SCHED_CLUSTER) \
    $(wildcard include/config/SCHED_MC) \
    $(wildcard include/config/CPU_FREQ_GOV_SCHEDUTIL) \
  /home/ns/linux-6.14.4/include/linux/sched/idle.h \
  /home/ns/linux-6.14.4/include/linux/sched/sd_flags.h \
  /home/ns/linux-6.14.4/include/linux/klist.h \
  /home/ns/linux-6.14.4/include/linux/pm.h \
    $(wildcard include/config/VT_CONSOLE_SLEEP) \
    $(wildcard include/config/CXL_SUSPEND) \
    $(wildcard include/config/PM) \
    $(wildcard include/config/PM_CLK) \
    $(wildcard include/config/PM_GENERIC_DOMAINS) \
  /home/ns/linux-6.14.4/include/linux/device/bus.h \
    $(wildcard include/config/ACPI) \
  /home/ns/linux-6.14.4/include/linux/device/class.h \
  /home/ns/linux-6.14.4/include/linux/device/driver.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/device.h \
  /home/ns/linux-6.14.4/include/linux/pm_wakeup.h \
  /home/ns/linux-6.14.4/include/linux/scatterlist.h \
    $(wildcard include/config/NEED_SG_DMA_LENGTH) \
    $(wildcard include/config/NEED_SG_DMA_FLAGS) \
    $(wildcard include/config/DEBUG_SG) \
    $(wildcard include/config/SGL_ALLOC) \
    $(wildcard include/config/ARCH_NO_SG_CHAIN) \
    $(wildcard include/config/SG_POOL) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/io.h \
    $(wildcard include/config/MTRR) \
    $(wildcard include/config/X86_PAT) \
  /home/ns/linux-6.14.4/arch/x86/include/generated/asm/early_ioremap.h \
  /home/ns/linux-6.14.4/include/asm-generic/early_ioremap.h \
    $(wildcard include/config/GENERIC_EARLY_IOREMAP) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/shared/io.h \
  /home/ns/linux-6.14.4/include/asm-generic/io.h \
    $(wildcard include/config/GENERIC_IOMAP) \
    $(wildcard include/config/TRACE_MMIO_ACCESS) \
    $(wildcard include/config/HAS_IOPORT) \
    $(wildcard include/config/GENERIC_IOREMAP) \
    $(wildcard include/config/HAS_IOPORT_MAP) \
  /home/ns/linux-6.14.4/include/asm-generic/iomap.h \
  /home/ns/linux-6.14.4/include/asm-generic/pci_iomap.h \
    $(wildcard include/config/PCI) \
    $(wildcard include/config/NO_GENERIC_PCI_IOPORT_MAP) \
    $(wildcard include/config/GENERIC_PCI_IOMAP) \
  /home/ns/linux-6.14.4/include/linux/logic_pio.h \
    $(wildcard include/config/INDIRECT_PIO) \
  /home/ns/linux-6.14.4/include/linux/fwnode.h \
  /home/ns/linux-6.14.4/include/linux/netdev_features.h \
  /home/ns/linux-6.14.4/include/net/flow_dissector.h \
  /home/ns/linux-6.14.4/include/linux/in6.h \
  /home/ns/linux-6.14.4/include/uapi/linux/in6.h \
  /home/ns/linux-6.14.4/include/linux/siphash.h \
  /home/ns/linux-6.14.4/include/uapi/linux/if_ether.h \
  /home/ns/linux-6.14.4/include/uapi/linux/pkt_cls.h \
    $(wildcard include/config/NET_CLS_ACT) \
  /home/ns/linux-6.14.4/include/uapi/linux/pkt_sched.h \
  /home/ns/linux-6.14.4/include/uapi/linux/if_packet.h \
  /home/ns/linux-6.14.4/include/linux/page_frag_cache.h \
  /home/ns/linux-6.14.4/include/net/flow.h \
  /home/ns/linux-6.14.4/include/linux/netfilter/nf_conntrack_common.h \
  /home/ns/linux-6.14.4/include/uapi/linux/netfilter/nf_conntrack_common.h \
  /home/ns/linux-6.14.4/include/net/net_debug.h \
  /home/ns/linux-6.14.4/include/net/dropreason-core.h \
  /home/ns/linux-6.14.4/include/net/netmem.h \
  /home/ns/linux-6.14.4/include/linux/inet_diag.h \
    $(wildcard include/config/IPV6) \
    $(wildcard include/config/SOCK_CGROUP_DATA) \
  /home/ns/linux-6.14.4/include/net/netlink.h \
  /home/ns/linux-6.14.4/include/linux/netlink.h \
  /home/ns/linux-6.14.4/include/net/scm.h \
    $(wildcard include/config/UNIX) \
    $(wildcard include/config/SECURITY_NETWORK) \
  /home/ns/linux-6.14.4/include/linux/net.h \
  /home/ns/linux-6.14.4/include/linux/once.h \
  /home/ns/linux-6.14.4/include/linux/sockptr.h \
  /home/ns/linux-6.14.4/include/uapi/linux/net.h \
  /home/ns/linux-6.14.4/include/linux/file.h \
  /home/ns/linux-6.14.4/include/linux/security.h \
    $(wildcard include/config/SECURITY_INFINIBAND) \
    $(wildcard include/config/SECURITY_NETWORK_XFRM) \
    $(wildcard include/config/SECURITY_PATH) \
    $(wildcard include/config/SECURITYFS) \
  /home/ns/linux-6.14.4/include/linux/kernel_read_file.h \
  /home/ns/linux-6.14.4/include/linux/bpf.h \
    $(wildcard include/config/FINEIBT) \
    $(wildcard include/config/CGROUP_BPF) \
    $(wildcard include/config/BPF_LSM) \
    $(wildcard include/config/BPF_JIT_ALWAYS_ON) \
    $(wildcard include/config/INET) \
  /home/ns/linux-6.14.4/include/uapi/linux/bpf.h \
    $(wildcard include/config/BPF_LIRC_MODE2) \
    $(wildcard include/config/EFFICIENT_UNALIGNED_ACCESS) \
    $(wildcard include/config/CGROUP_NET_CLASSID) \
    $(wildcard include/config/IP_ROUTE_CLASSID) \
    $(wildcard include/config/BPF_KPROBE_OVERRIDE) \
  /home/ns/linux-6.14.4/include/uapi/linux/bpf_common.h \
  /home/ns/linux-6.14.4/include/uapi/linux/filter.h \
  /home/ns/linux-6.14.4/include/linux/kallsyms.h \
    $(wildcard include/config/KALLSYMS_ALL) \
    $(wildcard include/config/HAVE_FUNCTION_DESCRIPTORS) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/sections.h \
  /home/ns/linux-6.14.4/include/asm-generic/sections.h \
  /home/ns/linux-6.14.4/include/linux/bpfptr.h \
  /home/ns/linux-6.14.4/include/linux/btf.h \
  /home/ns/linux-6.14.4/include/linux/bsearch.h \
  /home/ns/linux-6.14.4/include/linux/btf_ids.h \
  /home/ns/linux-6.14.4/include/uapi/linux/btf.h \
  /home/ns/linux-6.14.4/include/linux/rcupdate_trace.h \
    $(wildcard include/config/TASKS_TRACE_RCU_READ_MB) \
  /home/ns/linux-6.14.4/include/linux/static_call.h \
  /home/ns/linux-6.14.4/include/linux/cpu.h \
    $(wildcard include/config/GENERIC_CPU_DEVICES) \
    $(wildcard include/config/PM_SLEEP_SMP) \
    $(wildcard include/config/PM_SLEEP_SMP_NONZERO_CPU) \
    $(wildcard include/config/ARCH_HAS_CPU_FINALIZE_INIT) \
    $(wildcard include/config/CPU_MITIGATIONS) \
  /home/ns/linux-6.14.4/include/linux/node.h \
    $(wildcard include/config/HMEM_REPORTING) \
  /home/ns/linux-6.14.4/include/linux/cpuhotplug.h \
    $(wildcard include/config/HOTPLUG_CORE_SYNC_DEAD) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/static_call.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/text-patching.h \
    $(wildcard include/config/UML_X86) \
  /home/ns/linux-6.14.4/include/linux/memcontrol.h \
  /home/ns/linux-6.14.4/include/linux/cgroup.h \
    $(wildcard include/config/DEBUG_CGROUP_REF) \
    $(wildcard include/config/CGROUP_CPUACCT) \
    $(wildcard include/config/CGROUP_DATA) \
  /home/ns/linux-6.14.4/include/uapi/linux/cgroupstats.h \
  /home/ns/linux-6.14.4/include/uapi/linux/taskstats.h \
  /home/ns/linux-6.14.4/include/linux/seq_file.h \
  /home/ns/linux-6.14.4/include/linux/string_helpers.h \
  /home/ns/linux-6.14.4/include/linux/ctype.h \
  /home/ns/linux-6.14.4/include/linux/string_choices.h \
  /home/ns/linux-6.14.4/include/linux/ns_common.h \
  /home/ns/linux-6.14.4/include/linux/nsproxy.h \
  /home/ns/linux-6.14.4/include/linux/user_namespace.h \
    $(wildcard include/config/INOTIFY_USER) \
    $(wildcard include/config/FANOTIFY) \
    $(wildcard include/config/BINFMT_MISC) \
    $(wildcard include/config/PERSISTENT_KEYRINGS) \
  /home/ns/linux-6.14.4/include/linux/kernel_stat.h \
    $(wildcard include/config/GENERIC_IRQ_STAT_SNAPSHOT) \
  /home/ns/linux-6.14.4/include/linux/interrupt.h \
    $(wildcard include/config/IRQ_FORCED_THREADING) \
    $(wildcard include/config/GENERIC_IRQ_PROBE) \
    $(wildcard include/config/IRQ_TIMINGS) \
  /home/ns/linux-6.14.4/include/linux/irqreturn.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/irq.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/irq_vectors.h \
    $(wildcard include/config/PCI_MSI) \
  /home/ns/linux-6.14.4/include/linux/cgroup-defs.h \
    $(wildcard include/config/CGROUP_NET_PRIO) \
  /home/ns/linux-6.14.4/include/linux/u64_stats_sync.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/asm/local64.h \
  /home/ns/linux-6.14.4/include/asm-generic/local64.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/local.h \
  /home/ns/linux-6.14.4/include/linux/bpf-cgroup-defs.h \
  /home/ns/linux-6.14.4/include/linux/psi_types.h \
  /home/ns/linux-6.14.4/include/linux/kthread.h \
  /home/ns/linux-6.14.4/include/linux/cgroup_subsys.h \
    $(wildcard include/config/CGROUP_DEVICE) \
    $(wildcard include/config/CGROUP_FREEZER) \
    $(wildcard include/config/CGROUP_PERF) \
    $(wildcard include/config/CGROUP_HUGETLB) \
    $(wildcard include/config/CGROUP_PIDS) \
    $(wildcard include/config/CGROUP_RDMA) \
    $(wildcard include/config/CGROUP_MISC) \
    $(wildcard include/config/CGROUP_DMEM) \
    $(wildcard include/config/CGROUP_DEBUG) \
  /home/ns/linux-6.14.4/include/linux/cgroup_refcnt.h \
  /home/ns/linux-6.14.4/include/linux/page_counter.h \
  /home/ns/linux-6.14.4/include/linux/vmpressure.h \
  /home/ns/linux-6.14.4/include/linux/eventfd.h \
  /home/ns/linux-6.14.4/include/uapi/linux/eventfd.h \
  /home/ns/linux-6.14.4/include/linux/writeback.h \
  /home/ns/linux-6.14.4/include/linux/flex_proportions.h \
  /home/ns/linux-6.14.4/include/linux/backing-dev-defs.h \
    $(wildcard include/config/DEBUG_FS) \
  /home/ns/linux-6.14.4/include/linux/blk_types.h \
    $(wildcard include/config/FAIL_MAKE_REQUEST) \
    $(wildcard include/config/BLK_CGROUP_IOCOST) \
    $(wildcard include/config/BLK_INLINE_ENCRYPTION) \
    $(wildcard include/config/BLK_DEV_INTEGRITY) \
  /home/ns/linux-6.14.4/include/linux/pagevec.h \
  /home/ns/linux-6.14.4/include/linux/bio.h \
    $(wildcard include/config/BLK_DEV_ZONED) \
  /home/ns/linux-6.14.4/include/linux/mempool.h \
  /home/ns/linux-6.14.4/include/linux/cfi.h \
    $(wildcard include/config/CFI_CLANG) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/cfi.h \
  /home/ns/linux-6.14.4/include/linux/bpf_types.h \
    $(wildcard include/config/NETFILTER_BPF_LINK) \
    $(wildcard include/config/XDP_SOCKETS) \
  /home/ns/linux-6.14.4/include/uapi/linux/lsm.h \
  /home/ns/linux-6.14.4/include/linux/lsm/selinux.h \
    $(wildcard include/config/SECURITY_SELINUX) \
  /home/ns/linux-6.14.4/include/linux/lsm/smack.h \
    $(wildcard include/config/SECURITY_SMACK) \
  /home/ns/linux-6.14.4/include/linux/lsm/apparmor.h \
    $(wildcard include/config/SECURITY_APPARMOR) \
  /home/ns/linux-6.14.4/include/linux/lsm/bpf.h \
  /home/ns/linux-6.14.4/include/net/compat.h \
  /home/ns/linux-6.14.4/include/uapi/linux/netlink.h \
  /home/ns/linux-6.14.4/include/uapi/linux/inet_diag.h \
  /home/ns/linux-6.14.4/include/linux/proc_fs.h \
    $(wildcard include/config/PROC_PID_ARCH_STATUS) \
  /home/ns/linux-6.14.4/include/net/tcp.h \
    $(wildcard include/config/BPF) \
    $(wildcard include/config/SYN_COOKIES) \
    $(wildcard include/config/NET_L3_MASTER_DEV) \
    $(wildcard include/config/TCP_MD5SIG) \
    $(wildcard include/config/TCP_AO) \
    $(wildcard include/config/BPF_STREAM_PARSER) \
    $(wildcard include/config/SMC) \
    $(wildcard include/config/TLS_DEVICE) \
  /home/ns/linux-6.14.4/include/linux/tcp.h \
  /home/ns/linux-6.14.4/include/linux/win_minmax.h \
  /home/ns/linux-6.14.4/include/net/sock.h \
    $(wildcard include/config/SOCK_RX_QUEUE_MAPPING) \
    $(wildcard include/config/SOCK_VALIDATE_XMIT) \
    $(wildcard include/config/RPS) \
  /home/ns/linux-6.14.4/include/linux/netdevice.h \
    $(wildcard include/config/DCB) \
    $(wildcard include/config/HYPERV_NET) \
    $(wildcard include/config/WLAN) \
    $(wildcard include/config/AX25) \
    $(wildcard include/config/MAC80211_MESH) \
    $(wildcard include/config/NET_IPIP) \
    $(wildcard include/config/NET_IPGRE) \
    $(wildcard include/config/IPV6_SIT) \
    $(wildcard include/config/IPV6_TUNNEL) \
    $(wildcard include/config/NETPOLL) \
    $(wildcard include/config/BQL) \
    $(wildcard include/config/RFS_ACCEL) \
    $(wildcard include/config/FCOE) \
    $(wildcard include/config/XFRM_OFFLOAD) \
    $(wildcard include/config/NET_POLL_CONTROLLER) \
    $(wildcard include/config/LIBFCOE) \
    $(wildcard include/config/NET_SHAPER) \
    $(wildcard include/config/NETFILTER_EGRESS) \
    $(wildcard include/config/WIRELESS_EXT) \
    $(wildcard include/config/VLAN_8021Q) \
    $(wildcard include/config/NET_DSA) \
    $(wildcard include/config/TIPC) \
    $(wildcard include/config/ATALK) \
    $(wildcard include/config/CFG80211) \
    $(wildcard include/config/IEEE802154) \
    $(wildcard include/config/6LOWPAN) \
    $(wildcard include/config/MPLS_ROUTING) \
    $(wildcard include/config/MCTP) \
    $(wildcard include/config/NETFILTER_INGRESS) \
    $(wildcard include/config/PCPU_DEV_REFCNT) \
    $(wildcard include/config/GARP) \
    $(wildcard include/config/MRP) \
    $(wildcard include/config/NET_DROP_MONITOR) \
    $(wildcard include/config/MACSEC) \
    $(wildcard include/config/DPLL) \
    $(wildcard include/config/DIMLIB) \
    $(wildcard include/config/NET_FLOW_LIMIT) \
    $(wildcard include/config/NET_DEV_REFCNT_TRACKER) \
    $(wildcard include/config/ETHTOOL_NETLINK) \
  /home/ns/linux-6.14.4/include/linux/delay.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/delay.h \
  /home/ns/linux-6.14.4/include/asm-generic/delay.h \
  /home/ns/linux-6.14.4/include/linux/prefetch.h \
  /home/ns/linux-6.14.4/include/linux/dynamic_queue_limits.h \
  /home/ns/linux-6.14.4/include/net/net_namespace.h \
    $(wildcard include/config/NF_FLOW_TABLE) \
    $(wildcard include/config/IEEE802154_6LOWPAN) \
    $(wildcard include/config/NETFILTER) \
    $(wildcard include/config/WEXT_CORE) \
    $(wildcard include/config/MPLS) \
    $(wildcard include/config/CAN) \
    $(wildcard include/config/CRYPTO_USER) \
    $(wildcard include/config/DEBUG_NET_SMALL_RTNL) \
    $(wildcard include/config/NET_NS) \
    $(wildcard include/config/NET_NS_REFCNT_TRACKER) \
  /home/ns/linux-6.14.4/include/net/netns/core.h \
  /home/ns/linux-6.14.4/include/net/netns/mib.h \
    $(wildcard include/config/XFRM_STATISTICS) \
    $(wildcard include/config/TLS) \
  /home/ns/linux-6.14.4/include/net/snmp.h \
  /home/ns/linux-6.14.4/include/uapi/linux/snmp.h \
  /home/ns/linux-6.14.4/include/net/netns/unix.h \
  /home/ns/linux-6.14.4/include/net/netns/packet.h \
  /home/ns/linux-6.14.4/include/net/netns/ipv4.h \
    $(wildcard include/config/IP_ROUTE_MULTIPATH) \
    $(wildcard include/config/IP_MULTIPLE_TABLES) \
    $(wildcard include/config/IP_MROUTE) \
    $(wildcard include/config/IP_MROUTE_MULTIPLE_TABLES) \
  /home/ns/linux-6.14.4/include/net/inet_frag.h \
  /home/ns/linux-6.14.4/include/net/netns/ipv6.h \
    $(wildcard include/config/IPV6_MULTIPLE_TABLES) \
    $(wildcard include/config/IPV6_SUBTREES) \
    $(wildcard include/config/IPV6_MROUTE) \
    $(wildcard include/config/IPV6_MROUTE_MULTIPLE_TABLES) \
    $(wildcard include/config/NF_DEFRAG_IPV6) \
  /home/ns/linux-6.14.4/include/net/dst_ops.h \
  /home/ns/linux-6.14.4/include/uapi/linux/icmpv6.h \
  /home/ns/linux-6.14.4/include/net/netns/nexthop.h \
  /home/ns/linux-6.14.4/include/net/netns/ieee802154_6lowpan.h \
  /home/ns/linux-6.14.4/include/net/netns/sctp.h \
  /home/ns/linux-6.14.4/include/net/netns/netfilter.h \
    $(wildcard include/config/LWTUNNEL) \
    $(wildcard include/config/NETFILTER_FAMILY_ARP) \
    $(wildcard include/config/NETFILTER_FAMILY_BRIDGE) \
    $(wildcard include/config/NF_DEFRAG_IPV4) \
  /home/ns/linux-6.14.4/include/linux/netfilter_defs.h \
  /home/ns/linux-6.14.4/include/uapi/linux/netfilter.h \
  /home/ns/linux-6.14.4/include/linux/in.h \
  /home/ns/linux-6.14.4/include/uapi/linux/in.h \
  /home/ns/linux-6.14.4/include/net/netns/conntrack.h \
    $(wildcard include/config/NF_CT_PROTO_DCCP) \
    $(wildcard include/config/NF_CT_PROTO_SCTP) \
    $(wildcard include/config/NF_CT_PROTO_GRE) \
    $(wildcard include/config/NF_CONNTRACK_EVENTS) \
    $(wildcard include/config/NF_CONNTRACK_LABELS) \
  /home/ns/linux-6.14.4/include/linux/netfilter/nf_conntrack_tcp.h \
  /home/ns/linux-6.14.4/include/uapi/linux/netfilter/nf_conntrack_tcp.h \
  /home/ns/linux-6.14.4/include/linux/netfilter/nf_conntrack_dccp.h \
  /home/ns/linux-6.14.4/include/uapi/linux/netfilter/nf_conntrack_tuple_common.h \
  /home/ns/linux-6.14.4/include/linux/netfilter/nf_conntrack_sctp.h \
  /home/ns/linux-6.14.4/include/uapi/linux/netfilter/nf_conntrack_sctp.h \
  /home/ns/linux-6.14.4/include/net/netns/flow_table.h \
  /home/ns/linux-6.14.4/include/net/netns/nftables.h \
  /home/ns/linux-6.14.4/include/net/netns/xfrm.h \
  /home/ns/linux-6.14.4/include/uapi/linux/xfrm.h \
  /home/ns/linux-6.14.4/include/net/netns/mpls.h \
  /home/ns/linux-6.14.4/include/net/netns/can.h \
  /home/ns/linux-6.14.4/include/net/netns/xdp.h \
  /home/ns/linux-6.14.4/include/net/netns/smc.h \
  /home/ns/linux-6.14.4/include/net/netns/bpf.h \
  /home/ns/linux-6.14.4/include/net/netns/mctp.h \
  /home/ns/linux-6.14.4/include/net/net_trackers.h \
  /home/ns/linux-6.14.4/include/linux/ref_tracker.h \
    $(wildcard include/config/REF_TRACKER) \
  /home/ns/linux-6.14.4/include/linux/stackdepot.h \
    $(wildcard include/config/STACKDEPOT) \
    $(wildcard include/config/STACKDEPOT_MAX_FRAMES) \
    $(wildcard include/config/STACKDEPOT_ALWAYS_INIT) \
  /home/ns/linux-6.14.4/include/linux/seq_file_net.h \
  /home/ns/linux-6.14.4/include/net/dcbnl.h \
  /home/ns/linux-6.14.4/include/uapi/linux/dcbnl.h \
  /home/ns/linux-6.14.4/include/net/netprio_cgroup.h \
  /home/ns/linux-6.14.4/include/uapi/linux/neighbour.h \
  /home/ns/linux-6.14.4/include/uapi/linux/netdevice.h \
  /home/ns/linux-6.14.4/include/linux/if_ether.h \
  /home/ns/linux-6.14.4/include/linux/if_link.h \
  /home/ns/linux-6.14.4/include/uapi/linux/if_link.h \
  /home/ns/linux-6.14.4/include/uapi/linux/if_bonding.h \
  /home/ns/linux-6.14.4/include/uapi/linux/netdev.h \
  /home/ns/linux-6.14.4/include/linux/hashtable.h \
  /home/ns/linux-6.14.4/include/net/neighbour_tables.h \
  /home/ns/linux-6.14.4/include/linux/rculist_nulls.h \
  /home/ns/linux-6.14.4/include/linux/poll.h \
  /home/ns/linux-6.14.4/include/uapi/linux/poll.h \
  /home/ns/linux-6.14.4/arch/x86/include/generated/uapi/asm/poll.h \
  /home/ns/linux-6.14.4/include/uapi/asm-generic/poll.h \
  /home/ns/linux-6.14.4/include/uapi/linux/eventpoll.h \
  /home/ns/linux-6.14.4/include/linux/indirect_call_wrapper.h \
  /home/ns/linux-6.14.4/include/net/dst.h \
  /home/ns/linux-6.14.4/include/linux/rtnetlink.h \
    $(wildcard include/config/NET_INGRESS) \
  /home/ns/linux-6.14.4/include/uapi/linux/rtnetlink.h \
  /home/ns/linux-6.14.4/include/uapi/linux/if_addr.h \
  /home/ns/linux-6.14.4/include/net/neighbour.h \
  /home/ns/linux-6.14.4/include/net/rtnetlink.h \
  /home/ns/linux-6.14.4/include/net/tcp_states.h \
  /home/ns/linux-6.14.4/include/linux/net_tstamp.h \
  /home/ns/linux-6.14.4/include/uapi/linux/net_tstamp.h \
  /home/ns/linux-6.14.4/include/net/l3mdev.h \
  /home/ns/linux-6.14.4/include/net/fib_rules.h \
  /home/ns/linux-6.14.4/include/uapi/linux/fib_rules.h \
  /home/ns/linux-6.14.4/include/net/fib_notifier.h \
  /home/ns/linux-6.14.4/include/net/inet_connection_sock.h \
  /home/ns/linux-6.14.4/include/net/inet_sock.h \
  /home/ns/linux-6.14.4/include/linux/jhash.h \
  /home/ns/linux-6.14.4/include/linux/unaligned/packed_struct.h \
  /home/ns/linux-6.14.4/include/net/inet_dscp.h \
  /home/ns/linux-6.14.4/include/net/request_sock.h \
  /home/ns/linux-6.14.4/include/net/rstreason.h \
  /home/ns/linux-6.14.4/include/uapi/linux/mptcp.h \
  /home/ns/linux-6.14.4/include/uapi/linux/mptcp_pm.h \
  /home/ns/linux-6.14.4/include/net/netns/hash.h \
  /home/ns/linux-6.14.4/include/net/inet_timewait_sock.h \
  /home/ns/linux-6.14.4/include/net/timewait_sock.h \
  /home/ns/linux-6.14.4/include/uapi/linux/tcp.h \
  /home/ns/linux-6.14.4/include/net/inet_hashtables.h \
    $(wildcard include/config/IP_DCCP) \
  /home/ns/linux-6.14.4/include/linux/ip.h \
  /home/ns/linux-6.14.4/include/uapi/linux/ip.h \
  /home/ns/linux-6.14.4/include/linux/ipv6.h \
    $(wildcard include/config/IPV6_ROUTER_PREF) \
    $(wildcard include/config/IPV6_ROUTE_INFO) \
    $(wildcard include/config/IPV6_OPTIMISTIC_DAD) \
    $(wildcard include/config/IPV6_SEG6_HMAC) \
    $(wildcard include/config/IPV6_MIP6) \
  /home/ns/linux-6.14.4/include/uapi/linux/ipv6.h \
  /home/ns/linux-6.14.4/include/linux/udp.h \
  /home/ns/linux-6.14.4/include/uapi/linux/udp.h \
  /home/ns/linux-6.14.4/include/net/ip.h \
  /home/ns/linux-6.14.4/include/net/route.h \
  /home/ns/linux-6.14.4/include/net/inetpeer.h \
  /home/ns/linux-6.14.4/include/net/ipv6.h \
  /home/ns/linux-6.14.4/include/linux/jump_label_ratelimit.h \
  /home/ns/linux-6.14.4/include/net/if_inet6.h \
  /home/ns/linux-6.14.4/include/net/ip_fib.h \
  /home/ns/linux-6.14.4/include/uapi/linux/in_route.h \
  /home/ns/linux-6.14.4/include/net/arp.h \
  /home/ns/linux-6.14.4/include/linux/if_arp.h \
    $(wildcard include/config/FIREWIRE_NET) \
  /home/ns/linux-6.14.4/include/uapi/linux/if_arp.h \
  /home/ns/linux-6.14.4/include/net/ndisc.h \
  /home/ns/linux-6.14.4/include/net/ipv6_stubs.h \
  /home/ns/linux-6.14.4/include/linux/icmpv6.h \
    $(wildcard include/config/NF_NAT) \
  /home/ns/linux-6.14.4/include/uapi/linux/route.h \
  /home/ns/linux-6.14.4/include/net/lwtunnel.h \
  /home/ns/linux-6.14.4/include/uapi/linux/lwtunnel.h \
  /home/ns/linux-6.14.4/include/net/sock_reuseport.h \
  /home/ns/linux-6.14.4/include/linux/filter.h \
    $(wildcard include/config/HAVE_EBPF_JIT) \
  /home/ns/linux-6.14.4/include/linux/sched/clock.h \
    $(wildcard include/config/ARCH_WANTS_NO_INSTR) \
    $(wildcard include/config/GENERIC_SCHED_CLOCK) \
    $(wildcard include/config/HAVE_UNSTABLE_SCHED_CLOCK) \
  /home/ns/linux-6.14.4/include/linux/set_memory.h \
    $(wildcard include/config/ARCH_HAS_SET_MEMORY) \
    $(wildcard include/config/ARCH_HAS_SET_DIRECT_MAP) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/set_memory.h \
  /home/ns/linux-6.14.4/include/asm-generic/set_memory.h \
  /home/ns/linux-6.14.4/include/linux/if_vlan.h \
  /home/ns/linux-6.14.4/include/linux/etherdevice.h \
  /home/ns/linux-6.14.4/include/linux/crc32.h \
    $(wildcard include/config/CRC32_ARCH) \
  /home/ns/linux-6.14.4/include/linux/bitrev.h \
    $(wildcard include/config/HAVE_ARCH_BITREVERSE) \
  /home/ns/linux-6.14.4/include/linux/unaligned.h \
  /home/ns/linux-6.14.4/include/vdso/unaligned.h \
  /home/ns/linux-6.14.4/include/uapi/linux/if_vlan.h \
  /home/ns/linux-6.14.4/include/linux/vmalloc.h \
    $(wildcard include/config/HAVE_ARCH_HUGE_VMALLOC) \
  /home/ns/linux-6.14.4/arch/x86/include/asm/vmalloc.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/pgtable_areas.h \
  /home/ns/linux-6.14.4/include/crypto/sha1.h \
  /home/ns/linux-6.14.4/include/net/sch_generic.h \
  /home/ns/linux-6.14.4/include/net/gen_stats.h \
  /home/ns/linux-6.14.4/include/uapi/linux/gen_stats.h \
  /home/ns/linux-6.14.4/include/net/flow_offload.h \
  /home/ns/linux-6.14.4/include/net/tcp_ao.h \
  /home/ns/linux-6.14.4/include/net/inet_ecn.h \
  /home/ns/linux-6.14.4/include/net/dsfield.h \
  /home/ns/linux-6.14.4/include/net/mptcp.h \
    $(wildcard include/config/MPTCP_IPV6) \
  /home/ns/linux-6.14.4/include/net/xfrm.h \
    $(wildcard include/config/XFRM_SUB_POLICY) \
    $(wildcard include/config/NET_PKTGEN) \
    $(wildcard include/config/XFRM_MIGRATE) \
    $(wildcard include/config/XFRM_USER_COMPAT) \
    $(wildcard include/config/XFRM_INTERFACE) \
  /home/ns/linux-6.14.4/include/uapi/linux/pfkeyv2.h \
  /home/ns/linux-6.14.4/include/uapi/linux/ipsec.h \
  /home/ns/linux-6.14.4/include/linux/audit.h \
    $(wildcard include/config/AUDIT_COMPAT_GENERIC) \
  /home/ns/linux-6.14.4/include/linux/ptrace.h \
  /home/ns/linux-6.14.4/include/linux/pid_namespace.h \
    $(wildcard include/config/MEMFD_CREATE) \
    $(wildcard include/config/PID_NS) \
  /home/ns/linux-6.14.4/include/uapi/linux/ptrace.h \
  /home/ns/linux-6.14.4/include/linux/seccomp.h \
    $(wildcard include/config/HAVE_ARCH_SECCOMP_FILTER) \
    $(wildcard include/config/SECCOMP_FILTER) \
    $(wildcard include/config/CHECKPOINT_RESTORE) \
    $(wildcard include/config/SECCOMP_CACHE_DEBUG) \
  /home/ns/linux-6.14.4/include/uapi/linux/seccomp.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/seccomp.h \
  /home/ns/linux-6.14.4/include/asm-generic/seccomp.h \
  /home/ns/linux-6.14.4/include/linux/audit_arch.h \
  /home/ns/linux-6.14.4/include/uapi/linux/audit.h \
  /home/ns/linux-6.14.4/include/uapi/linux/netfilter/nf_tables.h \
  /home/ns/linux-6.14.4/include/uapi/linux/fanotify.h \
  /home/ns/linux-6.14.4/arch/x86/include/asm/syscall.h \
  /home/ns/linux-6.14.4/include/net/ip6_fib.h \
  /home/ns/linux-6.14.4/include/linux/ipv6_route.h \
  /home/ns/linux-6.14.4/include/uapi/linux/ipv6_route.h \
  /home/ns/linux-6.14.4/include/net/gro_cells.h \
  /home/ns/linux-6.14.4/include/linux/bpf-cgroup.h \
  tcp_vegas.h \

i_tcp_vegas.o: $(deps_i_tcp_vegas.o)

$(deps_i_tcp_vegas.o):

i_tcp_vegas.o: $(wildcard /home/ns/linux-6.14.4/tools/objtool/objtool)
#SYMVER tcp_vegas_init 0x5a31fa1d
#SYMVER tcp_vegas_pkts_acked 0x25a19275
#SYMVER tcp_vegas_state 0x887608b4
#SYMVER tcp_vegas_cwnd_event 0xb1e8090a
#SYMVER tcp_vegas_get_info 0xdfbecf3e
