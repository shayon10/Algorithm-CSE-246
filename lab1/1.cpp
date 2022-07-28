#include <iostream>
using namespace std;

int binary_search_for_up(int A[], int S, int lo, int hi) {
    int mid = (lo+hi)/2;
    int num=hi;
    int i, temp=1;

    while(lo<=hi) {
        if(A[mid]==S) {
            for(i=0; i<num-mid; i++) {
                if(A[mid+i]==A[mid+i+1]) {
                    temp=i+1;
                }
            }
            return mid+temp;
            break;
        }
        else if(A[mid]<S) {
            lo = mid+1;
        }
        else if(A[mid]>S) {
            hi = mid-1;
        }
        mid = (lo+hi)/2;
    }
    if(lo>hi) {
        int j, temp;
        for(j=0; j<num; j++) {
            if(A[lo]==A[lo+j]) {
                temp=j;
            }
        }
        return lo+temp;
    }

}

int binary_search_for_lo(int A[], int S, int lo, int hi) {
    int mid = (lo+hi)/2;
    int i, temp;

    while(lo<=hi) {
        if(A[mid]==S) {
            for(i=0; i<mid; i++) {
                if(A[mid]==A[mid-i]) {
                    temp=i;
                }
            }
            return mid-temp;
            break;
        }
        else if(A[mid]<S) {
            lo = mid+1;
        }
        else if(A[mid]>S) {
            hi = mid-1;
        }
        mid = (lo+hi)/2;
    }
    if(lo>hi) {
        int j, temp;
        for(j=1; j<lo; j++) {
            if(A[lo-1]==A[lo-j]) {
                temp=j;
            }
        }
        return lo-temp;
    }
}



void upperBound(int A[], int S, int N) {
    int x = binary_search_for_up(A, S, 0, N-1);
    cout << x << " ";
}

void lowerBound(int A[], int S, int N) {
    int y = binary_search_for_lo(A, S, 0, N-1);
    cout << y << " ";
}


int main() {
    int N,S;
    cin >> N;
    cin >> S;
    cout << endl;
    int A[N];

    for(int i = 0; i<N; i++) {
        cin >> A[i];
    }
    cout << endl;
    upperBound(A, S, N);
    lowerBound(A, S, N);

}



