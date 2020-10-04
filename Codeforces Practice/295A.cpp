#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k,m;
	cin>>n>>m>>k;
	ll arr[100005];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	ll l[100005],r[100005],d[100005];
	for(int i=1;i<=m;i++){
		cin>>l[i]>>r[i]>>d[i];
	}
	ll q[100005]={0};
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		q[x]++;
		q[y+1]--;
	}
	ll update[100005]={0};
	for(int i=1;i<=m;i++){
		q[i]+=q[i-1];
		d[i]*=q[i];
		update[l[i]]+=d[i];
		update[r[i]+1]-=d[i];
	}
	for(int i=1;i<=n;i++){
		update[i]+=update[i-1];
		cout<<update[i]+arr[i]<<" ";
	}

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