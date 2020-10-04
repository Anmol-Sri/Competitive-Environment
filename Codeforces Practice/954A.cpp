#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = n;
	for(int i = 0; i < n - 1; i++){
		string check = s.substr(i,2);
		if(check == "RU" || check == "UR"){
			ans -= 1;
			i++;
		}
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

	while( t-- ){
		solve();
	}

	return 0;
}