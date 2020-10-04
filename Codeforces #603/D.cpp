#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+100;
vector<int> graph[mxN];
bool visited[mxN];

void dfs(int u){
	visited[u]=true;
	for(int v:graph[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;

		for(char c:s){
			graph[i].push_back(n+c-'a');
			graph[n+c-'a'].push_back(i);
		}
	}
	int ans=0;
	for(int i=n;i<n+26;i++){
		if(!graph[i].empty() && !visited[i]){
			ans++;
			dfs(i);
		}
	}
	cout<<ans<<"\n";
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}