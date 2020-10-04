#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,h,a,b,k;
	cin>>n>>h>>a>>b>>k;

	while(k--){
		int f1,t1,f2,t2;
		cin>>t1>>f1>>t2>>f2;
		/*if(t1>t2){
			swap(t1,t2);
			swap(f1,f2);
		}*/
		if(t1==t2){
			cout<<abs(f1-f2)<<"\n";
			continue;
		}
		else if(f1>=a and f1<=b){
			cout<<abs(t2-t1)+abs(f2-f1)<<"\n";
		}
		else{
			if(abs(f1-a)<abs(f1-b)){
				cout<<abs(f1-a)+abs(t2-t1)+abs(a-f2)<<"\n";
			}
			else{
				cout<<abs(f1-b)+abs(t2-t1)+abs(b-f2)<<"\n";
			}
		}
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}