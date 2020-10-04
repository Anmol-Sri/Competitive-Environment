#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll summation(int x){
	return (ll)x*((ll)x+1LL)/2LL;
}

ll maxCircularSum(int arr[], int n, int k) 
{ 
	/*for(auto x:arr) cout<<x<<" ";
		cout<<endl;
		*/
    ll sum = 0, start = 0, end = k - 1; 
    int temp1=x;
    int i=0;
    while(temp1>0){
    	if(arr[i]<x){
    		sum+=summation(x);
    		break;
    	}
    	sum+=summation(arr[i++]);
    }

    ll ans = sum;
    for (ll i = k; i < n + k; i++) { 
        sum += arr[i % n] - arr[(i - k) % n]; 
        if (sum > ans) { 
            ans = sum; 
            start = (i - k + 1) % n; 
            end = i % n; 
        } 
    } 
  
   return ans;
} 

void solve(){
	int n,x;
	cin>>n>>x;
	int d[n];
	int maxi=-1,maxv=INT_MIN;
	std::vector<int> arr;
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	cout<<maxCircularSum(d,n,x)<<"\n";
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