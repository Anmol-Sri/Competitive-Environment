#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n+1];
	int ans[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		ans[arr[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
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