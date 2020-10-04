#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e5+1;
std::vector<int> tree[mxN];
int arr[mxN];
int ans,m,n;
bool visited[mxN];

void dfs(int u,int pr,int cats){
	visited[u]=true;
	if(arr[u]==1){
		cats++;
	}
	else{
		//cout<<"making cats 0 at :- "<<u<<"\n";
		cats=0;
	}
	if(cats>m){
		//cout<<"Terminate at - "<<u<<"\n";
		return ;
	}
	if(tree[u].size()==1 and tree[u][0]==pr){
		//cout<<"Found at :- "<<u<<" with cats =  "<<cats<<"\n";
		ans++;
		return;
	}
	for(int i=0;i<tree[u].size();i++){
		if(!visited[tree[u][i]]){
			dfs(tree[u][i],u,cats);
		}
	}
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		//i==n-1?cout<<arr[i]<<"\n":cout<<arr[i]<<" ";
	}
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	dfs(1,-1,0);
	cout<<ans<<"\n";
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