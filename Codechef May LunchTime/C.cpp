#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int a[n],b[n];
	ll x1=0,x2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		if(a[i]==b[i] and x1==x2){
			ans+=a[i];
			x1+=a[i];
			x2+=b[i];
		}
		else{
			x1+=a[i];
			x2+=b[i];
		}
	}
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}