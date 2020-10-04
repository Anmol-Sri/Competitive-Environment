#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int arr[5];
	ll sum=0;
	for(int i=0;i<5;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	ll p;
	cin>>p;
	ll pro=sum*p;
	if(pro>120){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
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