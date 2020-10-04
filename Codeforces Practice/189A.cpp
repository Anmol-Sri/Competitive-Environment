#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int a[3];
int arr[4001];
int recur(int n) {
	if(n==0) return 0;
	if(arr[n]!=-1) return arr[n];
	//ans=INT_MIN;
	arr[n]=INT_MIN;
	for(int i=0;i<3;i++){
		if(n>=a[i])
		arr[n]=max(arr[n],1+recur(n-a[i]));
	}
	return arr[n];
}

void solve(){
	int n;
	cin>>n;
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	for(int i=0;i<4001;i++) arr[i]=-1;
	cout<<recur(n)<<"\n";
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