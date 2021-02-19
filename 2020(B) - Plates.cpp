#include <bits/stdc++.h>
using namespace std;
int N, K;
int arr[51][31];
int dp[51][1505];

int solve(int i, int pick)
{
    if(pick < 0 || i >= N) {
        return 0;
    }

    if(dp[i][pick] != -1) {
        return dp[i][pick];
    }

    int beautyValue = solve(i+1, pick);

    int sum = 0;

    for(int j = 0; j < min(K, pick); j++)
    {
        sum += arr[i][j];
        beautyValue = max(beautyValue, (sum + solve(i+1, pick - (j + 1))));
    }

    return dp[i][pick] = beautyValue;
}

int main()
{
    int test;
    cin>>test;
    for(int p = 1; p <= test; p++)
    {
        int P;
        cin>>N>>K>>P;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < K; j++)
            {
                cin>>arr[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout<<"Case #"<<p<<": "<<solve(0, P)<<endl;
    }
    return 0;
}
