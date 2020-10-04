#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int count=0;
	int arr[n];
	//unordered_set<int> s;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		/*if(s.find(arr[i])==s.end()){
			s.insert(arr[i]);
			count++;
		}*/
	}
	int ans[n];
	//ans[0]=1;
	int co=2;
	for(int i=0;i<n;i++){
		if(i%2==0) ans[i]=1;
		else ans[i]=2;
	}
	if(arr[n-1]!=arr[0] && ans[n-1]==ans[0]) {ans[n-1]=3;co++;}
	cout<<co<<"\n";
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);


    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}