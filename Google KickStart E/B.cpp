#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define endl "\n"
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll power(ll n,ll m){
	if(m==0) return 1;
	ll val=power(n,m/2);
	if(m%2==0) return (val*val); else return ((val*val)*n);
}

ll powermod(ll n,ll m,ll MOD){
	if(m==0) return 1;
	ll val=powermod(n,m/2,MOD);
	val %= MOD;
	if(m%2==0) return (val*val) % MOD; else return (((val*val) % MOD) * n) % MOD;
}

void solve(){
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	if( c + ( a - c ) + ( b - c ) > n || n > 1 && a == c && b == c && c == 1){
		cout << "IMPOSSIBLE" << endl;
		return ;
	}
	for(int i = 0; i < a - c; i++){
		cout << n - 1 << " ";
	}
	if(c == 1 && a > c){
		for(int i = 0; i < n - (c + (a - c) + (b - c)); i++){
			cout << n - 2 << " ";
		}
	}
	cout << n << " ";
	if(c > 1){
		for(int i = 0; i < n - (c + (a - c) + (b - c)); i++){
			cout << n - 2 << " ";
		}
	}
	for(int i = 0; i < c - 1; i++){
		cout << n << " ";
	}
	if(c == 1 and a == c){
		for(int i = 0; i < n - (c + (a - c) + (b - c)); i++){
			cout << n - 2 << " ";
		}
	}
	for(int i = 0; i < b - c; i++){
		cout << n - 1 << " ";
	}
	cout << endl;
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
	cin >> t;

	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}