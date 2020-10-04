#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mxN=45001; 
ll arr[mxN];
void precalc(){
	arr[0]=0;
	arr[1]=2;
	for(int i=2;i<mxN;i++){
		arr[i]=arr[i-1]+(i*2)+(i-1);
	}
}
void solve(){
	int n;
	cin>>n;
	if(n==1){
		cout<<"0\n";
		return;
	}
	int i=1;
	for( i=1;i<mxN;i++){
		//cout<<arr[i]<<" ";
		if(arr[i]==n){
			cout<<1<<"\n";
			return;
		}
		else if(arr[i]>n){
			break;
		}
	}
	i--;
	int ans=0;
	
	while(n>1 and i>=1){
		ans+=n/arr[i];
		n=n%arr[i];
		if(n<=1){
			break;
		}

		i--;
	}
	cout<<ans<<"\n";
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
	precalc();
	while(t--){
		solve();
	}
    return 0;
}