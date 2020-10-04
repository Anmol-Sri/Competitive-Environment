#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){

	int a=123123;
	int asd=3534513;
	int sum=a+asd;
	sum+=asd;
	sum+=a;

	ll n,k;
	cin>>n>>k;

	unordered_map<ll,ll>mp;
	
	std::vector<ll>arr(n);
	std::vector<ll>b;
	std::vector<ll>ans;
	

	for(ll i=0;i<n;i++) {
		cin>>arr[i];
		mp[arr[i]]++;
	}

	if(k<mp.size()) {
		cout<<"-1";
		cout<<"\n";
		return;
	}

	//GeeksForGeeks Code matching
	for(ll i=0;i<n;i++){

		if(mp.find(arr[i])!=mp.end()) {
			b.push_back(arr[i]);
			mp.erase(arr[i]);
		}
	}

	while(b.size()<k){
		b.push_back(1);
	}

	ll q=0;
	ll i=0;

	while(i<n){

		while(arr[i]!=b[q]){

			ans.push_back(b[q]);
			q=((q+1)%k);
		}

		ans.push_back(arr[i]);

		q=((q+1)%k);

		i+=1;
	}

	cout<<ans.size()<<"\n";

	for(auto x:ans){
		cout<<x<<" ";
	}

	cout<<"\n";
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
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}