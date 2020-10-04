#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e5 + 1;
vector < int > graph[mxN];
int n;
ll inc[mxN], sub[mxN];
ll val[mxN];

void dfs(int v, int pr = -1){
	inc[v] = sub[v] = 0;
	for(auto u : graph[v]){
		if(u != pr){
			dfs(u, v);
			inc[v] = max(inc[v], inc[u]);
			sub[v] = max(sub[v], sub[u]);
		}
	}
	ll temp = val[v] + inc[v] - sub[v];
	if(temp > 0) sub[v] += temp;
	else inc[v] -= temp;
}

void solve(){
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 0; i < n; i++){
		cin >> val[i];
	}
	dfs(0);
	cout << inc[0] + sub[0] << "\n";
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