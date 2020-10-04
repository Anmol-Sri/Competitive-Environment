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

ll mult(ll a,ll b){ return (a*b)%MOD; }

ll div_calc(ll n,ll k){
	if (k==0) return 1;
	ll a = div_calc(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n); else return a;
}

ll divide(ll a,ll b){ return mult(a,div_calc(b,MOD-2)); }
ll sub(ll a,ll b){ if (a-b>=0) return a-b; return a-b+MOD; }
ll add(ll a,ll b){ if (a+b>=MOD) return a+b-MOD;return a+b; }

ll n, k;
int val[100];
string res[100];
int i;
int next(){
	if(k == 2) return (n - 6) % 8 + 6;
	else if(k == 3) return (n - 12) % 16 + 12;
	return (n - 32) % 32 + 32;
}

void solve(){
	cin>>n;
	switch(k){
		case 1 :
				switch(n % 4){
					case 0 : cout << "0\n";  i = 1; while(i <= n){ cout << "1001"; i = i + 4;} break;
					case 1 : cout << "1\n"; cout << "1";  i = 2; if(4 < n) while(i <= n){ cout << "1001"; i = i + 4;} break;
					case 2 : cout << "1\n"; cout << "10";  i = 3; if(4 < n) while(i <= n){ cout << "1001"; i = i + 4;} break;
					default : cout << "0\n"; cout << "001";  i = 4; if(4 < n) while(i <= n){ cout << "1001"; i = i + 4;} break;
				}
				cout << "\n";
				break;
		case 2 :
				res[0] = "";
				res[1] = "1";
				res[2] = "01";
				res[3] = "001";
				res[4] = "0001";
				res[5] = "01001";
				res[6] = "101001";
				res[7] = "1101001";
				res[8] = "01101001";
				res[9] = "101101001";
				res[10] = "1000111010";
				res[11] = "10111000101";
				res[12] = "000000001101";
				res[13] = "0110100010101";
				val[0] = 0;
				val[1] = 1;
				val[2] = 3;
				val[3] = 4;
				val[4] = 2;
				val[5] = 3;
				val[6] = 1;
				val[7] = 0;
				val[8] = 0;
				val[9] = 1;
				val[10] = 1;
				val[11] = 0;
				val[12] = 0;
				val[13] = 1;

				if(n > 13){
					cout << val[next()] << "\n" << res[next()];
					int i = next();
					while(i < n){ cout << res[8]; i += 8;}
				}
				else cout << val[n] << "\n" << res[n];
				cout << "\n";
				break;
		case 3 :
				res[0] = "";
				res[1] = "1";
				res[2] = "01";
				res[3] = "001";
				res[4] = "0001";
				res[5] = "00001";
				res[6] = "010001";
				res[7] = "0001110";
				res[8] = "00110110";
				res[9] = "011010110";
				res[10] = "0000000101";
				res[11] = "00001101001";
				res[12] = "001011100110";
				res[13] = "0000111011010";
				res[14] = "01011001101001";
				res[15] = "001111010111100";
				res[16] = "1001011001101001";
				res[17] = "10010110111110010";
				res[18] = "010011010101011010";
				res[19] = "1100110110100111100";
				res[20] = "01011111110111111000";
				res[21] = "001010011111111010010";
				res[22] = "0001000111111101111000";
				res[23] = "10001111101111110111000";
				res[24] = "101011110110111110111000";
				res[25] = "0001111011111111111110000";
				res[26] = "01001111110101101101111000";
				res[27] = "011101101111111011111110000";
				val[0] = 0;
				val[1] = 1;
				val[2] = 7;
				val[3] = 18;
				val[4] = 28;
				val[5] = 25;
				val[6] = 7;
				val[7] = 26;
				val[8] = 4;
				val[9] = 5;
				val[10] = 1;
				val[11] = 12;
				val[12] = 0;
				val[13] = 1;
				val[14] = 1;
				val[15] = 0;
				val[16] = 0;
				val[17] = 1;
				val[18] = 1;
				val[19] = 0;
				val[20] = 0;
				val[21] = 1;
				val[22] = 1;
				val[23] = 0;
				val[24] = 0;
				val[25] = 1;
				val[26] = 1;
				val[27] = 0;
				val[28] = 0;

				if(27 < n){
					cout << val[next()] << "\n"  << res[next()];
					int i = next();
					while(i < n){ cout << res[16]; i = i + 16;}
				}
				else cout << val[n] << "\n" << res[n];
				cout << "\n";
				break;
		case 4 :
				res[0] = "";
				res[1] = "1";
				res[2] = "10";
				res[3] = "110";
				res[4] = "1110";
				res[5] = "11110";
				res[6] = "111110";
				res[7] = "1111110";
				res[8] = "11010001";
				res[9] = "111110001";
				res[10] = "1010110110";
				res[11] = "11111010110";
				res[12] = "110010101001";
				res[13] = "1101001010110";
				res[14] = "11111110000101";
				res[15] = "100001110101001";
				res[16] = "0000111000001110";
				res[17] = "10000111111101010";
				res[18] = "111111001011110001";
				res[19] = "1000010010110111100";
				res[20] = "00001010110111011100";
				res[21] = "111111111011011011100";
				res[22] = "0101001111011111110100";
				res[23] = "00001000100110111101100";
				res[24] = "000010011110110111110100";
				res[25] = "1000110101011101111111000";
				res[26] = "11101011111011101111001010";
				res[27] = "001111000000011110111111000";
				res[28] = "0001011111000101111011111000";
				res[29] = "11101111111011001110111010001";
				res[30] = "100010010001010111111111011000";
				res[31] = "1101100001110111011111111101000";
				res[32] = "10010110011010010110100110010110";
				res[33] = "110010110011010010110100110010110";
				res[34] = "1010101110111111111011101111101000";
				res[35] = "01000111001011010111111101111110000";
				res[36] = "100101010100011101111111111011110000";
				res[37] = "0000000001010000000000010110010111010";
				res[38] = "00000000000000011011101011011100101010";
				res[39] = "000000000000000110101011101000101011001";
				res[40] = "0000000000000010101001011110111010111000";
				res[41] = "00000000000000000010111011100010111000101";
				res[42] = "000000000000000000010010000000000110010111";
				res[43] = "0000000000000000101111101111111110000110001";
				res[44] = "00000000000000000111110110101110101100101010";
				res[45] = "000000000000000000010100100000000110010011011";
				res[46] = "0000000000000000000011011011101010001110101010";
				res[47] = "00000000000000000010101011011110111010101001001";
				res[48] = "111100011111000110010110011010010110100110010110";
				res[49] = "1111110100110100110010110011010010110100110010110";
				res[50] = "00000000000000000000000000000000010010101100011011";
				res[51] = "111001100000011011010010110011010010110100110010110";
				res[52] = "1111010100100010001110010110011010010110100110010110";
				res[53] = "00000000000000000000000000000001110010100101011010110";
				res[54] = "111100111110010001010110010110011010010110100110010110";
				res[55] = "1111110010011100010001110010110011010010110100110010110";
				res[56] = "11111101100000000001111010010110011010010110100110010110";
				res[57] = "111101010110001001101101010010110011010010110100110010110";
				res[58] = "0000000000000000000000000000000000000011001010011010110011";
				res[59] = "11111101010100110011001011010010110011010010110100110010110";
				res[60] = "111111110111001101000000011110010110011010010110100110010110";
				res[61] = "0000000000000000000000000000000000000000101010111111011100001";
				res[62] = "10001001000101011111111101100010010110011010010110100110010110";
				res[63] = "110110000111011101111111110100010010110011010010110100110010110";
				res[64] = "1001011001101001011010011001011010010110011010010110100110010110";
				res[65] = "11001011001101001011010011001011010010110011010010110100110010110";
				res[66] = "101010111011111111101110111110100010010110011010010110100110010110";
				res[67] = "0100011100101101011111110111111000010010110011010010110100110010110";
				res[68] = "10010101010001110111111111101111000010010110011010010110100110010110";
				res[69] = "000000000101000000000001011001011101010010110011010010110100110010110";
				val[0] = 0;
				val[1] = 1;
				val[2] = 15;
				val[3] = 64;
				val[4] = 158;
				val[5] = 271;
				val[6] = 317;
				val[7] = 126;
				val[8] = 34;
				val[9] = 253;
				val[10] = 13;
				val[11] = 92;
				val[12] = 30;
				val[13] = 47;
				val[14] = 31;
				val[15] = 2;
				val[16] = 0;
				val[17] = 1;
				val[18] = 13;
				val[19] = 0;
				val[20] = 0;
				val[21] = 9;
				val[22] = 1;
				val[23] = 0;
				val[24] = 0;
				val[25] = 1;
				val[26] = 5;
				val[27] = 0;
				val[28] = 0;
				val[29] = 5;
				val[30] = 1;
				val[31] = 0;
				val[32] = 0;
				val[33] = 1;
				val[34] = 1;
				val[35] = 0;
				val[36] = 0;
				val[37] = 1;
				val[38] = 1;
				val[39] = 0;
				val[40] = 0;
				val[41] = 1;
				val[42] = 1;
				val[43] = 0;
				val[44] = 0;
				val[45] = 1;
				val[46] = 1;
				val[47] = 0;
				val[48] = 0;
				val[49] = 1;
				val[50] = 1;
				val[51] = 0;
				val[52] = 0;
				val[53] = 1;
				val[54] = 1;
				val[55] = 0;
				val[56] = 0;
				val[57] = 1;
				val[58] = 1;
				val[59] = 0;
				val[60] = 0;
				val[61] = 1;
				val[62] = 1;
				val[63] = 0;
				val[64] = 0;
				val[65] = 1;
				val[66] = 1;
				val[67] = 0;
				val[68] = 0;
				val[69] = 1;
				if(61 < n){
					cout << val[next()] << "\n" << res[next()];
					int i = next();
					while(i < n){ cout << res[32]; i = i + 32; }
				}
				else cout << val[n] << "\n" << res[n];
				cout << "\n";
				break;	
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

	cin >> k;
	int t = 1;
	cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}