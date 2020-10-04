#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mxN=2e5+1;
void solve(){
	ll n,a,b;
	cin>>n>>a>>b;
	ll pref[n+1];
	for(int i=0;i<n;i++){
		cin>>pref[i+1];
		pref[i+1]+=pref[i];
	}
	ll ans=-1e18;
	set<pair<ll,ll>>s;
	for(int i=0;i<=n;i++){
		if(i>=a){
			s.insert({pref[i-a],i-a});
		}
		if(!s.empty()){
			ans=max(pref[i]-(*s.begin()).first,ans);
		}
		if(i>=b){
			s.erase({pref[i-b],i-b});
		}
	}
	cout<<ans<<"\n";
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

/*	#ifndef ONLINE_JUDGE
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