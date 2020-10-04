#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e6 + 1;
struct Point{
	int x, y, id;
	bool operator < (Point a){
		if((x / 1000) != (a.x / 1000)) return (x / 1000) < (a.x / 1000);
		if((x / 1000) & 1) return y < a.y;
		return y > a.y;
	}
};

void solve(){
	int n;
	cin >>  n;
	Point p[n];
	for(int i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;
		p[i].id = i; 
	}
	sort(p, p + n);
	for(auto x : p) cout << x.id + 1 << " ";
	cout << "\n";
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