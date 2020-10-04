#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fi first
#define se second
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
const ll LINF = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int n, k, arr[N], pos[N], b[N];
bool vis[N];
void upd(int x, int y, int z)
{
	assert(x!=y); assert(y!=z); assert(x!=z);
	int store = arr[z];
	arr[z] = arr[y];
	pos[arr[y]] = z; 
	arr[y] = arr[x]; 
	pos[arr[x]] = y;
	arr[x] = store;
	pos[store] = x;
}
void solve()
{
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++) 
	{
		scanf("%d", a+i);
		pos[arr[i]] = i;
	}
	vector <array<int,3>> order;
	for(int i=1; i<=n; i++)
	{
		vis[i] = 0;
		if(i!=pos[i])
		{
			int x = pos[i], y = i, z = arr[i];
			if(z==x) continue;
			order.pb({y, z, x});
			upd(y, z, x);
		}
	}
	vector <pii> swap_order;
	for(int i=1; i<=n; i++)
	{
		if(i!=pos[i] && pos[i]==arr[i] && !vis[pos[i]])
		{
			swap_order.pb({i, pos[i]});
			vis[i] = vis[pos[i]] = 1;
		}
	}
	if(sz(swap_order)&1) 
	{
		puts("-1");
		return;
	}
	for(int i=0; i<sz(swap_order); i+=2)
	{
		int a = swap_order[i].fi, b = swap_order[i].se, c = swap_order[i+1].fi, d = swap_order[i+1].se;
		order.pb({b, c, d});
		upd(b, c, d);
		order.pb({a, b, c});
		upd(a, b, c);
	}
	if(sz(order)>k || !is_sorted(a+1, a+n+1)) puts("-1");
	else
	{
		cout << sz(order) << '\n';
		for(auto it : order) printf("%d %d %d\n", it[0], it[1], it[2]);
	}
}
int main()
{
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}