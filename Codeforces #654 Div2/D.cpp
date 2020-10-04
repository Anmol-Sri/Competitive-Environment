#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n][n];
	memset(arr,0,sizeof(arr));
	int l=0,g=0;
	for(int i=0;i<k;i++){
		arr[l][(l+g)%n]++;
		l=(l+1)%n;
		if(l==0) g++;
	}
	if(k%n==0){
		cout<<"0\n";
	}
	else{
		cout<<"2\n";
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j];
		}
		cout<<"\n";
	}
	return  ;
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}