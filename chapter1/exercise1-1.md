# Options Controlling the Kind of Output

GCC / G++ Version: (Ubuntu 11.2.0-19ubuntu1) 11.2.0
Documentation: [GCC 11.3.0](https://gcc.gnu.org/onlinedocs/gcc-11.3.0/gcc.pdf)

## File name suffixes

**For any given input file, the file name suffix determines what kind of compilation is done:**

C source code that must be preprocessed:
 - file.c

C source code that should not be preprocessed:
 - file.i

C++ source code that should not be preprocessed:
 - file.ii

C / C++ header file to be turned into a precompiled header (default), or C / C++ header file to be turned into an Ada spec (via the "-fdump-ada-spec" switch) 

C++ source code that must be preprocessed *(Note that in ".cxx", the last two letters must both be literally "x". Likewise, ".C" refers to a literal capital C)*:
 - file.cc
 - file.cp
 - file.cxx
 - file.cpp
 - file.CPP
 - file.c++
 - file.C

C++ header file to be turned into a precompiled header or Ada spec:
 - file.hh
 - file.H
 - file.hp
 - file.hxx
 - file.hpp
 - file.HPP
 - file.h++
 - file.tcc

Assembler code:
 - file.s

Assembler code to be preprocessed:
 - file.S
 - file.sx

Object file to be fed straight to linking:
 - *Any file name with no recognized suffix is treated this way*


## Specify the language explicitly

**Option: -x *language***

Specify explicitly the *language* for the following input files (rather than letting the compiler choose a default based on the file name suffix). This option applies to all following files until the next "-x" option.

-x *language*; where *language* can be:
 - c
 - c-header
 - cpp-output
 - c++
 - c++-header
 - c++-system-header
 - c++-user-header
 - c++-cpp-output
 - assembler assembler-with-cpp

-x *none*; turn off any specification of a language, so that the subsequent files are handled according to their file name suffixes.

## Output file

**Option: -o *file***

Place the primary output in file *file*. This applies to whatever sort of output is being produced, whether it be an executable, an object file, an assembler file, or preprocessed C code.

If "-o" is not specified, the default is to put an executable in "a.out", the object file for "source.suffix" in "source.o", its assembler file in "source.s", a precompiled header file in "source.suffix.gch", and all preprocessed C source on standard output.

Though, "-o" names only the primary output, it also affects the naming of auxiliary and dump outputs. Unless overridden, both auxiliary outputs and dump outputs are placed in the same directory as the primary output.