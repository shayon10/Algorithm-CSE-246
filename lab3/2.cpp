#include <bits/stdc++.h>
using namespace std;

void Pattern_x_Array (char Text [], char Pattern [], int SIZE, int Pattern_x []);


void K_M_P (char Text [], char Pattern []) {

    int SIZE_Text = strlen (Text);
    int SIZE_Pattern = strlen (Pattern);

    int Pattern_x [SIZE_Pattern];

    Pattern_x_Array (Text, Pattern, SIZE_Pattern, Pattern_x);

    int i = 0, j = 0;

    while (i < SIZE_Text) {

        if (Pattern [j] == Text [i]) {

            j++;
            i++;
        }

        else {

            if (j != 0) {

                j = Pattern_x [j - 1];
            }
            else {

                i++;
            }
        }

        if (j == SIZE_Pattern) {

            cout << i - j << " " << i - 1 << endl;

            j = Pattern_x [j - 1];
        }
    }
}

void Pattern_x_Array (char Text [], char Pattern [], int SIZE_Pattern, int Pattern_x []) {

    int Y = SIZE_Pattern;

    int length = 0;
    Pattern_x [0] = 0;

    for (int i = 1; i < Y; i++) {

        if (Pattern [i] == Pattern [length]) {

            length++;
            Pattern_x [i] = length;
        }
        else {

            Pattern_x [i] = 0;
            length = 0;
        }
    }


}



int main (void) {

    char Text [100000];
    char Pattern [1000];

    cin >> Text;
    cin >> Pattern;

    K_M_P (Text, Pattern);

    return 0;
}
