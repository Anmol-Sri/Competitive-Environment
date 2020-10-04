#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int n, m;
 
bool check_func(int **arr, int x, int y){
	ld t1 = arr[x][y];
	ld t2 = 0, count = 0,t3 = 0, t4 = 0, t5 = 0;
	for (int i = x+1; i < n; ++i){
		if(arr[i][y] == 0) 
			continue;
		count++;
		t3 = arr[i][y];
		break;
	}
	for (int i = x-1; i >= 0; --i){
		if(arr[i][y] == 0)
			 continue;
		count++;
		t2 = arr[i][y];
		break;
	}
	 
	for (int i = y+1; i < m; ++i){
		if(arr[x][i] == 0) 
			continue;
		count++;
		t5 = arr[x][i];
		break;
	}
	for (int i = y-1; i >= 0; --i){
		if(arr[x][i] == 0)
			 continue;
		count++;
		t4 = arr[x][i];
		break;
	}
	 
	if(count != 0){
		ld avg = (t4 + t5 + t2 + t3) / count;
		return (t1 < avg);
	}
	else {
		return false;
	}
 
}
 
 
void solve(){
	cin >> n >> m;
	int **arr = new int *[n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j]; 
	bool check = false;
	ll ans = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
			ans += arr[i][j];
		}
	 
	int tempcount = 3;

	while(!check){
		check = true;
		vector<pair<int, int> > called;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if(arr[i][j] == 0)
					 continue;
				if(check_func(arr, i, j)){
				check = false;
				called.push_back({i, j});
				}
			}
		}
	 
		for (auto i: called){
			arr[i.first][i.second] = 0; 
		}
		if(!check){
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j){
				ans += arr[i][j];
				}
			}
		}
	}
	cout << ans << "\n";
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	for (int i = 1; i <= t; i++)
	{
	cout << "Case #" << i << ": ";
	solve();
	}
    return 0;
}