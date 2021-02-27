#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for(int p = 1; p <= test; p++) {
        int ans = 0;
        long long int n, k;
        scanf("%lld %lld", &n, &k);
        long long int sum = 0;
        int arr[100005];
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            ans++;
            if(sum > k) {
                ans--;
                break;
            }
        }
        printf("Case #%d: %d\n", p, ans);
    }
    return 0;
}