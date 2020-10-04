#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;

	int arr[n+1]={0};
	int ans[n+1];
	//memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++) cin>>arr[i],ans[i]=1;

	for(int i=1;i<=n;i++){
		for(int j=i*2;j<=n;j+=i){
			if(arr[i]<arr[j]){
				ans[j]=max(ans[j],1+ans[i]);
			}
		}
	}
	cout<<*max_element(ans+1,ans+n+1)<<"\n";
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