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

void solve(){
	int n, m;
	cin >> n >> m;
	int cx, cy;
	cin >> cx >> cy;
	--cx;
	--cy;
	int dx, dy;
	cin >> dx >> dy;
	--dx;
	--dy;
	vector < string > g(n);
	for(int i = 0; i < n; i++){
		cin >> g[i];
	}
	vector<vector<int>> dist(n, vector<int>(m, -1));
	vector<vector<pair<int, int>>> que(n * m * 2);
	auto add = [&](int x, int y, int d){
		if (x < 0 || x >= n || y < 0 || y >= m) return;
		if (g[x][y] == '#') return;
		if (dist[x][y] >= 0 && d >= dist[x][y]) return;
		dist[x][y] = d;
		que[d].push_back(make_pair(x, y));
	};
	add(cx, cy, 0);
	for (int d = 0; d + 1 < que.size(); d++) {
		for (int close = 0; close < que[d].size(); ++close) {
			int x = que[d][close].first;
			int y = que[d][close].second;
			for (int dx = -2; dx <= 2; dx++) {
				for (int dy = -2; dy <= 2; dy++){
					int new_x = x + dx;
					int new_y = y + dy;
					add(new_x, new_y, d + (abs(dx) + abs(dy) > 1 ? 1 : 0));
				}
			}
		}
	}
	cout << dist[dx][dy] << endl;
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