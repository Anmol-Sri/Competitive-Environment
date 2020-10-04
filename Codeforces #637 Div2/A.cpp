#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	if(n*(a-b)>(c+d) or n*(a+b)<(c-d))
		cout<<"No";
	else {
		cout<<"Yes";
	}
	cout<<"\n";
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