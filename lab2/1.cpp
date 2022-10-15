#include <iostream>
#include <algorithm>
using namespace std;

int n_coins (int arr_coins [], int N, int k) {

    int coins = 0;

    for (int i = N - 1; i >= 0; i--) {


        while (k >= arr_coins [i]) {


            k = k - arr_coins [i];
            coins++;
        }
    }

    return coins;
}

int main (void) {


    int N, k;
    cin >> N >> k;


    int arr_coins [100000];


    for (int i = 0; i < N; i++) {

        cin >> arr_coins [i];
    }


    cout << n_coins (arr_coins, N, k);

    return 0;
}
