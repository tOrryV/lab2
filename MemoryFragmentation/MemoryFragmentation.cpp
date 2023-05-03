#include <iostream>
#include <cstdlib>

int main()
{
    const int chunkSize = 1024 * 1024;
    char* mem[100];

    for (int i = 0; i < 100; ++i) {
        mem[i] = new char[chunkSize];
        std::cout << "Allocated chunk " << i << " of " << chunkSize / 1024 << " KB\n";
    }

    for (int i = 0; i < 100; i += 2) {
        delete[] mem[i];
        std::cout << "Deallocated chunk " << i << "\n";
    }

    for (int i = 1; i < 100; i += 2) {
        mem[i] = new char[chunkSize];
        std::cout << "Allocated chunk " << i << " of " << chunkSize / 1024 << " KB\n";
    }

    return 0;
}
