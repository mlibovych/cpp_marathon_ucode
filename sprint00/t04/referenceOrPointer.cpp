#include "referenceOrPointer.h"

using namespace std;

void multiplyByPointer(int* ptr, int mult) {
    *ptr *= mult;
}

void multiplyByReference(int& ref, int mult) {
    ref *= mult;
}
