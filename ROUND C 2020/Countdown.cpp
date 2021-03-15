#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test, n, k, a;
    cin>>test;
    for(int p = 1; p <= test; p++) {
        cin>>n>>k;
        int val = k;
        bool temp;
        int coun = 0;
        for(int i = 0; i < n; i++) {
            cin>>a;
            if(val == a) {
                if(val == 1) {
                    coun++;
                    val = k;
                }
                else {
                    val--;
                }
            }
            else {
                val = k;
                if(val == a) {
                    val--;
                }
            }
        }
        cout<<"Case #"<<p<<": "<<coun<<endl;
    }
    return 0;
}
