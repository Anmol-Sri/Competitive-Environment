#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m;
	cin>>n>>m;
	if(m&1){
		cout<<((m-1)/2)*n+(n+1)/2<<"\n";
	}
	else{
		cout<<(m/2)*n<<"\n";
	}
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