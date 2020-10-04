#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
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
int a[mxN], y[mxN], lx[mxN], rx[mxN], f[mxN];
int x[mxN], ly[mxN], ry[mxN];
vector < int > l[mxN], r[mxN], q[mxN];

void add(int i, int  val){
	for(i++; i <= mxN; i  += i & -i)  f[i] += val;
}

int get(int i){
	int ans = 0;
	for(i++; i; i -= i & -i) ans += f[i];
	return ans;
}

void solve(){
	cin >> n >> m;
	ll cnt = 1;
	for(int i = 1; i <= n; i++){
		cin >> y[i] >> lx[i] >> rx[i];
		if(lx[i] == 0 && rx[i] == (int)1e6)cnt++;
		l[lx[i]].pb(i);
		r[rx[i] + 1].pb(i);
	}
	for(int i = 1; i <= m; i++){
		cin >> x[i] >> ly[i] >> ry[i];
		if(ly[i] == 0 && ry[i] == (int)1e6) cnt++;
		q[x[i]].pb(i);
	}
	for(int i = 0; i <= (int)1e6; i++){
		for(int x : l[i]) add(y[x], 1);
		for(int x : r[i]) add(y[x], -1);
		for(int x : q[i]){
			if(ly[x] == 0) cnt += get(ry[x]);
			else cnt += get((int)1e6) - get(ly[x] - 1);
		}
	}
	cout << cnt << "\n";
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