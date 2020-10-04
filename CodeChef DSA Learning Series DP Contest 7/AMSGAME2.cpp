#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 61;
map< pair< ll , ll > , ll > mp;
ll arr[mxN];
ll n;

ll gcd(ll  a, ll b){
	if(b > a) return gcd(b, a);
	if(b == 0) return a;
	return gcd(b, a % b);
}

ll recur(ll ind, ll g){
	if(ind == n){
		if(g == 1) return 1;
		return 0;
	}
	pair< ll , ll > x = make_pair(ind, g);
	if(mp.find(x) != mp.end()) return mp[x];

	ll g_new =
	mp[x] = recur(ind + 1, g) + recur(ind + 1, gcd(g, arr[ind]));
	return mp[x];
}
void solve(){
	cin >> n;
	mp.clear();
	for(ll i =0; i < n; i++){
		cin >> arr[i];
	}
	ll ans = 0;
	for(int i =0; i < n; i++){
		ans += recur(i + 1, arr[i]);
	}
	cout << ans << "\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}