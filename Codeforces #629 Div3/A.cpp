#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll a,b;
	cin>>a>>b;
	if(a<=b){
		cout<<b-a<<"\n";
		return;
	}
	else if(a%b==0){
		cout<<"0\n";
		return;
	}
	else{
		ll mi=a/b;
		ll ans=(mi+1)*b-a;
		cout<<ans<<"\n";
		return;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);


    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}