#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, x;
	cin >> n >> x;
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(x % i == 0 && x / i <= n) cnt++;
	cout << cnt << "\n";
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