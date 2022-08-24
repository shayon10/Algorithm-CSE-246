#include<bits/stdc++.h>
using namespace std;

int dp [1000];
int minCoins(int coins[], int N, int K)
{
  for(int i = 0;i<=K;i++)
    {
        dp[i] = INT_MAX;

    }

    dp[0] = 0;

  for(int i = 1;i<=K;i++)
  {
    for(int j = 0;j<N;j++)
    {
      if(coins[j] <= i)
      {
        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
      }
      else{
        dp[i] = dp[i];
      }
    }
  }
  return dp[K];
}

int main() {
    int N,K;
    cin>>N>>K;
  int coins[N];
  for(int i=0;i<N;i++)
  {
      cin>>coins[i];
  }
  cout << minCoins(coins, N, K);
}






