#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n;
	cin>>n;
	cout<<n<<" ";
	while(n!=1){
		if(n&1){
			n=n*3+1;
		}
		else{
			n=n/2;
		}
		cout<<n<<" ";
	}
	return;
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