#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector < int > graph[n + 1];
	vector < int > mark(n + 1);
	vector < int > order(n);
	vector < bool > vis(n + 1, false);
	vector < int > ans;
	for(int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i = 0; i < n; i++){
		cin >> order[i];
		mark[order[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end(), [&](int a, int b){
			return mark[a] < mark[b];
		});
	}
	queue < int > q;
	q.push(1);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		ans.push_back(x);
		vis[x] = true;
		for(auto j : graph[x]){
			if(!vis[j]){
				q.push(j);
			}
		}

	}
	for(int i = 0; i < n; i++){
		if(ans[i] != order[i]){
			cout << "No\n";
			return ;
		}
	}
	cout << "Yes\n";
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