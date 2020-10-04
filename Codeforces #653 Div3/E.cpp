#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	ll items=0;
	vector<array<ll,4>> arr;
	for(int i=0;i<n;i++){
		ll t,a,b;
		cin>>t>>a>>b;
		arr.push_back({t,a,b,0});
	}
	sort(arr.begin(), arr.end());
	ll alice=0,bob=0;
	for(int i=0;i<n;i++){
		if(arr[i][1]==1 && arr[i][2]==1){
			// cout<<arr[i][0]<<"\n";
			items++;
			ans+=arr[i][0];
			arr[i][3]=1;
		}
		if(items==k){
			cout<<ans<<"\n";
			return ;
		}
	}
	alice=bob=items;
	for(int i=0;i<n;i++){
		if(arr[i][3]==0){
			if(arr[i][1]==1 && alice<k){
				alice++;
				ans+=arr[i][0];
			}
			else if(arr[i][2]==1 && bob<k){
				bob++;
				ans+=arr[i][0];
			}			
		}
		if(alice>=k && bob>=k){
			break;
		}
	}
	ll mn=ans;
	// cout<<mn<<"\n";
/*	for(int i=0;i<n;i++){
		cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<"\n";	
	}*/
	alice=bob=0;
	ans=0;
	for(int i=0;i<n;i++){
		if(arr[i][1]==1 && arr[i][2]==1 && (alice<k || bob<k)){
			alice++;
			bob++;
			ans+=arr[i][0];
		}
		else if(arr[i][1]==1 && alice<k){
			alice++;
			ans+=arr[i][0];
		}
		else if(arr[i][2]==1 && bob<k){
			bob++;
			ans+=arr[i][0];
		}
		if(alice>=k && bob>=k){
			break;
		}
	}
	if(alice>=k && bob>=k){
		cout<<min(ans,mn)<<"\n";
	}
	else{
		cout<<"-1\n";
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
	#endif
		
	int t=1;

	while(t--){
		solve();
	}

	return 0;
}