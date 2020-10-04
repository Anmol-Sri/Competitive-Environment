#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,q;
	cin>>n>>q;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];

	}
	ll ans=0;
	while(q--){
		int x,y;
		char ch;
		cin>>ch>>x>>y;
		x--;
		if(ch=='Q'){
			for(int i=x;i<y;i++){
				ans+=arr[i]*(i-x+1)*pow(-1,i-x);
			}
		}
		else{
			arr[x]=y;
		}
	}
	cout<<ans<<"\n";
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
	int i=1;
	while(t--){
		cout<<"Case #"<<i<<": ";
		solve();
		i++;
	}
    return 0;
}