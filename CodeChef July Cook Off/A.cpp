#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int fre[26] = {0};
	for(char c : s){
		fre[c - 'a']++;
	}
	bool ok = true;
	for(int i = 0; i < 26; i++){
		if(fre[i]%2 != 0){
			ok = false;
			break;
		}
	}
	if(ok){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}