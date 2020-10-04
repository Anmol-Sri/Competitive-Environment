#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	ll sum=(1LL*n*(n+1))/2;
	ll half_sum=sum/2;
	if(sum%2!=0){
		cout<<"NO\n";
		return;
	}
	ll check=0;
	int num=0;
	bool used[n+1]={false};
	for(int i=n;i>=1 && check!=half_sum;i--){
		if(half_sum-check>=i){
			check+=i;
			used[i]=true;
			num++;
		}
	}
	//cout<<check<<"\n";
	//ll fir=0,sec=0;
	cout<<"YES\n"<<num<<"\n";
	for(int i=1;i<=n;i++){
		if(used[i]){
			//fir+=i;
			cout<<i<<" ";
		}
	}
	cout<<"\n"<<n-num<<"\n";
	for(int i=1;i<=n;i++) if(!used[i]) cout<<i<<" ";
	cout<<"\n";
	//cout<<"sum 1= "<<fir<<"sum 2 = "<<sec<<"\n";
	return;

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