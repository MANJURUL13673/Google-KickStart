#include <bits/stdc++.h>
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
        long long int lowDay = 1;
        long long int highDay = day;
        long long int midDay;
        bool flag;
        long long int ans;
        long long int selfDay;
        long long int prevBusDay;
        while(lowDay <= highDay) {
            midDay = lowDay + (highDay - lowDay) / 2;
            flag = true;
            prevBusDay = midDay;
            for(int i = 0; i < n; i++) {
                selfDay = ceil(prevBusDay / (arr[i]*1.0)) * arr[i];
                //cout<<arr[i]<<" "<<selfDay<<endl;
                if(!(selfDay >= prevBusDay && selfDay <= day)) {
                    flag = false;
                    break;
                }
                prevBusDay = selfDay;
            }
            //cout<<midDay<<" "<<flag<<endl;
            if(flag == true) {
                lowDay = midDay + 1;
                ans = midDay;
            }
            else {
                highDay = midDay - 1;
            }
        }
        cout<<"Case #"<<p<<": "<<ans<<endl;
    }
    return 0;
}
