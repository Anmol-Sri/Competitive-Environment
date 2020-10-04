#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 2e5 + 1;

struct graph{
	int n;
	vector < vector < int > > adj;
	vector < vector < int > > adj2;
	graph(int _n, vector< pair < int , int > > edge){
		n = _n;
		adj = vector < vector < int > >(n);
		adj2 = vector < vector < int > >(n);
		for(auto x : edge){
			adj[x.first - 1].push_back(x.second - 1);
			adj2[x.second - 1].push_back(x.first - 1);
		}
	}
	vector < int > topological_sort(){
		vector< int > d(n);
		queue < int > q;
		for(int i = 0; i < n; i++){
			d[i] = adj2[i].size();
			if(!d[i]) q.push(i);
		}
		vector < int > ans;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(auto v : adj[u]){
				--d[v];
				if(!d[v]) q.push(v);
			}
			ans.push_back(u);
		}
		if(ans.size() < n) ans.clear();
		return ans;
	}
};

void solve(){
	int n, m;
	cin >> n >> m;
	vector < pair < int, int > > assign;
	vector < pair < int, int > > edge;
	for(int i = 0; i < m; i++){
		int x, a, b;
		cin >> x >> a >> b;
		if(x == 0){
			assign.emplace_back(a, b);
		}
		else{
			edge.emplace_back(a, b);
		}
	}
	graph g(n, edge);
	vector< int > order = g.topological_sort();
	if(order.size() == 0){
		cout << "NO\n";
		return ;
	}
	else{
		cout << "YES\n";
		vector< int > idx(n);
		for(int i = 0; i < n; i++){
			idx[order[i]] = i;
		}
		for(auto x : edge){
			cout << x.first << " " << x.second << "\n";
		}
		for(auto &x : assign){
			if(idx[x.first - 1] > idx[x.second - 1]) cout << x.second << " " << x.first << "\n";
			else cout << x.first << " " << x.second << "\n";
		}
	}
	return;
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