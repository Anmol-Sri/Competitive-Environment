#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[2*n];
	int g=1;
	int lim=2*n;
	std::vector<int> even;
	std::vector<int> odd;
	for(int i=0;i<2*n;i++){
		cin>>arr[i];
		if(i==0) g=arr[i];
		else g=__gcd(arr[i],g);
		if(arr[i]%2==0){
			even.push_back(i+1);
		}
		else{
			odd.push_back(i+1);
		}
	}
	if(g>1){
		for(int i=1;i<=lim-2;i+=2){
			cout<<i<<" "<<i+1<<"\n";
		}
		return ;
	}
	if(even.size()>=lim-2){
		for(int i=0;i<lim-2;i+=2){
			cout<<even[i]<<" "<<even[i+1]<<"\n";
		}
		return ;
	}
	else if(odd.size()>=lim-2){
		for(int i=0;i<lim-2;i+=2){
			cout<<odd[i]<<" "<<odd[i+1]<<"\n";
		}
		return ;
	}
	else{
		int num=0;
		for(int i=0;i+1<odd.size();i+=2){
			cout<<odd[i]<<" "<<odd[i+1]<<"\n";
			num++;
		}
		if(num==n-1){
			return ;
		}
		for(int i=0;i+1<even.size();i+=2){
			cout<<even[i]<<" "<<even[i+1]<<"\n";
			num++;
			if(num==n-1){
				return ;
			}
		}
		return ;
	}
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
	#ifndef ONLINE_JUDGE
		cerr<<fixed<<setprecision(10)<<"Time Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
	#endif

	return 0;
}