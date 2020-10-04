#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+10;
int depth[mxN];
std::vector<int> graph[mxN];
int parent[mxN];
int arr[mxN];
int n,q;
ll ans;

void dfs(int cur,int par=-1,int dep=-1){
	parent[cur]=par;
	depth[cur]=dep;

	for(int v:graph[cur]){
		if(v!=par){
			dfs(v,cur,dep+1);
		}
	}
}

int calc(int a,int b){
	int fre[101];
	memset(fre,0,sizeof fre);
	while(a!=b){
		if(depth[a]>depth[b]){
			fre[arr[a]]++;
			if(fre[arr[a]]>1) return 0;
			a=parent[a];	
		}
		else{
			fre[arr[b]]++;
			if(fre[arr[b]]>1) return 0;
			b=parent[b];
		}
	}
	fre[arr[a]]++;
	if(fre[arr[a]]>1){
		return 0;
	}
	int pre=-200;
	int ans=105;
	for(int i=1;i<=100;i++){
		if(fre[i]){
			ans=min(ans,i-pre);
			pre=i;
		}
	}
	return ans;
}

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		graph[i].clear();
	}
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1);
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<calc(a,b)<<"\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}