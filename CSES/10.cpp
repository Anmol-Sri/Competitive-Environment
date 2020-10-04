#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MOD=1e9+7;
ll trailingzero(ll n){
	ll count=0;
	for(ll i=5;n/i>=1;i*=5) count+=n/i;
	return count;
}
void solve(){
	ll n;
	cin>>n;
	cout<<trailingzero(n)<<"\n";
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
	#endif
*/
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}