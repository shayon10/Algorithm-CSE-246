#include <bits/stdc++.h>
using namespace std;

void pattern_Array (char pattern [], int SIZE, int pattern_x []);
void pattern_Array_print (int pattern_x [], int Y);

void K_M_P (char pattern []) {

    int SIZE = strlen (pattern);
    int pattern_x [SIZE];

    pattern_Array (pattern, SIZE, pattern_x);
}

void pattern_Array (char pattern [], int SIZE, int pattern_x []) {

    int Y = SIZE;

    int length = 0;
    pattern_x [0] = 0;

    for (int i = 1; i < Y; i++) {

        if (pattern [i] == pattern [length]) {

            length++;
            pattern_x [i] = length;
        }
        else {

            pattern_x [i] = 0;
            length = 0;
        }
    }

    pattern_Array_print (pattern_x, Y);
}

void pattern_Array_print (int pattern_x [], int Y) {

    for (int i = 0; i < Y; i++) {

        cout << pattern_x [i] << " ";
    }
}

int main (void) {

    char pattern [100000];
    cin >> pattern;

    K_M_P (pattern);

    return 0;
}
