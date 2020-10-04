#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool check2power(ll n){
	if(n==0) return false;
	return (ceil(log2(n))==floor(log2(n)));
}
void solve(){
	ll n;
	cin>>n;
	if(n==1 or n==2 or check2power(n)){
		cout<<"0\n";
		return ;
	}
	if(n%2){
		cout<<(n)/2<<"\n";
		return ;
	}
	for(;n%2==0 and n>1;n=n/2);
	cout<<n/2<<"\n";
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
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}