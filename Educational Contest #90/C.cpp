#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define F first
#define S second

bool cmp(pair<int,int> a,pair<int,int> b){
	return (a.S<b.S);
}

void solve(){
	string s;
	cin>>s;
	std::vector<pair<int,int>> arr;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='+') ans++;
		else ans--;
		if(ans<0){
			arr.push_back({ans,i+1});
		}
	}
	int len=s.size();
	if(arr.size()==0){
		cout<<len<<"\n";
		return ;
	}
	sort(arr.begin(), arr.end(),cmp);
	ll res=0;
	ll temp=0;
	for(auto x:arr){
		ll val=x.S * (abs(x.F)-temp);
		if(abs(x.F)>temp){
			res+=val;
			temp=abs(x.F);
		}
	}
	res+=len;
	cout<<res<<"\n";
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