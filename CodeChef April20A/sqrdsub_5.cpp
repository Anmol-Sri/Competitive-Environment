#include <bits/stdc++.h>
using namespace std;
#define ll long int
typedef pair<long long, int> ii;

void SQRDSUB() { /// CodeChef
 int t; cin >> t;
 while (t--) {
 long long n; cin >> n;
 vector<ii> pos;
 pos.push_back(ii(-1, 0));
 for (int i = 0; i < n; i++) {
 long long x; cin >> x;
 x = fabs(x);
 if (x % 4 == 2) pos.push_back(ii(i, 1));
 else if (x % 4 == 0) pos.push_back(ii(i, 0));
 }
 pos.push_back(ii(n, 0));
 /*
 for (int i = 0; (int)pos[i].size() > 0; i++) {
 int len = pos[i].size();
 for (int j : pos[i]) cout << j << ' ';
 cout << '\n';
 }
 */
 long long res = n * (n + 1);
 res /= 2LL;
 int len = pos.size();
 for (int i = 1; i < len - 1; i++) {
 if (pos[i].second == 0) continue;
 long long tmp = (pos[i].first - pos[i - 1].first);
 tmp *= (pos[i + 1].first - pos[i].first);
 res -= tmp;
 }
 cout << res << '\n';
 }
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

	while(t--){
		solve();
	}
    return 0;
}