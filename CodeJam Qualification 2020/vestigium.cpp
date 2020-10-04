#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	for(int q=1;q<=t;q++){
		int n;
		cin>>n;
		int arr[n][n];
		int r=0,c=0;
		ll trace=0;
		for(int i=0;i<n;i++){
			int row[n+1]={0};
			bool flag=false;
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
				row[arr[i][j]]++;
				if(i==j){
					trace+=arr[i][j];
				}
				if(row[arr[i][j]]>1) flag=true;
			}
			if(flag) r++;
		}

		for(int i=0;i<n;i++){
			int col[n+1]={0};
			bool flag=false;
			for(int j=0;j<n;j++){
				col[arr[j][i]]++;
				if(col[arr[j][i]]>1){
					flag=true;
					break;
				}
			}
			if(flag) c++;
		}
		cout<<"Case #"<<q<<": "<<trace<<" "<<r<<" "<<c<<"\n";

	}
    return 0;
}