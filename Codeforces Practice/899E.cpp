#include <bits/stdc++.h>
#define ll long long int
#define debug(x) cout << (#x) << " = " << x << endl;
#define ld long double
#define mem(a,b) memset(a, b, sizeof a)
#define debug2(i,j) cout << (#i) << "=" << i << " , " << (#j) << "=" << j << endl;
#define all(x) x.begin(), x.end()
using namespace std;

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
	int n;
	cin >> n;
	vector < pair < int, int > > arr;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(arr.size() >= 1 && x == arr.back().first) arr.back().second++;
		else arr.emplace_back(x, 1);
	}
	int moves = 0;

	while(arr.size() > 0){
		int mx = 0;
		for(auto x : arr){
			mx = max(x.second, mx);
		}
		vector < pair < int, int > > latest;
		for(auto &x : arr){
			if(latest.size() >= 1 && latest.back().first == x.first){
				x.second += latest.back().second;
				latest.pop_back();
			}
			if(x.second >= mx) moves++;
			else latest.emplace_back(x);
		}
		arr = latest;
	}
	cout << moves << "\n";
	return;
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