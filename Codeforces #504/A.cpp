#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;


	if(s==t){
		cout<<"YES\n";
		return;
	}
	if(n>m+1){
		cout<<"NO\n";
		return;
	}
	int pos=-1;
	for(int i=0;i<n;i++){
		if(s[i]=='*'){
			pos=i;
			break;
		}
		else if(s[i]!=t[i]){
			cout<<"NO\n";
			return;
		}
	}
	if(pos==-1){
		cout<<"NO\n";
		return;
	}
	int p2=m-1;
	for(int i=n-1;i>=0;i--,p2--){
		if(s[i]=='*'){
			break;
		}
		if(s[i]!=t[p2]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}