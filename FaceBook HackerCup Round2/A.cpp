#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define ar array
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define db2d(arr) for(auto x : arr){ for(auto y : x) cout << y << " "; cout << "\n";}
#define read(arr) for(auto &x : arr) cin >> x;
#define nl "\n"
#define sz(x) (int)x.size()
#define MOD 1000000007
#define MOD2 998244353
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #define ordered_set_int tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// #define ordered_set_ll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k 
// find_by_order(k) : K-th element in a set (counting from zero)

void dbvar() { cerr << "]" << endl; }
template<class H, class... T> void dbvar(H h, T... t){
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	dbvar(t...);
}

const ll inf = (ll)1e18;
const int mod = (ll)1e9 + 7;
const ld eps = (ld)1e-9;
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int d8x[8]={-1, -1, 0, 1, 1, 1, 0, -1};
const int d8y[8]={0, 1, 1, 1, 0, -1, -1, -1};

ll power(ll n,ll m){
	if(m==0) return 1;
	ll val=power(n,m/2);
	if(m%2==0) return (val*val); else return ((val*val)*n);
}

ll powermod(ll n,ll m,ll _MOD){
	if(m==0) return 1;
	ll val=powermod(n,m/2,_MOD);
	val %= _MOD;
	if(m%2==0) return (val*val) % _MOD; else return (((val*val) % _MOD) * n) % _MOD;
}

int mult(ll a,ll b){ return (a*b)%MOD; }

int pot(int n,int k){
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}
 
int divide(int a,int b){ return mult(a,pot(b,MOD-2)); }
int sub(int a,int b){ if (a-b>=0) return a-b; return a-b+MOD; }
int add(int a,int b){ if (a+b>=MOD) return a+b-MOD;	return a+b; }

const ll Nmax = 1e6 + 6;
const ll N = 2005;

ll n,k;
ll s[Nmax] , x[Nmax], y[Nmax];

void solve(){
	ll a,b,c,d;
	cin >> n >> k;
	for(int i = 0; i < k; i++) cin >> s[i];
	cin >> a >> b >> c >> d;
	for(int i = k;i < n; i++) s[i] = ((a * s[i-2] % d + b * s[i-1] % d ) % d + c) % d;
	for(int i = 0; i < k ; i++) cin >> x[i];
	cin >> a >> b >> c >> d;
	for(int i = k; i < n; i++) x[i] = ((a * x[i-2] % d + b * x[i-1] % d ) % d + c) % d;
	for(int i = 0; i < k ; i++) cin >> y[i];
	cin >> a >> b >> c >> d;
	for(int i = k; i < n; i++) y[i] = ((a * y[i-2] % d + b * y[i-1] % d ) % d + c) % d;
	ll left = 0;
	ll to_remove = 0;
	ll to_add = 0;
	ll right = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] > x[i] + y[i]){
			left += s[i] - x[i] - y[i];
			to_remove += (s[i] - x[i]);
		}
		else if(s[i] < x[i]){
			right += x[i] - s[i];
			to_add += x[i] + y[i] - s[i];
		}
		else{
			to_add += x[i] + y[i] - s[i];
			to_remove += s[i] - x[i];
		}
	}
	if(right > to_remove || left > to_add)
	    cout << "-1" << nl;
	else
	    cout << max(left,right) << nl;
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("capastaty_input.txt","r",stdin);
		freopen("outputA.txt","w",stdout);	
	#endif

	int t = 1;
	cin >> t;

	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}