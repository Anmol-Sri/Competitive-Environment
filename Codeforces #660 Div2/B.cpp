#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	char s[n];
	for(int i = 0; i < n; i++) s[i] = '9';
	int last = n - 1;
	if(n %4 == 0){
		for(int i = 0; i < n / 4; i++) s[last] = '8', last--;
	}
	else{
		for(int i = 0; i <= n/4; i++) s[last] = '8', last--;
	}
	for(int i = 0; i < n; i++) cout << s[i];
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}