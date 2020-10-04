#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cntA = 0, cntB = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'A') cntA++;
		else cntB++;
	}
	int x = abs(cntA - cntB);
	if(x == 1) cout << "Y\n"; else cout << "N\n";
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("alchemy_input.txt","r",stdin);
		freopen("Bout.txt","w",stdout);
	#endif
		
	int t;
	cin>>t;

	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}