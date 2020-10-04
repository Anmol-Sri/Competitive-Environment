#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll andOperator(ll a, ll b){ 
	while(a < b){ 
	    b -= (b & -b); 
	} 
	return b; 
} 

int pairAndSum( int q,int n) 
{ 
    int ans = 0;  // Initialize result 
    for (int i = 0; i < 64; i++) 
    { 
        // Count number of elements with i'th bit set 
        int k = 0;  // Initialize the count 
        for (int j = q; j <=n; j++) 
            if ( (j & (1 << i))) 
                k++; 
  
        // There are k set bits, means k(k-1)/2 pairs. 
        // Every pair adds 2^i to the answer. Therefore, 
        // we add "2^i * [k*(k-1)/2]" to the answer. 
        ans += (1<<i) * (k*(k-1)/2); 
    } 
  
    return ans; 
} 

void solve(){
	ll n;
	cin>>n;
	ll ans=0;
	for(int i=1;i<n;i++){

		ans+=andOperator(i,n);
		cout<<"for i = "<<i<<"ans = "<<pairAndSum(i,n)<<"\n";
	}
	if(ans==0){
		cout<<"-1\n";
		return ;
	}
	cout<<ans<<"\n";
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