#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i + i + 1 < n && s.substr(0, i + 1) == s.substr(i + 1, i + 1)){
			ans = max(ans, i + 1);
		}
	}
	if(ans == 0) cout << n << "\n";
	else cout << n - ans + 1<< "\n";
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

	while( t-- ){
		solve();
	}

	return 0;
}