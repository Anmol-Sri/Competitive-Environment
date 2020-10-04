#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	std::vector<pair<int,bool>> arr;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		arr.push_back(make_pair(x,true));
		arr.push_back(make_pair(y,false));
	}
	sort(arr.begin(), arr.end());
	int mx=0;
	int cur=0;
	for(int i=0;i<arr.size();i++){
		cur+=arr[i].second?1:-1;
		mx=max(mx,cur);
	}
	cout<<mx<<"\n";
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