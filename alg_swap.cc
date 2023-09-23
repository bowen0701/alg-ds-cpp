#include <iostream>

// Swap two integers without a 3rd temporary variable.
void Swap(int& x, int& y) {
    if (x == y) return;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

int main() {
    int x = 5;
    int y = 10;
    Swap(x, y);
    assert(x == 10 && y == 5);

    return 0;
}