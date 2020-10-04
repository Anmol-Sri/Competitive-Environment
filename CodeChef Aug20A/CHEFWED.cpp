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

const int INF = INT_MAX;

int recur(int n, int k, int cur, vector < int > &f, vector < int > &val){
	if(n <= cur) return INF;
	if(val[cur] != -1) return val[cur];
	vector < int > ft(101);
	int tot = INF;
	int cnt = 0;
	int le = INF;
	int ret = INF;
	int i = cur;
	while (i < n){
		ft[f[i]] += 1;
		if (ft[f[i]] == 2) cnt += 2;
		else if (ft[f[i]] > 2) cnt += 1;
		ret = recur(n, k, i + 1, f, val);
		if (ret != INF) ret += cnt + k;
		le = min(le, ret);
		i += 1;
	}
	tot = cnt + k;
	if (le < tot) val[cur] = le;
	else  val[cur] = tot;
	return val[cur];
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector < int > f(n);
	for(int i = 0; i < n; i++){
		cin >> f[i];
	}
	vector < int > val(n);
	for(int i = 0; i < n; i++) val[i] = -1;
	ll ans = recur(n, k, 0, f, val);
	cout << ans << "\n";
	return ;
}

int main()
{
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