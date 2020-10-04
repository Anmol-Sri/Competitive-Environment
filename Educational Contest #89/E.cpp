#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MOD=998244353;
const int mxN=2e5+1;
int mul(int a ,int b){
	return (1LL*a*b)%MOD;
}
void solve(){
	int n,m;
	cin>>n>>m;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	reverse(a,a+n);
	reverse(b,b+m);
	a[n]=-1;

	int mn=a[0];
	int pos=0;
	while(pos<n && mn>b[0]){
		pos++;
		mn=min(mn,a[pos]);
	}
	if(pos==n || mn<b[0]){
		cout<<"0\n";
		return ;
	}

	int ans=1;
	int idx=0;

	while(true){
		if(idx==m-1){
			if(*min_element(a+pos,a+n)!=b[idx]){
				cout<<"0\n";
				return ;
			}
			break;
		}
		bool ok=true;
		int min_pos=pos;
		while(min_pos<n && mn!=b[idx+1]){
			++min_pos;
			mn=min(mn,a[min_pos]);
			if(ok && mn<b[idx]){
				ok=false;
				ans=mul(ans,min_pos-pos);
			}
		}
		if(min_pos==n || mn!=b[idx+1]){
			cout<<"0\n";
			return ;
		}
		++idx;
		pos=min_pos;
	}
	cout<<ans<<"\n";
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

	while(t--){
		solve();
	}
    return 0;
}