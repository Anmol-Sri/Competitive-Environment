#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll power(ll n,ll m){
	if(m==0) return 1;
	ll val=power(n,m/2);
	if(m%2==0) return (val*val); else return ((val*val)*n);
}

ll powermod(ll n,ll m,ll MOD){
	if(m==0) return 1;
	ll val=powermod(n,m/2,MOD);
	val %= MOD;
	if(m%2==0) return (val*val) % MOD; else return (((val*val) % MOD) * n) % MOD;
}

struct Point{
	ll x, y;
	Point() : x(), y(){}
	Point(ll _x, ll _y) : x(_x), y(_y){}
	void scan(){
		cin >> x >> y;
	}
	Point operator + (const Point &a) const{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const{
		return Point(x - a.x, y - a.y);
	}
	ll operator * (const Point &a) const{
		return x * a.y - y * a.x;
	}
};

const int mxN = 1e5 + 10;
int n;
Point a[mxN], b[mxN];
int m;

bool check(Point P, Point p){
	m = 0;
	for(int i = 0; i < n; i++){
		if((a[i] - P) * p != 0) b[m++] = a[i];
	}
	if(m <= 2) return true;
	P = b[0];
	p = b[1] - b[0];
	for(int i = 0; i < m; i++){
		if((b[i] - P) * p != 0) return false;
	}
	return true;
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		a[i].scan();
	}
	if(n <= 4){
		cout << "YES\n";
		return ;
	}
	if(check(a[0], a[1] - a[0]) || check(a[0], a[2] - a[0]) || check(a[1], a[2] - a[1])) cout << "YES\n";
	else cout << "NO\n";
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
	// cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}