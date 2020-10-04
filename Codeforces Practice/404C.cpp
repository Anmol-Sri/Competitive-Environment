#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e5 + 1;
vector< int > graph[mxN];
vector< int > store[mxN];
vector < pair < int , int > > arr;
int n, k, x;

void solve(){
	cin >> n >> k;
	int mx = -1;
	for(int i = 1; i <= n; i++){
		cin >> x;
		mx = max(x, mx);	
		graph[x].push_back(i);
	}
	if(graph[0].size() != 1){
		cout << "-1\n";
		return ;
	}
	vector< pair< int , int > > ans;
	for(int i = 1; i <= mx; i++){
		if(graph[i - 1].size() * k < graph[i].size() || graph[i].size() == 0){
			cout << "-1\n";
			return ;
		}
		int q = 0;
		int cnt = 0;
		bool ok = false;
		for(int x = 0; x < graph[i].size() && q < graph[i - 1].size(); x++){
			if(store[graph[i - 1][q]].size() < k){
				// cnt = 0;
				ans.emplace_back(graph[i - 1][q], graph[i][x]);
				store[graph[i][x]].push_back(graph[i - 1][q]);
				store[graph[i - 1][q]].push_back(graph[i][x]);
				cnt++;
			}
			else{
				q++;
				x--;
			}
		}
		if(cnt < graph[i].size()){
			cout << "-1\n";
			return ;
		}
	}
	cout << ans.size() << "\n";
	for(auto x : ans){
		cout << x.first << " " << x.second << "\n";
	}
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
	// cin>>t;

	while(t--){
		solve();
	}

	return 0;
}