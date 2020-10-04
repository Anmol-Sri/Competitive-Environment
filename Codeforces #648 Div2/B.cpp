#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	int type[n];
	bool one=false;
	bool zero=false;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cin>>type[i];
		if(type[i]==0) zero=true;
		else{
			one=true;
		}
	}
	if(one && zero)
		cout<<"Yes\n";
	else if(is_sorted(arr,arr+n)){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}