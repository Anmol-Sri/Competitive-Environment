#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define MP make_pair
#define mt make_tuple
#define eb emplace_back
#define ar array
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define db2d(arr) for(auto x : arr){ for(auto y : x) cout << y << " "; cout << "\n";}
#define read(arr) for(auto &x : arr) cin >> x;
#define sz(x) (int)x.size()
#define MOD 1000000007
#define MOD2 998244353
#define nl '\n'
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k 
// find_by_order(k) : K-th element in a set (counting from zero)

string to_string(char c) {
    return string(1, c);
}

string to_string(bool b) {
    return b ? "true" : "false";
}

string to_string(const char* s) {
    return string(s);
}

string to_string(string s) {
    return s;
}

string to_string(vector < bool > v) {
    string res;
    for(int i = 0; i < sz(v); i++)
        res += char('0'+v[i]);
    return res;
}
 
template < size_t S > string to_string(bitset < S > b) {
    string res;
    for(int i = 0; i < S; i++)
        res += char('0' + b[i]);
    return res;
}

template < class T > string to_string(T v) {
    bool f = 1;
    string res;
    for(auto x : v) {
        if(!f)
            res+=' ';
        f=0;
        res += to_string(x);
    }
    return res;
}
 
void dbvar() { cerr << "]" << endl; }
template<class H, class... T> void dbvar(H h, T... t){
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    dbvar(t...);
}

template<class A> void write(A x) {
    cout << to_string(x);
}

template<class H, class... T> void write(const H& h, const T&... t) { 
    write(h);
    write(t...);
}

void print() {
    write("\n");
}

template<class H, class... T> void print(const H& h, const T&... t) { 
    write(h);
    if(sizeof...(t))
        write(' ');
    print(t...);
}

template <typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type floor_div(T1 x, T2 y) {
    assert(y != 0);
    if (y < 0) x = -x, y = -y;
    return x < 0 ? (x - y + 1) / y : x / y;
}

const ll INFL = (ll)1e18;
const int INF = (int)1e9;
const ld eps = (ld)1e-9;
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

ll power(ll n, ll m){
    if(m == 0) return 1;
    ll val = power(n, m/2);
    if(m % 2 == 0) return (val * val); else return ((val * val) * n);
}

ll powermod(ll n, ll m, ll _MOD){
    if(m == 0) return 1;
    ll val = powermod(n,m/2,_MOD);
    val %= _MOD;
    if(m % 2 == 0) return (val * val) % _MOD; else return (((val * val) % _MOD) * n) % _MOD;
}

ll calc(int row_wise,int inv_row_wise,int col_wise,int inv_col_wise){
	ll ans=0;
    ll res = 0;
	res=min(row_wise/2,col_wise)-1;
	if(res>0) ans+=res;
	res=min(row_wise,col_wise/2)-1;
	if(res>0) ans+=res;
	res=min(row_wise/2,inv_col_wise)-1;
	if(res>0) ans+=res;
	res=min(row_wise,inv_col_wise/2)-1;
	if(res>0) ans+=res;
	res=min(inv_row_wise/2,col_wise)-1;
	if(res>0) ans+=res;
	res=min(inv_row_wise,col_wise/2)-1;
	if(res>0) ans+=res;
	res=min(inv_row_wise/2,inv_col_wise)-1;
	if(res>0) ans+=res;
	res=min(inv_row_wise,inv_col_wise/2)-1;
	if(res>0) ans+=res;
	return ans;
}

