#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	int  mx = 0;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		if(x <= mx) mx = max(mx, y);
	}
	if(mx < m) cout << "NO\n";
	else cout << "YES\n";
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