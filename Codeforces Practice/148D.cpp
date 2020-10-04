#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e3 + 1;
map< pair < int , int > , double > dp;

double calc(int w, int b){
	if(w <= 0) return 0;
	if(b <= 0) return 1;
	pair < int, int > cur = {w, b};
	if(dp.find(cur) != dp.end()) return dp[cur];
	double prince_win = ((double)w * 1.0)/(w + b);
	double cont = ((double)b * 1.0)/(w + b);
	// black mice decrease since to continue the process the prince should have taken the black mice
	b--;
	cont *=  ((double)b * 1.0)/(w + b);
	b--;
	if (cont > 1e-13) {
		double if_black_jumps_out = calc(w, b - 1) * ((double)b * 1.0)/(w + b);
		double if_white_jumps_out = calc(w - 1, b) * ((double)w * 1.0)/(w + b);
		prince_win += cont * (if_white_jumps_out + if_black_jumps_out);
	}	
	dp[cur] = prince_win;
	return prince_win;
}

void solve(){
	int  w, b;
	cin >> w >> b;
	cout << fixed << setprecision(12) ;
	cout << calc(w, b) << "\n";
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}