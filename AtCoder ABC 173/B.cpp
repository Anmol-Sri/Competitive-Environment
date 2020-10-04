#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[4] = {0};
	string s;
	for(int i =0; i < n; i++){
		cin >> s;
		if(s == "AC") arr[0]++;
		else if(s == "WA") arr[1]++;
		else if(s == "TLE") arr[2]++;
		else arr[3]++;
	}
	cout << "AC x "<< arr[0] << endl;
	cout << "WA x "<< arr[1] << endl;
	cout << "TLE x "<< arr[2] << endl;
	cout << "RE x "<< arr[3] << endl;

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

	while(t--){
		solve();
	}

	return 0;
}