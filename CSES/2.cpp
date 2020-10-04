#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	bool used[n+1]={false};
	used[0]=true;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		used[x]=true;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			cout<<i<<"\n";
			break;
		}
	}
	return;
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