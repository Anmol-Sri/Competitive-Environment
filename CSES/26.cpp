#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	set<int > s;
	int last=0;
	int mx=1;
	int i=0;

	while(i<n){
		if(s.count(arr[i])>0){
			mx=max(mx,i-last);
			while(arr[last]!=arr[i]){
				s.erase(arr[last++]);			}
			++last;
		}
		else{
			s.insert(arr[i]);
		}
		i++;
	}
	cout<<max(mx,i-last)<<"\n";
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