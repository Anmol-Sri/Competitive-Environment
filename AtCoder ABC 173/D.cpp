#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n;
	cin >> n;
	ll arr[n];
	for( ll i = 0; i < n; i++){
		cin >> arr[i];
	}
	ll ans = 0;
	sort(arr, arr + n,greater<int>());
	vector< ll > qwe;
	for( int i = 0; i < n; i++){
		qwe.push_back(arr[i]);
		if(i) qwe.push_back(arr[i]);
	}
	for( int i = 0; i < n -1; i++){
		ans += qwe[i];
	}
	cout << ans <<"\n";
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