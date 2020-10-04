#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ll long long int
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
const int mxN = 1e6 + 10;
int n;
int k;
int w;
long long int l[mxN];
long long int h[mxN];
long long int a[2],b[2],c[2],d[2];
long long int p[mxN];
long long int ans;
long long int mod = 1e9 + 7;
unordered_map<long long int,long long int> m;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("perimetric_chapter_1_input (1).txt","r",stdin);
		freopen("outA_1.txt","w",stdout);	
	#endif
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		cin >> n >> k >> w;
		for(int i=0; i < k; i++) cin >> l[i];
		cin >> a[0] >> b[0] >> c[0] >> d[0];
		for(int i=0;i<k;i++) cin >> h[i];
		cin >> a[1] >> b[1] >> c[1] >> d[1];
		for(int i=k; i<n; i++){
			l[i] = (((a[0]*l[i-2])%d[0] + (b[0]*l[i-1])%d[0])%d[0] + c[0])%d[0] + 1;
			h[i] = (((a[1]*h[i-2])%d[1] + (b[1]*h[i-1])%d[1])%d[1] + c[1])%d[1] + 1;
		}
		p[0] = 2*h[0] + 2*w;
		m[l[0] + w] = h[0];
		for(int i=1;i<n;i++){
			long long int x = 2 * min(1LL * w, l[i] - l[i-1]);
			long long int y = 0;
			long long int curr = l[i] + w;
			for(int g=0; g<=w; g++) if(m.find(curr-g) != m.end()) y = max(y,m[curr-g]);
			p[i] = (p[i-1] + x) % mod;
			m[l[i] + w] = h[i];
			p[i] = p[i] + 2 * max(0LL, h[i] - y);
			p[i] = p[i] % mod;
		}
		ans = 1;
		for(int i=0;i<n;i++) ans = (ans*p[i])%mod;
		cout << ans << "\n";
		m.clear();
	}
	return 0;
}