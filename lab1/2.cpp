#include<iostream>

using namespace std;

struct stu{
    int roll;
    float higt;
};
int binarySearch(struct stu a[], int n, float key){
    int lo, mid, hi;
    lo = 0;
    hi = n-1;

    while(lo<=hi){
        mid = (lo+hi)/2;
        if(a[mid].higt == key){
            return mid+1;
        }
        else if(a[mid].higt<key){
            lo = mid+1;
        }
        else if(a[mid].higt>key){
            hi = mid-1;
        }
    }
    return -1;
}


int partition(struct stu A[], int lo, int hi){
    float pivot = A[lo].higt;
    struct stu temp;
    int i = lo+1;
    int j = hi;

    do{
        while(A[i].higt<=pivot){
            i++;
        }
        while(A[j].higt>pivot){
            j--;
        }

        if(i<j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i<j);

    temp = A[lo];
    A[lo] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(struct stu A[], int lo, int hi){
    int partition_index;

    if(lo<hi){
        partition_index = partition(A, lo, hi);
        quickSort(A, lo, partition_index-1);
        quickSort(A, partition_index+1, hi);
    }
}


int main(){
    int N,K;
    stu stu[100000];
    cin>>N;

    for(int i=0;i<N;i++){
        stu[i].roll = i+1;
        cin>>stu[i].higt;
    }

    cin>>K;

    float temp = stu[K-1].higt;

    quickSort(stu,0,N-1);

    int result = binarySearch(stu,N,temp);

    cout<<result<<endl;
    return 0;
}
