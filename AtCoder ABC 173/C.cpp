#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int h, w, k;
	cin >> h >> w >> k;
	char s[h][w];
	for( int i = 0; i < h; i++){
		for( int j = 0; j < w; j++){
			cin >> s[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < (1 << h) - 1; i++){
		for(int j = 0; j < (1 << w) - 1; j++){
			int black = 0;
			for(int x = 0; x < h; x++){
				for(int y = 0; y < w; y++){
					if(((i >> x) & 1) == 0 && ((j >> y) & 1) == 0 && s[x][y] == '#'){
						black++;
					}
				}
			}
			if(black == k){
				ans++;
			}
		}
	}
	cout << ans << "\n";
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