#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x>k){
			ans+=x-k;
		}
	}
	cout<<ans<<"\n";
	return;
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