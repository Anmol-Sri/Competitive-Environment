#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	string s;
	cin>>s;
	ll ans1=0,ans2=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			ans1++;
		}
		else{
			ans2++;
		}
	}
	if(ans1==0 || ans2==0){
		cout<<s<<"\n";
		return;
	}
	else{
		string ans;
		for(int i=0;i<s.size();i++){
			ans+='1';
			ans+='0';
		}
		cout<<ans<<"\n";
		return;
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