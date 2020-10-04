#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n, c;
  cin>>n>>c;
  map <pair <int, int>, vector <pair <int, int>>> cont;
  for(int i = 1; i <= n; i++) {
	int x, y;
	cin>>x>>y;
	cont[make_pair(x - y, ((x % c) + c) % c)].emplace_back(x, y);
  }
  int checkpoint = cont.size();
  long long moves = 0;
  for(auto i : cont) {
	auto v = i.second;
	sort(v.begin(), v.end());
	auto pivot = v[v.size() / 2];
	for(auto j : v) {
	  moves += abs(pivot.first - j.first) / c;
	}
  }
  cout<<checkpoint<<" "<<moves<<"\n";
  return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		clock_t tStart = clock();
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
	#ifndef ONLINE_JUDGE
		cerr<<fixed<<setprecision(10)<<"Time Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
	#endif

	return 0;
}