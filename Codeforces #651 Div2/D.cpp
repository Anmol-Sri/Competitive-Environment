#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+1;

int n,k;
//int ans;
int recur(int arr[],int i,std::vector<int> sub){
	if(i>n || i<0){
		return INT_MAX;
	}
	if(sub.size()==k){
		int even=INT_MAX;
		int odd=INT_MAX;
		for(int i=0;i<sub.size();i++){
			if((i+1)%2==0){
				odd=max(odd,arr[i]);
			}
			else{
				even=max(even,arr[i]);
			}
		}
		cout<<"even = "<<even<<" -- "<<"odd = "<<odd<<"\n";
		return min(even,odd);
	}
	int b=recur(arr,i+1,sub);
	sub.push_back(arr[i]);
	cout<<"inserting = "<<arr[i]<<"\n";
	int a=recur(arr,i+1,sub);
	cout<<a<<" "<<b<<"\n";
	return min(a,b);
}
void solve(){
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	std::vector<int> sub;
	cout<<recur(arr,0,sub)<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		clock_t tStart = clock();
	#endif
		
	int t=1;

	while(t--){
		solve();
	}
	#ifndef ONLINE_JUDGE
		cerr<<fixed<<setprecision(10)<<"Time Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
	#endif

	return 0;
}