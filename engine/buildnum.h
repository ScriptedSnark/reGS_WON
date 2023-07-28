#ifdef REGS_HOOKED
typedef int (*_build_number)();
extern _build_number ORIG_build_number;
#endif

int build_number();