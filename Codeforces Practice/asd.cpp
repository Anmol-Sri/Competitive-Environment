#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{	
	int n,m;
	cin>>n>>m;

	int arr[m];
	for(int i=0;i<m;i++){
		cin>>arr[i];
	}

	int dp[n+1][m];
	for(int i=0;i<m;i++){
		dp[0][i]=1;
	}

	int x=0,y=0;

	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			x=(i-arr[j]>=0)?dp[i-arr[j]][j]:0;
			y=(j>=1)?dp[i][j-1]:0;
			dp[i][j]=x+y;
		}
	}

	cout<<dp[n][m-1]<<"\n";
}