#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n;
	cin >> n;
	ll arr[n + 1];
	for(ll i = 1; i <= n; i++){
		cin >> arr[i];
		if(arr[i] == 0){
			i--;
			n--;
			continue;
		}
	}
	if(n > 3 * 64){
		cout << "3\n";
		return ;
	}
	ll dis[n + 1][n + 1];
	memset(dis,127/4,sizeof dis);
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(arr[i] & arr[j]){
				dis[i][j] = dis[j][i] = 1;
			}
		}
	}
	ll adj[n + 1][n + 1];
	memcpy(adj, dis, sizeof adj);
	ll ans = 2e9 + 1;
	for(int k = 1; k <= n; k++){
		for(int i = 1; i < k; i++){
			for(int j = i + 1; j < k ; j++){
				ans = min(ans, adj[i][k] + adj[k][j] + dis[i][j]);
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	if(ans > 1e3){
		cout << "-1\n";
		return ;
	}
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