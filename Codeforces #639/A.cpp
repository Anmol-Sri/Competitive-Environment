#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int a;
	int b;
	cin>>a>>b;
	if(a==1 || b==1){
		cout<<"YES\n";
		return;
	}
	else if(a==2 and b==2){
		cout<<"YES\n";
		return;
	}
	else{
		cout<<"NO\n";
	}
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

	while(t--){
		solve();
	}
    return 0;
}