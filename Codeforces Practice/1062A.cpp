#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n + 2];
	arr[0] = 0;
	arr[n + 1] = 1001;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 0;i <= n+1; i++){
		for (int j = i+2 ;j <= n+1; j++){
			if ( arr[j] - arr[i] == j - i){
				ans=max(ans,j-i-1);
			}
		}
	}
	cout << ans << "\n";
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
		
	int t = 1;

	while( t-- ){
		solve();
	}

	return 0;
}