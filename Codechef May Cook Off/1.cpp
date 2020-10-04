#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e3+1;
int fre[mxN];
void solve(){
	int n;
	cin>>n;
	int arr[n];
	int prev=-1;
	std::vector<int> single;
	memset(fre,0,sizeof(fre));
	unordered_map<int,int> qwe;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		fre[arr[i]]++;
		if(prev!=arr[i]){
			single.push_back(arr[i]);
			prev=arr[i];
		}
	}
	//sort(fre,fre+mxN);
	unordered_map<int,int> mp;
	for(int x:single){
		mp[x]++;
	}
	for(auto x:mp){
		if(x.second>1){
			cout<<"NO\n";
			return;
		}
	}
	for(int i=0;i<mxN;i++){
		if(fre[i]==0) continue;
		qwe[fre[i]]++;
	}
	for(auto x:qwe){
		if(x.second>1){
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
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