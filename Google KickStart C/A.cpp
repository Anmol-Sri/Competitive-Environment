#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];

	}
	if(k==1){
		int ans=0;
		for(int i=0;i<n;i++){
			if(arr[i]==1){
				ans++;
			}
		}
		cout<<ans<<"\n";
		return ;
	}
	int ans=0;
	bool flag=false;
	int check=k;
	for(int i=0;i<n;i++){
		if(arr[i]==k){
			flag=true;
			check=k;
		}

		if(flag && arr[i]==check){
			//cout<<"same at i="<<i<<endl;
			check--;
		}
		else{
			flag=false;
			check=k;
		}	
		if(check==0){
			//cout<<"at i="<<i<<"\n";
			ans++;
			check=k;
			flag=false;
		}
	}
	cout<<ans<<"\n";

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