
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

const ll INF = LLONG_MAX;

ll calc(ll asd, int b, vector < ll > l_temp[]){
	vector < ll > l = l_temp[b];
	ll i = 0;
	while(i<l.size() && asd>0){
        ll temp = min(l[i],asd);
        l[i] = l[i] - temp;
        asd = asd - temp;
        i++;
    }
	if(asd > 0) return 0;
	
	ll s = 0;
	ll k = l.size();
	i = 0;
	while(i < k){
		s += l[i];
		i++;
	}
	ll s2 = 0;
	ll temp[k + 1];
	i = 0;
	while(i < k){
		temp[i] = l[i] * (s - l[i]);
		s2 += temp[i];
		i++;
	}
	s2 /= 2;
	ll s3 = 0;
	i = 0;
	while(i < k){
		s3 += l[i] * (s2 - temp[i]);
		i++;
	}
	s3 /= 3;
	return s3;
}

void solve(){
	ll n, c, k;
	cin >> n >> c >> k;
	unordered_map < ll , int > col[c + 1];
	vector < ll > l[c + 1];
	ll i = 1;
	while(i <= n){
		ll x, y, val;
		cin >> x >> y >> val;
		col[val][x]++;
		i++;
	}
	ll v[c + 1] = {0};
	i = 1;
	while(i <= c){
		cin >> v[i];
		i++;
	}
	i = 1;
	while(i <= c){
		vector < ll > temp;
		for(auto x : col[i]){
			temp.push_back(x.second);
		}
		sort(all(temp));
		l[i] = temp;
		i++;
	}
	ll store[k + 1][c + 1];
	ll m[k + 1][c + 1];
	i = 0;
	ll j = 0;
	while(i <= k){
		j = 0;
		while(j <= c){
			store[i][j] = INF;
			if(j == 0) store[i][j] = 0;
			m[i][j] = -1;
			j++;
		}
		i++;
	}
	i = 0;
	while(i <= k){
		j = 1;
		while(j <= c){
			ll mx = i/v[j];
			ll asd = 0;
			while(asd <= mx){
				ll zxc = asd * v[j];
				if(m[asd][j] == -1) m[asd][j] = calc(asd,j,l);
				store[i][j] = min(store[i-zxc][j-1] + m[asd][j], store[i][j]);
				asd++;
			}
			j++;
		}
		i++;
	}
	cout << store[k][c] << endl;
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

	int t = 1;
	cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}