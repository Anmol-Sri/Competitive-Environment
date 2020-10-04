#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	string s;
	cin>>s;
	int count=1;
	char prev=s[0];
	for(int i=1;i<s.size();i++){
		char ch=s[i];
		if(ch==prev){
			count++;
		}
		else{
			prev=ch;
			count=1;
		}
		if(count>=7){
			cout<<"YES\n";
			return ;
		}
	}
	cout<<"NO\n";
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