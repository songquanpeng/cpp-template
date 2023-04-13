#include <unistd.h>
#include <iostream>
#include <string>
#include <getopt.h>
#include "utils.h"

using namespace std;

static const struct option long_options[] = {
        {"help",    no_argument,       nullptr, 'h'},
        {"version", no_argument,       nullptr, 'v'},
        {"input",   required_argument, nullptr, 'i'},
        {"output",  optional_argument, nullptr, 'o'},
        {"debug",   no_argument,       nullptr, 'd'},
        {nullptr,   no_argument,       nullptr, 0}
};

void print_version() {
    cout << "Cpp Template v0.0.0" << endl;
    cout << "Copyright (c) 2023 JustSong." << endl;
    cout << "Compiled on " << __DATE__ << " at " << __TIME__ << "." << endl;
}

void print_help() {
    cout << "Usage: cpp-template [options]" << endl;
    cout << "Options:" << endl;
    cout << "  -h, --help     display this help and exit" << endl;
    cout << "  -v, --version  output version information and exit" << endl;
    cout << "  -d, --debug    enable debug mode" << endl;
    cout << "  -i, --input    input file" << endl;
    cout << "  -o, --output   output file" << endl;
}

int main(int argc, char *argv[]) {
    string input, output;
    int opt, opt_idx;
    while ((opt = getopt_long(argc, argv, "vdi:o:", long_options, &opt_idx)) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                exit(EXIT_SUCCESS);
                break;
            case 'v':
                print_version();
                exit(EXIT_SUCCESS);
                break;
            case 'd':
                enable_debug_mode();
                break;
            case 'i':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
            default:
                print_help();
                exit(EXIT_FAILURE);
        }
    }
    if (input.empty()) {
        std::cerr << argv[0] << ": missing -i option" << std::endl;
        print_help();
        exit(EXIT_FAILURE);
    }
    if (output.empty()) {
        output = input + "_processed";
    }
    string info = "Your input file is " + input + ", and your output file is " + output + ".";
    print_info(info, __FUNCTION__);
    return 0;
}
