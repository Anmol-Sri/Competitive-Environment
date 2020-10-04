#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<pair<int,int>> arr(n);
	for(auto &x:arr) cin>>x.second>>x.first;
	sort(arr.begin(), arr.end());
	multiset<int,greater<int>> s;
	/*for(auto x:arr){
		cout<<x.first<<" - "<<x.second<<"\n";
	}*/
	while(k--) s.insert(0);
	int ans=0;
	for(auto x:arr){
		// cout<<" for "<<x.first<<" - "<<x.second<<"\n";
		auto q=s.lower_bound(x.second);
		// cout<<*q<<"\n";
		if(q!=s.end()){
			s.erase(q);
			// cout<<"erase - "<<*q<<" inserting - "<<x.first<<"\n";
			s.insert(x.first);
			ans++;
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
	#endif*/
		
	int t=1;

	while(t--){
		solve();
	}
	return 0;
}