#include <bits/stdc++.h>
using namespace std;
#define ll long int
bool prime[1001]; 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int check(vector<int> v[],int e){
	bool ch=true;
	for(int i=1;i<12;i++){
		ch=true;
		for(int j=0;j<v[i].size();j++){
			if(gcd(v[i][j],e)<=1){
				ch=false;
				break;
			}
		}
		if(ch){
			return i;
		}
	}
	return -1;

}
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	if(n<=11){
		cout<<n<<"\n";
		for(int i=1;i<=n;i++)
			cout<<i<<" ";
		cout<<"\n";
	}
	else{
		int ans[n];
		bool ch=false;
		memset(ans,-1,sizeof(ans));
		std::vector<int> v[12];
		int count=1;
		for(int i=0;i<n;i++){
			if(i==0){
				ans[i]=count;
				v[count].push_back(arr[i]);
			}
			else{
				int cond=check(v,arr[i]);
				if(cond!=-1){
					v[cond].push_back(arr[i]);
					ans[i]=cond;
				}
				else{
					
					for(int j=1;j<12;j++){
						if(v[j].size()==0){
							v[i].push_back(arr[i]);
							ans[i
						}
					}
				}
			}

		}

		cout<<count<<"\n";
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}		
		cout<<"\n";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
	//SieveOfEratosthenes(1001);
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}