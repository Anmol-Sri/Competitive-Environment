#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n;
	cin>>n;
	ll dp[500];
	dp[0]=1;
	dp[1]=2;
	for(int i=2;i<=500;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	int ans;
	for(int i=0;i<=500;i++){
		if(n<dp[i]){
			break;
		}
		ans=i;
	}
	cout<<ans<<"\n";
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