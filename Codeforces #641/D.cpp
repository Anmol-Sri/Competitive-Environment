#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mxN=1e5+10;
int k,n;
int arr[mxN];
void solve(){
	cin>>n>>k;
	bool flag=false;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>k) arr[i]=2;
		else if(arr[i]==k) arr[i]=1,flag=true;
		else arr[i]=0;
	}
	if(!flag){
		cout<<"NO\n";
		return ;
	}
	if(n==1){
		cout<<"YES\n";
		return ;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n and j-i<=2;j++){
			if(arr[i] and arr[j]){
				cout<<"YES\n";
				return ;
			}
		}
	}
	cout<<"NO\n";
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