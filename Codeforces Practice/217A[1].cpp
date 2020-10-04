#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e2 + 1;
bool vis[mxN];
int n;
int x[mxN], y[mxN];

void dfs(int v){
	vis[v] = true;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			if(x[i] == x[v] || y[i] == y[v]){
				dfs(i);
			}
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i);
			ans++;
		}
	}
	cout << ans - 1 << "\n";
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