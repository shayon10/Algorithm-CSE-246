#include <bits/stdc++.h>
using namespace std;

struct product {
    int product_gain, weight;
};
struct S_tmp {
    int tm_x, tm_w;
};

int partition(product arr_product[], int Percentage[], int low, int high) {
    S_tmp t;
    int tmp;
    int pivot = Percentage[(low+high)/2];

    while(low<=high) {
        while(Percentage[low]>pivot) {
            low++;
        }
        while(Percentage[high]<pivot) {
            high--;
        }
        if(low<=high) {
            tmp = Percentage[low];
            t.tm_x = arr_product[low].product_gain;
            t.tm_w = arr_product[low].weight;
            Percentage[low] = Percentage[high];
            arr_product[low].product_gain = arr_product[high].product_gain;
            arr_product[low].weight = arr_product[high].weight;
            Percentage[high] = tmp;
            arr_product[high].product_gain = t.tm_x;
            arr_product[high].weight = t.tm_w;
            low++;
            high--;
        }
    }
    return low;
}

void quick_Sort(product arr_product[], int Percentage[], int low, int high) {
    int pi = partition(arr_product, Percentage, low, high);

    if(low<pi-1) {
        quick_Sort(arr_product, Percentage, low, pi-1);
    }
    if(pi<high) {
        quick_Sort(arr_product, Percentage, pi, high);
    }
}

int main() {
    int N,i,j;
    double W,tmp_Weight=0,tmp_product_gain=0;

    while(1) {
        cin >> N;
        cin >> W;
        int Percentage[N];
        product arr_product[N];

        for(i=0; i<N; i++) {
            j=i;
            cin >> Percentage[i];
        }

        for(i=0; i<N; i++) {
            cin >> arr_product[i].weight;
            arr_product[i].product_gain = Percentage[i]*arr_product[i].weight;
        }

        quick_Sort(arr_product, Percentage, 0, N-1);

        for(i=0; i<N-1; i++) {
            if(W>arr_product[i].weight) {
                tmp_Weight = tmp_Weight+arr_product[i].weight;
                W = W-arr_product[i].weight;
                tmp_product_gain = tmp_product_gain+arr_product[i].product_gain;
            }
            else {
                tmp_Weight = tmp_Weight+W;
                tmp_product_gain = tmp_product_gain+Percentage[i]*W;
                i=N;
            }
        }
        cout << endl;
        cout << tmp_product_gain;
        cout << endl;
        cout << endl;
        cout << endl;
        tmp_Weight=0;
        tmp_product_gain=0;
    }


    return 0;
}
