#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,x;
	cin>>n>>x;
	std::vector<pair<int,int>> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].first;
		arr[i].second=i+1;
	}
	sort(arr.begin(), arr.end());
	int a=-1,b=-1,c=-1;
	int ans[3]={0};
	for(int i=0;i<n;i++){
		int rem=x-arr[i].first;
		int start=0;
		int end=n-1;
		bool ok=false;
		ans[0]=arr[i].second;
		while(start<end){
			if(start==end || start==i || end==i){
				start++;
			}
			int found=arr[start].first+arr[end].first;
			if(found==rem){
				ok=true;
				ans[1]=arr[start].second;
				ans[2]=arr[end].second;
				break;
			}
			else if(found<rem){
				start++;
			}
			else{
				end--;
			}
		}
		if(ok){
			for(int i:ans){
				cout<<i<<" ";
			}
			return ;
		}
	}
	cout<<"IMPOSSIBLE\n";
	return ;
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
	#endif*/
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}