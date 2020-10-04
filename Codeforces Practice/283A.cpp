#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll mxN = 2e5 + 10;
ll add[mxN];
ll val[mxN];
void solve(){
	int n ;
	cin >> n;
	ll pos = 1;
	ll sum = 0;
	while(n--){
		int ch ;
		cin >> ch;
		if(ch == 1){
			int a, x;
			cin >> a >> x;
			sum += 1LL * a * x;
			add[a] += x;
		}
		else if(ch  == 2){
			int x;
			cin >> x;
			val[++pos] = x;
			sum += x;
			add[pos] = 0;
		}
		else{
			sum -= add[pos] + val[pos];
			add[pos - 1] += add[pos];
			pos--;
		}
		double avg = ((double)sum)/((double)pos);
		cout << avg << "\n";
	}	
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
		
	cout << fixed << setprecision(12) ;	
	int t = 1;
	// cin>>t;

	while(t--){
		solve();
	}

	return 0;
}