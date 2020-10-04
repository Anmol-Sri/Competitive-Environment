#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> arr[3005];
void solve(){
	int n,m;
	cin>>n>>m;	
	for(int i=0;i<n;i++){
		int p,c;
		cin>>p>>c;
		p--;
		arr[p].push_back(c);
	}
	for(int i=0;i<m;i++){
		sort(arr[i].begin(),arr[i].end());
	}
	ll best=LLONG_MAX;

	for(int votes=1;votes<=n;votes++){
		ll cost=0;
		int needed=votes-(int)arr[0].size();
		vector<int> remaining;

		for(int p=1;p<m;p++){
			int start=max((int)arr[p].size()-(votes-1),0);
			for(int i=0;i<start;i++){
				cost+=arr[p][i];
				needed--;
			}
			for(int i=start;i<(int)arr[p].size();i++){
				remaining.push_back(arr[p][i]);
			}
		}
		if(needed>0){
			nth_element(remaining.begin(),remaining.begin()+needed, remaining.end());

			for(int i=0;i<needed;i++){
				cost+=remaining[i];
			}
		}
		best=min(best,cost);
	}
	cout<<best<<"\n";
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