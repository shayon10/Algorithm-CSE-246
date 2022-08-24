#include <bits/stdc++.h>
using namespace std;
int mx = 1e9+999;
int store[10000];
void  path_printing(int Dp[],int n,int k) {
  int temp[n+1];
  temp[0] = 0;
  int temp_2[n+1];
  temp_2[0] = 0;
  int i,j;
  for(j=1;j<=n;j++) {
    int mini=mx;
    int coin=0;
    for(i=1;i<=k;i++) {
      if(j>= Dp[i]) {
        if((1+temp[j-Dp[i]]) < mini) {
          mini = 1+temp[j-Dp[i]];
          coin = i;
        }
      }
    }
    temp[j]=mini;
    temp_2[j]=coin;
  }   int l = n;   while(l>0) {
    store[Dp[temp_2[l]]]++;
    l=l-Dp[temp_2[l]];   }
    for(int i=0;i<10000;i++)
        {     if(store[i]>0){         cout<<i<< " " <<store[i]<<endl;    }
         }
    }
  int main() {
    int n,k;
    cin>>n>>k;
    int coins[n+1];
    coins[0]=0;
    for(int i=1;i<=n;i++)
        {     cin>>coins[i];   }
    path_printing(coins,k,n);
    return 0;}
