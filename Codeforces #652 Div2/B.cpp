#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	string start="";
	string end="";
	string mid="";
	int zero=0,one=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			zero++;
		}
		else{
			break;
		}
	}
	for(int j=n-1;j>=0;j--){
		if(s[j]=='1'){
			one++;
		}
		else{
			break;
		}
	}
	bool ok=false;
	if(n>zero+one){
		ok=true;
	}
	if(ok){
		string ans="";
		for(int i=0;i<zero+1;i++){
			ans+="0";
		}
		for(int i=0;i<one;i++){
			ans+="1";
		}
		cout<<ans<<"\n";
	}
	else{
		string ans="";
		for(int i=0;i<zero;i++){
			ans+="0";
		}
		for(int i=0;i<one;i++){
			ans+="1";
		}
		cout<<ans<<"\n";
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