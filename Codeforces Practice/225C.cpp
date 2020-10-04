#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	char s[n][m];
	int max_hash[m]={0};
	int sum[m+1]={0};
	for(int i=0;i<n;++i){
		for(int j=0;j<m;j++){
			cin>>s[i][j];

			if(s[i][j]=='#')
				max_hash[j]++;
		}
	}
	//for(int qwe:max_hash) cout<<qwe<<" ";
	for(int i=0;i<m;i++){
		sum[i+1]=sum[i]+max_hash[i];
	}
	//for(int qwe:sum) cout<<qwe<<" ";
	int dp[2005][2];
	memset(dp,63,sizeof(dp));
	dp[0][0]=dp[0][1]=0;

	for(int i=0;i<m;i++){
		for(int j=x;j<=y;j++){
			if(i+j>m) break;
			dp[i+j][0]=min(dp[i+j][0],dp[i][1]+sum[i+j]-sum[i]);
			dp[i+j][1]=min(dp[i+j][1],dp[i][0]+n*j-(sum[i+j]-sum[i]));
		}
	}
	cout<<min(dp[m][0],dp[m][1])<<"\n";
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