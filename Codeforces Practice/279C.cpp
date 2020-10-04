#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define debug(a) for(auto x : a) cout << x << " " ; cout << "\n";

void solve(){
	int n, m;
	cin >> n >> m;
	int arr[n + 2] = {0};
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	int dec[n + 2] = {0}, inc[n + 2] = {0};
	for(int i = 1; i <= n; i++) if(arr[i] <= arr[i - 1]) dec[i] = dec[i - 1] + 1; else dec[i] = 1;
	for(int i = n; i >= 1; i--) if(arr[i] <= arr[i + 1]) inc[i] = inc[i + 1] + 1; else inc[i] = 1;
	// debug(dec);
	// debug(inc);
	for(int i = 1; i <= m; i++){
		int lq, rq; cin >> lq >> rq;
		if(dec[rq] + inc[lq] >= rq - lq + 1) cout << "Yes\n"; else cout << "No\n";
	}
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