#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string digits[]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
void solve(){
	int n,k;
	cin >> n >> k;
	string s[n];
	for(int i = 0; i < n; i++){
		cin>>s[i];
	}
	int dist[n][10];
	memset(dist, 0, sizeof(dist));

	for(int i = 0; i < n; i++ ){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 7; k++){
				char x = s[i][k];
				char y = digits[j][k];

				if(x == '1' && y == '0'){
					dist[i][j]=-1;
					break;
				}
				if(x == '0' && y == '1'){
					dist[i][j]++;
				}
			}
		}
	}

	int dp[n + 1][k + 1];
	memset(dp, 0, sizeof(dp));
	dp[n][0]=1;
	for(int i = n; i > 0; i--){
		for(int j = 0; j <=k; j++){
			if(dp[i][j]){
				for(int q = 0; q < 10; q++){
					if(dist[i - 1][q] != -1 && j + dist[i - 1][q] <= k){
						dp[i -1][j + dist[i - 1][q]] = 1;
					}
				}
			}
		}
	}

	if(dp[0][k] == 0){
		cout<<"-1\n";
		return ;
	}

	for(int i = 0; i < n; i++){
		int now = -1;
		for(int j = 9; j >= 0; j--){
			if(dist[i][j] != -1 && k >=dist[i][j] && dp[i + 1][k - dist[i][j]]){
				now = j;
				k -= dist[i][j];
				break;
			}
		}
		assert(now != -1);
		cout<<now;
	}
	cout<<"\n";
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
		
	int t=1;

	while(t--){
		solve();
	}

	return 0;
}