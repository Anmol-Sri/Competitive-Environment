#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n+1];
	int l1=(int)sqrt(n);
	int start=n;
	for(int i=1;i<=n;i+=l1){
		for(int j=min(i+l1-1,n);j>=i;arr[j--]=start--);
	}

	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}