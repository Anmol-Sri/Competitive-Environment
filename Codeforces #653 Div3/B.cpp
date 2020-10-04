#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin>>n;
	int ans=0;
	while(n!=1){
		if(n%6==0){
			ans++;
			n/=6;
		}
		else if((n*2)%6==0){
			n=n*2;
			ans++;
		}
		else{
			break;
		}
	}
	if(n==1){
		cout<<ans<<"\n";
	}
	else{
		cout<<"-1\n";
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