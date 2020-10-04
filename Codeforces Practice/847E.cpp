#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 2e5 + 1;
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector < int > packman;
	vector < int > food;
	for(int i = 0; i < n; i++){
		if(s[i] == 'P') packman.push_back(i);
		if(s[i] == '*') food.push_back(i);
	}
	int l = 0;
	int r = 3 * n;

	while(l < r){
		int mid = (l + r) >> 1;
		int cnt = 0;
		for(int x : packman){
			int from = x, to = x;
			while(cnt < food.size()){
				from = min(from , food[cnt]);
				to = max(to, food[cnt]);
				int need = to -  from + min(to - x, x - from);
				if(need > mid){
					break;
				}
				cnt++;
			}
		}
		if(cnt == food.size()) r = mid;
		else l = mid + 1;
	}
	cout << l << "\n";
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