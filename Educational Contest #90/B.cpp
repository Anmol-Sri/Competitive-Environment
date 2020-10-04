#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
	string s;
	cin>>s;
	int dif=0;
	int one=0;
	int zero=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			zero++;
		}
		else{
			one++;
		}
	}
	if(one==0 || zero==0){
		cout<<"NET\n";
		return ;
	}
	int temp=min(one,zero);
	if(temp%2==0){
		cout<<"NET\n";
	}
	else{
		cout<<"DA\n";
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