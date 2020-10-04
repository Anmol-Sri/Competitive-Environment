#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e7+1;
int prime[mxN];

void pre_calc(){
	prime[0]=prime[1]=1;
	for(int i=2;i<mxN;i++){
		for(int j=i;j<mxN;j+=i){
			if(!prime[j]){
				prime[j]=i;
			}
		}
	}
}
void solve(){
	pre_calc();
	int n;
	cin>>n;
	int arr[n];
	int d1[n];
	int d2[n];
	for(int i=0;i<n;i++) d1[i]=-1,d2[i]=-1;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		d1[i]=prime[a];
		d2[i]=a;

		while(true){
			if(d2[i]%prime[a]!=0) break;
			d2[i]/=prime[a];
		}
		if(d2[i]==1){
			d1[i]=d2[i]=-1;
		}
	}
	for(int i=0;i<n;i++){
		cout<<d1[i]<<" ";
	}
	cout<<"\n";
	for(int i=0;i<n;i++){
		cout<<d2[i]<<" ";
	}
	cout<<"\n";
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
		
	int t=1;
	while(t--){
		solve();
	}
    return 0;
}