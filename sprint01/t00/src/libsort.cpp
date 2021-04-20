#include "libsort.h"

void mysort(std::array<std::string, 5>& arr) {
    int first = 1;

    std::sort(arr.begin(), arr.end());
    for (const auto& it : arr) {
        if (!first) {
            std::cout << " ";
        }
        else {
            first = 0;
        }
        std::cout << it;
    }
    std::cout << std::endl;
}