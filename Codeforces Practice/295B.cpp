#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int INF = 2e9;
void solve(){
	int n ;
	cin >> n;
	int adj[n + 1][n + 1] = {0};
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= n; j++){
			cin >> adj[i][j];
		}
	}
	ll distance[n +  1][n + 1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) distance[i][j] = 0;
			else if(adj[i][j]) distance[i][j] = adj[i][j];
			else distance[i][j] = INF;
		}
	}
	bool ok[n + 1] = {false};
	vector< ll > ans;
	int arr[n];
	for(int  i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int asd = n - 1; asd >= 0; asd--){
		ok[arr[asd]] = true;
		ll sum = 0;
		int k = arr[asd];
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <=n; j++){
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
				if(ok[i] && ok[j]) sum += distance[i][j];
			}
		}
		ans.push_back(sum);
	}
	reverse(ans.begin(), ans.end());
	for(auto x : ans){
		cout << x << " ";
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