#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n;


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
		cin>>n;
		int arr[n+1];
		set<pair<int,pair<int,int>>> store;
		store.insert(make_pair(-n,make_pair(1,n)));
		int val=1;
		while(store.size()){
			pair<int,pair<int,int>> automate=*store.begin();
			int start=automate.second.first;
			int end=automate.second.second;
			store.erase(automate);
			if(start>end){
				continue;
			}
			if(start==end){
				arr[start]=val++;
				continue;
			}
			int check =end-start+1;
			if(check&1){
				check=(start+end)>>1;
				arr[check]=val++;
			}
			else{
				check=(start+end-1)>>1;
				arr[check]=val++;
				
			}
			store.insert(make_pair(-(check-start),make_pair(start,check-1)));
			store.insert(make_pair(-(end-check),make_pair(check+1,end)));
		}
		for(int i=1;i<=n;i++){
			cout<<arr[i]<<" ";

		}
		cout<<"\n";
	}
    return 0;
}