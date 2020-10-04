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

const int mxN = (1<<19);
const int MOD = 1e9 + 7;
int n, m;
map < int , int > mp;
pair < int , int > arr[mxN];
vector < int > v[mxN];
ll dp[mxN];

void solve(){
	cin >> n >> m;
	mp[0] = 1;
	mp[n] = 1;
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		arr[i] = make_pair(a, b);
		mp[a] = 1;
		mp[b] = 1;
	}
	int cnt = 0;
	for(auto x : mp){
		mp[x.first] = ++cnt;
	}
	n =  mp.size();
	for(int i = 1; i <= m; i++){
		arr[i].first = mp[arr[i].first];
		arr[i].second = mp[arr[i].second];
		v[arr[i].second].push_back(arr[i].first);
	}
	dp[1] = 1;
	for(int i = 1; i <= n; i++){
		for(auto x : v[i]){
			dp[i] += dp[i - 1] - dp[x - 1];
			dp[i] += MOD;
			dp[i] %= MOD;
		}
		dp[i] += dp[i - 1];
		dp[i] %= MOD;
	}
	cout << (dp[n] - dp[n - 1] + MOD) % MOD << "\n";
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