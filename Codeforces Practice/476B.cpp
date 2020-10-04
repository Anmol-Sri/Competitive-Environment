#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int ans;

void recur(int x, int cur, int pos){
	if(x == 0){
		if(cur == pos) ans++;
		return ;
	}
	recur(x - 1, cur + 1, pos);
	recur(x - 1, cur - 1, pos);
}

void solve(){
	string a, b;
	cin >> a >> b;
	int cnt = 0;
	int org = 0;
	int cur = 0;
	for(int i = 0; i < a.size(); i++){
		org += (a[i] == '+') ? 1 : -1;
		if(b[i] == '+') cur++; else if(b[i] == '-') cur--;
		cnt += (b[i] == '?') ? 1 : 0;
	}
	cout << fixed << setprecision(12);
	double prb = 0.0;
	if(cnt == 0){
		if(org == cur) prb = 1.0;
		cout << prb << "\n";
		return ;
	}
	bool ok = false;
	ans = 0;
	recur(cnt, cur, org);
	if(ans != 0) prb = ((double)(ans)) / ((double)(pow(2, cnt)));
	cout << prb << "\n";
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