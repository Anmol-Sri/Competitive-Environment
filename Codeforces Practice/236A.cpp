#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	string s;
	cin >> s;
	map< char , int > mp;
	for(char c: s) mp[c]++;
	if(mp.size() & 1){
		cout << "IGNORE HIM!";
	}
	else{
		cout << "CHAT WITH HER!";
	}
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
	// cin>>t;

	while(t--){
		solve();
	}

	return 0;
}