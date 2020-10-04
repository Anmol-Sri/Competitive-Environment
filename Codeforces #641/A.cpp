#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;
	int div;
	int j;
	if(n%2==0){
		cout<<n+(2*k)<<"\n";
		return ;
	}
	int i;
	bool flag=false;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0){
			flag=true;
			break;
		}
	}
	if(!flag){
		n=n+n;

	}
	else{
		n=n+i;
	}

	cout<<n+(2*(k-1))<<"\n";
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