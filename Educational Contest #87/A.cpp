#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a<=b) {cout<<b<<"\n";return ;}
	if(c<=d){
		cout<<"-1\n";
		return ;
	}
	ll rem=a-b;
	ll rept=(rem+(c-d)-1)/(c-d);
	cout<<b+rept*c<<"\n";
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