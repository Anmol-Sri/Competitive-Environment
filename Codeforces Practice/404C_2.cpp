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

const int mxN = 1e5 + 1;

vector < int >  g[mxN];
vector < int >  store[mxN];
int n, k;

void solve(){
	cin >> n >> k;
	int mx = -1;
	vector < pair < int , int > > ans;
	for(int  i = 1; i <= n; i++){
		int x;
		cin >> x;
		mx = max(mx, x);
		g[x].push_back(i);
	}
	if(g[0].size() != 1){
		cout << "-1\n";
		return ;
	}
	for(int i = 1; i <= mx; i++){
		if(g[i - 1].size() * k < g[i].size() || g[i].size() == 0){
			cout << "-1\n";
			return ;
		}
		int q = 0;
		int cnt = 0;
		for(int x = 0; x < g[i].size() && q < g[i - 1].size(); x++){
			if(store[g[i  - 1][q]].size() < k){
				ans.emplace_back(g[i - 1][q], g[i][x]);
				store[g[i][x]].push_back(g[i - 1][q]);
				store[g[i - 1][q]].push_back(g[i][x]);
				cnt++;
			}
			else{
				q++;
				x--;
			}
		}
		if(cnt < g[i].size()){
			cout << "-1\n";
			return ;
		}
	}
	cout << ans.size() << "\n";
	for(auto x : ans) cout << x.first << " " << x.second << "\n";
	return ;
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