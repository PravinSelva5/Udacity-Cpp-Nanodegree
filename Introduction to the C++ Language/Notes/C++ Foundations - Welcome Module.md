# C++ Foundations - Welcome Module

Created: January 6, 2023 6:25 PM

- C++ 20 is a minor release but has ‘concepts’ which are important for general programming with templates
- C++ Core Guidelines
    - [https://github.com/isocpp/CppCoreGuidelines](https://github.com/isocpp/CppCoreGuidelines)

- ****************************************************************Use libraries wherever possible.****************************************************************
    - No need to re-invent the wheel.
- ********************************************************************************************Prefer the standard library to other libraries********************************************************************************************
- C++ is a compiled progamming language. Therefore, a program (compiler) is used to convert human-readable code into machine readable **********************object********************** and ********************executable******************** files.
- The compiler must have access to a compiled version of the standard library, stored in object files. The compiler ********************must link******************** the standard library object files to the object files created by the programmer’s source code.

### Build Tools

- **Make** and **CMake** are two separate and similar build tools.
- ********Make********
    - this build tool relies on automate the process of buidling a project
    - **build** is a common target name that is configured in the makefile to compile all the **project’s source code into .exe**
    - **clean**, on the other hand, deletes all object files and other artifacts of the build process, **resulting in a clean, unbuilt project state.**
    - `make build`
    - `make clean`
- **********CMake**********
    - supports ******************************************cross-platform builds,****************************************** allows you to build the same source code on Linux, macOS, Windows, etc.
    - You need to make a CMakeLists.txt
- **************Style Guides**************
    - [http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl-naming-and-layout-rules](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl-naming-and-layout-rules)
    - [https://google.github.io/styleguide/cppguide.html](https://google.github.io/styleguide/cppguide.html)
- ****************Debugger****************
    - ************************GDB and LLDB************************ are two popular, open-source debuggers for C++.