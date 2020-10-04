#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll k;
	cin>>k;
	string s="codeforces";
	ll len=s.size();
	int arr[len];
	for(int i=0;i<len;i++) arr[i]=1;
	
	ll prod=1;
	for(ll idx=0;prod<k;idx=(idx+1)%10){
		prod=1;
		arr[idx]++;
		for(int i=0;i<10;i++){
			prod*=arr[i];
		}
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<arr[i];j++){
			cout<<s[i];
		}
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
		
	int t=1;

	while(t--){
		solve();
	}

	return 0;
}