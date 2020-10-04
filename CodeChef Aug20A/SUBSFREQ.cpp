#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define N 100005
ll mod = 1e9 +7;
// nCr % mod
ll fact[6*N];
ll inv[6*N],invfac[6*N];
//ll mod = 1e9 + 7;

ll power(ll x,ll y)
{
    ll temp;
    if(y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return (((x*temp)%mod)*temp)%mod;
}

void factorial()
{
    fact[0] = invfac[0] = fact[1] = invfac[1] = 1;
    inv[1] = 1;
    for(int i=2;i<=5*N + 10;i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
        inv[i] = (inv[mod%i]*(mod - mod/i))%mod;
        invfac[i] = (invfac[i-1]*inv[i])%mod;
    }
}

//Code Taken from - https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
ll modInverse(ll a, ll m = mod)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        ll q = a / m;
        ll t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}

const int Nmax = 5e5 + 6;

ll a[Nmax];
ll ans[Nmax];
ll cnr[Nmax];
int n;

void solve(){
	cin >> n;
    vector<pair<ll,int>> v;
    vector<ll > cnt(n+5,0);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    memset(cnr,0, sizeof cnr);
    memset(ans,0, sizeof ans);
    priority_queue<pair<ll,ll>> pq;
    for(int i=0;i<n+5;i++)
    {
        if(cnt[i])
        {
            pq.push({cnt[i],-i});
            v.push_back({cnt[i],i});
        }
    }
    ll sum = 1;
    for(auto x : v)
    {
        ll c = x.first;
        ll val = x.second;
        cnr[val ] = power(2,c);
        sum = (sum*cnr[val]);
        sum %= mod;
    }
    while(pq.size())
    {
        pair<ll,ll> p = pq.top();pq.pop();
        ll c = p.first;
        ll val = -p.second;
        ll tot = cnt[val];
        ll modinv = modInverse(cnr[val]);
        sum = (sum*modinv)%mod;
        ll t = (((fact[tot]*invfac[c])%mod)*invfac[tot-c])%mod;
        ans[val] += (sum*t)%mod;
        ans[val]  %= mod;
        c--;
        cnr[val] = (cnr[val] + mod - t)%mod;
        if(c)
        {
            pq.push({c,-val});
            sum = (sum*cnr[val])%mod;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << ans[i] << " ";
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
	cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}