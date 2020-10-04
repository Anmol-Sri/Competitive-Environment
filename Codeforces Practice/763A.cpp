#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e5+10;
vector<int> graph[mxN];
int n;
int color[mxN];
int cur_color;
bool ok;
void dfs(int v,int parent){
	ok=ok&& (color[v]==cur_color);
	for(int x:graph[v]){
		if(x!=parent) dfs(x,v);
	}
}

bool check(int v){
	bool ans=true;
	for(int i=0;i<graph[v].size();i++){
		cur_color=color[graph[v][i]];
		ok=true;
		dfs(graph[v][i],v);
		ans=ans && ok;
	}
	return ans;
}

void solve(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		cin>>color[i];
	}
	int e1=-1,e2=-1;

	for(int i=1;i<=n;i++){
		for(int x:graph[i]){
			if(color[x]!=color[i]){
				e1=x;
				e2=i;
			}
		}
	}
	//cout<<e1<<" "<<e2<<"\n";
	if(e1==-1 ){
		cout<<"YES\n1\n";
		return ;
	}
	bool ok1=check(e1);
	bool ok2=check(e2);
	//cout<<ok1<<" "<<ok2<<"\n";
	if(ok1){
		cout<<"YES\n"<<e1<<"\n";
		return;
	}
	if(ok2){
		cout<<"YES\n"<<e2<<"\n";
		return ;
	}
	cout<<"NO\n";
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