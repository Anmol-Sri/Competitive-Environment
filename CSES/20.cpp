#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m;
	cin>>n>>m;
	multiset<int,greater<int>> h;
	int x;
	while(n--){
		cin>>x;
		h.insert(x);
	}
	while(m--){
		cin>>x;
		auto it=h.lower_bound(x);
		if(it==h.end()){
			cout<<"-1\n";
		}
		else{
			cout<<*it<<"\n";
			h.erase(it);
		}
	}
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