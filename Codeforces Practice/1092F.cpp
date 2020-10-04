#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n;
vector < int > arr;
vector < ll > sum;
vector < vector < int > > graph;
ll res, ans;

void dfs(int v, int p = -1, int h = 0){
	res += h * 1LL * arr[v];
	sum[v] = arr[v];
	for(auto to : graph[v]){
		if(to != p){
			dfs(to, v, h + 1);
			sum[v] += sum[to];
		}
	}
}

void dfs2(int v, int p = -1){
	ans = max(ans, res);
	for(auto to : graph[v]){
		if(to != p){
			res -= sum[to];
			sum[v] -= sum[to];
			res += sum[v];
			sum[to] += sum[v];
			dfs2(to, v);
			sum[to] -= sum[v];
			res -= sum[v];
			sum[v] += sum[to];
			res += sum[to];
		}
	}
}

void solve(){
	cin >> n;
	arr = vector < int > (n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	graph = vector < vector < int > > (n);
	sum = vector < ll > (n);
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