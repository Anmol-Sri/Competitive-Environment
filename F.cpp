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

// CPP program to find maximum points that can
// be collected in a journey from top to bottom
// and then back from bottom to top,
// #include <bits/stdc++.h>
// using namespace std;
// #define MAX 111
// #define N 111
// #define M 111
// #define inf 1e9

// int cost(vector < vector < int > > grid, int row1, int col1, int row2, int col2)
// {
// 	if (row1 == row2 && col1 == col2) {
// 		if (grid[row1][col1] == 1) return 1;
// 		return 0;
// 	}
// 	int ans = 0;
// 	if (grid[row1][col1] == 1) ans++;
// 	if (grid[row2][col2] == 1) ans++;
// 	return ans;
// }

// int solve(int n, int m, vector < vector < int > > grid,int dp[MAX][MAX][MAX], int row1,int col1, int row2)
// {
// 	int col2 = (row1 + col1) - (row2);
// 	if (row1 == n - 1 && col1 == m - 1 && row2 == n - 1 && col2 == m - 1) return 0;
// 	if (row1 >= n || col1 >= m || row2 >= n || col2 >= m) return -1 * inf;
// 	if (dp[row1][col1][row2] != -1) return dp[row1][col1][row2];
// 	int ch1 = -1 * inf, ch2 = -1 * inf;
// 	int ch3 = -1 * inf, ch4 = -1 * inf;
// 	if (grid[row1][col1 + 1] != -1 && grid[row2 + 1][col2] != -1)
// 	ch1 = cost(grid, row1, col1 + 1, row2 + 1, col2) + solve(n, m, grid, dp, row1, col1 + 1, row2 + 1);
// 	if (grid[row1][col1 + 1] != -1 && grid[row2][col2 + 1] != -1)
// 	ch2 = cost(grid, row1, col1 + 1, row2, col2 + 1) + solve(n, m, grid, dp, row1, col1 + 1, row2);
// 	if (grid[row1 + 1][col1] != -1 && grid[row2][col2 + 1] != -1)
// 	ch3 = cost(grid, row1 + 1, col1, row2, col2 + 1) + solve(n, m, grid, dp, row1 + 1, col1, row2);
// 	if (grid[row1 + 1][col1] != -1 && grid[row2 + 1][col2] != -1)
// 	ch4 = cost(grid, row1 + 1, col1, row2 + 1, col2) + solve(n, m, grid, dp, row1 + 1, col1, row2 + 1);
// 	return dp[row1][col1][row2] = max({ch1, ch2, ch3, ch4});
// }
// int wrapper(int n, int m, vector < vector < int > > grid)
// {
// 	int ans = 0;
// 	int dp[MAX][MAX][MAX];
// 	memset(dp, -1, sizeof dp);
// 	if (grid[n - 1][m - 1] == -1 || grid[0][0] == -1) ans = -1 * inf;
// 	if (grid[0][0] == 1) ans++;
// 	grid[0][0] = 0;
// 	if (grid[n - 1][m - 1] == 1) ans++;
// 	grid[n - 1][m - 1] = 0;
// 	ans += solve(n, m, grid, dp, 0, 0, 0);
// 	return max(ans, 0);
// }

// int main()
// {	
// 	// ios_base::sync_with_stdio(false);
// 	// cin.tie(NULL);
// 	// cout.tie(0);

// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt","r",stdin);
// 		freopen("output.txt","w",stdout);
// 	#endif

// 	// cout << setprecision(10) << fixed;
	
// 	int t = 1;
// 	// cin >> t;

// 	for(int i = 1; i <= t; i++){
// 		// cout << "Case #" << i << ": ";
// 		// int n = 5, m = 5;
// 		int n, m; cin >> n >> m;
// 		vector < vector < int > > a(n, vector < int > (m));
// 		for(int i = 0; i < n; i++){
// 			for(int j = 0; j < m; j++){
// 				cin >> a[i][j];
// 			}
// 		}
// 		cout << wrapper(n, m, a) << endl;
// 		return 0;
// 	}

// 	return 0;
// }
// CPP program to find maximum points that can
// be collected in a journey from top to bottom
// and then back from bottom to top,
// #include <bits/stdc++.h>
// using namespace std;
#define MAX 111
#define N 3
#define M 3
#define inf 100000

