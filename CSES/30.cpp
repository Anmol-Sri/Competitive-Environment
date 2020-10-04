#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n,t;
bool num(ll arr[],ll products){
	ll ans=0;
	for(ll i=0;i<n;i++){
		ans+=(products/arr[i]);
		if(ans>t){
			return false;
		}
	}
	if(ans<t)
		return true;
	return false;
}

void solve(){
	cin>>n>>t;
	ll arr[n];
	for(ll&i:arr) cin>>i;
	if(t==0){
		cout<<"0\n";
		return ;
	}
	// sort(arr,arr+n);
	ll start=1;
	ll end=t*(*max_element(arr,arr+n));
	while(start<end){
		ll mid=(start+end)>>1;
		bool ok=num(arr,mid);		
		if(ok){
			start=mid+1;
		}
		else{
			end=mid;
		}
	}
	cout<<end<<"\n";
	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

/*    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}