#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=5005;
int all[mxN]={0};
void solve(){
	int n;
	cin>>n;
	set<int> arr;
	int great=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.insert(x);
		all[x]++;
		great=max(great,x);
		//lim[i]=2*arr[i];
	}
	int best=INT_MAX;
	for(auto i:arr){
		int remove=0;
		for(int j=1;j<5001;j++){
			if(j<i || j>2*i)
				remove+=all[j];
		}
		//cout<<i<<" - "<<remove<<"\n";
		best=min(best,remove);
	}

	cout<<best<<"\n";
	return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    //#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	//#endif
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}