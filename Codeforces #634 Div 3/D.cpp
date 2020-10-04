#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	char arr[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>arr[i][j];
		}
	}

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(arr[i][j]=='3'){
				
				 if((j+1)%3==1){
					arr[i][j+1]='3';
					j++;
				}
				else if((j+1)%3==2){
					arr[i][j-1]='3';
				}
				else{
					if(i==0){
						arr[i+1][j]='3';
						j++;
					}
					else{
						arr[i-1][j]='3';
					}
					
				}
			}
		}
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<arr[i][j];
			if(j%3==2 ) cout<<"|";
		}
		cout<<"\n";
	}
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

	while(t--){
		solve();
	}
    return 0;
}