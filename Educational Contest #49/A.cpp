#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool cmp(char a,char b){
	if(a==b){
		return true;
	}
	if(a+1==b-1){
		return true;
	}
	if(a-1==b+1){
		return true;
	}
	return false;
}

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;

	for(int i=0;i<=n/2;i++){
		if(cmp(s[i],s[n-i-1])){
			continue;
		}
		else{
			cout<<"NO\n";
			return ;
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}