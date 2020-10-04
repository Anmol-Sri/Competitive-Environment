#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define MP make_pair
#define ar array
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define db2d(arr) for(auto x : arr){ for(auto y : x) cout << y << " "; cout << "\n";}
#define read(arr) for(auto &x : arr) cin >> x;
#define sz(x) (int)x.size()
#define MOD 1000000007
#define MOD2 998244353
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define ordered_set_int tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// #define ordered_set_ll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
// order_of_key (k) : Number of items strictly smaller than k 
// find_by_order(k) : K-th element in a set (counting from zero)

void dbvar() { cerr << "]" << endl; }
template<class H, class... T> void dbvar(H h, T... t){
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	dbvar(t...);
}

const ll INF = (ll)1e18;
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

int div_calc(int n,int k){
	if (k==0) return 1;
	ll a = div_calc(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n); else return a;
}

int divide(int a,int b){ return mult(a,div_calc(b,MOD-2)); }
int sub(int a,int b){ if (a-b>=0) return a-b; return a-b+MOD; }
int add(int a,int b){ if (a+b>=MOD) return a+b-MOD;	return a+b; }

ll n;
void solve(){
	cin >> n;
	auto calc = [&](ll x) -> ll{
		return (x*(x+1)) >> 1;
	};
	ll cur = calc(n);
	// cout << cur << "\n";
	ll res = 0LL;
	if(cur % 2 == 0){
		ld val = sqrt(8 * (cur >> 1)+1);
		ld check = (val - 1) / 2;
		ld i;
		ld d = modf(check, &i);
		if(d==0) res = calc(n - 1 - (ll)check) + calc((ll)check - 1);
		res = res + n - (ll)check;
	}
	else res = 0;
	cout << res << "\n";
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