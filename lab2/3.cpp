#include <bits/stdc++.h>
using namespace std;

struct Time_activit {
    int first, last;
};

struct Tmp {
    int tmps,tmpx;
};
int partition(Time_activit at[], int lo, int hi) {
    Tmp t;
    int pivot = at[(lo+hi)/2].last;
    while(lo<=hi) {
        while(at[lo].last<pivot) {
            lo++;
        }
        while(at[hi].last>pivot) {
            hi--;
        }
        if(lo<=hi) {
            t.tmpx = at[lo].last;
            t.tmps = at[lo].first;
            at[lo].last = at[hi].last;
            at[lo].first = at[hi].first;
            at[hi].last = t.tmpx;
            at[hi].first = t.tmps;
            lo++;
            hi--;
        }
    }
    return lo;
}

void quick_Sort(Time_activit at[], int lo, int hi) {
    int pi = partition(at, lo, hi);
    if(lo<pi-1) {
        quick_Sort(at, lo, pi-1);
    }
    if(pi<hi) {
        quick_Sort(at, pi, hi);
    }
}

void maxActivities(Time_activit at[], int N) {
    int i,j,cunt;
    i=0;
    cunt=1;
    for (j=1; j<N; j++) {
        if (at[j].first>at[i].last) {
            cunt++;
            i=j;
        }
    }
    cout << endl;
    cout << cunt;
    cout << endl;
    cout << endl;

}

int main() {
    int N,i,j;
    while(1) {
        cin >> N;
        Time_activit at[N];
        for(i=0; i<N; i++) {
            j=i;
            cin >> at[i].first;
            cin >> at[j].last;
        }
        quick_Sort(at, 0, N-1);
        maxActivities(at, N);
    }
}
