// PDP11 Assembler (c) 15-01-2015 vinxru

// Feb-2018 removed WIN32 code and translated to English by SHAOS

#include "compiler.h"
#include <iostream>

int main(int argc, char** argv)
{

    printf("PDP11/8080 Assembler/C\nALPHA VERSION MODIFIED BY SHAOS\n2017 (c) aleksey.f.morozov@gmail.com\n");
    try {
        Compiler c;

        // expects one argument
        if(argc != 2) {
            std::cout << "Specify one file name on the command line" << std::endl;
            return 0;
        }

        // compilation
        c.compileFile(argv[1]);

        // exit without errors
        std::cout << "Done" << std::endl;
        return 0;

    } catch(std::exception& e) {
        // exit with errors
        std::cout << e.what() << std::endl;
        return 1;
    }
}
