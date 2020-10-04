#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
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

int h, w, m;

void solve(){
	cin >> h >> w >> m;
	set<pair < int , int > > all;
	vector < pair < int , int > > row(h + 1), col(w + 1);

	for(int i = 0; i < h + 1; i++) row[i].second = i;
	for(int i = 0; i < w + 1; i++) col[i].second = i;

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		row[x].first++;
		col[y].first++;
		all.insert(make_pair(x, y));
	}

	sort(all(row));
	reverse(all(row));
	sort(all(col));
	reverse(all(col));

	for(int r = 0; row[r].first == row[0].first; r++){
		for(int c = 0; col[c].first == col[0].first; c++){
			if(!all.count(make_pair(row[r].second, col[c].second))) {
				cout << col[c].first + row[r].first << endl;
				return;
			}
		}
	}
	int ans = max(0, col[0].first + row[0].first - 1);
	cout << ans << endl;
	
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
	// cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}