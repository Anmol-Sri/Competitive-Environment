#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int precalc[n];
	memset(precalc,0,sizeof(precalc));
	int ans=-1;
	int la=0;
	for(int i=1;i<n-1;i++){
		if(arr[i-1]<arr[i] and arr[i]>arr[i+1]){
			precalc[i]=1;
		}
	}

	int count=0;
	for(int i=1;i<k-1;i++){
		if(precalc[i])
			count++;

	}

	ans=count;

	for(int i=k;i<n;i++){
		if(precalc[i-k+1]==1){
			count--;
		}
		if(precalc[i-1]) count++;
		if(count>ans){
			ans=count;
			la=i-k+1;
		}
	}
	cout<<ans+1<<" "<<la+1<<"\n";


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