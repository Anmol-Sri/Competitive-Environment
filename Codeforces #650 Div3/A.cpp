#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	string s;
	cin>>s;
	int sz=s.size();
	for(int i=0;i<sz;i++){
		if(!(i&1)){
			cout<<s[i];
		}
	}

	cout<<s[sz-1]<<"\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}