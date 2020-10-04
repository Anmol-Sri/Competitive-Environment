#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
	ll a,b,c;
	cin>>a>>b>>c;
	bool one=false;
	bool two=false;
	ll a1=-1,a2=-1;
	/*for(int i=1;i<=1e9;i++){
		ll sec_price=0;
		if(i<=b){
			sec_price=c;
		}
		else if(i%b==0){
			sec_price=(i/b)*c;
		}
		else{
			sec_price=c*((i/b)+1);
		}
		// cout<<sec_price<<"\n";
		if(sec_price<i*a){
			two=true;
			a2=i;
		}
		else if(i*a<sec_price){
			one=true;
			a1=i;
		}
		if(one && two){
			break;
		}
	}*/

	if(a<c){
		if(a*b<=c){
			cout<<"1 -1\n";
		}
		else{
			cout<<"1 "<<b<<"\n";
		}
		return ;
	}
	else if(a==c){
		cout<<"-1 "<<b<<"\n";
		return ;
	}
	else{
		cout<<"-1 1\n";
	}
	// cout<<a1<<" "<<a2<<"\n";
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