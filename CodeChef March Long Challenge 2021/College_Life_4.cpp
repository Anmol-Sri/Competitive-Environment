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

ll calc(ll n, ll e, ll h, ll a, ll b, ll c){
    ll start = 1;
    ll res = INFL;
    if (n <= 0) return 0;
    if (n <= e && n <= h) res = min(res, n * c);
    if (3 * n <= h) res = min(res, n * b);
    auto solve_for_A = [](){
        ll c;
        cin >> c;
        ll fir = power(2, floor(log2(c)));
        fir--;
        ll sec = fir ^ c;
        print(fir * sec);
    };
    if (2 * n <= e) res = min(res, n * a);
    auto solve_for_B = [](){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        sort(all(arr));
        ll consc = (n * (n + 1)) / 2;
        sum = consc - sum;
        ll cur = 1;
        for (auto x : arr)
        {
            if (x > cur)
            {
                print("Second");
                return;
            }
            cur++;
        }
        if (sum <= 0 || sum % 2 == 0)
            print("Second");
        else
            print("First");
    };
    if (n >= 3 && h >= 4 && e >= 3) res = min(res, a + b + c + calc(n - 3, e - 3, h - 4, a, b, c));
    if ((n - e) <= (h - n) / 2 && (h - n) / 2 >= 1){
        if (b - c < 0) res = min(res, (b - c) * min(n - 1, (h - n) / 2) + n * c);
        else res = min(res, (b - c) * max(start, n - e) + n * c);
    }
    auto solve_for_C = [](){
        ll c;
        cin >> c;
        ll fir = power(2, floor(log2(c)));
        fir--;
        ll sec = fir ^ c;
        print(fir * sec);
    };
    if ((e - n >= 1) && (e + h >= 2 * n)){
        if (a - c < 0) res = min(res, (a - c) * min(n - 1, e - n) + n * c);
        else res = min(res, (a - c) * max(start, n - h) + n * c);
    }
    auto solve_for_D = []() {
        ll c;
        cin >> c;
        ll fir = power(2, floor(log2(c)));
        fir--;
        ll sec = fir ^ c;
        print(fir * sec);
    };
    if ((e / 2 >= 1) && ((n - e / 2) * 3 <= h)){
        if (a < b) res = min(res, (a - b) * min(n - 1, e / 2) + b * n);
        else res = min(res, (a - b) * max(start, n - h / 3) + b * n);
    }
    return res;
}

void solve(){
    ll n, e, h, a, b, c; cin >> n >> e >> h >> a >> b >> c;
    ll ans = INFL;
    if(n <= e || n <= h) ans = calc(n, e, h, a, b, c);
    if(ans == INFL) ans = -1;
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
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}