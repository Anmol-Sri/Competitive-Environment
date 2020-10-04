#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MOD=1e9+7;

void solve(){
	int n,k;
	cin>>n>>k;
	int dp[k+1][n+1];
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++) dp[1][i]=1;

	for(int i=2;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int q=j;q<=n;q+=j){
				dp[i][q]=(dp[i][q]+dp[i-1][j])%MOD;
			}
		}
	}
	//for(int i=0;i<=k;i++){ for(int j=0;j<=n;j++) cout<<dp[i][j]<<" "; cout<<endl;}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+dp[k][i])%MOD;
	}
	cout<<ans<<endl;
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