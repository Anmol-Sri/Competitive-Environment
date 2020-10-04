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

const int MOD = 998244353;
void solve(){
	ll n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	ll exp[m];
	exp[0] = 1;
	for(int i = 1; i < m; i++){
		exp[i] = exp[i - 1];
		if(b[i] == '1') exp[i]++;
	}
	ll ans = 0;
	ll j = m - 1;
	ll two = 1;
	for(int i = n - 1; i >= 0 ; i--){
		if(j < 0) break;
		if(a[i] == '1') ans += two * exp[j];
		j--;
		two *= 2;
		two %= MOD;
		ans %= MOD;
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
	// cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}