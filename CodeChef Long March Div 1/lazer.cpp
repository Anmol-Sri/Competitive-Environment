#include <bits/stdc++.h>
#define ll long int
using namespace std;



vector<int> initializeDiffArray(vector<int>& A) 
{ 
    int n = A.size(); 
  
    // We use one extra space because 
    // update(l, r, x) updates D[r+1] 
    vector<int> D(n + 1); 
  
    D[0] = A[0], D[n] = 0; 
    for (int i = 1; i < n; i++) 
        D[i] = A[i] - A[i - 1]; 
    return D; 
} 
  
// Does range update 
void update(vector<int>& D, int l, int r, int x) 
{ 
    D[l] += x; 
    D[r + 1] -= x; 
} 
  
// Prints updated Array 
int printArray(vector<int>& A, vector<int>& D) 
{ 
    for (int i = 0; i < A.size(); i++) { 
        if (i == 0) 
            A[i] = D[i]; 
  
        // Note that A[0] or D[0] decides 
        // values of rest of the elements. 
        else
            A[i] = D[i] + A[i - 1]; 

        cout << A[i] << "\n"; 
    } 
} 


void solve(){
	int n,q;
	cin>>n>>q;
	vector<int>arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	
	for(int i=0;i<q;i++){
		int x1,x2,y;
		cin>>x1>>x2>>y;
		x1--;
		x2--;
		ll ans=0;
		vector<int> D = initializeDiffArray(arr);
		vector<array<int,2>> up_1;
		vector<int> up_2;
		int start=x1;
		for(int j=x1;j<x2;j++){
			/*if(arr[j+1]>=y && y>arr[j]) ans++;
			else if(arr[j+1]<=y && arr[j]>y) ans++;
			else if(arr[j]==y && arr[j+1]!=y) ans++;
			else if(arr[j]==y && arr[j+1]==y) ans=ans+2;
			*/
			if(arr[j]==y && arr[j+1]==y) {
				up_1.push_back({start,j-1});
				up_2.push_back(j);
				start=j+1;
			}

			if((arr[j+1]<=y && arr[j]<y)||(arr[j+1]>=y && arr[j]>y)||(arr[j]!=y)){
				up_1.push_back({start,j});
				start=j+1;
			}
		}
		for(int i=0;i<up_1.size();i++){
			update(D,up_1[i][0],up_1[i][1],1);
		}
		for(int i=0;i<up_2.size();i++){
			update(D,up_2[i],up_2[i],2);
		}
		//cout<<ans<<"\n";
		printArray(arr,D);
	}
	
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
    return 0;
}