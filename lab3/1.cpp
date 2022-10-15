#include <bits/stdc++.h>
using namespace std;

int main() {

    int Text, elemeent, count_elemeent = 0;

    cin >> Text;

    for (int x = 0; x < Text; x++) {

        cin >> elemeent;

        for (int y = 2; y <= (elemeent / 2); y++) {

            if (elemeent % y == 0) {

                count_elemeent = 1;
            }
        }

        if (count_elemeent == 0) {

            cout << "PRIME" << endl;
        }
        else {

            cout << "NOT PRIME" << endl;
        }

        count_elemeent = 0;
    }

    return 0;
}

