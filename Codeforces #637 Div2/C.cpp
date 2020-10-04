#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int i=0;

	for(;i<n-1;){
		if(arr[i+1]<arr[i])
			i++;
		else if(arr[i]+1==arr[i+1]){
			i++;
		}
		else{
			break;
		}
	}

	if(i==n-1){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
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