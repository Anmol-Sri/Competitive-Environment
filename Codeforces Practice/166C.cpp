#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,x;
	cin>>n>>x;
	int arr[n+1];
	bool flag=false;
	int small=0,large=0,eq=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]<x){
			small++;
		}
		else if(arr[i]>x){
			large++;
		}
		else eq++;
	}
	//sort(arr+1,arr+n+1);

	//for(int i:arr) cout<<i<<" ";
	//cout<<"small = "<<small<<" large = "<<large<<"\n";
	int ans=0;
	if(eq==0){
		ans=abs(small-large);
		if(small>=large) ans++;
		cout<<ans<<"\n";
		return ;
	}

	int med=(n+1)>>1;
	//cout<<"med = "<<med<<"\n";
	if(med>small and med<=small+eq){
		ans=0;
	}
	else{
		if(small >= eq+large){
			ans=small-eq-large+1;
		}
		else{
			ans=large-small-eq;
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}