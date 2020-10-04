#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	string s;
	cin>>s;
	int len=s.size();
	int ans=0;
	int cnt=0;
	bool x=false;
	bool y=false;
	for(int i=0;i<len;i++){
		if(s[i]=='x'){
			x=true;
		}
		else{
			y=true;
		}
		if(x && y){
			ans++;
			x=false;
			y=false;
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

	while(t--){
		solve();
	}
    return 0;
}