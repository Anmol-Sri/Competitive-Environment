#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll power(ll n,ll m){
	if(m==0) return 1;
	ll val=power(n,m/2);
	if(m%2==0) return (val*val); else return ((val*val)*n);
}

ll powermod(ll n,ll m,ll MOD){
	if(m==0) return 1;
	ll val=powermod(n,m/2,MOD);
	val %= MOD;
	if(m%2==0) return (val*val) % MOD; else return (((val*val) % MOD) * n) % MOD;
}

void solve(){
	ll  x1, x2, y1, y2, z1, z2;
	cin >> x1 >> y1 >> z1;
	cin >> x2 >> y2 >> z2;
	ll ans = 0;
	ll rem = 0;

	// if(x1 < x2) x2 = x2 - x1, x1 = 0; else x1 = x1 - x2, x2 = 0;
	// if(y1 < y2) y2 = y2 - y1, y1 = 0; else y1 = y1 - y2, y2 = 0;
	// if(z1 < z2) z2 = z2 - z1, z1 = 0; else z1 = z1 - z2, z2 = 0;

	// if(z1 > z2){
	// 	if(y2){
	// 		ll temp = min(z1, y2)
	// 		ans = 2 * temp;
	// 		z1 = z1 - temp;
	// 		y2 = y2 - temp;
	// 	}
	// }
	// else{
	// 	if(x1){

	// 	}
	// }

	if(z1 < y2){
		ans = 2 * z1;
		y2 = y2 - z1;
		z1 = 0;
	}
	else{
		ans = 2 * y2;
		z1 = z1 - y2;
		y2 = 0;
	}
	if(y1 < y2){
		y2 = y2 - y1;
		y1 = 0;
	}
	else{
		y1 = y1 - y2;
		y2 = 0;
	}
	if(z2 < x1){
		x1 = x1 - z2;
		z2 = 0;
	}
	else{
		z2 = z2 - x1;
		x1 = 0;
	}
	if(z2){
		ll temp = min(z2, z1);
		z2 -= temp;
		z1 -= temp;
		if(z2){
			if(y1){
				temp = min(y1, z2);
				ans -= 2 * temp;
				y1 -= temp;
				z2 -= temp;
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
	cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}