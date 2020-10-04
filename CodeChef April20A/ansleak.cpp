#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	int arr[n][k];
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cin>>arr[i][j];
		}
	}
	int ans[n];
	for(int i=0;i<n;i++){
		ans[i]=rand()%m+1;
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}