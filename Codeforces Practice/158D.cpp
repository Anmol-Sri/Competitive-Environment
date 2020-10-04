#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int &x:arr)cin>>x;
	int ans=INT_MIN;
	for(int i=3;i<=n;i++){
		if(n%i==0){
			int counter=n/i;
			//cout<<counter<<"\n";
			for(int j=0;j<counter;j++){
				int sum=0;
				//cout<<ans<<"\n";
				for(int k=j;k<n;k+=counter){
					sum+=arr[k];
				}
				//cout<<ans<<"\n";
				ans=max(ans,sum);
			}
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}