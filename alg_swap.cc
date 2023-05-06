#include <iostream>

// Swap two integers without a 3rd temporary variable.
void Swap(int& x, int& y) {
    if (x == y) return;
    x = x + y;
    y = x - y;
    x = x - y;
}

int main() {
    int x = 5;
    int y = 10;
    Swap(x, y);
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    return 0;
}