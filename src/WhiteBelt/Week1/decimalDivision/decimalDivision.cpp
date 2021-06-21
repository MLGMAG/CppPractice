#include <iostream>

using namespace std;

void divide(int value, int divider) {
    if (divider == 0) {
        cout << "Impossible";
        return;
    }

    cout << value / divider;
}
