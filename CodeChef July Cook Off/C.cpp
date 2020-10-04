#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 101;
vector < int > arr;
vector < int > ans;
vector < bool > vis;
vector< int > graph[mxN];
int n;
int a;
int fir;
int mx, mxi;
void dfs(int u, int p = -1){
	if(p != -1){
		arr[u] = arr[p] + 1;
		if(arr[u] > mx){
			mx = arr[u];
			mxi = u;
		}
	}
	for(int v : graph[u]){
		if(v != p){
			dfs(v, u);
		}
	}
}

void dfs2(int u,  int val){
	vis[u] = true;
	ans[u] = val + 1;
	for(int v : graph[u]){
		if(!vis[v]){
			dfs2(v, val + 1);
		}
	}
}

void solve(){
	mx = -1;
	mxi = -1;
	a = 1;
	cin >> n;
	// arr.clear();
	arr.assign(n, 0);
	// ans.clear();
	ans.assign(n, 0);
	// vis.clear();
	vis.assign(n, false);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(0);
	dfs2(mxi, 0);
	// dfs2(fir);
	// for(int i = 0; i < n; i++){
	// 	vis.clear();
	// 	vis.assign(n, false);
	// 	dfs(i);
	// }
	for(int i = 0; i < n; i++){
		graph[i].clear();
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}