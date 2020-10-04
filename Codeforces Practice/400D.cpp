#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e5 + 10;
const int INF = 1e9;
int ans[505][505];
int n, m, k;
vector < int > c(505);
vector < pair < int, int > > g[mxN];
vector < int > type(mxN);
vector < vector < int > > cost(505, vector < int > (505, INF));
vector < int > vis(mxN, 0);

void dfs(int root, int cur){
	vis[root] = cur;
	for(auto x : g[root]){
		if(x.second == 0){
			if(!vis[x.first])
				dfs(x.first, cur);
		}
	}
}

void solve(){
	cin >> n >> m >> k;
	int cur = 0;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = cur + 1; j <= cur + c[i]; j++){
			type[j] = i;
		}
		cur += c[i];
	}
	for(int i = 1; i <= m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		cost[type[x]][type[y]] = min(cost[type[x]][type[y]], w);
		cost[type[y]][type[x]] = min(cost[type[y]][type[x]], w);
		g[x].emplace_back(y, w);
		g[y].emplace_back(x, w);
	}
	cur = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cur++;
			dfs(i, cur);
		}
	}
	bool ok = true;
	cur = 0;
	for(int i = 1; i <= k; i++){
		int val = 0;
		for(int j = cur + 1; j <= cur + c[i]; j++){
			if(!val) val = vis[j];
			if(val != vis[j]){
				cout << "No\n";
				exit(0);
			}
		}
		cur += c[i];
		cost[i][i] = 0;
	}
	for (int x = 1; x <= k; x++) {
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= k; j++) {
				cost[i][j] = min(cost[i][j],cost[i][x]+cost[x][j]);
			}
		}
	}
	cout << "Yes\n";
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++)
			if(cost[i][j] != INF) cout << cost[i][j] << " ";
			else cout << "-1 ";
		cout << "\n";
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

	while(t--){
		solve();
	}

	return 0;
}