#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	unordered_map < int ,  int > mp;
	multiset < int > two, four;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		mp[x]++;
		if(mp[x] > 2 && mp[x] % 4 == 0){
			two.erase(x);
			four.insert(x);
		}
		else if(mp[x] % 2 == 0){
			two.insert(x);
		}
	}
	// cout << four.size() << " " << two.size() << "\n";
	int q;
	cin >> q;
	while(q--){
		char ch;
		cin >> ch;
		int x;
		cin >> x;
		if(ch == '+'){
			mp[x]++;
			if(mp[x] % 4 == 0){
				two.erase(x);
				four.insert(x);
			}
			else if(mp[x] % 2 == 0){
				two.insert(x);
			}
		}
		else{
			mp[x]--;
			if(mp[x] % 4 == 3){
				auto itr = four.find(x);
				if(itr != four.end()){
				    four.erase(itr);
				}
				two.insert(x);
			}
			else if(mp[x] % 4 == 1){
				auto itr = two.find(x);
				if(itr != two.end()){
				    two.erase(itr);
				}
			}
		}
		// cout << mp[x]  << " " << four.size() << " " << two.size() << "\n";

		if(four.size() >= 2 || (four.size() == 1 && two.size() >= 2)){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
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