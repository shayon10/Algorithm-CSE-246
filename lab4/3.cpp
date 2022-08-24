#include<bits/stdc++.h>
using namespace std;

int two_D_dp_array[1001][2001] ;

int high(int x, int y){
    if(x>y) return x ;
    return y ;
}
int knapsack(int wEight[], int value[] , int cap, int n)
{
    if(n == 0 || cap == 0) return 0 ;

    if(two_D_dp_array[n][cap] != -1) return two_D_dp_array[n][cap] ;

    if(wEight[n] <= cap){
        return two_D_dp_array[n][cap] = high(value[n]+knapsack(wEight, value, cap-wEight[n], n-1) , knapsack(wEight, value, cap, n-1)) ;
    }
    else if(wEight[n] > cap){
        return two_D_dp_array[n][cap] = knapsack(wEight, value, cap, n-1) ;
    }
}
int main()
{
    int wEight[100], value[100], cap , i , n ;
    memset(two_D_dp_array, -1, sizeof(two_D_dp_array)) ;

    cin>>n ;
    cin>>cap ;
    for(i = 1 ; i <= n ; i++){
        cin>>value[i] ;
    }
    for(i = 1 ; i <= n ; i++){
        cin>>wEight[i] ;
    }

    int profit = knapsack(wEight, value, cap, n) ;
    cout<< profit ;
}
