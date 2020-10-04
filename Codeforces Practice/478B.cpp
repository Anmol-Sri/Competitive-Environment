#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll calc(ll x){
	return x * (x - 1) / 2;
}

void solve(){
	int n, m;
	cin >> n >> m;
	cout << ((n % m == 0) ? m * calc(n / m) : calc(n / m) * (m - n % m) + calc(n / m + 1) * (n % m)) << " " << calc(n  - m + 1) << "\n";
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
	// cin>>t;

	while(t--){
		solve();
	}

	return 0;
}