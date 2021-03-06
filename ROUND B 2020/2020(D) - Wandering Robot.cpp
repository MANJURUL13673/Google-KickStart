#include<bits/stdc++.h>
using namespace std;

double cumLog[2*100005];

void calcLog()
{
    cumLog[0] = 0;
    for(int i = 1; i <= 2*100000; i++) {
        cumLog[i] = cumLog[i-1] + log(i);
    }
}

double calcProb(int x, int y)
{
    return exp(cumLog[x]-cumLog[y]-cumLog[x-y]-x*log(2));
}
int main()
{
    calcLog();
    int test, w, h, l, u, r, d;
    cin>>test;
    for(int p = 1; p <= test; p++) {
        cin>>w>>h>>l>>u>>r>>d;
        double ans = 0.0;
        if(d < h) {
            for(int i = 1; i < l; i++) {
                ans += calcProb(i+d-2,i-1)/2.0;
            }
        }
        if(r < w) {
            for(int j = 1; j < u; j++) {
                ans += calcProb(r+j-2,j-1)/2.0;
            }
        }
        cout<<setprecision(7)<<fixed<<"Case #"<<p<<": "<<ans<<endl;
    }
    return 0;
}
