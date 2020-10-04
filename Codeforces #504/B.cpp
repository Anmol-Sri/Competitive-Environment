#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    long long n,k;
    cin>>n>>k;
    if(n>=k) cout<<(k-1)/2<<endl;
     else if (n*2>k) cout<<n-k/2<<endl;
     else cout<<0<<endl;
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
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}