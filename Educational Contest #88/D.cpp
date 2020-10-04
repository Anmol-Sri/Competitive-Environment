#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxSubArraySum(int a[], int size) 
{
	std::vector<int> ans;
	int uptil_now = INT_MIN, end_here = 0;
	int ele=a[0];
	int start =0, end = 0, s=0; 
	int orig=INT_MIN;
	for (int i=0; i< size; i++ ) 
	{ 
	    end_here += a[i]; 
	    ele=max(ele,a[i]);
	    if (uptil_now < end_here) 
	    { 
	        uptil_now = end_here-ele;
	        start = s; 
	        end = i; 
	    }
	    else if(uptil_now >= end_here){
	    	ans.push_back(uptil_now);	
	    }
	    if (end_here < 0) 
	    { 
	    	ele=a[i];
	        end_here = 0; 
	        s = i + 1; 
	    }
	}
	ans.push_back(uptil_now);
	if(start==end) return 0;
	sort(ans.begin(),ans.end(),greater<int>());
    return ans[0];
} 

int calc(int arr[],int n){
	int ans=0;
	int sum=arr[0];
	int max_ele=arr[0];

	for(int i=0;i<n;i++){
		sum=max(arr[i],sum+arr[i]);
		ans=max(sum,ans);
		if(sum+arr[i]<arr[i]){

			sum=arr[i];
		}
		else{
			sum+=arr[i];
		}
	}

	cout<<"without removing max ele : - "<<ans<<"\n";
}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<calc(arr,n);

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