#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=32000;
double arr[mxN];

//GeeksForGeeks Code
int precalc(int n){
	int ans=0;
	while(n){
		n=n/2;
		ans++;
	}
	return ans;
}
void solve(){
	int n;
	cin>>n;
	int k=precalc(n);

    std::vector<int>arr;
    int s=0;
    for(int i=0;i<k-1;i++){
    	int kk=pow(2,i);
    	arr.push_back(kk);
    	s+=kk;
    }
    if(s<n)
    	arr.push_back(n-s);
    sort(arr.begin(),arr.end());

    cout<<k-1<<"\n";

    for(int i=0;i<k-1;i++){

    	if(arr[i]==arr[i+1])
    		cout<<0<<" ";
    	else
    		cout<<arr[i+1]-arr[i]<<" ";
    }
    cout<<"\n";
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