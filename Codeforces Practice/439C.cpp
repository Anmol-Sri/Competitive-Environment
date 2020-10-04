#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, k, p;
	cin >> n >> k >> p;
	int ne = p;
	int no = k - p;
	set< int >  odd, even;
	int	x;
	vector< int > ans[k];
	vector<ll> sum(k, 0);
	for(int i = 0; i < n; i++){
		cin >> x;
		if(x & 1){
			odd.insert(x);
		}
		else{
			even.insert(x);
		}
	}
	int exact_odd = odd.size();
	int exact_even = even.size();
	if(exact_odd < no){
		cout << "NO\n";
		return ;
	}
	else if(exact_even < ne && (ne - exact_even) > (exact_odd - no)/2){
		cout << "NO\n";
		return ;
	}
	for(int i = 0; i < no; i++){
		ans[i].push_back(*odd.begin());
		sum[i] += *odd.begin();
		odd.erase(odd.begin());
	}
	for(int i = no; i < k ; i++){
		if(even.size() > 0){
			ans[i].push_back(*even.begin());
			sum[i] += *even.begin();
			even.erase(even.begin());
		}
		else{
			if(odd.size() < 2){
				cout << "NO\n";
				return;
			}
			ans[i].push_back(*odd.begin());
			sum[i] += *odd.begin();
			odd.erase(odd.begin());		
			ans[i].push_back(*odd.begin());
			sum[i] += *odd.begin();
			odd.erase(odd.begin());
		}
	}
	while(even.size()){
		ans[k - 1].push_back(*even.begin());
		even.erase(even.begin());
	}
	ll rem = 0;
	vector<int > left ;
	while(odd.size()){
		left.push_back(*odd.begin());
		rem += *odd.begin();
		odd.erase(odd.begin());
	}
	bool ok = false;
	for(int i = 0; i < no; i++){
		if((sum[i] + rem) & 1){
			ok = true;
			ans[i].insert(ans[i].end(),left.begin(), left.end());
			break;
		}
	}
	if(!ok){
		for(int i = no; i < k; i++){
			if((sum[i] + rem) % 2 == 0){
				ok = true;
				ans[i].insert(ans[i].end(),left.begin(), left.end());
				break;
			}
		}
	}
	if(!ok){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	for(auto x : ans){
		cout << x.size() << " ";
		for(auto y : x){
			cout << y << " ";
		}
		cout << "\n";
	}
	cout  << "\n";
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
		
	int t = 1;
	// cin>>t;

	while(t--){
		solve();
	}

	return 0;
}