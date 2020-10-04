#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e6+1;
std::vector<int> a,k;
int n,q;

int check(int x){
	int cnt=0;
	for(auto y:a){
		if(y<=x) cnt++;
	}

	for(auto y:k){
		if(y>0 && y<=x){
			cnt++;
		}
		if(y<0 && abs(y)<=cnt){
			cnt--;
		}
	}
	return cnt;
}

void solve(){
	cin>>n>>q;
	a.resize(n);
	k.resize(q);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<q;i++){
		cin>>k[i];
	}
	if(check(int(1e9))==0){
		cout<<"0\n";
		return ;
	}
	int l=0;
	int r=mxN;

	while( r - l > 1 ){
		int mid=(l+r)/2;
		if(check(mid)>0){
			r=mid;
		}
		else{
			l=mid;
		}
	}

	cout<<r<<"\n";
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