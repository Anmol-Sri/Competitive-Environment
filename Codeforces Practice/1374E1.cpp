#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n,k;
	cin>>n>>k;
	vector<ll> both,al,bo;
	ll alice=0,bob=0,ans=LLONG_MAX;
	for(ll i=0;i<n;i++){
		ll t,a,b;
		cin>>t>>a>>b;
		if(a==1) alice++;
		if(b==1) bob++;
		if(a==0 && b==0) continue;
		else if(a==1 && b==1) both.push_back(t);
		else if(a==0 &&  b==1) bo.push_back(t);
		else if(a==1 &&  b==0) al.push_back(t);
	}
	if(alice<k || bob<k){
		cout<<"-1\n";
		return ;
	}
	al.push_back(0);
	bo.push_back(0);
	both.push_back(0);
	sort(both.begin(), both.end());
	sort(al.begin(), al.end());
	sort(bo.begin(), bo.end());
	for(int i=1;i<both.size();i++) both[i]+=both[i-1];
	for(int i=1;i<bo.size();i++) bo[i]+=bo[i-1];
	for(int i=1;i<al.size();i++) al[i]+=al[i-1];
	// ll new_alice=0,new_bob=0;
	ll range=both.size();
	for(int i=0;i<min(k+1,range);i++){
		if(k-i<al.size() && k-i<bo.size())
			ans=min(ans,both[i]+al[k-i]+bo[k-i]);
		// cout<<i<<" "<<k-i<<" "<<ans<<"\n";
	}
	if(al.size()>k && bo.size()>k){
		ans=min(ans,al[k]+bo[k]);
	}
	cout<<ans<<"\n";
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