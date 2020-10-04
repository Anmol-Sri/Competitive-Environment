#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,x;
	cin>>n>>x;
	std::vector<pair<int,int>> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back({x,i});
	}
	sort(arr.begin(), arr.end());
	int start=0,end=n-1;

	while(start<end){
		int sum=arr[start].first+arr[end].first;
		if(sum==x){
			cout<<arr[start].second+1<<" "<<arr[end].second+1<<"\n";
			return ;
		}
		else if(sum<x){
			start++;
		}
		else{
			end--;
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
	#endif
*/		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}