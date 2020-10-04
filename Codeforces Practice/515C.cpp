#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string pre[10]={"","","2","3","223","5","53","7","7222","7332"};
void solve(){
	int n;
	string s;
	cin>>n>>s;
	string ans="";
	for(char i:s) ans+=pre[i-'0'];
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}