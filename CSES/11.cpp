#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int a,b;
	cin>>a>>b;
	if(a<b) swap(a,b);
	if(a>2*b) {cout<<"NO\n";return ;}

	if((a+b)%3==0){
		cout<<"YES\n";
		return ;
	}
	cout<<"NO\n";
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
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}