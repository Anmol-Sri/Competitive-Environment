#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector < int > arr;
vector < int > dp;
vector < int > ans;
vector < vector < int > > graph;

void dfs(int v, int p = - 1){
	dp[v] = arr[v];
	for(int u : graph[v]){
		if(u != p){
			dfs(u, v);
			dp[v] += max(0, dp[u]);
		}
	}
}

void dfs2(int v, int p = - 1){
	ans[v] = dp[v];
	for(int u : graph[v]){
		if(u != p){
			dp[v] -= max(0, dp[u]);
			dp[u] += max(0, dp[v]);
			dfs2(u, v);
			dp[u] -= max(0, dp[v]);
			dp[v] += max(0, dp[u]);
		}
	}
}

void solve(){
	int n;
	cin >> n;
	arr = vector < int > (n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] == 0) arr[i] = -1;
	}
	dp = vector < int > (n);
	ans = vector < int > (n);
	graph = vector < vector < int > > (n);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(0);
	dfs2(0);
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
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