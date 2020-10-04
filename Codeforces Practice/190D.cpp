#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	map < int, int > mp;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int j = 0;
	ll ans = 0;
	bool ok = false;
	for(int i = 0; i < n; i++){
		if(i != 0){
			mp[arr[i - 1]]--;
			if(mp[arr[i - 1]] == k - 1) ok = false;
		}
		while(!ok && j < n){
			mp[arr[j]]++;
			if(mp[arr[j]] >= k) ok = true;
			j++;
		}
		if(ok) ans += n - j + 1;
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

	while(t--){
		solve();
	}

	return 0;
}