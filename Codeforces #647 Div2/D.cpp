#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=5e5+1;
std::vector<int> graph[mxN];
bool vis[mxN];
set<int> s[mxN];
int topic[mxN];
bool ok;
int parent[mxN];

void make_set(int v){
	parent[v]=v;
}

int find_set(int v){
	if(v==parent[v]) return v;
	return find_set(parent[v]);
}

void union_set(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b)
		parent[b]=a;
}

void dfs(int u){
	vis[u]=true;
	for(int v:graph[u]){
		if(topic[v]==topic[u]){
			ok=false;
			return ;
		}
		else{
			if(!vis[v])
				dfs(v);
		}
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		cin>>topic[i];
		s[topic[i]].insert(i);
	}
	ok=true;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	if(!ok){
		cout<<"-1\n";
		return ;
	}
	memset(vis,false,sizeof(vis));
	int ans[n];
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			for(int x:s[i]){
				cout<<x<<" ";
			}
		}
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
	while(t--){
		solve();
	}
    return 0;
}