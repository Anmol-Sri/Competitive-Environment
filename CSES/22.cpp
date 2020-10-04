#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>> arr;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		arr.push_back(make_pair(y,x));
	}
	sort(arr.begin(), arr.end());
	int prev=-1;
	int ans=0;
	for(auto x:arr){
		if(x.second>=prev){
			prev=x.first;
			ans++;
		}
	}
	cout<<ans<<"\n";
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