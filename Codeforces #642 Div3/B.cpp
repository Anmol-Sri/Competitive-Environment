#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,k;
	cin>>n>>k;
	int a[n];
	int b[n];
	int sum=0;
	for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
	for(int i=0;i<n;i++) cin>>b[i];

	sort(a,a+n);
	sort(b,b+n,greater<int>());
	if(a[0]>b[0]){
		cout<<sum<<"\n";
		return ;
	}
	int i=0;
	int j=0;
	while(k--){
		if(a[i]<b[j]){
			sum=sum-a[i]+b[j];
			i++;
			j++;
		}
		else{
			break;
		}
	}
	cout<<sum<<"\n";
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