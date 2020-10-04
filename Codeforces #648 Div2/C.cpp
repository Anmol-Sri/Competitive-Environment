#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+1;
void solve(){
	int qwe[mxN]={0};
	map<int,int> mp;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int asd[n];
	for(int i=0;i<n;i++){
		cin>>asd[i];
		qwe[asd[i]]=i;
	}
	for(int i=0;i<n;i++){
		if(qwe[arr[i]]<=i){
			mp[i-qwe[arr[i]]]++;
			
		}
		else{
			mp[n-qwe[arr[i]]+i]++;
		}
	}
	int ans=0;
	for(auto x:mp){
		ans=max(ans,x.second);
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
	while(t--){
		solve();
	}
    return 0;
}