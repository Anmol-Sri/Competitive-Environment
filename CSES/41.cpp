#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
    int n, k;
    cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ordered_set s;
    for (int i = 0; i < k; i++) s.insert(a[i]);
    ll old_m = *s.find_by_order((k + 1) / 2 - 1);
    ll d = 0;
    for (int i = 0; i < k; i++) d += abs(a[i] - old_m);
    cout << d;
    for (int i = 0; i < n - k; i++) {
        s.erase(s.find_by_order(s.order_of_key(a[i])));
        s.insert(a[i + k]);
        ll m = *s.find_by_order((k + 1)/ 2 - 1);
        d = d + abs(m - a[i + k]) - abs(old_m - a[i]);
        if (k % 2 == 0) d -= (m - old_m);
        old_m = m;
        cout << " " << d;
    }
    cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

/*	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
		
	int t=1;

	while(t--){
		solve();
	}
	return 0;
}