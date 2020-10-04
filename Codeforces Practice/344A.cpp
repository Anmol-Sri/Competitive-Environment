#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n ;
	cin >> n;
	int prev = 0;
	int grp = 0;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if (i == 0){
			prev = (s == "10")? -1 : 1;
			grp++;
			continue;
		}
		int cur = (s == "10")? -1 : 1;
		if (cur != prev){
			grp++;
			prev= cur;
		}
	}
	cout << grp << "\n";
	return;
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