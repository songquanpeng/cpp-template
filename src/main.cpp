#include <unistd.h>
#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

void print_version() {
    cout << "Cpp Template v0.0.0" << endl;
    cout << "Copyright (c) 2023 JustSong." << endl;
    cout << "Compiled on " << __DATE__ << " at " << __TIME__ << "." << endl;
}

void print_usage() {
    cerr << "Usage: " << endl;
    cerr << "  -d: debug mode" << endl;
    cerr << "  -i: input file" << endl;
    cerr << "  -o: output file" << endl;
}

int main(int argc, char *argv[]) {
    string input, output;
    int opt;
    while ((opt = getopt(argc, argv, "vdi:o:")) != -1) {
        switch (opt) {
            case 'v':
                print_version();
                exit(0);
                break;
            case 'd':
                enable_debug_mode();
                break;
            case 'i':
                input = optarg;
                std::cout << "Option i is set with value " << input << std::endl;
                break;
            case 'o':
                output = optarg;
                std::cout << "Option o is set with value " << output << std::endl;
                break;
            case '?':
                std::cout << "unknown option: " << optopt << std::endl;
                print_usage();
                exit(1);
                break;
            default:
                std::cout << "Unexpected option" << std::endl;
        }
    }
    if (input.empty()) {
        std::cerr << argv[0] << ": missing -i option" << std::endl;
        print_usage();
        exit(1);
    }
    print_info("Hello world!", "main");
    return 0;
}
