#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int a,b;
	cin>>a>>b;
	if(a==0){
		cout<<"0\n";
		return ;
	}
	if(b==0){
		cout<<"0\n";
		return ;
	}
	int asd=min(a,b);
	int temp=(a+b)/3;
	cout<<min(asd,temp)<<"\n";
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