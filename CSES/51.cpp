#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MOD=1e9+7;
const int mxN=1e5+1;
int change[]={-1,0,1};
void solve(){
	ll n,m;
	cin>>n>>m;
	ll dp[n][m+1];
	memset(dp,0,sizeof(dp));
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i==0){
			if(arr[i]==0){
				for(int j=0;j<=m;j++){
					dp[i][j]=1;
				}
			}
			else{
				dp[i][arr[i]]=1;
			}
		}
		else{
			if(arr[i]==0){
				for(int j=1;j<=m;j++){
					for(int x:{j-1,j,j+1}){
						if(x>=1 && x<=m){
							(dp[i][j]+=dp[i-1][x])%=MOD;
						}
					}
				}
			}
			else{
				for(int x:{arr[i]-1,arr[i],arr[i]+1}){
					if(x>=1 && x<=m){
						(dp[i][arr[i]]+=dp[i-1][x])%=MOD;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=m;i++){
		(ans+=dp[n-1][i])%=MOD;
	}
	cout<<ans<<"\n";
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
	#endif
		*/
	int t=1;

	while(t--){
		solve();
	}
	return 0;
}