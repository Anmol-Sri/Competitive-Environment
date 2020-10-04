#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	string b1,b2;
	cin>>b1>>b2;
	int both_one=0,down_zero=0,both_zero=0,up_zero=0;
	ll ans=0;
	for(int i=0;i<n;i++){
		if(b1[i]=='0' and b2[i]=='0'){
			both_zero++;
		}
		else if(b1[i]=='1' and b2[i]=='1'){
			both_one++;
		}
		else if(b1[i]=='0' and b2[i]=='1'){
			up_zero++;
		}
		else if(b1[i]=='1' and b2[i]=='0'){
			down_zero++;
		}
	}
	ans=both_zero*both_one+both_zero*down_zero+up_zero*down_zero;
	cout<<ans<<"\n";

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
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}