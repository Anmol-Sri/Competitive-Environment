#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, a;

void solve(){
	cin >> n >> a;
	int ans = 2;
	for(int i = 3; i < n; i++){
		if(abs(a * n - 180 * (n - i)) < abs(a * n - 180 * (n - ans))) ans = i;
	}
	cout << "1 2 " << ans + 1 << "\n";
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