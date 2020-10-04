#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector< int > prefix_function(string s){
	int n = s.size();
	vector< int > arr(n,0);
	for(int i = 1; i < n; i++){
		int j = arr[i - 1];
		while(j > 0 && s[i] != s[j]) j = arr[j - 1];
		if(s[i] == s[j]) j++;
		arr[i] = j;
	}
	return arr;
}

void solve(){
	string s;
	cin >> s;
	vector < int > prefix = prefix_function(s);
	int  n = prefix.size();
	if(prefix[n - 1] == 0){
		cout << "Just a legend\n";
		return ;
	}
	for(int i = 0; i < n - 1; i++){
		if(prefix[i] == prefix[n - 1]){
			cout << s.substr(n - prefix[n - 1], prefix[i]);
			return ;
		}
	}
	cout << s << "\n";
	for(int a : prefix){
		cout << a << " ";
	}
	cout  << "\n";
	if(prefix[prefix[n - 1] - 1] == 0){
		cout << "Just a legend\n";
		return;
	}
	else{
		cout << s.substr(0, prefix[prefix[n - 1] - 1]) << "\n";
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}