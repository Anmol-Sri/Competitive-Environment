const ll mxN = 1e5 + 20;
const ll logn = 22; // hard coded the value of log2 of mxN
ll sparse_table[mxN][logn];
ll n;

void init(){
    // preprocessing and storing the min-range values for 2^i-th ranges in sparse table.
    for(ll k = 1; k < logn; k++){
        for(ll i = 0; i + (1 << k) - 1 < n; i++){
            sparse_table[i][k] = min(sparse_table[i][k - 1], sparse_table[i + (1 << (k - 1))][k - 1]);
        }
    }
}
ll calc_sparse_min(ll l, ll r){
    ll len = r - l + 1; // lenght of the range
    ll k = 31 - __builtin_clz(len); // calculating the largest power of 2 less than len....
    return min(sparse_table[l][k], sparse_table[r - (1 << k) + 1][k]); // taking range from l..2^k to r - 2^k for the range lenght of k...
}

void solve(){
	cin >> n;
    vector < ll > arr(n);
    // taking array as input ans initializing the sparse table for 2^0 -th values.
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        sparse_table[i][0] = arr[i];
    }
    init();
    // queries in the form of l...r
    ll q; cin >> q;
    while(q--){
        ll l, r; cin >> l >> r;
        print(calc_sparse_min(l, r));
    }
}