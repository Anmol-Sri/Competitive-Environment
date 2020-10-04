#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	queue < array < int , 3 > > q;
	set < int > s;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s.insert(x);
		q.push({x - 1, -1, 1});
		q.push({x + 1, 1, 1});
	}
	ll sum = 0;
	vector < int > ans;
	while(m){
		array < int, 3> temp = q.front();
		q.pop();
		if(s.find(temp[0]) != s.end()){
			continue;
		}
		ans.push_back(temp[0]);
		s.insert(temp[0]);
		q.push({temp[0] + temp[1], temp[1], temp[2] + 1});
		sum +=  temp[2];
		m--;
	}
	cout << sum << "\n";
	for(auto x : ans){
		cout << x << " ";
	}
	cout << "\n";
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