#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test , n;
    long long int day, arr[1005];
    cin>>test;
    for(int p = 1; p <= test; p++) {
        cin>>n>>day;
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        long long int ansDay = day;
        for(int i = n-1; i >= 0; i--) {
            ansDay = (long long int)(ansDay / arr[i]) * arr[i];
            //cout<<ansDay<<endl;
        }
        cout<<"Case #"<<p<<": "<<ansDay<<endl;
    }
    return 0;
}
