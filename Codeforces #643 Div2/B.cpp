#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+1;
void solve(){
	int n;
	cin>>n;
	unordered_map<int,int>mp;
	int num[mxN]={0};
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mp[arr[i]]++;
	}
	sort(arr,arr+n);
	
	ll count=0,ans=0;

	for(int i=0;i<n;i++){
		count++;
		if(arr[i]==count){
			ans++;
			count=0;
		}
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