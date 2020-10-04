#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int INF=1e9;
void bfs(int s,vector<int> &da,vector<int> graph[]){
	da[s]=0;
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(auto x:graph[v]){
			if(da[x]==INF){
				da[x]=da[v]+1;
				q.push(x);
			}
		}
	}
}

void solve(){
	int n,m,a,b,c;
	cin>>n>>m>>a>>b>>c;
	--a;
	--b;
	--c;

	int price[m];
	for(int i=0;i<m;i++)
		cin>>price[i];
	sort(price,price+m);


	ll pref[m+1];
	pref[0]=0;
	for(int i=0;i<m;i++)
		pref[i+1]=price[i]+pref[i];


	vector<int> graph[n];
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		--x;
		--y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	std::vector<int> da(n,INF);
	std::vector<int> db(n,INF);
	std::vector<int> dc(n,INF);
	bfs(a,da,graph);
	bfs(b,db,graph);
	bfs(c,dc,graph);

	ll ans=1e18;

	for(int i=0;i<n;i++){
		if(da[i]+db[i]+dc[i]>m)
			continue;
		ans=min(ans,pref[db[i]]+pref[da[i]+db[i]+dc[i]]);
	}
	cout<<ans<<"\n";
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