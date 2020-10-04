#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int cap[n + 1] = { 0 };
	int arr[n + 1] = { 0 };
	set<int > s;
	for(int i = 1; i <= n; i++){
		cin >> cap[i];
		s.insert(i);
	}
	int m;
	cin >> m;
	while(m--){
		int ch;
		cin >> ch;
		if(ch == 1){
			int p, x;
			cin >> p >> x;
			while(x > 0){
				auto it = s.lower_bound(p);
				auto i = *it;
				if(it == s.end()) break;
				ll prev = arr[i];
				arr[i] = min(arr[i] + x, cap[i]);
				if(arr[i] == cap[i]){
					p++;
					x -= arr[i] - prev;
					s.erase(i);
				}
				else{
					x = 0;
				}
			}
		}
		else{
			int k;
			cin >> k;
			cout << arr[k] << "\n";
		}
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