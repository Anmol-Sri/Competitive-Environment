#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;

	if(2*n>k){
		cout<<"NO\n";
		return ;
	}

	cout<<"YES\n";
	for(int i=0;i<n-1;i++){
		cout<<"2 ";
		k=k-2;
	}
	cout<<k<<"\n";
	cout<<1<<"\n";
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}