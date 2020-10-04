#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	int x,m,n;
	cin>>x>>n>>m;
	if((x-(m*10))<=0){
		cout<<"YES\n";
		return;
	}
	for(int i=1;i<=n;i++){
		x=((int)floor(x/2))+10;
		if(x<=0){
			cout<<"YES\n";
			return;
		}
	}
	if((x-(m*10))>0){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
	}
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