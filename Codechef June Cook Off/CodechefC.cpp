#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+1;
ll n,m;
bool vis[mxN];
std::vector<ll> graph[mxN];
std::vector<ll> ans;
std::vector<ll> a,b;
bool selected[mxN];

void dfs(ll u){
	ans.push_back(u);
	vis[u]=true;
	for(ll v:graph[u]){
		if(!vis[v] && selected[v]){
			dfs(v);
		}
	}
}
void solve(){
	cin>>n>>m;
	a=std::vector<ll> (n+1);
	b=std::vector<ll> (n+1);
	memset(selected,false,sizeof(selected));
	memset(vis,false,sizeof(vis));
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		graph[i].clear();
	}
	for(ll i=1;i<=n;i++){
		cin>>b[i];
	}
	for(ll i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	ll num=a[1],den=b[1];
	for(ll i=1;i<=n;i++){
		if(a[i]*den>b[i]*num){
			num=a[i];
			den=b[i];
		}
	}
	for(ll i=1;i<=n;i++){
		if(a[i]*den==b[i]*num){
			selected[i]=true;
		}
	}
	std::vector<ll> store;
	for(ll i=n;i>=1;i--){
		if(!vis[i] && selected[i]){
			ans.clear();
			dfs(i);
			if(ans.size()>store.size()){
				store=ans;
			}
		}
	}
	cout<<store.size()<<"\n";
	random_shuffle(store.begin(), store.end());
	for(ll i:store){
		cout<<i<<" ";
	}
	cout<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		clock_t tStart = clock();
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
	#ifndef ONLINE_JUDGE
		cerr<<fixed<<setprecision(10)<<"Time Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
	#endif

	return 0;
}