#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	if(n==1){
		cout<<"1\n";
		return ;
	}
	if(n<=3){
		cout<<"NO SOLUTION\n";
		return;
	}
	int start_even;
	int start_odd;
	if(n%2==1){
		start_even=n-1;
		start_odd=n;
	}
	else{
		start_even=n;
		start_odd=n-1;
	}
	int i=2;
	while(i<=start_even){
		cout<<i<<" ";
		i+=2;
	}
	i=1;
	while(i<=start_odd){
		cout<<i<<" ";
		i+=2;
	}
	cout<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	*/
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}