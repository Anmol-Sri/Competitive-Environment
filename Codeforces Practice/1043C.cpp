#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	string s;
	cin >> s;
	vector < int > ans(s.size(), 0);
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'a'){
			if(i != 0) ans[i  - 1] = 1;
			while(s[i + 1] == 'a') i++;
			ans[i] = 1;
		}
	}
	for(int x : ans) cout << x << " ";
	cout << "\n";
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