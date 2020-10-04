#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	string s;
	cin>>s;
	int len=s.size();
	int ans=0;
	for(int i=2;i<=len-2;i+=2){
		string a=s.substr(0,i/2);
		string b=s.substr(i/2,i/2);
		//cout<<a<<" - "<<b<<"for i = "<<i<<"\n";
		if(a!=b){
			continue;
		}
		/*
		for(int j=2;j<len-i;j+=2){
			string c=s.substr(i,j/2);
			string d=s.substr(i+j/2,j/2);
			cout<<c<<" - "<<d<<"for j = "<<j<<"\n";
			if(c==d){
				ans++;
			}
		}*/
		int rem=(len-i)/2;
		string c=s.substr(i,rem);
		string d=s.substr(i+rem,rem);
		//cout<<c<<" - "<<d<<"for rem = "<<rem<<"\n";
		if(c==d){
			ans++;
		}
		
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}