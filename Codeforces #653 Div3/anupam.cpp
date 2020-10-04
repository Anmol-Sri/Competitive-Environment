#include <bits/stdc++.h>
using namespace std;
// typedef unsigned long long ulong long int;
// typedef long long long long int;
// #define long long int long long
#define dd double
#define MOD1 1000000007
#define MOD2 998244353
#define nl cout<<endl
#define rt long long int Q[100005]={0}
#define mp make_pair
#define test() long long int t;cin>>t;while(t--)
#define pb push_back
#define ff first    
#define ss second
#define along long int(v) v.begin(),v.end()
#define s(ar,n) sort(ar,ar+n)
#define rs(ar,n) sort(ar, ar+n, greater<long long int>()) 
#define oa(a,n) for(long long int i=0;i<n;i++)cout<<a[i]<<" ";nl
#define cn(a,n) for(long long int i=0;i<n;i++)cin>>a[i];
#define ov(a,n) for(long long int i=n-1;i>=0;i--)cout<<a[i]<<" ";nl
#define ovp(a,n) for(long long int i=0;i<n;i++)cout<<a[i].ff<<" "<<a[i].ss<<endl;
#define maxa(ar,N) *max_element(ar,ar+N)
#define mina(ar,N) *min_element(ar,ar+N)
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef pair<long long int,long long int> pii;
long long int powe(long long int n,long long int m){if(m==0)return 1;long long int t=powe(n,m/2);if(m%2==0)return (t*t);return (((t*t))*n);}
long long int mpowe(long long int n,long long int m,long long int MOD){if(m==0)return 1;long long int t=mpowe(n,m/2,MOD);t%=MOD;if(m%2==0)return (t*t)%MOD;return (((t*t)%MOD)*n)%MOD;}
long long int logtwo(long long int n){if(n==1)return 0;if(n==0) return -1;return logtwo(n/2)+1;}

const ll INF=1e18;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

    int n,k;
    cin >> n >> k;
    std::vector<array<int,3>> arr[n];
    int pehli =0,dusri=0;
    int a,b,c;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b >> c;
        pehli+=(b==1)?1:0;
        dusri +=(c==1)?1:0;
        b^=1;
        c^=1;
        // t[i] = make_tuple(a,b,c);
        arr.push_back({a,b,c});
    }
    if(pehli>=k && dusri>=k){
    	ll dp[2000001];
    	ll dp1[2000001];
    	ll dp2[2000001];
    	for(int i=1;i<Nmax;i++)
	    {
	        dp1[i] = INF;
	        dp[i] = INF;
	        dp2[i] = INF;
	    }
	    sort(arr.begin(), arr.end());
	    int a=0,b=0,c=0;
	    ll ans = 1e18; 
	    for(int i=0;i<n;i++)
	    {
	        array<int,3> x = t[i];
	        ll val = x[0];
	        ll p = x[1];
	        ll q = x[2];
	        if(p==0 && q==1){
	            dp1[a+1] = min(dp1[a+1] , dp1[a] + val);
	            a++;
	        }
	        if(q==0 && p==1){
	            dp2[b+1] = min(dp2[b+1] , dp2[b] + val);
	            b++;
	        }
	        if(!p & !q){
	            dp[c+1] = min(dp[c+1],dp[c] + val);
	            c++;
	        }
	        if(a+c >= k && c+b>=k){
	            ans = min(ans,dp[c] + dp1[k-c] + dp2[k-c]);
	        }
	    }
	    cout << ans;
    }
    else{
    	cout<<"-1\n";
    }
    return 0;
}