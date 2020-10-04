#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	stack<int> s;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(i==0){
			cout<<"0 ";
			s.push(arr[i]);
			continue;
		}
		while(!s.empty() && arr[s.top()]>=arr[i]){
			s.pop();
		}
		if(s.empty()){
			cout<<"0 ";
		}
		else{
			cout<<s.top()<<" ";
		}
		s.push(i);
	}
	cout<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

/*    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}