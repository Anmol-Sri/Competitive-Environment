#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ar array

void solve(){
	string s;
	cin>>s;
	int dif=0;
	int one=0;
	int zero=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			zero++;
		}
		else{
			one++;
		}
	}
	if(one==0 || zero==0){
		cout<<"NET\n";
		return ;
	}
	int temp=min(one,zero);
	if(temp%2==0){
		cout<<"NET\n";
	}
	else{
		cout<<"DA\n";
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
		
	// int t=1;
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}