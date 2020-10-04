#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	cout<<(x2-x1)*(y2-y1)+1<<"\n";
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