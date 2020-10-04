#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll l, r;
	cin >> l >> r;
	ll u = 1;
	while(u*10 <= r) u *= 10;
	if(l < u) l = u;
	ll best = (u * 10 - 1) / 2;
	if(best > r) best = r;
	if(best < l) best = l;
	cout << best * (u * 10 - 1 - best) << "\n";
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