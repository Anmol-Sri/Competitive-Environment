#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	std::vector<int> ans;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		auto it=upper_bound(ans.begin(), ans.end(),x);
		if(it==ans.end()){
			ans.push_back(x);
		}
		else{
			*it=x;
		}
	}
	cout<<ans.size()<<"\n";
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