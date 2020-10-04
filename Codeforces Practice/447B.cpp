#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	ll val[26];
	for(int i=0;i<26;i++){
		cin>>val[i];
	}
	ll ans=0;
	for(int i=0;i<s.size();i++){
		ans=ans+((i+1)*val[s[i]-'a']);
	}
	int ma=*max_element(val,val+26);
	for(int i=s.size()+1;i<=s.size()+k;i++){
		ans=ans+(i*ma);
	}

	cout<<ans<<"\n";
	return ;

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