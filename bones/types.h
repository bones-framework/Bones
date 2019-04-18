#ifndef BONES_TYPES_H
#define BONES_TYPES_H

#define ARCH_CHAR_BITS 8

// TODO Add endianess integration
// Defines the base machine word size (in bytes)
// e.a register size for the architecture
// this also defines the maximum contained data
// and bits
// Note: Assuming that the definitions are GNU C
#ifndef ARCH_XLEN
  #if defined(__alpha__)
    #define ARCH_XLEN 8
    #define ARCH_BITS 64
    #define ARCH_MAX  0xffffffffffffffffu
  #endif
  
  #if defined(__amd64__) || defined(__amd64) || \
	  defined(__x86_64__) || defined(__x86_64)
    #define ARCH_XLEN 8
    #define ARCH_BITS 64
    #define ARCH_MAX  0xffffffffffffffffu
  #endif

  // TODO Add full ARM support, respecting thumb sizes

  #if defined(__aarch64__)
    #define ARCH_XLEN 8
    #define ARCH_BITS 64
    #define ARCH_MAX  0xffffffffffffffffu
  #endif

  #if defined(__bfin) || defined(__BFIN__)
    #warning Detected blackfin! please ensure \
	    appropriate architecture size definitions \
	    assuming 32 bits default configuration
    #define ARCH_XLEN 4
    #define ARCH_BITS 32
    #define ARCH_MAX  0xffffffffu
  #endif
  
  // TODO Add convex architecture

  #if defined(__epiphany__)
    #warning Detected epiphany system! assuming \
	    pre ephiphany-V design (32-bit)
    #define ARCH_XLEN 4
    #define ARCH_BITS 32
    #define ARCH_MAX  0xffffffffu
  #endif

  #if defined(__hppa__)
    // Since the FPU is based on 64 bits
    // its a 64 bit architecture but XLEN should
    // be 4 since the GPRs are 32-bit
    #define ARCH_XLEN 4
    #define ARCH_BITS 64
    #define ARCH_MAX  0xffffffffu
  #endif

  #if defined(i386) || defined(__i386) || \
	  defined(__i386__) || defined(__i486__) || \
	  defined(__i586__) || defined(__i686__)
    #define ARCH_XLEN 4
    #define ARCH_BITS 32
    #define ARCH_MAX  0xffffffffu
  #endif

  #if defined(__ia64__) || defined(_IA64) || \
	  defined(__IA64__)
    #define ARCH_XLEN 8
    #define ARCH_BITS 64
    #define ARCH_MAX  0xffffffffffffffffu
  #endif

  #if defined(__m68k__)
    // 32-bit registers with 16 bit ALU, then
    // bits and XLEN are 32/4 respectively
    // while max is set to 16-bit
    #define ARCH_XLEN 4
    #define ARCH_BITS 32
    #define ARCH_MAX  0xffffu
  #endif

  #if defined(__mips__) || defined(mips)
    #define ARCH_XLEN 4
    #define ARCH_BITS 32
    #define ARCH_MAX  0xffffffffu
  #endif

  #if defined(__powerpc) || defined(__powerpc__) || \
	  defined(__POWERPC__) || defined(__ppc__) \
	  || defined (__PPC__) || defined(_ARCH_PPC)
    #if defined(__powerpc64__) || defined(__PPC64__) \
	    || defined(_ARCH_PPC64)
      // Detected 64-bit definition
      #define ARCH_XLEN 8
      #define ARCH_BITS 64
      #define ARCH_MAX  0xffffffffffffffffu
    #else
      // Assume 32-bit
      #define ARCH_XLEN 4
      #define ARCH_BITS 32
      #define ARCH_MAX  0xffffffffu
    #endif
  #endif

  #if defined(__sparc__)
    #if defined(__sparc_v8__)
      // Detected V8 (32-bit)
      #define ARCH_XLEN 4
      #define ARCH_BITS 32
      #define ARCH_MAX  0xffffffffu
    #elif defined(__sparc_v9__)
      // Detected V9 (64-bit)
      #define ARCH_XLEN 8
      #define ARCH_BITS 64
      #define ARCH_MAX  0xffffffffffffffffu
    #else
      #warning Detected sparc architecture but \
	      couldn't discern bits, defaulting to \
	      32-bit default configuration. Please \
	      re-define ARCH macros as appropriate \
	      to your system.
      #define ARCH_XLEN 4
      #define ARCH_BITS 32
      #define ARCH_MAX  0xffffffffu
    #endif
  #endif

  #if defined(__sh__)
    #warning Assuming 32-bit instructions / data
    //TODO Discern different versions (1-5)
    #define ARCH_XLEN 4
    #define ARCH_BITS 32
    #define ARCH_MAX  0xffffffffu
  #endif

  // TODO Possibly add SystemZ support

#endif // ARCH_XLEN

#endif // BONES_TYPES_H
