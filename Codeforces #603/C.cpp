#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin >> n;
	set<int> ans;
	int s = (int)sqrtl(n);
	for (int i = 0; i <= s; i++)
		ans.insert(i);
	for (int i = 1; i <= s; i++)
		ans.insert(n / i);
	//sort(ans.begin(), ans.end());
	//s.resize(unique(ans.begin(), ans.end()) - ans.begin());
	cout << ans.size() << endl;
	for (int x : ans)
		cout << x << " ";
	cout << endl;
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}