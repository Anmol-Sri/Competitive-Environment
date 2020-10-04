#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	vector < int > arr(n + 1, 0);
	int store = INT_MAX, ans = -1;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	store = INT_MAX;
	for(int i = k; i <= n; i++){
		if(store > arr[i] - arr[i - k]){
			store = arr[i] -  arr[i - k];
			ans = i - k + 1;
		}
	}
	cout << ans << "\n";
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}