#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll a,b;
	cin>>a>>b;
	int arr[a][b];
	bool r[a]={false};
	bool c[b]={false};

	for(ll i=0;i<a;i++){
		for(ll j=0;j<b;j++){
			cin>>arr[i][j];
			if(arr[i][j]){
				r[i]=true;
				c[j]=true;
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<a;i++){
		for(ll j=0;j<b;j++){
			if(!r[i] and !c[j]){
				ans++;
				r[i]=true;
				c[j]=true;
			}
		}
	}
	if(ans%2==0){
		cout<<"Vivek\n";
	}
	else{
		cout<<"Ashish\n";
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