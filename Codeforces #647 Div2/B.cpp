#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1024;
void solve(){
	int n;
	cin>>n;
	set<int>s;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.insert(x);
	}
	int i;
	for( i=1;i<=1024;i++){
		bool ok=true;
		for(int x:s){
			if(s.find(x^i)==s.end()){
				ok=false;
				break;
			}
		}
		if(ok){
			cout<<i<<"\n";
			return ;
		}
	}
	if(i==1025){
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