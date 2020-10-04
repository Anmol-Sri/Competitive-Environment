#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0;
	int open=0,close=0;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			open++;
		}
		else{
			open--;	
		}
		if(open<0){
			ans++;
			open=0;
		}
	}
	// cout<<abs(open-close)<<"\n";
	cout<<ans<<"\n";
	return;
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