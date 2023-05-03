#include <cassert>

int main() {
    char *heapArr = new char[100000];


    assert(sizeof(heapArr) == 8);

    delete[] heapArr;

    return 0;
}
