#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n,m;
const int mxN=1e6+5;
std::vector<int> graph[mxN];
unordered_set<int> remaining;
std::vector<int> inQ(mxN,0);
std::vector<int> nextToQ(mxN,0);
std::vector<int> ans;

void dfs(int u){
	remaining.erase(u);
	for(auto x:graph[u]){
		remaining.erase(x);
	}
	if(!remaining.empty()){
		dfs(*remaining.begin());
	}
	if(!nextToQ[u]){
		inQ[u]=1;
		nextToQ[u]=1;
		for(auto x:graph[u]){
			nextToQ[x]=1;
		}
		ans.push_back(u);
	}
}

void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		remaining.insert(i);
	}
	dfs(1);
	cout<<ans.size()<<"\n";
	for(auto x:ans){
		cout<<x<<" ";
	}
	cout<<"\n";
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