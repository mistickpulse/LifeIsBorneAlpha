//
// Created by zouz on 13/11/17.
//

#include <cstdlib>
#include <iostream>
#include "core.hpp"

int main() {

    try {
        Core core;
        core.run();
    } catch (std::exception &err) {
       std::cerr << err.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "Oh shit" << std::endl;
        return EXIT_FAILURE;
    }
   return EXIT_SUCCESS;
}