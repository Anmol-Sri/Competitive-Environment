#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 2e5 + 1;
ll a[mxN], b[mxN];
bool vis[mxN] = {false};
ll ans = 0;
vector < ll > neg, pos;
vector < ll > g[mxN];
ll n;

void dfs(int v){
	vis[v] = true;
	for(int x : g[v]){
		if(!vis[x]) dfs(x);
	}
	ans += a[v];
	if(b[v] != -1 && a[v] > 0){
		a[b[v]] += a[v];
	}
	if(a[v] > 0) pos.push_back(v);
	else neg.push_back(v);
}
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x != -1){
			x--;
			g[x].push_back(i);
		}
		b[i] = x;
	}
	ans = 0;
	for(int i = 0; i < n; i++){
		if(!vis[i]) dfs(i);
	}
	cout << ans << "\n";
	reverse(neg.begin(), neg.end());
	for(int i : pos) cout << i + 1 << " ";
	for(int i : neg) cout << i + 1 << " ";
	cout << "\n";
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