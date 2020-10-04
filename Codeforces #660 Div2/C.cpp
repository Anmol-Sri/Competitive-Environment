#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e5 + 10;
vector < int > g[mxN];
vector < int > p(mxN);
vector < int > h(mxN);
vector < int > tot(mxN);
vector < int > happy(mxN);

bool ok;
int n, m;

void dfs(int v, int par = -1){
	tot[v] = p[v];
	int cur = 0;
	for(auto x : g[v]){
		if(x == par) continue;
		dfs(x, v);
		cur += happy[x];
		tot[v] += tot[x];
	}
	if(	(tot[v] + h[v] ) % 2 != 0) ok = false;
	happy[v] = (tot[v] + h[v]) / 2;
	if(happy[v] >= 0 && happy[v] <= tot[v]) {} else ok = false;
	if(cur > happy[v]) ok = false;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	for(int i = 0;  i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	ok = true;
	dfs(0);
	if(ok) cout << "YES\n"; else cout << "NO\n";
	for(int i = 0; i < n; i++){
		g[i].clear();
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}