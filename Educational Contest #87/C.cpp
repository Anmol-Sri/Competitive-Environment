#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI 3.14159265
const int inf = 1012345678;
const double pi = acos(-1.0);

void solve(){
	cout<<std::setprecision(20);
	int n;
	cin>>n;
	float ans;
	if(n&1)
	 	ans=cos(pi/(4*n))/sin(pi/(2*n));
	 else 
	 	ans=1.0/tan(pi/(2*n));
	cout<<ans<<"\n";
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