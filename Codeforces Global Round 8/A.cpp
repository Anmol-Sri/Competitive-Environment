#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int a,b,n;
	cin>>a>>b>>n;
	int ans=0;
	if(a<b){
		swap(a,b);
	}
	while(a<=n && b<=n){
		if(ans&1) a+=b;
		else b+=a;
		ans++;
	}
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