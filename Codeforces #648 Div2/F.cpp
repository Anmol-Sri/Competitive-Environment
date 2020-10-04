#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int &i:a)cin>>i;
	for(int &i:b)cin>>i;
	if(n&1 && a[n/2]!=b[n/2]) {
		cout<<"No\n";
		return ;
	}
	map<pair<int,int>,int> mp;
	for(int i=0;i<n/2;i++) mp[make_pair(min(a[i],a[n-1-i]),max(a[i],a[n-1-i]))]++;
	for(int i=0;i<n/2;i++){
		if(mp[make_pair(min(b[i],b[n-1-i]),max(b[i],b[n-1-i]))]<=0){
			cout<<"No\n";
			return;
		}
		else{
			mp[make_pair(min(b[i],b[n-1-i]),max(b[i],b[n-1-i]))]--;
		}
	}
	cout<<"Yes\n";
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