#include <iostream>
#include <utility>
#include <string>
#include "IntArray.h"
using namespace std;
using namespace seneca;
void prnArray(IntArray a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i != a.size() - 1) cout << ", ";
    }
    cout << endl;
}
// As practice, write a function that recives series of integers from the console and 
// returns it as an IntArray to the caller function

int main() {
    IntArray I{ 5 }, J{ 20 };
    prnArray(I); // prnArray(IntArray a = I)
    for (int i = 1; i < 10; i++) {
        I[i - 1] = i * 10;
    }
    prnArray(I);
    J = I;
    prnArray(J);
    return 0;
}

//assignment at the moment of creation is construcion