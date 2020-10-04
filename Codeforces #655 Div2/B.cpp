#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll gcd(ll a, ll b){
	if(a < b) return gcd(b, a);
	if(b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b){
	return (a * b)/gcd(a, b);
}

void solve(){
	ll n;
	cin >> n;
	ll temp = n;
	vector< ll > factors;
	for(ll i = 2; i  <= sqrt(n); i++){
		if(n % i == 0){
			factors.push_back(i);
			if(n/i != i){
				factors.push_back(n/i);
			}
		}
	}
	// sort(factors.begin(), factors.end());
	/*int start = 0; 
	int end = factors.size() - 1;
	int l = start; 
    int r = end; 
    vector < pair< int , pair < int , int > > > ans;
    ans.push_back(make_pair(lcm(1,n - 1), make_pair(1, n - 1)));
    while (l <= r) { 
        if (factors[l] + factors[r] == n){
        	ans.push_back(make_pair(lcm(factors[l],factors[r]), make_pair(factors[l],factors[r])));
        	l++;
        }
        else if (factors[l] + factors[r] < n) 
            l++; 
        else 
            r--; 
    }*/
	ll fir = 1;
	ll sec = n - 1;
    for(ll i : factors){
    	if(lcm(fir, sec) > lcm(i, n - i)){
    		fir = i;
    		sec = n - i;
    	}
    }
/*    sort(ans.begin(), ans.end());
    cout << ans[0].second.first << " " << ans[0].second.second << "\n";*/
    cout << fir << " " << sec << "\n";
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