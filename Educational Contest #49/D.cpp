#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n+1]={0};
	int cost[n+1]={0};
	int visited[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>cost[i];
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=i;
		while(!visited[x]){
			visited[x]=i;
			x=arr[x];
		}
		if(visited[x]!=i){
			continue;
		}
		int mini=cost[x];
		int y=arr[x];
		while(y!=x) mini=min(mini,cost[y]),y=arr[y];
		ans+=mini;
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}