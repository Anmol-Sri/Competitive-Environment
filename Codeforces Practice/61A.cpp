#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	string a,b,ans="";
	cin>>a>>b;

	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) ans+='1';
		else ans+='0';
	}
	cout<<ans;

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