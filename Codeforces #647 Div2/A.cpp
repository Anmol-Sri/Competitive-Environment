#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll a,b;
ll ans;
void solve(){
	ans=0;
	cin>>a>>b;
	if(a<=b){
		for(;a<b;){
			a*=2;
			ans++;
		}
		if(a==b){
			ans = ((ans%3)%2) + ((ans%3)/2) + (ans/3);
	        cout<<ans<<"\n";
	        return;
		}
		else{
			cout<<"-1\n";
			return ;
		}
	}
	else{
		while(a>b){
			if(a%2==0){
				a/=2;
				ans++;
			}
			else{
				break;
			}
		}
		if(a==b){
			ans = ((ans%3)%2) + ((ans%3)/2) + (ans/3);
	        cout<<ans<<"\n";
	        return;
		}
		else{
			cout<<"-1\n";
			return ;
		}
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}