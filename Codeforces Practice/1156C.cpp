#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, z;
	cin >> n >> z;
	int arr[n];
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int l = 0;
	int r = n / 2 + 1;
	while(l + 1 < r){
		int m = (l + r) / 2;
		bool good = true;
		for(int i = 0; i < m; i++){
			good &= (arr[n - m + i] - arr[i] >= z);
		}
		if(good) l = m;
		else r = m ;
	}
	cout << l << "\n";
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