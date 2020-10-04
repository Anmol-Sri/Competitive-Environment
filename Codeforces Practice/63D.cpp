#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int row = max(b, d);
	int col = a + c;
	char ans[row][col];
	int dy;
	if(a % 2 == 1) dy = -1; else dy = 1;
	memset(ans, '.', sizeof ans);
	int idx = 0;
	int cnt = 0;
	for(int i = 0; i < col; i++){
		int lim = (i < a) ? b : d;
		int start = (dy == 1) ? 0 : lim - 1;
		int end = (dy == 1) ? lim - 1 : 0;
		for(int j = start; j != end + dy; j += dy){
			ans[j][i] = (char)(idx + 'a');
			cnt++;
			if(cnt == arr[idx]) idx++, cnt = 0;
		}
		if(dy == 1) dy = -1;
		else dy = 1;
	}
	cout << "YES\n";
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << ans[i][j] ;
		}
		cout << "\n";
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