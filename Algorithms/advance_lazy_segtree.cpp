template < typename	num_t>
struct segtree{
	int n, depth;
	vector < num_t > tree, lazy;
	void init(int s, ll* arr){
		n = s;
		tree = vector < num_t > (4 * s, 0);
		lazy = vector < num_t > (4 * s, 0);
		init(0, 0, n - 1, arr);
	}
	num_t init(int i, int l, int r, ll* arr){
		if(l == r) return tree[i] = arr[l];
		int mid = (l + r) / 2;
		num_t a = init(2 * i + 1, l, mid, arr),
			  b = init(2 * i + 2, mid + 1, r, arr);
		return tree[i] = a.op(b);
	}
	void update(int l, int r, num_t v){
		if(l > r) return;
		update(0, 0, n - 1, l, r, v);
	}
	num_t update(int i, int tl, int tr, int ql, int qr, num_t v){
		eval_lazy(i, tl, tr);
		if(tr < ql || qr < tl) return tree[i];
		if(ql <= tl && tr <= qr){
			lazy[i] = lazy[i].val + v.val;
			eval_lazy(i, tl, tr);
			return tree[i];
		}
		int mid = (tl + tr) / 2;
		num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
			  b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
		return tree[i] = a.op(b);
	}
	num_t query(int l, int r){
		if(l > r) return num_t::null_v;
		return query(0, 0, n - 1, l, r);
	}
	num_t query(int i, int tl, int tr, int ql, int qr){
		eval_lazy(i, tl, tr);
		if(ql <= tl && tr <= qr) return tree[i];
		if(tr < ql || qr < tl) return num_t :: null_v;

		int mid = (tl + tr) / 2;
		num_t a = query(2 * i + 1, tl, mid, ql, qr),
			  b = query(2 * i + 2, mid + 1, tr, ql, qr);
		return a.op(b);
	}
	void eval_lazy(int i, int l, int r){
		tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
		if(l != r){
			lazy[2 * i + 1] = lazy[i].val + lazy[2 * i + 1].val;
			lazy[2 * i + 2] = lazy[i].val + lazy[2 * i + 2].val;
		}
		lazy[i] = num_t();
	}
};

ll v_gcd(ll a, ll b){
	if(a == 0 || b == 0) return a + b;
	return __gcd(a, b);
}

struct gcd_t{
	ll val;
	static const ll null_v = 0;
	gcd_t() : val(0) {}
	gcd_t(ll v) : val(v){};

	gcd_t op(gcd_t &other){
		return gcd_t(v_gcd(val, other.val));
	}

	gcd_t lazy_op(gcd_t& v, int size){
		return gcd_t(val + v.val);
	}
};

ll a[1010000];
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	// cout << setprecision(10) << fixed;
	
	int t = 1;
	cin >> t;

	// initializing the segtree : 
	memset(a, 0, sizeof a);
	st.init(mxN, a);

	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}