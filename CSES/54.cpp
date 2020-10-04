#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN=1e5+1;
int n;
bool dp[101][mxN];
array<int,101> arr;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dp[0][0]=true;
	for(int i=1;i<=n;i++){
		for(int j=0;j<mxN;j++){
			if(j-arr[i]>=0){
				dp[i][j] |= dp[i-1][j-arr[i]];
			}
			dp[i][j] |= dp[i-1][j];
		}
	}
	std::vector<int> ans;
	for(int i=1;i<mxN;i++){
		if(dp[n][i]){
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<"\n";
	for(auto x:ans) cout<<x<<" ";
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