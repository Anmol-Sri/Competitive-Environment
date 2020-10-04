#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(string a){
	for(int i = 1; i < a.size(); i++){
		if(abs(a[i - 1] - a[i]) == 1){
			return false;
		}
	}
	return true;
}

void solve(){
	string s;
	cin >> s;
	string o = "";
	string e = "";
	// a - 97 - 122
	// A - 65 - 90
	for(int i = 0; i < s.size(); i++){
		if(s[i] % 2 == 0){
			o += s[i];
		}
		else{
			e += s[i];
		}
	}
	sort(o.begin(), o.end());
	sort(e.begin(), e.end());
	string one = o + e;
	string two = e + o;
	if(check(one)){
		cout << one << "\n";
	}
	else if(check(two)){
		cout << two << "\n";
	}
	else{
		cout << "No answer\n";
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