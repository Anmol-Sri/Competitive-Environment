#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	string s;
	cin >> s;
	if(s.size() == 1){
		cout << s << "\n";
		return ;
	}
	string ans = "";
	
	for(int i = 0; i < s.size(); i++){
		if(ans.size() >= 2 && ans[ans.size() - 1] == ans[ans.size() - 2] && ans[ans.size() - 1] == s[i]) continue;
		else if(ans.size() >= 3 && ans[ans.size() -2] == ans[ans.size() - 3] && ans[ans.size() - 1] == s[i]) continue;
		else ans += s[i];
	}
	cout << ans << "\n";
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