#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	std::vector<pair<int,int>> v(n);
	for(auto &i:v) cin>>i.first>>i.second;
	sort(v.begin(), v.end());
	ll ans=0;
	ll time_passed=0;
	for(auto i:v) time_passed+=i.first,ans+=(i.second-time_passed);
	cout<<ans<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

/*    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}