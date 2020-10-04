#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n,k,s;
	cin>>n>>k>>s;
	ll arr[k];	
	if(s<k){
		cout<<"NO\n";
		return;
	}
	if(s>k*(n-1)){
		cout<<"NO\n";
		return;
	}
	ll travelled=1;
	cout<<"YES\n";
	for(;k>0;){
		ll calc=min(n-1,s-(k-1));
		if(travelled-calc>0){
			travelled=travelled-calc;
		}
		else{
			travelled=travelled+calc;
		}
		s-=calc;
		k--;
		cout<<travelled<<" ";
	}
	cout<<endl;

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
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}