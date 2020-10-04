#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll u,v;
	cin>>u>>v;
	if(u%2!=v%2 || u>v){
		cout<<"-1\n";
		return ;
	}
	if(u==v){
		if(!u){
			cout<<"0\n";
			return ;
		}
		cout<<"1\n"<<u<<"\n";
		return ;
	}
	ll x=(v-u)/2;
	if(u&x){
		cout<<3<<"\n"<<u<<" "<<x<<" "<<x<<"\n";
		return ;
	}
	else{
		cout<<"2\n"<<(u^x)<<" "<<x<<"\n";
	}
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
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}