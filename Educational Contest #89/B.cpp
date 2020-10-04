#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,x,m;
	cin>>n>>x>>m;
	int ans=0;
	int start=-1;
	int end=-1;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(start==-1 && end==-1 && a<=x && x<=b){
			start=a;
			end=b;
			continue;
		}
		if(start<=a && end>=a && end<=b){
			end=max(b,end);
		}
		else if(start>=a && start<=b && end>=b){
			start=min(a,start);
		}
		else if(start>=a && start<=b && end>=a && end<=b){
			start=min(start,a);
			end=max(b,end);
		}
		//cout<<start<<" "<<end<<"\n";
	}
	cout<<max(0,end-start+1)<<"\n";
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