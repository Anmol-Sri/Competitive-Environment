#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e3 + 5;
int dp[mxN][11];
int arr[11];
int m;

bool recur(int  i, int left, int right, vector<  int > weights, int prev = -1){
	if(i == m){
		cout << "YES\n";
		for(int qwe : weights){
			cout << qwe << " ";
		}
		exit(0) ;
	}
	if(i < m){
		bool ok = false;
		if(i % 2 == 0){
			for(int qwe = 1; qwe < 11; qwe++){
				if(arr[qwe] == 1 && qwe + left > right && prev != qwe){
					ok = true;
					weights.push_back(qwe);
					bool asd = recur(i + 1, left + qwe, right, weights, qwe);
					weights.pop_back();
				}
			}
		}
		else{
			for(int qwe = 1; qwe < 11; qwe++){
				if(arr[qwe] == 1 && qwe + right > left && prev != qwe){
					ok = true;
					weights.push_back(qwe);
					bool asd = recur(i + 1, left, right + qwe, weights, qwe);
					weights.pop_back();
				}
			}
		}
		if(!ok){
			return false;
		}
	}
	return false;
}

void solve(){
	string s;
	cin >> s >> m;

	for(int i = 0; i < 10; i++){
		arr[i + 1] = s[i] - '0';
	}
	// cout << endl;
	// for(int i = 1; i < 11; i++){
	// 	cout << arr[i] << " ";
	// }
	// int  left = 0;
	// int right = 0;

	/*for(int i = 0; i < m; i++){
		if(i % 2 == 0){
			for(int j = 1; j < 11; j++){
				if(arr[i] && i + left > right){
					dp[i][j] = 1;
				}
				else{
					dp[i][j] = -1;
				}
			}
		}
		else{
			for(int j = 1; j < 11; j++){
				if(arr[i] && i + right > left){
					dp[i][j] = 1;
				}
				else{
					dp[i][j] = -1;
				}
			}
		}
		bool ok = false;
		for(int j = 1; j < 11; j++){
			if(dp[i][j] != -1){
				ok = true;
			}
		}
		if(!ok){
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
	for(int i = 0; i < )
	return ;*/

	vector < int > qwe;
	bool asd = recur(0, 0, 0, qwe);
	if(!asd){
		cout << "NO\n";
	}
	return  ;
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
	// cin>>t;

	while(t--){
		solve();
	}

	return 0;
}