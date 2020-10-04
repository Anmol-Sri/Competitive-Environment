#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	if(n == 0){
		cout << "O-|-OOOO" << "\n";
		return ;
	}
	while(n > 0){
		int d = n % 10;
		n = n / 10;
		string ans = "";
		if(d < 5){
			ans += "O-|";
		}
		else{
			d -= 5;
			ans += "-O|";
		}
		if(d == 0) ans += "-OOOO";
		else if(d == 1) ans += "O-OOO";
		else if(d == 2) ans += "OO-OO";
		else if(d == 3) ans += "OOO-O";
		else if(d == 4) ans += "OOOO-";
		cout << ans << "\n";
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