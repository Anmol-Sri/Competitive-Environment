#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll pre[100001];
void solve(){
	ll n,k;
	cin>>n>>k;
	ll count=-1;
	for(int i=0;i<100001;i++){
		if(pre[i]>=k){
			count =i;
			break;
		}
	}
	ll second=pre[count]-k;
	//cout<<count<<" - "<<second<<endl;
	char str[n];
	memset(str,'a',sizeof(str));
	str[n-count-1]='b';
	str[n-count+second]='b';
	for(int i=0;i<n;i++)
		cout<<str[i];
	cout<<"\n";	

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    pre[0]=0;
    for(int i=1;i<100001;i++)
    	pre[i]=pre[i-1]+i;

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}