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

class SegmentTree {
private:
    int n;
    vector<char> st;

    int left(int i) { return i<<1; }
    int right(int i) { return (i<<1)+1; }

    int build(int L, int R, int idx, const vector<int> &A) {
	if(L == R) st[idx] = getSign(A[L]);
	else {
	    int left_val = build(L, (L+R)/2, left(idx), A);
	    int right_val = build(((L+R)/2)+1, R, right(idx), A);
	    st[idx] = combine(left_val, right_val);
	}
	return st[idx];
    }

    char getSign(int i) {
		return (i > 0 ? '+' : (i == 0 ? '0' : '-'));
    }

    char combine(char i, char j) {
		if(i == '0' || j == '0') return '0';
		if(i == j) return '+';
		return '-';
    }

    char query(int i, int j, int L, int R, int idx) {
		if(j < L || R < i) return -1;
		if(i <= L && R <= j) return st[idx];

		char left_val = query(i, j, L, (L+R)/2, left(idx));
		char right_val = query(i, j, ((L+R)/2)+1, R, right(idx));

		if(left_val == -1) return right_val;
		if(right_val == -1) return left_val;
		return combine(left_val, right_val);
    }

    char update(int i, int v, int L, int R, int idx) {
		if(i < L || i > R) return st[idx];
		if(L == R && L == i) {
		    st[idx] = getSign(v);
		    return st[idx];
		}
		char left_val = update(i, v, L, (L+R)/2, left(idx));
		char right_val = update(i, v, ((L+R)/2)+1, R, right(idx));
		return st[idx] = combine(left_val, right_val);
    }

public:
    SegmentTree(vector<int> &A) {
		n = A.size();
		st.assign(4*n, 0);
		build(0, n-1, 1, A);
    }

    char query(int i, int j) {
		return query(i, j, 0, n-1, 1);
    }

    void update(int i, int v) {
		update(i, v, 0, n-1, 1);
    }
};

int n, k;
vector<int> a;

void solve(){
	while(cin >> n >> k) {
		a.resize(n);
		for(auto &x : a) cin >> x;
			SegmentTree st(a);
		string ans = "";
		while(k--) {
	    	char c; int a, b;
	    	cin >> c >> a >> b;
			    if(c == 'C') st.update(a-1, b);
		    else ans += st.query(a-1, b-1);
		}
		cout << ans << '\n';
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