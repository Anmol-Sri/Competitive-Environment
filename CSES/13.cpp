#include <bits/stdc++.h>
using namespace std;
#define ll long long int
set<string> se;
void recur(string s,int l,int r){
	if(l==r){
		se.insert(s);
	}
	else{
		for(int i=l;i<=r;i++){
			swap(s[l],s[i]);
			recur(s,l+1,r);
			swap(s[l],s[i]);
		}
	}
}

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	recur(s,0,n-1);
	cout<<se.size()<<"\n";
	for(auto i:se) cout<<i<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
/*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
*/		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}