#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char x;
			cin>>x;
			arr[i][j]=x-'0';
		}
	}
	bool dp1[n][n];
	bool dp2[n][n];
	bool res[n][n];
	memset(dp1,false,sizeof(dp1));
	memset(dp2,false,sizeof(dp2));
	memset(res,false,sizeof(res));

	bool ans=true;
	for(int i=n-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			if(arr[i][j] && !arr[i+1][j] && !arr[i][j+1]){
				ans=false;
				break;
			}
		}
	}
	if(ans) cout<<"YES\n";
	else cout<<"NO\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}