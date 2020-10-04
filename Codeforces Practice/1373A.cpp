#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ar array

void solve(){
	ll a,b,c;
	cin>>a>>b>>c;
	if(c<a){
		cout<<"-1 1\n";
	}
	else if(a<c){
		cout<<"1 ";
		if(a*b<=c){
			cout<<-1<<"\n";
		}
		else{
			cout<<b<<"\n";
		}
	}
	else if(a*b<c){
		cout<<"1 -1\n";
	}
	else if(a==c){
		cout<<"-1 "<<b<<"\n";
	}
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
		
	// int t=1;
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}