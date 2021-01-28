#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int N = 1e5 + 5;

int d = 505;
ll mod = 1e9 + 7;

pair<int,pair<int,int>> q[N];
ll arr[N];

ll ans=0;
ll f[10*N];

// summation f*(3*f - 2)*arr[i] from l to r
// MO's algorithm
// Code NCode Video

bool comp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
{
    if(a.first / d != b.first / d)
        return a.first/d < b.first/d;
    return a.second.first < b.second.first ;
}

void add(int i)
{
    ll cnt = f[arr[i]];
    f[arr[i]]++;
    ans -= (((3*cnt * cnt)%mod)*(arr[i]))%mod;
    ans += mod;
    ans %= mod;
    ans += (2*cnt*arr[i])%mod;
    ans %= mod;
    cnt++;
    ans += (((3*cnt*cnt)%mod)*arr[i])%mod;
    ans %= mod;
    ans = (ans - (2*cnt*arr[i])%mod + mod)%mod;
}

void remove(int i)
{
    ll cnt = f[arr[i]];
    f[arr[i]]--;
    ans -= (((3*cnt * cnt)%mod)*(arr[i]))%mod;
    ans += mod;
    ans %= mod;
    ans += (2*cnt*arr[i])%mod;
    ans %= mod;
    cnt--;
    ans += (((3*cnt*cnt)%mod)*arr[i])%mod;
    ans %= mod;
    ans = (ans - (2*cnt*arr[i])%mod + mod)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> arr[i];
        int qq;
        cin >> qq;
        memset(f,0,sizeof f);
        for(int i=0;i<qq;i++)
        {
            cin >> q[i].first >> q[i].second.first;
            q[i].first --;
            q[i].second.first --;
            q[i].second.second = i;
        }
        sort(q,q+qq,comp);
        int start = 0,end = -1;
        ll res[N];
        for(int i=0;i<qq;i++)
        {
            int l = q[i].first;
            int r = q[i].second.first;
            while(start > l)
            {
                start--;
                add(start);
            }
            while(end < r)
            {
                end++;
                add(end);
            }
            while(start < l)
            {
                remove(start);
                start++;
            }
            while(end > r)
            {
                remove(end);
                end--;
            }
            res[q[i].second.second] = ans;
        }
        for(int i=0;i<qq;i++)
            cout << res[i] << "\n";
    }
}

//practice question :- Codeforces Powerful Array
