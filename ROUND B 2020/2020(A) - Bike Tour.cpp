#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int p = 1; p <= test; p++) {
        int n;
        int arr[101];
        cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        int totalPeak = 0;
        for(int i = 1; i < (n - 1); i++) {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                totalPeak++;
            }
        }
        cout<<"Case #"<<p<<": "<<totalPeak<<endl;
    }
    return 0;
}
