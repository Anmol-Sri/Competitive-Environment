#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	ll n;
	cin>>n;
	if(n<=2){
		cout<<"0\n";
	}
	else if(n%2==0){
		cout<<n/2-1<<"\n";
	}
	else{
		cout<<n/2<<"\n";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}