#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	ll sum=0;
	for(int i=0;i<n;++i){
		cin>>arr[i];
		sum+=arr[i];
	}
	if(sum%3!=0){
		cout<<"0\n";
		return ;
	}
	ll ans=0;
	ll cnt=0;
	ll first=sum/3;
	ll sec=2*first;
	sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(sum==sec and i<n-1){
			ans+=cnt;
		}
		if(sum==first) cnt++;
	}

	cout<<ans<<"\n";
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}