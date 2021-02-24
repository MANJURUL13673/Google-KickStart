#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    int n, k;
    int a, b;
    for(int p = 1; p <= test; p++) {
        cin>>n>>k;
        vector<int>difficulty;
        int ma = 0;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                cin>>a;
            }
            else {
                cin>>b;
                difficulty.push_back(b - a);
                ma = max(ma, difficulty[i-1]);
                a = b;
            }
        }
        int low = 1;
        int high = ma;
        int minDifficulty = 1000000005;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int totalK = 0;
            for(int i = 0; i < difficulty.size(); i++) {
                totalK = totalK + ceil(difficulty[i] / (mid * 1.0)) - 1;
            }
            if(totalK > k) {
                low = mid+1;
            }
            else if(totalK <= k) {
                high = mid - 1;
                minDifficulty = min(minDifficulty, mid);
            }
        }
        cout<<"Case #"<<p<<": "<<minDifficulty<<endl;
    }
    return 0;
}
