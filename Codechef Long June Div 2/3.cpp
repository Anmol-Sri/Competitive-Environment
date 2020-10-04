#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int &x:arr) cin>>x;
	int num5=0,num10=0,num15=0;
	for(int i=0;i<n;i++){
		if(arr[i]==5){
			num5++;
		}
		else if(arr[i]==10){
			if(num5>0){
				num5--;
				num10++;
			}
			else{
				cout<<"NO\n";
				return ;
			}
		}
		else{
			if(num10>0){
				num10--;
				num15++;
			}
			else if(num5>=2){
				num5-=2;
				num15++;
			}
			else{
				cout<<"NO\n";
				return ;
			}
		}
	}
	cout<<"YES\n";
	return ;
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