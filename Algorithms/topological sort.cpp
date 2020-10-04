#include <bits/stdc++.h>
#define ll long long int
using namespace std;

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