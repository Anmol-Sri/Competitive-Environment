#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minMoves(int n, int a[], int k) 
{ 
  
    int ct1[k] = { 0 }, ct0[k] = { 0 }, moves = 0; 
  
    // Count the number of 1s and 2s 
    // at each X such that i % K = X 
    for (int i = 0; i < n; i++) 
        if (a[i] == 1) 
            ct1[i % k]++; 
        else
            ct0[i % k]++; 
  
    // Choose the minimum elements to change 
    for (int i = 0; i < k; i++) 
        moves += min(ct1[i], ct0[i]); 
  
    // Return the minimum moves required 
    return moves;

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
		int n,k;
		cin>>n>>k;
		int arr[n];
		char ch;
		for(int i=0;i<n;i++){
			cin>>ch;
			arr[i]=(ch=='1')?1:0;
		}
		if(n==1 and k==1){
			cout<<"0\n";
			continue;
		}

		//cout<<minMoves(n,arr,k)<<"\n";

		//int count[k]={0};
		int best=INT_MAX;
		for(int i=0;i<k;i++){
			int moves=0;
			for(int j=i;j<n;j++){
				if(j%k==0){
					if(arr[j]==1)
						continue;
					else moves++;
				}
				else if(arr[j]==0){
					continue;
				}
				else{
					moves++;
				}
			}
			//cout<<moves<<"\n";
			best=min(moves,best);
		}
		cout<<best<<"\n";
	}
    return 0;
}