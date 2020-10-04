#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MOD=1e9+7;
ll powmod(ll n,ll pow){
	if(n==1|| n==0) return n%MOD;
	if(pow==0) return 1;
	ll ans=1;
	while(pow){
		if(pow%2){
			ans=(ans*n)%MOD;
		}
		n=(n*n)%MOD;
		pow/=2;
	}
	return ans;
}
void solve(){
	ll n;
	cin>>n;
	cout<<powmod(2,n)<<"\n";
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