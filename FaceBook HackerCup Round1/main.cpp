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

int n,k,w;
ll l[Nmax],h[Nmax];
ll a[2],b[2],c[2],d[2];
ll p[Nmax];
ll ans = 1;
ll mod = 1e9 + 7;
unordered_map<ll,ll> m;

void take(int i)
{
    cin >> a[i] >> b[i] >> c[i] >> d[i];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    int cas = 1;
    while(t--)
    {
        cout << "Case #" << cas++ << ": ";
        m.clear();
        cin >> n >> k >> w;
        ans = 1;
        for(int i=0;i<k;i++)
            cin >> l[i];
        take(0);
        for(int i=0;i<k;i++)
        {
            cin >> h[i];
        }
        take(1);
        for(int i=k;i<n;i++)
        {
            l[i] = (((a[0]*l[i-2])%d[0] + (b[0]*l[i-1])%d[0])%d[0] + c[0])%d[0] + 1;
            h[i] = (((a[1]*h[i-2])%d[1] + (b[1]*h[i-1])%d[1])%d[1] + c[1])%d[1] + 1;
        }
        p[0] = 2*h[0] + 2*w;
        m[l[0]+w] = h[0];
        for(int i=1;i<n;i++)
        {
            ll x = 2*min(1LL*w,l[i] - l[i-1]);
            ll y = 0;
            ll curr = l[i]+w;
            for(int g=0;g<=w;g++)
            {
                if(m.find(curr-g)!=m.end())
                {
                    y = max(y,m[curr-g]);
                }
            }
            //debug2(x,y);
            p[i] = (p[i-1] + x)%mod;

            m[l[i]+w] = h[i];
            p[i] += 2*max(0LL,h[i] - y);
            p[i] %= mod;
        }
        ans = 1;
        for(int i=0;i<n;i++)
        {
            //debug(p[i]);
            ans = (ans*p[i])%mod;
        }
        cout << ans << "\n";
    }
}
