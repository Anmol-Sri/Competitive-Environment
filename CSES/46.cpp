#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MOD=1e9+7;
const int mxN=1e6+1;
ll dp[mxN];
void solve(){
	int n,x;
	cin>>n>>x;
	int coins[n];
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	dp[0]=1;
	for(int i=1;i<=x;i++){
		for(auto c:coins){
			if(i-c>=0){
				dp[i]+=dp[i-c];
				dp[i]%=MOD;
			}
		}
	}
	cout<<dp[x]<<"\n";
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