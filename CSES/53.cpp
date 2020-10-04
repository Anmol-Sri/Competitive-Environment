#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN=501;
int dp[mxN][mxN];
bool vis[mxN][mxN]={false};
int recur(int a,int b){
	if(a==b){
		return 0;
	}
	else if(vis[a][b]){
		return dp[a][b];
	}
	else if(a%b==0){
		vis[a][b]=true;
		return dp[a][b] = a/b-1;
	}
	else if(b%a==0){
		vis[a][b]=true;
		return dp[a][b] = b/a-1;
	}
	vis[a][b]=true;
	int ans=INT_MAX;
	for(int i=1;i<=a/2;i++){
		ans=min(ans,recur(a-i,b)+recur(i,b)+1);
	}
	for(int i=1;i<=b/2;i++){
		ans=min(ans,recur(a,b-i)+recur(a,i)+1);
	}
	return dp[a][b]=ans;
}

void solve(){
	int a,b;
	cin>>a>>b;
	cout<<recur(a,b)<<"\n";
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