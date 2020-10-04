#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN=2e5+1;
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int &i:arr) cin>>i;

	int dp[n];
	memset(dp,0,sizeof(dp));
	int length=1;
	dp[0]=arr[0];
	for(int i=1;i<n;i++){
		auto it=lower_bound(dp,dp+length,arr[i]);
		if(*it==dp[length]){
			dp[length++]=arr[i];
		}
		else{
			*it=arr[i];
		}
	}
	cout<<length<<"\n";
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
		
	int t=1;

	while(t--){
		solve();
	}

	return 0;
}