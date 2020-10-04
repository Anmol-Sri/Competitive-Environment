#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int x[n], y[n];
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	ll ans = 0, temp = 0;
	map < pair < int, int > , set < int > > mp;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			int ydif = y[i] - y[j];
			int xdif = x[i] - x[j];
			int g = __gcd(xdif, ydif);
			xdif = xdif / g;
			ydif = ydif / g;
			if(ydif < 0){
				ydif = -1 * ydif;
				xdif = -1 * xdif;
			}
			else if(ydif == 0 && xdif < 0){
				ydif = -1 * ydif;
				xdif = -1 * xdif;
			}
			ll intercept = ydif * x[i] - xdif * y[i];
			auto &asd = mp[{ydif, xdif}];
			if(asd.find(intercept) == asd.end()){
				temp++;
				asd.insert(intercept);
				ans += temp - asd.size();
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

	while(t--){
		solve();
	}

	return 0;
}