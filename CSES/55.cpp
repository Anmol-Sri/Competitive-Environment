#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN=5e3+1;
ll dp[mxN][mxN];
ll n,sum;
array<ll,mxN> arr;
void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	for(int start=n-1;start>=0;start--){
		for(int end=start;end<n;end++){
			if(start==end){
				dp[start][end]=arr[start];
			}
			else{
				dp[start][end]=max(arr[start]-dp[start+1][end],arr[end]-dp[start][end-1]);
			}
		}
	}
	cout<<(sum+dp[0][n-1])/2<<"\n";
	return;
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