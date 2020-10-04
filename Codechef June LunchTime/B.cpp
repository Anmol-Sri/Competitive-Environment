#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN=2e5+1;
void solve(){
	int n;
	cin>>n;
	int arr[n];
	int fre[mxN]={0};
	bool ok=true;
	std::vector<int> a,b;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		fre[arr[i]]++;
		if(fre[arr[i]]==1){
			a.push_back(arr[i]);
		}
		else if(fre[arr[i]]==2){
			b.push_back(arr[i]);
		}
		else{
			ok=false;
		}
	}
	if(fre[*max_element(arr,arr+n)]>1 || !ok){
		cout<<"NO\n";
		return ;
	}
	else{
		cout<<"YES\n";
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(),greater<int>());
		for(int q:a){
			cout<<q<<" ";
		}
		for(int q:b){
			cout<<q<<" ";
		}
		cout<<"\n";
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
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}