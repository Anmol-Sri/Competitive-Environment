#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define endl "\n"
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

const int mxN = 5e5 + 10;
ll a[mxN], tree[(int)1e7], lazy[(int)1e7];

void build(int node, int start, int end){
	if(start == end) tree[node] = tree[start];
	else{
		int mid = (start + end) >> 1;
		build(node << 1, start, mid);
		build(node << 1 | 1, mid + 1, end);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}
}

void upd(int node , int start, int end, int l , int r, ll val){
	if(r < start || l > end) return ;
	if(l <= start && r >= end) {lazy[node] += val; return ;}
	int mid = (start + end) >> 1;
	upd(node << 1, start, mid, l, r, val);
	upd(node << 1 | 1, mid + 1, end, l, r, val);
	tree[node] = min(tree[node << 1] + lazy[node << 1] , tree[node << 1 | 1] + lazy[node << 1 | 1]);
}

ll qry(int node , int start, int end, int l, int r){
	if(start > r || end < l) return LLONG_MAX;
	if(l <= start && r >= end) return  tree[node] + lazy[node];
	int mid = (start + end) >> 1;
	return min(qry(node << 1, start, mid, l, r), qry(node << 1 | 1, mid + 1, end, l, r)) + lazy[node];
}

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		upd(1, 0, n - 1, i, i, a[i]);
	}
	int q;
	cin >> q;
	string s;
	getline(cin, s);
	while(q--){
		int l, r;
		ll val;
		getline(cin , s);
		stringstream ss;
		ss << s;
		ss >> l >> r >> val;
		if(ss){
			if(l > r) upd(1, 0, n - 1, 0, r, val), upd(1, 0, n - 1, l, n - 1, val);
			else upd(1, 0, n - 1, l, r, val);
		}
		else{
			ll mn = LLONG_MAX;
			if(l > r) mn =  min(qry(1, 0, n - 1, 0, r), qry(1, 0, n - 1, l, n - 1));
			else mn = qry(1, 0, n - 1, l, r);
			cout << mn << endl;
		}
	}
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