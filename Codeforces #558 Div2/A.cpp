#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	if(m == 0) cout << 1 << "\n";
	else if(m == n) cout << 0 << "\n";
	else{
		if(m > n - m) cout << n - m << "\n";
		else cout << m << "\n";
	}
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