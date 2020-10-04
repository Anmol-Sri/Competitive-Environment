#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool desc(std::vector<ll> vec){
	return is_sorted(vec.begin(),vec.end(),greater<ll>());
}
bool asc(std::vector<ll> vec){
	return is_sorted(vec.begin(),vec.end());
}
void solve(){
	int n;
	cin>>n;
	std::vector<ll> arr(n);

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll dp[n][n]; 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=arr[j]-arr[i];
		}
	}

	if(asc(arr)){
		cout<<"asc";
	}
	else if(desc(arr)){
		cout<<"desc";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}