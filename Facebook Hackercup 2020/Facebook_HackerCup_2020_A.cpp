#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(char ch){
	if(ch == 'Y') return true;
	return false;
}

void solve(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	bool pos[n][n];
	memset(pos, false, sizeof pos);
	int i = 0;
	while(i < n){
		int j = 0;
		while(j < n){
			if(i == j){
				pos[i][i] = true;
				j++;
				continue;
			}
			bool inc = check(a[j]);
			bool out = check(b[i]);
			pos[i][j] = inc && out;
			for(int k = min(i, j) + 1; k < max(i, j); k++){
				bool ti = check(a[k]);
				bool to = check(b[k]);
				pos[i][j] = pos[i][j] && (ti && to);
			}
			j++;
		}
		i++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(pos[i][j]) cout << "Y";
			else cout << "N";
		}
		cout << "\n";
	}
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("travel_restrictions_input.txt","r",stdin);
		freopen("Aout.txt","w",stdout);
	#endif
		
	int t;
	cin>>t;

	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ":\n";
		solve();
	}

	return 0;
}