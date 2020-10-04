#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int INF=1e9;
const int mxN=1e6+1;
int n,c;
ll dp[mxN];
void solve(){
	cin>>n>>c;
	int arr[n];
	//memset(dp,INF,sizeof(dp));
	for(int &i:arr) cin>>i;
	for(int i=1;i<=c;i++){
		dp[i]=INF;
		for(auto q:arr){
			if(i-q>=0){
				dp[i]=min(dp[i],1+dp[i-q]);
			}
		}
	}
	if(dp[c]!=INF)
		cout<<dp[c]<<"\n";
	else cout<<"-1\n";
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

/*	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
		
	int t=1;

	while(t--){
		solve();
	}
	return 0;
}