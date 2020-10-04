#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mxN=2e6+1;
const int MOD=1e9+7;
ll dp[mxN],ans[mxN];
void solve(){
	int n;
	cin>>n;
	cout<<ans[n]<<"\n";
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
		clock_t tStart = clock();
	#endif
	for(int i=0;i<mxN;i++) dp[i]=1;
	for(int i=3;i<mxN;i++){
		dp[i]=dp[i-1]+dp[i-2]*2;
	    dp[i]=dp[i]%MOD;
	}
   	memset(ans,0,sizeof(ans));
   	for(int i=3;i<mxN;i++){
		ans[i]=ans[i-3]+dp[i-2]*4;
	    ans[i]=ans[i]%MOD;
	}
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