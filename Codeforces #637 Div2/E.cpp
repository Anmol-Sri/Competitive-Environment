#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e6+1;
std::vector<int> d;
int n,m;
int r,g;
ll ans;

void recur(int cur_g,int pos){
/*	ll temp=0;
	int i;
	if(pos==m-1){
		;
	}
	if(d[i]>cur_g)
	for( i=pos;i<m;i++){
		if(d[i]<cur_g){
			temp=d[i];
			cur_g-=d[i];
		}
		else{
			break;
		}
	}
	if(cur_g==g){
		ans= -1;
		return;
	}

	ans+=temp;
	if(i==m)
	*/
	if(d[pos]>cur_g){
		ans=-1;
		return;
	}
}

void solve(){

	cin>>n>>m;

	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		d.push_back(x);
	}
	sort(d.begin(),d.end());
	
	cin>>g>>r;
	if(d[0]>g){
		cout<<"-1";
		return;
	}
	recur(g,0);
	cout<<ans<<"\n";

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