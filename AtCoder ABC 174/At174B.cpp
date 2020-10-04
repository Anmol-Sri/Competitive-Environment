#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	double  d;
	cin >> n >> d;
	int ans = 0;
	while(n--){
		int x, y;
		cin >> x  >> y;
		double a = 1.0 * x * x;
		double b = 1.0 * y * y;
		double qwe = sqrt(a + b);
		if(qwe <= d) ans++;
	}
	cout << ans << "\n";
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