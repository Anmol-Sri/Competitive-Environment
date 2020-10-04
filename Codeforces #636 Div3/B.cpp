#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(int n) 
{ 
   if(n==0) 
   return false; 
  
   return (ceil(log2(n)) == floor(log2(n))); 
}

void solve(){

	int n;
	cin>>n;
	n=n/2;
	if(n%2==1){
		cout<<"NO\n";
		return;
	}
	else{
		cout<<"YES\n";

		ll sum=2;
		for(int i=0;i<n;i++){
			cout<<sum<<" ";
			sum+=2;
		}
		ll odd=1;
		for(int i=0;i<n-1;i++){
			cout<<odd<<" ";
			odd+=2;
		}
		cout<<odd+n<<"\n";
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