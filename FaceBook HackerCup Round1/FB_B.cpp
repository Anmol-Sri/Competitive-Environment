#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ll long long
#define dd double
#define MOD1 1000000007
#define MOD2 998244353
#define nl cout<<endl
#define rt ll Q[100005]={0}
#define mp make_pair
#define test() ll t;cin>>t;while(t--)
#define pb push_back
#define ff first 
#define ss second
#define all(v) v.begin(),v.end()
#define s(ar,n) sort(ar,ar+n)
#define rs(ar,n) sort(ar, ar+n, greater<ll>()) 
#define oa(a,n) for(ll i=0;i<n;i++)cout<<a[i]<<" ";nl
#define cn(a,n) for(ll i=0;i<n;i++)cin>>a[i];
#define ov(a,n) for(ll i=n-1;i>=0;i--)cout<<a[i]<<" ";nl
#define ovp(a,n) for(ll i=0;i<n;i++)cout<<a[i].ff<<" "<<a[i].ss<<endl;
#define maxa(ar,N) *max_element(ar,ar+N)
#define mina(ar,N) *min_element(ar,ar+N)
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef pair<ll,ll> pii;
ll powe(ll n,ll m){if(m==0)return 1;ll t=powe(n,m/2);if(m%2==0)return (t*t);return (((t*t))*n);}
ll mpowe(ll n,ll m,ll MOD){if(m==0)return 1;ll t=mpowe(n,m/2,MOD);t%=MOD;if(m%2==0)return (t*t)%MOD;return (((t*t)%MOD)*n)%MOD;}
ll logtwo(ll n){if(n==1)return 0;if(n==0) return -1;return logtwo(n/2)+1;}
const int MAXN = 1e6 + 6;
long long int m;
long long int p[MAXN],q[MAXN];
long long int n;
vector<pair<long long int,long long int>> v;
long long int k;
long long int s;
bool func(long long int mid){
    long long int ff = 0;
    long long int ss =0;
    bool yes = true;
    long long int i = 0;
    while(i<v.size()){
        if(v[i].ss == 1) if(ss < v[i].ff && ff == 0) ff = v[i].ff;
        if(v[i].ss == 0){
            if(ff){
                if(mid - (v[i].ff-ff) < 0) return false;
                ss = max({v[i].ff,v[i].ff+(mid-2*(v[i].ff-ff)),v[i].ff + (mid - (v[i].ff-ff))/2});
                ff = 0;
            }
            else ss = v[i].ff + mid;
        }
        i++;
    }
    if(ff) return false;
    return true;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("dislodging_logs_input (1).txt","r",stdin);
		freopen("outB_1.txt","w",stdout);	
	#endif
	int t = 1;
	cin >> t;
	for(int qweasd = 1; qweasd <= t; qweasd++){
		cout << "Case #" << qweasd << ": ";
		cin >> n >> m >> k >> s;
        v.clear();
        long long int i = 0;
        while(i<k){
            cin >> p[i];
            v.push_back({p[i],0});
            i++;
        }
        long long int a[2];
        long long int b[2];
        long long int c[2];
        long long int d[2];
        cin >> a[0] >> b[0] >> c[0] >> d[0];
        i = 0;
        while(i<k){
            cin >> q[i];
            v.push_back({q[i],1});
            i++;
        }
        cin >> a[1] >> b[1] >> c[1] >> d[1];
        i = k;
        while(i<n){
            long long int val = ((a[0]*p[i-2] % d[0] + b[0]*p[i-1] % d[0])%d[0] + c[0])%d[0] + 1;
            p[i] = val;
            v.push_back({p[i],0});
            i++;
        }
        i = k;
        while(i<m){
            long long int val = (( (a[1]*q[i-2])%d[1] + (b[1]*q[i-1])%d[1])%d[1] + c[1])%d[1] + 1;
            q[i] = val;
            v.push_back({q[i],1});
            i++;
        }
        sort(v.begin(),v.end());
        long long int low = 0;
        long long int high = 1e18 + 10;
        long long int ans = high;
        while(low <= high){
            long long int mid = (low + high)/2;
            if(func(mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        cout << ans << "\n";    
	}
	return 0;
}