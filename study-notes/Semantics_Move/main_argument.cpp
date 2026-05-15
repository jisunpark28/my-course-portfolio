#include <iostream>
#include <utility>
#include <string>
#include "IntArray.h"
using namespace std;
using namespace seneca;

void prnArray(string name, IntArray a) {
    cout << name << "  => [";
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i != a.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}


int main(size_t argc, char* argv[]) {
    IntArray A{ argc - 1 };
    for (size_t i = 1; i < argc; A[i - 1] = stoi(argv[i]), i++);
    prnArray("A", A);
    return 0;
}

// As practice, write a function that recives series of integers from the console and 
// returns it as an IntArray to the caller function