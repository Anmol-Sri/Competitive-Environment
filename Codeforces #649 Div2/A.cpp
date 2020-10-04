#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int ans;
int a,b;
void solve(){
	cin>>a;
	cin>>b;
	ans=0;
	int arr[a];
	for(int i=0;i<a;i++){
		cin>>arr[i];
		ans+=arr[i];
	}
	int start=0;
	int end=0;
	for(;start<a && arr[start]%b==0;start++);
	for(;end<a && arr[a-end-1]%b==0;end++);
	if(ans%b==0){
		cout<<a-min(start,end)-1<<"\n";
		return ;
	}
	else{
		cout<<a<<"\n";
		return ;
	}
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}