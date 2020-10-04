#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}	

	for(int i=n-2;i>=0;i--){
		int j=0;
		while(j<s[i].size() and j<s[i+1].size() and s[i][j]==s[i+1][j]) j++;
		if(j==s[i+1].size() and j<s[i].size() or s[i][j]>s[i+1][j]) s[i].resize(j);
	}
	for(int i=0;i<n;i++){
		cout<<s[i]<<"\n";
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}