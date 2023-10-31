#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateR(int* a, const int size, const double Low, const double High, int i = 0) {
    if (i == size) {
        return;
    }
    double random = ((double)rand() / RAND_MAX) * (High - Low) + Low;
    a[i] = random;
    CreateR(a, size, Low, High, i + 1);
}

template<typename T>
void CreateUR(T* a, const int size, const T Low, const T High, int i = 0) {
    if (i == size) {
        return;
    }
    T random = ((T)rand() / RAND_MAX) * (High - Low) + Low;
    a[i] = random;
    CreateUR(a, size, Low, High, i + 1);
}

void PrintR(int* a, const int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << a[i] << setw(10);
    PrintR(a, size, i + 1);
}

template<typename T>
void PrintUR(T* a, const int size, int i = 0) {
    cout << fixed << setprecision(2);
    if (i == size) {
        cout << endl;
        return;
    }
    cout << a[i] << setw(10);
    PrintUR(a, size, i + 1);
}

int findMinR(int* a, int size, int i = 1, int min = INT_MAX) {
    if (i == size) {
        return min;
    }
    if (a[i] < min) {
        min = a[i];
    }
    return findMinR(a, size, i + 1, min);
}

template <typename T>
T findMinUR(T* a, int size, int i = 1, T min = std::numeric_limits<T>::max()) {
    if (i == size) {
        return min;
    }
    if (a[i] < min) {
        min = a[i];
    }
    return findMinUR(a, size, i + 1, min);
}

int main() {
    srand((unsigned)time(NULL));
    const int n = 10;
    int a[n];
    double aU[n];
    double Low = -10.0;
    double High = 10.0;

    CreateR(a, n, Low, High);
    CreateUR(aU, n, Low, High);

    PrintR(a, n);
    PrintUR(aU, n);

    cout << "Minimal: " << findMinR(a, n) << endl;
    cout << "MinimalU: " << findMinUR(aU, n) << endl;

    return 0;
}
