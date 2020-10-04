#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
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

const int mxN = 1e6 + 10;
int n, m;
int a[mxN], b[mxN];
int need[32];
int ori_have[32];
int have[32];

bool check(int x){
	for(int  i = 0; i <= 30; i++){
		have[i] = ori_have[i];
	}
	mem(need, 0);
	for(int i = 0; i < x; i++) need[b[i]]++;
	for(int i = 30; i >= 0; i--){
		if(have[i] < need[i]) return false;
		int lefts = 2 * (have[i] - need[i]);
		if(i > 0) have[i - 1] += min(lefts, 10000000);
	}
	return true;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j <= 30; j++){
			if((1 << j) & a[i]) have[j]++;
		}
	}
	for(int i = 0; i <= 30; i++){
		ori_have[i] = have[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	sort(b, b + m);
	int l = 0;
	int r = m;
	while(l < r){
		int m = (1 + l + r)/ 2;
		if(check(m)) l = m;
		else r = m - 1;
	}
	cout << l << "\n";
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
	// cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}