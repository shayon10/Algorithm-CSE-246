#include <iostream>
using namespace std;

int partition(int A[], int lo, int hi) {
    int pivot = A[(lo+hi)/2];

    while(lo<=hi) {
        while(A[lo]<pivot) {
            lo++;
        }
        while(A[hi]>pivot) {
            hi--;
        }
        if(lo<=hi) {
            int temp = A[lo];
            A[lo] = A[hi];
            A[hi] = temp;
            lo++;
            hi--;
        }
    }
    return lo;
}

void quick_sort(int A[], int lo, int hi) {
    int pi = partition(A, lo, hi);

    if(lo<pi-1) {
        quick_sort(A, lo, pi-1);
    }
    if(pi<hi) {
        quick_sort(A, pi, hi);
    }
}


void display_array(int A[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void min_diff(int A[], int size) {
    int i,j=0,temp;
    int x[size-1];
    for(i=0; i<size; i++) {
        j++;
        temp=A[i]-A[j];
        x[i]=-temp;
    }
    int n = sizeof(x)/sizeof(x[0]);
    quick_sort(x, 0, n-1);
    cout << x[0];
}

int main() {
    int item;
    cin >> item;
    int A[item];

    for(int i = 0; i<item; i++) {
        cin >> A[i];
    }
    int n = sizeof(A)/sizeof(A[0]);
    quick_sort(A, 0, n-1);
    cout << endl;
    cout << endl;
    min_diff(A, n);

    return 0;
}
