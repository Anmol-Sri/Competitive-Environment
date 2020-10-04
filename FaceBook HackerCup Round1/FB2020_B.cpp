#include <iostream>
#include <math.h>
#include <iomanip>
#include <bits/stdc++.h>
#include <string.h>
#include <string>
#include <algorithm>
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define N 100005
#define inf 1e18
#define mem(a,b) memset(a,b,sizeof(a))
#define debug(x) cout << (#x) << " = " << x << endl;
#define debug2(i,j) cout << (#i) << "=" << i << " , " << (#j) << "=" << j << endl;

using namespace std;

ll binomialCoeff(ll n,ll k)
{
    ll res = 1;
    if(k >n - k)
        k = n - k;
    for(int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll power(ll x,ll y)
{
    ll temp;
    if(y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}


/* nCr % mod
ll fact[6*N];
ll inv[6*N],invfac[6*N];
ll mod = 998244353;

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
}*/

vector<ll> primes;
vector<bool> prime;

void Sieve(int n)
{
    prime = vector<bool> (n+1,true);
    //vector<bool> prime(n+1,true);
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
          primes.push_back(p);
}

//******************************************************    CHECK CONSTRAINTS   ***************************************************************//

const int Nmax = 1e6 + 6;

ll n,m,k,s;
ll p[Nmax],q[Nmax];
vector<pair<ll,ll>> v;

bool check(ll mid)
{
    ll left = 0;
    ll right =0;
    bool yes = true;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].second == 1)
        {
            if(right < v[i].first && left == 0 )
                left = v[i].first;
        }
        if(v[i].second == 0)
        {
            if(left )
            {
                if(mid - (v[i].first-left) < 0)
                    return false;
                right = max({v[i].first,v[i].first+(mid-2*(v[i].first-left)),v[i].first + (mid - (v[i].first-left))/2});
                left = 0;
            }
            else
                right = v[i].first+mid;
        }
    }
    if(left)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    int cas = 1;
    while(t--)
    {
        cout << "Case #" << cas++ << ": ";
        cin >> n >> m >> k >> s;
        v.clear();
        for(int i=0;i<k;i++)
        {
            cin >> p[i];
            v.pb({p[i],0});
        }
        ll a[2],b[2],c[2],d[2];
        cin >> a[0] >> b[0] >> c[0] >> d[0];
        for(int i=0;i<k;i++)
        {
            cin >> q[i];
            v.pb({q[i],1});
        }
        cin >> a[1] >> b[1] >> c[1] >> d[1];
        for(int i=k;i<n;i++)
        {
            ll val = ((a[0]*p[i-2] % d[0] + b[0]*p[i-1] % d[0])%d[0] + c[0])%d[0] + 1;
            p[i] = val;
            v.pb({p[i],0});
        }
        for(int i=k;i<m;i++)
        {
            ll val = (( (a[1]*q[i-2])%d[1] + (b[1]*q[i-1])%d[1])%d[1] + c[1])%d[1] + 1;
            q[i] = val;
            v.pb({q[i],1});
        }
        sort(v.begin(),v.end());
        ll low = 0;
        ll high = 1e18 + 5;
        ll best = high;
        while(low <= high)
        {
            ll mid = (low + high)/2;
            if(check(mid))
            {
                best = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        cout << best << '\n';
    }
}
