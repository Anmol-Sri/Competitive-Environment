#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll s,n,ans;
	cin>>s>>n;
	if(s==1){
		cout<<"1\n";
		return ;
	}
	if(s<=n && s%2==0){
		cout<<"1\n";
		return ;
	}
	else if(s<=n){
		cout<<"2\n";
		return;
	}
	else if(s%2!=0){
		ans=1;
		s--;
		ans+=s/n;
		if(s%n) ans++;
		cout<<ans<<"\n";
		return ;
	}
	else{
		ans=s/n;
		if(s%n) ans++;
		cout<<ans<<"\n";
		return ;
	}
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