void solve(){
    ll r, c; cin >> r >> c;
    ll arr[r][c];
    for(ll i = 0; i < r; i++) for(ll j = 0; j < c; j++) cin >> arr[i][j];
    ll ans = 0;
    ll row_wise[r][c];
    ll inv_row_wise[r][c];
    ll col_wise[r][c];
    ll inv_col_wise[r][c];
    mem(row_wise, 0);
    mem(inv_row_wise, 0);
    mem(col_wise, 0);
    mem(inv_col_wise, 0);
    // print();
    for(ll i = 0; i < r; i++){
        for(ll j = 0; j < c; j++){
            if(i == 0) row_wise[i][j] = arr[i][j];
            else row_wise[i][j] = row_wise[i - 1][j] + arr[i][j];
            // cout << row_wise[i][j] << ' ';
        }
        // print();
    }
    for(ll i = r - 1; i >= 0; i--){
        for(ll j = 0; j < c; j++){
            if(i == r - 1) inv_row_wise[i][j] = arr[i][j];
            else inv_row_wise[i][j] = inv_row_wise[i + 1][j] + arr[i][j];
            // cout << inv_row_wise[i][j] << ' ';
        }
        // print();
    }
    for(ll i = 0; i < c; i++){
        for(ll j = 0; j < r; j++){
            if(i == 0) col_wise[j][i] = arr[j][i];
            else col_wise[j][i] = col_wise[j][i - 1] + arr[j][i];
            // cout << col_wise[j][i] << ' ';
        }
        // print();
    }
    for(ll i = c - 1; i >= 0; i--){
        for(ll j = r - 1; j >= 0; j--){
            if(i == c - 1) inv_col_wise[j][i] = arr[j][i];
            else inv_col_wise[j][i] = inv_col_wise[j][i + 1] + arr[j][i];
            // cout << inv_col_wise[j][i] << ' ';
        }
        // print();
    }
    //longer in row :     
    for(ll j = 0; j < c; j++){
        for(ll i = 3; i < r; i++){
            if(row_wise[i][j] > 3 && row_wise[i][j] % 2 == 0){
                ll val = row_wise[i][j] / 2;
                // print(i, j, j + val - 1, j - val + 1);
                if(j + val - 1 < c && col_wise[i][j + val - 1] - col_wise[i][j] == val) ans++;
                if(j - val + 1 >= 0 && col_wise[i][j] - col_wise[i][j - val + 1] == val) ans++;
            }
        }
        for(ll i = r - 3 - 1; ~i; i--){
            if(inv_row_wise[i][j] > 3 && inv_row_wise[i][j] % 2 == 0){
                ll val = inv_row_wise[i][j] / 2;
                // print(i, j, j + val - 1, j - val + 1);
                if(j + val - 1 < c && col_wise[i][j + val - 1] - col_wise[i][j] == val) ans++;
                if(j - val + 1 >= 0 && col_wise[i][j] - col_wise[i][j - val + 1] == val) ans++;
            }
        }
    }
    // //longer in col : 
    // for(ll i = 0; i < r; i++){
    //     for(ll j = 3; j < c; j++){
    //         if(col_wise[i][j] > 3 && col_wise[i][j] % 2 == 0){
    //             ll val = col_wise[i][j] / 2;
    //             if(i + val - 1 < r && row_wise[i + val - 1][j] - row_wise[i][j] == val) ans++;
    //             if(i - val + 1 >= 0 && row_wise[i][j] - row_wise[i - val + 1][j] == val) ans++;
    //         }
    //     }
    //     for(ll j = c - 3 - 1; ~j; j--){
    //         if(inv_col_wise[i][j] > 3 && inv_col_wise[i][j] % 2 == 0){
    //             ll val = inv_col_wise[i][j] / 2;
    //             if(i + val - 1 < r && row_wise[i + val - 1][j] - row_wise[i][j] == val) ans++;
    //             if(i - val + 1 >= 0 && row_wise[i][j] - row_wise[i - val + 1][j] == val) ans++;
    //         }
    //     }
    // }
    ans = 0;
    mem(row_wise, 0);
    mem(inv_row_wise, 0);
    mem(col_wise, 0);
    mem(inv_col_wise, 0);
    for(ll i=0;i<r;i++){
        ll res=0;
        for(ll j=c-1;j>=0;j--){
            if(arr[i][j]==1){
                res++;
                col_wise[i][j]=res;
            }
            else res = 0;
        }
    }
    for(ll i=0;i<r;i++){
        ll res=0;
        for(ll j=0;j<c;j++){
            if(arr[i][j]==1){
                res++;
                inv_col_wise[i][j]=res;
            }
            else res = 0;
        }
    }
    for(ll i=0;i<c;i++){
        ll res=0;
        for(ll j=0;j<r;j++){
            if(arr[j][i]==1){
                res++;
                row_wise[j][i]=res;
            }
            else res = 0;
        }
    }
    for(ll i=0;i<c;i++){
        ll res=0;
        for(ll j=r-1;j>=0;j--){
            if(arr[j][i]==1){
                res++;
                inv_row_wise[j][i]=res;
            }
            else res = 0;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ans += calc(row_wise[i][j],inv_row_wise[i][j],col_wise[i][j],inv_col_wise[i][j]);
        }
    }
    print(ans);
}

int main()
{	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    // cout << setprecision(10) << fixed;
    
    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}