#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	ll n;
	cin>>n;
	if(n==1){
		cout<<"1\n";
		return;
	}
	else cout<<n<<"\n";
	return;
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