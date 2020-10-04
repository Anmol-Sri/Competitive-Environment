#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int INF=1e9;
void solve(){
	string a,b;
	cin>>a>>b;
	int len1=a.size();
	int len2=b.size();
	int dp[len1+1][len2+1];
	memset(dp,INF,sizeof(dp));
	for(int i=0;i<=len1;i++) dp[i][0]=i;
	for(int i=0;i<=len2;i++) dp[0][i]=i;
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+((a[i-1]==b[j-1])?0:1)));
		}
	}
	/*for(int i=0;i<=len1;i++){
		for(int j=0;j<=len2;j++){
			if(i==0 && j==0){
				cout<<"0 ";
				continue;
			}
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<dp[len1][len2]<<"\n";
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
/*
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
		
	int t=1;

	while(t--){
		solve();
	}

	return 0;
}