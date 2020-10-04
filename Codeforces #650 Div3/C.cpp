#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<n;){

		int j=i+1;
		for(;j<n&&s[j]!='1';j++);

		int left=(s[i]=='1')?k:0;
		int right=(j<n&&s[j]=='1')?k:0;
		int len=j-i;
		if(left==k) len--;

		len-=left+right;
		if(len>0) ans+=(len+k)/(k+1);
		i=j;
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