#include "Debug.h"

void debugPrint(const std::string& text) {
    if ( DEBUG ) {
        std::cout << "\033[33m" << text << "\033[30m" << std::endl;
    }
}

void debugPrint(const std::string& text1, const std::string& text2) {
    if ( DEBUG ) {
        std::cout << "\033[33m" << text2 << ": " << text1 << "\033[30m" << std::endl;
    }
}
