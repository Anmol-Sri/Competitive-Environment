#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool cont(string s){
	string asd = "abacaba";
	int cnt = 0;
	for(int i = 0; i <= s.size() - 7; i++){
		if(s.substr(i, 7) == asd) cnt++;
	}
	if(cnt == 1) return true;
	return false;
}

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string check = "abacaba";
	bool ans = true;
	int cnt = 0;
	for(int i = 0; i <= n - 7; i++){
		if(s.substr(i, 7) == check) cnt++;
	}
	if(cnt > 1){
		cout << "No\n";
		return;
	}
	else if(cnt == 1){
		cout << "Yes\n";
		for(int i = 0; i < n; i++){
			if(s[i] == '?') cout << "z";
			else cout << s[i] ;
		}
		cout << "\n";
		return ;
	}
	else{
		for(int i = 0; i <= n - 7; i++){
			bool ok = true;
			for(int j = i; j < i + check.size(); j++){
				if(s[j] == '?') continue;
				else if(s[j] != check[j - i]){
					ok = false;
					break;
				}
			}
			if(ok){
				string temp = "";
				for(int j = 0; j < i; j++){
					if(s[j] == '?') temp +=  "z";
					else temp += s[j];
				}
				temp += check ;
				for(int j = i + 7; j < n; j++){
					if(s[j] == '?') temp += "z";
					else temp += s[j];
				}
				if(cont(temp)){
					cout << "Yes\n";
					cout << temp << "\n";
					return ;
				}
			}
		}
	}
	cout << "No\n";
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