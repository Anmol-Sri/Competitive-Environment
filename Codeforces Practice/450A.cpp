#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int ans=-1;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		ans=max( ans, (int)ceil((arr[i] + m - 1)/m));
	}
	int res=0;
	for(int i = 0; i< n; i++){
		int temp =(int)ceil((arr[i] + m -1)/m);
		if(ans == temp){
			res =i+1;
		}
	}
	cout<< res <<"\n";
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
		
	int t =1;

	while(t--){
		solve();
	}

	return 0;
}