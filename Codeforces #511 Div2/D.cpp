#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	ll small = min(n, m);
	ll large = max(n, m);
	ll ans = 0;
	if(small == 1){
		ll num = large / 6;
		ll rem = m % 6 - 3;
		ans = 6 * num + 2 * max(rem, 0LL);
		cout << ans << "\n";
		return ;
	}
	if(small == 2){
		if(large == 2) ans = 0;
		else if(large == 3) ans = 4;
		else if(large == 7) ans = 12;
		else ans = 2 * large;
		cout << ans << "\n";
		return ;
	}
	if(n>m)swap(n,m);
	ans = (small*large)/2;
	cout << 2 *  ans << "\n";
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