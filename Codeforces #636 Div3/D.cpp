/*
Problem int he solution
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+50;
const int mxK=4e5+100;

void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=1;i<=n;i++) cin>>arr[i];
	int dp[mxK];
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n/2;i++){
		int a=arr[i];
		int b=arr[n-i-1];
		if(a>b)
			swap(a,b);
		dp[1]+=2;
		dp[a+b]--;
		dp[a+b+1]++;

		dp[k+b+1]++;
		dp[a+1]--;
		for(int j=1;j<=2*k;j++){
			cout<<dp[i]<<" ";
		}
		cout<<endl;
	}
	cout<<"-----------------------\n"<<endl;
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}