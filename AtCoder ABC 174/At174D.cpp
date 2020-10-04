#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int  n;
	cin >> n;
	string s;
	cin >> s;
	int red = 0;
	int white = 0;
	int inv = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'R')red++;
		else white ++;
		if(i > 0){
			if(s[i] == 'R' && s[i - 1] == 'W') inv++;
		}
	}
	if(red == 0 || white == 0 || inv == 0){
		cout << "0\n";
		return ;
	}
	int ans = 0;
	int left = 0, right = n - 1;
	while(left < right){
		if(s[left] == 'W' && s[right] == 'R'){
			ans++;
			left++;
			right--;
		}
		else if(s[left] == 'R') left++;
		else if(s[right] == 'W')right--;
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

	while(t--){
		solve();
	}

	return 0;
}