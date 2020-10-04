#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int ll INF=1e18;
const int mxN=1e6+1;
unordered_map<pair<int,int>,int> mp;
void pre_calc(){
	for(int i=0;i<mxN;i++){
		ll sum=0;
		for()
	}
}
void solve(){
	ll n,k;
	cin>>n>>k;
	if(mp.find({n,k})!=mp.end()){
		cout<<mp[{n,k}]<<"\n";
	}
	else{
		cout<<"-1\n";
	}
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
		clock_t tStart = clock();
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
	#ifndef ONLINE_JUDGE
		cerr<<fixed<<setprecision(10)<<"Time Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
	#endif

	return 0;
}