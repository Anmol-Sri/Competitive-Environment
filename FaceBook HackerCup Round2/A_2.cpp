#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll mxN = 1e6 + 10;

ll n;
ll k;
ll s[mxN];
ll x[mxN];
ll y[mxN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("capastaty_input (1).txt","r",stdin);
		freopen("outputA_2.txt","w",stdout);	
	#endif
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n >> k;
		for(int i = 0; i < k; i++) cin >> s[i];
		ll as, bs, cs, ds;
		cin >> as >> bs >> cs >> ds;
		for(int i = k;i < n; i++) s[i] = ((as * s[i-2] % ds + bs * s[i-1] % ds ) % ds + cs) % ds;
		for(int i = 0; i < k ; i++) cin >> x[i];
		ll ax, bx, cx, dx;
		cin >> ax >> bx >> cx>> dx;
		for(int i = k; i < n; i++) x[i] = ((ax * x[i-2] % dx + bx * x[i-1] % dx ) % dx+ cx) % dx;
		for(int i = 0; i < k ; i++) cin >> y[i];
		ll ay, by, cy, dy;
		cin >> ay >> by >> cy >> dy;
		for(int i = k; i < n; i++) y[i] = ((ay * y[i-2] % dy + by * y[i-1] % dy) % dy + cy) % dy;
		ll qwe = 0;
		ll to_remove = 0;
		ll to_add = 0;
		ll asd = 0;
		ll res = 0;
		for(int i = 0; i < n; i++){
			if(s[i] > x[i] + y[i]){
				qwe += s[i] - x[i] - y[i];
				to_remove += (s[i] - x[i]);
			}
			else if(s[i] < x[i]){
				asd += x[i] - s[i];
				to_add += x[i] + y[i] - s[i];
			}
			else{
				to_add += x[i] + y[i] - s[i];
				to_remove += s[i] - x[i];
			}
		}
		if(asd > to_remove || qwe > to_add) res = -1;
		else res = max(qwe, asd);
		cout << "Case #" << i << ": " << res << endl;
	}

	return 0;
}