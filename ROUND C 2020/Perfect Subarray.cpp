#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test, n, a;
    cin>>test;
    for(int p = 1; p <= test; p++) {
        cin>>n;
        int sum = 0;
        unordered_map<int, int>cumSum;
        int mi = 0;
        long long int ans = 0;
        cumSum[0] = 1;
        for(int i = 0; i < n; i++) {
            cin>>a;
            sum += a;
            mi = min(sum, mi);
            for(int j = 0; sum - (j*j) >= mi; j++) {
                if(cumSum.count(sum - (j*j)) == 1) {
                    ans += cumSum[sum - (j*j)];
                }
            }
            cumSum[sum]++;
        }
        cout<<"Case #"<<p<<": "<<ans<<endl;
    }
    return 0;
}

