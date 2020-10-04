#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
ll c[2][2];
ll a[2][2];
ll res[2][2];

void mult(ll a[2][2], ll b[2][2]){
	ll i, j, k ;
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			c[i][j] = 0;
		}
	}
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			for(k = 0; k < 2; k++){
				c[i][k] += a[i][j] * b[j][k];
				c[i][k] %= MOD;
			}
		}
	}
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			a[i][j] = c[i][j];
		}
	}
}

void solve(){
	ll n, m;
	cin >> n >> m;
	ll fir = m % MOD;
	ll sec = fir * fir;
	sec %= MOD;
	m--;
	m = m % MOD;
	n--;
	a[0][0] = m;
	a[0][1] = m;
	a[1][0] = 1;
	a[1][1] = 0;

	res[1][1] = 1;
	res[0][0] = 1;
	res[1][0] = 0;
	res[0][1] = 0;

	while(n){
		if(n & 1) mult(res, a);
		mult(a, a);
		n = n >> 1;
	}

	sec *= res[1][0];
	sec %= MOD;
	sec += res[1][1] * fir;
	sec %= MOD;
	cout << sec << "\n";
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