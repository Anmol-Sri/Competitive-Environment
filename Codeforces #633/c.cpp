#include <bits/stdc++.h>
using namespace std;
#define ll long int

const int mxN=100005;
int arr[mxN];

int calc_log(int n){
	int ans;
	for(ans=0;(1LL<<ans)<=n;ans++);
	return ans;
}

void solve(){
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int fir=arr[0];
	int ans=0;

	for(int i=1;i<n;i++){
		if(arr[i]<fir){
			ans=max(ans,calc_log(fir-arr[i]));
		}
		else{
			fir=arr[i];
		}
	}
	cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}