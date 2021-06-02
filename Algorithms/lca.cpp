const ll mxN = 1e4 + 10;
const ll logn = 20; // hard coded max possible value of power of 2 of n
vector < ll > g[mxN]; // graph
vector < ll > depth(mxN); // depth of node
ll up[mxN][logn]; // up[v][j] is 2^j-th ancestor of v

void dfs(ll a){ // calculates the depth, 2^j th ancestor of a
    for(auto b : g[a]){
        depth[b] = depth[a] + 1;
        up[b][0] = a;
        for(ll j = 1; j < logn; j++) up[b][j] = up[up[b][j - 1]][j - 1];
        dfs(b);
    }
}

ll lca(ll a, ll b){ // program for lca.
    if(depth[a] < depth[b]) swap(a, b);
    ll k = depth[a] - depth[b];
    for(ll j = logn - 1; ~j; j--) if(k & (1 << j)) a = up[a][j];
    if(a == b) return a;
    for(ll j = logn - 1; ~j; j--){
        if(up[a][j] != up[b][j]){ a = up[a][j]; b = up[b][j]; }
    }
    return up[a][0];
}

void solve(){
    ll n; cin >> n; // taking input in the form of first m then m children for the i-th node.
    for(ll i = 0; i < n; i++){
        ll c; cin >> c;
        for(ll j = 0; j < c; j++){
            ll x; cin >> x; g[i].pb(x);
        }
    }
    dfs(0); // pre calculates all the ancestors for the tree.
    ll q; cin >> q;
    while(q--){
        ll u, v; cin >> u >> v;
        print(lca(u, v)); // lca for u and v.
    }
}