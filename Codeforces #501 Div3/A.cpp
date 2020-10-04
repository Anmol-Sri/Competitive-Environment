#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m;
	cin>>n>>m;
	int arr[m+1];
	memset(arr,0,sizeof arr);
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
			for(int j=x;j<=y;j++){
				arr[j]++;
			}
		
	}
	int count=0;
	vector<int > points;
	for(int i=1;i<=m;i++){
		if(arr[i]==0) {count++; points.push_back(i);}
	}
	if(count==0){
		cout<<"0\n";
		return;
	}
	cout<<count<<"\n";
	for(auto x:points){
		cout<<x<<" ";
	}
	cout<<"\n";
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}