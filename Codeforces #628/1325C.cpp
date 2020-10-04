#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e5+1;
std::vector<int> graph[mxN];
int ans[mxN];

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(i);
		graph[y].push_back(i);
		ans[i]=-1;
	}
	pair<int,int> mx(0,0);
	for(int i=1;i<=n;i++){
		mx=max(mx,make_pair((int)graph[i].size(),i));
	}
	int cur=0;
	for(int i:graph[mx.second]){
		ans[i]=cur++;
	}
	for(int i=1;i<n;i++){
		if(ans[i]==-1){
			ans[i]=cur++;
		}
		cout<<ans[i]<<"\n";
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
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}