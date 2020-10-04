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
double calcd(int x, int y){return sqrt(y*y+x*x);}
double calct(double temp_di, int vel){return (temp_di/vel);}
int merge(int cnt){	return ((cnt)*(cnt-1))/2;}
void solve(){
	int n;
	cin>>n;
	int in[n][3];
	for(int i=0;i<n;i++){ for(int j=0;j<3;j++) cin>>in[i][j];}
	unordered_map<int,int> mp;
	int i=0;
	while(i<n){
		double temp_di = calcd(in[i][0], in[i][1]);
		double temp_ti = calct(temp_di, in[i][2]);
		mp[temp_ti]++;
		i++;
	}
	int ans=0;
	for(auto q:mp) if(q.second>1) ans+=merge(q.second);
	
	int final_ans=0;
	i=0;
	while(i<n){
		double temp_di = calcd(in[i][0], in[i][1]);
		double temp_ti = calct(temp_di, in[i][2]);
		int j=i+1;
		while(j<n){ if(temp_ti==calct(calcd(in[j][0],in[j][1]),in[j][2])){final_ans++;}j++; }
        i++;
	}
	cout<<final_ans;
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
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}