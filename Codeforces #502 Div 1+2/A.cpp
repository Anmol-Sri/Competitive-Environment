#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int t1,t2,t3,t4;
	cin>>t1>>t2>>t3>>t4;

	ll sum=t1+t2+t3+t4;
	int rank=1;
	for(int i=1;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		ll temp=a+b+c+d;
		if(sum<temp){
			rank++;
		}
	}
	cout<<rank<<"\n";
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
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}