// Calculating the points at a (row1, col1) &&
// (row2, col2) from path1 && path2
int cost(char grid[][M], int row1, int col1,
						int row2, int col2)
{
	// If both path is at same cell
	if (row1 == row2 && col1 == col2) {

		// If the cell contain *, return 1
		if (grid[row1][col1] == '*')
			return 1;

		// else return 0.
		return 0;
	}

	int ans = 0;

	// If path 1 contain *, add to answer.
	if (grid[row1][col1] == '*')
		ans++;

	// If path contain *, add to answer.
	if (grid[row2][col2] == '*')
		ans++;

	return ans;
}

// Calculate the maximum points that can be
// collected.
int solve(int n, int m, char grid[][M],
		int dp[MAX][MAX][MAX], int row1,
					int col1, int row2)
{
	int col2 = (row1 + col1) - (row2);

	// If both path reach the bottom right cell
	if (row1 == n - 1 && col1 == m - 1 &&
		row2 == n - 1 && col2 == m - 1)
		return 0;

	// If moving out of grid
	if (row1 >= n || col1 >= m ||
		row2 >= n || col2 >= m)
		return -1 * inf;

	// If already calculated, return the value
	if (dp[row1][col1][row2] != -1)
		return dp[row1][col1][row2];

	// Variable for 4 options.
	int ch1 = -1 * inf, ch2 = -1 * inf;
	int ch3 = -1 * inf, ch4 = -1 * inf;

	// If path 1 is moving right and path 2
	// is moving down.
	if (grid[row1][col1 + 1] != '#' &&
		grid[row2 + 1][col2] != '#')
	ch1 = cost(grid, row1, col1 + 1, row2 + 1, col2) +
		solve(n, m, grid, dp, row1, col1 + 1, row2 + 1);

	// If path 1 is moving right and path 2 is moving
	// right.
	if (grid[row1][col1 + 1] != '#' &&
		grid[row2][col2 + 1] != '#')
	ch2 = cost(grid, row1, col1 + 1, row2, col2 + 1) +
			solve(n, m, grid, dp, row1, col1 + 1, row2);

	// If path 1 is moving down and path 2 is moving right.
	if (grid[row1 + 1][col1] != '#' &&
		grid[row2][col2 + 1] != '#')
	ch3 = cost(grid, row1 + 1, col1, row2, col2 + 1) +
		solve(n, m, grid, dp, row1 + 1, col1, row2);

	// If path 1 is moving down and path 2 is moving down.
	if (grid[row1 + 1][col1] != '#' &&
		grid[row2 + 1][col2] != '#')
	ch4 = cost(grid, row1 + 1, col1, row2 + 1, col2) +
		solve(n, m, grid, dp, row1 + 1, col1, row2 + 1);

	// Returning the maximum of 4 options.
	return dp[row1][col1][row2] = max({ch1, ch2, ch3, ch4});
}

// Wrapper Function
int wrapper(int n, int m, char grid[N][M])
{
	int ans = 0;
	int dp[MAX][MAX][MAX];
	memset(dp, -1, sizeof dp);

	// If last bottom right cell is blcoked
	if (grid[n - 1][m - 1] == '#' || grid[0][0] == '#')
		ans = -1 * inf;

	// If top left cell contain *
	if (grid[0][0] == '*')
		ans++;
	grid[0][0] = '.';

	// If bottom right cell contain *
	if (grid[n - 1][m - 1] == '*')
		ans++;
	grid[n - 1][m - 1] = '.';

	ans += solve(n, m, grid, dp, 0, 0, 0);
	return max(ans, 0);
}

// Driven Program
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	// int n = 5, m = 5;
	int n, m; cin >> n >> m;

	// char grid[N][M] = {
	// 	{ '.', '*', '.', '*', '.' },
	// 	{ '*', '#', '#', '#', '.' },
	// 	{ '*', '.', '*', '.', '*' },
	// 	{ '.', '#', '#', '#', '*' },
	// 	{ '.', '*', '.', '*', '.' }
	// };
	char grid[N][M];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	cout << wrapper(n, m, grid) << endl;
	return 0;
}
