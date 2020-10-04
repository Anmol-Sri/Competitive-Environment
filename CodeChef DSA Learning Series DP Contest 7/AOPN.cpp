#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> num;
ll DP[20][2][2][2][11][11];

ll a, b;
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

ll call(int pos, int odd, int even ,int f,int cnt, int last){
    if(pos == num.size()){
        if(odd == 1 &&  even == 1) return 1;
        else return 0;
    }

    if(DP[pos][odd][even][f][cnt][last] != -1) return DP[pos][odd][even][f][cnt][last];
    ll res = 0;

    int LMT ;

    if(f == 0){
        /// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        LMT = num[pos];
    } else {
        /// The number has already become smaller than b. We can place any digit now.
        LMT = 9;
    }

    /// Try to place all the valid digits such that the number doesn't exceed b
    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f, to = odd, te = even;
        // int ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        // if(dgt == d) ncnt++;
        if(dgt == last && pos > 1) to = 1; // cur digit == sec. last entered digit even palindrome string made
        if(dgt == cnt && pos > 0) te = 1; // cur  digit ==  last digit entered odd palindrome string made 
        if(cnt == 10 && dgt == 0) res += call(pos + 1, to, te, nf, 10, cnt);  // if first iteration of digit
        else res += call(pos + 1, to, te, nf, dgt, cnt);
    }

    return DP[pos][odd][even][f][cnt][last] = res;
}

ll calc(ll b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
	return max(0LL, call(0,0,0,0,10,10));
}

void solve(){
	cin >> a >> b;
	cout << calc(b) - calc(a) << "\n";
	return ;
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}