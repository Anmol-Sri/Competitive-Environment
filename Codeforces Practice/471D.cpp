#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int > calcDif(vector<int > arr){
	vector<int > ans;
	for(int i =1; i < arr.size(); i++ ){
		ans.push_back(arr[i] - arr[i - 1]);
	}
	return ans;
}

vector< int > calcZarr(vector< int > arr){
	int n = (int) arr.size();
	vector<int> z(n);
	// creating a window L to R
	int l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i <= r){
			z[i] = min( z[i - l], r - i + 1);
		}
		while(i + z[i] < n && arr[z[i]] == arr[i + z[i]]){
			++z[i];
		}
		if(i + z[i] > r){
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int calc(vector< int > &arr , vector< int > &pattern ){
	if( pattern.size() == 0){
		return arr.size() + 1;
	}
	vector< int > str = pattern;
	str.insert( str.end(), arr.begin(), arr.end());
	vector<int > zarr = calcZarr(str);
	int ans = 0;
	for( int i = pattern.size() ; i < zarr.size(); i++){
		if( zarr[i] >= pattern.size()){
			ans++ ;
		}
	}
	return ans;
}

void solve(){
	int  n, w;
	cin >> n >> w;
	std::vector<int> a1(n);
	std::vector<int> a2(w);
	for(int &i : a1) cin >> i;
	for(int &i : a2) cin >> i;

	vector<int >  aDiff = calcDif(a1);
	vector<int >  bDiff = calcDif(a2);

	cout << calc(aDiff, bDiff) << "\n";
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
		
	int t=1;

	while(t--){
		solve();
	}

	return 0;
}