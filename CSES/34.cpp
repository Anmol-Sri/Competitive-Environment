#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() 
{ 	
	int n, x;
	cin >> n >> x;
	vector<pair<int,int>> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		 arr[i].second = i+1; 
	}
	sort(arr.begin(), arr.end());
	for (int p = 0; p < n; ++p)
	{
		for (int q = p+1; q < n; ++q)
		{
			int reqd = x - arr[p].first - arr[q].first;
			for (int r = q+1, s = n-1; r < s;)
			{
				if (arr[r].first+arr[s].first == reqd) {
					cout << arr[p].second << " " << arr[q].second << " " << arr[r].second << " " << arr[s].second << '\n'; 
					return ; 
				}
				else if (arr[r].first+arr[s].first < reqd) ++r;
				else --s;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return ;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

/*    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}