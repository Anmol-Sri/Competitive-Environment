#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ar array

void solve(){
	string s;
	cin>>s;
	ll ans=s.size();
	ll cur=0;
	ll asd=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='+') cur++;
		else cur--;
		if(cur<asd){
			asd=cur;
			ans += i+1;
		}
	}
	cout<<ans<<"\n";
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
		
	// int t=1;
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}