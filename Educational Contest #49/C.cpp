#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	//int cnt=0;
	std::vector<ll> dup;
	for(ll i=0;i<n-1;i++){
		if(arr[i]==arr[i+1]){
			dup.push_back(arr[i]);
			i++;
		}
	}

	ll a=dup[0];
	ll b=dup[1];
	ll p=(a+b)*(a+b);
	ll s=(a*b);

	for(ll i=0;i<dup.size()-1;i++){
		ll p2=(dup[i]+dup[i+1])*(dup[i]+dup[i+1]);
		ll s2=(dup[i]*dup[i+1]);
		if(s2*p>s*p2){
			a=dup[i];
			b=dup[i+1];
			s=s2;
			p=p2;
		}
	}
	cout<<a<<" "<<a<<" "<<b<<" "<<b<<"\n";
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