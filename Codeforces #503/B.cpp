#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e3+1;
int arr[mxN];
int freq[mxN];

int recur(int pos){
	//cout<<pos<<" ";
	freq[arr[pos]]++;
	if(freq[arr[pos]]==2){
		return arr[pos];
	}
	return recur(arr[pos]);
}

void solve(){
	int n;
	cin>>n;

	for(int &x:arr){
		int t;
		cin>>t;
		x=t-1;
	}

	for(int i=0;i<n;i++){
		//cout<<"\nFor i="<<i<<"\n";
		memset(freq,0,sizeof freq);
		freq[i]++;
		cout<<recur(i)+1<<" ";
		
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}