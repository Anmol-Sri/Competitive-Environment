#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct qu{
	int start;
	int end;
	int diff;
};

bool cmp(struct qu a,struct qu b){
	return a.diff>b.diff;
}

void solve(){
	int n,cap;
	cin>>n>>cap;
	struct qu arr[n];
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i].start;
		sum+=arr[i].start;
		cin>>arr[i].end;
		arr[i].diff=arr[i].start-arr[i].end;
	}
	if(sum<=cap){
		cout<<"0\n";
		return;
	}
	int count=0;
	sort(arr,arr+n,cmp);
	/*
	for(auto x:arr){
		cout<<x.start<<" "<<x.end<<" "<<x.diff<<"\n";
	}
	*/
	ll compress=sum-cap;
	//cout<<sum<<" "<<compress<<"\n";
	int i;
	ll already=0;
	for(i=0;i<n;i++){
		already+=arr[i].diff;
		count++;
		if(already>=compress){
			break;
		}
	}
	if(i==n){
		cout<<"-1\n";
		return;
	}
	else{
		cout<<count<<"\n";
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}