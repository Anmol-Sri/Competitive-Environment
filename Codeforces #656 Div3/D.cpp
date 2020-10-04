#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll recur(char ch, ll left, ll right, string &s){
	ll len = (right - left + 1) / 2;
	ll temp = 0;
	if(left == right){
		if(s[left] == ch) {
			return 0;
		}
		else{
			return 1;
		}
	}
	ll i = left;
	while(i < left + len) {
		if(s[i] != ch) temp++;
		i+= 1;
	}
	ll ans = temp + recur(ch + 1, left + len, right, s);
	temp = 0;
	i = left + len;
	while( i <= right) {
		if (s[i] != ch) temp++;
		i+=1;
	}
	ans = min(ans, temp + recur(ch + 1, left, left + len - 1, s));
	return ans;
}

void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll ans = recur('a', 0, n - 1, s);
	cout << ans << "\n";
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