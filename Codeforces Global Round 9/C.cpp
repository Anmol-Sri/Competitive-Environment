#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(int i =0; i < n; i++){
		cin >> arr[i];
	}
	stack< int > s;
	for(int i = n - 1; i >= 0; i--){
		if(s.empty() || i==0){
			s.push(arr[i]);
			continue;
		}
		if(s.top()>arr[i]){
			continue;
		}
		else{
			s.push(arr[i]);
		}
	}
	bool ok = true;
	int start = s.top();
	s.pop();
	while(!s.empty()){
		if(s.top()<start){
			ok =false;
			break;
		}
		s.pop();
	}
	if(ok){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	/*if(s.size() == 1){
		cout << "YES\n";
	}
	else if(s.size() == 2){
		int x = s.top();
		s.pop();
		int y = s.top();
		if(x < y){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	else{
		cout << "NO\n";
	}*/
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}