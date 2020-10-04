#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>> arr;
	arr.emplace_back(0,0);
	arr.emplace_back(1,0);
	arr.emplace_back(0,1);
	// arr.emplace_back(1,1);
	// arr.emplace_back(2,1);
	// arr.emplace_back(1,2);
	int i;
	for(i=1;i<=n;i++){
		arr.emplace_back(i,i);
		arr.emplace_back(i+1,i);
		arr.emplace_back(i,i+1);
	}
	arr.emplace_back(i,i);
	cout<<arr.size()<<"\n";
	for(auto x:arr){
		cout<<x.first<<" "<<x.second<<"\n";
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
		
	int t=1;
	// cin>>t;

	while(t--){
		solve();
	}

	return 0;
}