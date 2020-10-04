#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	int even=0,odd=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i%2!=arr[i]%2){
			if(arr[i]%2==0){
				even++;
			}
			else{
				odd++;
			}
		}
	}
	if(even!=odd){
		cout<<"-1\n";
		return ;
	}
	else{
		cout<<even<<"\n";
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