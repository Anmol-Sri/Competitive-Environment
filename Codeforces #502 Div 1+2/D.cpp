#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	int arr[n];
	std::vector<string> str;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		str.push_back(s);
	}

	vector<int,vector<string>> vec;

	while(q--){
		string s;
		int k;
		cin>>s>>k;
		int count=0;
		int sum=0;
		for(auto x:str){
			sum=0;
			for(int i=0;i<n;i++){
				if(s[i]==x[i]) {
					sum+=arr[i];
				}
			}
			if(sum<=k){
				//cout<<sum<<"\n";
				count++;
			}
		}
		//cout<<"\n-----------------------\n";
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