#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n,x;
	cin>>n>>x;
	ll arr[n];
	ll sum=0;
	int wealthy=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		if(arr[i]>=x){
			wealthy++;
		}
	}
	sort(arr,arr+n,greater<int>());
	ll count=0;
	ll s=0;
	while(count<n and s+arr[count]>=(count+1)*x){
		s+=arr[count];
		count++;

	}
	cout<<count<<"\n";
	return;
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