#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void  cyclic(vector<int> &arr, int pos){
	swap(arr[pos + 1], arr[pos + 2]);
	swap(arr[pos], arr[pos + 1]);
}

void solve(){
	int n;
	cin >> n;
	vector< int > arr(n);
	vector < pair < int , int > > store(n);
	for(int i = 0; i < n ; i++ ){
		cin >> arr[i];
		store[i] = { arr[i] , i };
	}
	sort(store.begin(), store.end());
	for(int i = 0; i <  n ; i++){
		arr[store[i].second] = i;
	}
	int count = 0 ;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			count += arr[j] < arr[i];
		}
	}
	// if inversions are odd ..... swap the duplicates..
	if(count & 1){
		for(int i = 0; i < n - 1; i++){
			if(store[i].first == store[i + 1].first){
				swap(arr[store[i].second], arr[store[i + 1].second]);
				break;
			}
		}
	}
	vector< int > ans ;
	for(int i = 0; i < n - 2; i++){
		int pos = min_element(arr.begin() + i, arr.end()) - arr.begin();
		while(pos > i + 1){
			cyclic(arr, pos - 2);
			ans.push_back(pos - 2);
			pos -= 2;
		}
		if(pos != i){
			cyclic(arr, i);
			cyclic(arr, i);
			ans.push_back(i);
			ans.push_back(i);
			pos = i;
		}
	}
	for(int i = 0; i < 3; i++){
		if(is_sorted(arr.begin(), arr.end())) break;
		cyclic(arr, n - 3);
		ans.push_back(n - 3);
	}

	if(!is_sorted(arr.begin(), arr.end())){
		cout << "-1\n";
	}
	else{
		cout << ans.size() << "\n";
		for(auto x : ans){
			cout << x +1 << " ";
		}
		cout<<"\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}