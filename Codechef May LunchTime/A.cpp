#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	int cont=0;
	std::vector<int> pos;
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==1){
			pos.push_back(i);
		}
	}
	if(pos.size()==0){
		cout<<"0\n";
		return;
	}
	if(pos.size()==1){
		cout<<"-1\n";
		return;
	}
	bool last=false;
	int last_val=0;
	if(arr[n-1]==1)
	{
		last=true;
		int i;
		for(i=0;i<n;i++){
			if(arr[i]==1){
				break;
			}
		}
		int l1=i;
		for(i=n-2;i>=0;i--){
			if(arr[i]==1){
				break;
			}
		}
		int l2=i-1;
		last_val=min(ll,l2);
	}
	ll ans=0;
	for(int i=0;i<pos.size();i++){
		if()
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}