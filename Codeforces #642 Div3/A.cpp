#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m;
	cin>>n>>m;
	if(n>=3){
		cout<<2*m<<"\n";
		return ;
	}
	if(n==2){
		cout<<m<<"\n";
		return ;
	}
	if(n==1){cout<<"0"<<"\n"; return ;}
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