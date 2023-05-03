#include <cassert>

struct CustomStruct {
    int value;

    CustomStruct(int value) : value(value) {}
};

void Increment(int v) {
    v++;
}

void Increment(CustomStruct& s) {
    s.value++;
}

int main() {
    int value = 10;
    Increment(value);
    assert(value == 10);

    CustomStruct customStruct(10);
    Increment(customStruct);
    assert(customStruct.value == 10);

    return 0;
}