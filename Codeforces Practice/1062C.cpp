#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 1e5 + 10;
int powasd[mxN], arr[mxN];
int  n, q;

void solve(){
	cin >> n >> q;
	powasd[0] = 1;
	for(int i = 1; i <= n; i++) powasd[i] = (powasd[i - 1] * 2) % MOD;
	string s;
	cin >> s;
	arr[0] = 0;	
	for(int i = 1; i <= n; i++) arr[i] = (s[i - 1] == '1'), arr[i] += arr[i - 1];
	while(q--){
		int l, r;
		cin >> l >> r;
		int x = arr[r] - arr[l - 1];
		int y = r - l + 1- x;
		cout << ((( powasd[x] -1 + MOD) % MOD ) * 1LL * powasd[y] % MOD) << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	int t = 1;

	while( t-- ){
		solve();
	}

	return 0;
}