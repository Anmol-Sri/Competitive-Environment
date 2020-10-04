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
	int pos[n + 1];
	int arr[n + 1];
	bool ans[n + 1];
	bool vis[n + 1];
	memset(ans, false, sizeof ans);
	memset(vis, false, sizeof ans);

	for(int i = 1; i <= n; ++i){
		cin >> arr[i];
		pos[arr[i]] = i;
	}

	ans[1] = true;
	ans[n] = false;
	vis[pos[n]]= true;
	for(int i = n - 1; i >= 2; i--){
		int cur = pos[i];
		vis[cur] = true;
		for(int j = cur + i; j <= n; j += i){
			if(vis[j] && ans[arr[j]] == false) ans[i] = true;
		}
		for(int j = cur - i; j >= 1; j -= i){
			if(vis[j] && ans[arr[j]] == false) ans[i] = true;
		}
	}

	for(int i = 1; i <= n; i++){
		if(ans[arr[i]]) cout << "A"; else cout << "B";
	}
	cout << "\n";
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