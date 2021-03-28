#include<bits/stdc++.h>

using namespace std;

#define mx 2 * 100001
long long int arr[mx];
long long int tree1[mx * 3];
long long int tree2[mx * 3];

void init(int node, int b, int e)
{
	if (b == e) {
	    int val;
	    if((b - 1) % 2) val = 1;
	    else val = -1;
		tree1[node] = val * arr[b] * b;
		tree2[node] = val * arr[b];
		return;
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	init(left, b, mid);
	init(right, mid + 1, e);
	tree1[node] = tree1[left] + tree1[right];
	tree2[node] = tree2[left] + tree2[right];
}

long long int query1(int node, int b, int e, int i, int j)
{
	if (i > e || j < b) {
		return 0;
	}
	if (b >= i && e <= j) {
		//cout << tree[node] << " " << pow(-1, b - i) * tree[node] * (b - i + 1) << endl;
// 		int val;
// 	    if((i - 1) % 2) val = 1;
// 	    else val = -1;
		return tree1[node];
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	long long int p1 = query1(left, b, mid, i, j);
	long long int p2 = query1(right, mid + 1, e, i, j);
	return p1 + p2;
}

long long int query2(int node, int b, int e, int i, int j)
{
	if (i > e || j < b) {
		return 0;
	}
	if (b >= i && e <= j) {
		//cout << tree[node] << " " << pow(-1, b - i) * tree[node] * (b - i + 1) << endl;
// 		int val;
// 	    if((i - 1) % 2) val = 1;
// 	    else val = -1;
		return tree2[node];
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	long long int p1 = query2(left, b, mid, i, j);
	long long int p2 = query2(right, mid + 1, e, i, j);
	return p1 + p2;
}

void update(int node, int b, int e, int i, int newvalue)
{
	if (i > e || i < b)
		return;
	if (b >= i && e <= i) {
	    int val;
	    if((i - 1) % 2) val = 1;
	    else val = -1;
		tree1[node] = val * newvalue * i;
		tree2[node] = val * newvalue;
		return;
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	update(left, b, mid, i, newvalue);
	update(right, mid + 1, e, i, newvalue);
	tree1[node] = tree1[left] + tree1[right];
	tree2[node] = tree2[left] + tree2[right];
}

int main()
{
	int test, n, q;
	cin >> test;
	char val;
	int l1, l2;
	for (int p = 1; p <= test; p++) {
		cin >> n >> q;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		init(1, 1, n);
		long long int ans = 0;
		while (q--) {
			cin >> val >> l1 >> l2;
			if (val == 'U') {
				update(1, 1, n, l1, l2);
			}
			else {
			    int mul;
			    if((l1 - 1) % 2) mul = 1;
			    else mul = -1;
				long long int val = mul * (query1(1, 1, n, l1, l2) - ((l1 - 1) * query2(1, 1, n, l1, l2)));
				//cout << val << endl;
				ans += val;
			}
		}
		cout << "Case #" << p << ": " << ans << endl;
	}
	return 0;
}