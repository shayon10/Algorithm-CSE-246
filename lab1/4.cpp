#include <iostream>
#include <algorithm>
using namespace std;

int partition (int element [], int lo, int hi) {

    int i = lo;
    int j = hi;
    int pivot = element [lo];

    while (i < j) {

        while (pivot >= element [i]) {
            i = i + 1;
        }
        while (pivot < element[j]) {
            j = j - 1;
        }
        if (i < j) {
            swap (element[i], element[j]);
        }
    }
    swap (element[lo], element[j]);

    return j;
}

void quicksort (int element [], int lo, int hi) {

    if (lo < hi) {

        int pivot = partition (element, lo, hi);

        quicksort (element, lo, pivot - 1);
        quicksort (element, pivot + 1, hi);
    }
}

int main (void) {

    int N;
    cin >> N;

    int element [100000];
    for (int i = 0; i < N; i++) {
        cin >> element [i];
    }
    quicksort (element, 0, N - 1);
    int count = 0;
    int temp = 0;
    int stored_value;
    for (int i = 1; i <= N; i++) {
        if (element [i - 1] == element [i]) {
            count++;
            if (count >= temp) {
                stored_value = element [i];
            }
        }
        else {
            if (count > temp) {
                temp = count;
           }
            count = 0;
        }
    }
    cout << stored_value;
    return 0;
}
