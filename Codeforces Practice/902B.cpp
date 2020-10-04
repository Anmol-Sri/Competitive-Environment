#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e4 + 10;
int n;
vector < int > g[mxN];
vector < int > color;
vector < int > parent;
ll ans;

void dfs(int v, int col){
	if(color[v] != col) ans++, col = color[v];
	for(auto x : g[v]){
		dfs(x, col);
	}
}

void solve(){
	cin >> n;
	color.resize(n + 1);
	parent.resize(n + 1);
	parent[0] = 0;
	parent[1] = 1;
	for(int i = 2; i <= n; i++){
		cin >> parent[i];
		g[parent[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		cin >> color[i];
	}
	dfs(1, 0);
	cout << ans << "\n";
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

	while(t--){
		solve();
	}

	return 0;
}