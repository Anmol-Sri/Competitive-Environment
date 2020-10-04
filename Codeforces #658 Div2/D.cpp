#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector< int > arr(2*n);
	for(auto &x : arr) cin >> x;
	vector < int > a;
	vector < int > cur;
	for(auto &x : arr){
		if(cur.size() && cur.front() > x){

		}
		else{
			a.push_back(cur.size());
			cur.clear();
		}
		cur.push_back(x);
	}
	a.push_back(cur.size());
	/* // debug(a)....
	for(auto x : a) cout << x << " ";
	cout << "\n";*/
	
	 // Method - 1 For  Subset Sum DP 
	bitset < 4001 > res;
	res[0] = 1;
	for(auto x : a){
		res |= res << x;
	}
	if(res[n]) cout << "YES\n"; else cout << "NO\n";
	return ;
	/*// Method - 2 For Subset Sum DP
	vector < vector < int > > dp(a.size() + 1, vector < int > (n + 1, 0));
	dp[0][0] = 1;
	for(int i = 1; i <= a.size(); i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] |= dp[i - 1][j];
			if(j >= a[i - 1]){
				dp[i][j] |= dp[i - 1][j - a[i - 1]]; 
			}
		}
	}
	if(dp[a.size()][n]) cout << "YES\n";
	else cout << "NO\n";
	return ; */

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