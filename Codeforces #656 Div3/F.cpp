#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const  int mxN = 2e5 + 1;

void solve(){
	int n, k;
	cin >> n >> k;
	vector < vector < int > > graph(n);
	vector < bool > leaf(n, false);
	vector < int > degree(n, 0);
	vector < int > leaf_parent(n, 0);
	for(int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
		degree[x]++;
		degree[y]++;
	}
	if(k == 1){
		cout << n - 1 << "\n";
		return ;
	}
	if(n == 2){
		cout << "1\n";
		return ;
	}
	for(int i = 0; i < n; i++){
		if(degree[i] == 1){
			leaf[i] = true;
			leaf_parent[graph[i][0]]++;
		}
	}
	queue < int > q;
	for(int i = 0; i < n; i++){
		if(leaf_parent[i] >= k) q.push(i);
	}
	int ans = 0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		int edges = leaf_parent[cur] / k;
		edges *= k;
		if(edges == 0) continue;
		degree[cur] -= edges;
		leaf_parent[cur] -= edges;
		ans += edges / k;
		if(degree[cur] == 1){
			leaf[cur] = true;
			for(auto x : graph[cur]){
				if(!leaf[x]){
					leaf_parent[x]++;
					if(leaf_parent[x] == k) q.push(x);
				}
			}
		}
	}
	cout  << ans << "\n";
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