#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void caller(){
	int n,p;
	cin>>n>>p;

	int arr[n][n];
	memset(arr,0,sizeof(arr));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i<=n/2 && j<=n/2){
				cout<<1<<i<<" "<<j<<" "<<n<<" "<<n<<endl;
				int a;
				cin>>a;
				cout<<1<<i+1<<" "<<j<<" "<<n<<" "<<n<<endl;
				int b;
				cin>>b;
				cout<<1<<i<<" "<<j+1<<" "<<n<<" "<<n<<endl;
				int c;
				cin>>c;
				
			}
			else if(){
				cout<<1<<i<<" "<<j<<" "<<n<<" "<<n<<endl;
				int a;
				cin>>a;
				cout<<1<<i+1<<" "<<j<<" "<<n<<" "<<n<<endl;
				int b;
				cin>>b;
				cout<<1<<i<<" "<<j+1<<" "<<n<<" "<<n<<endl;
				int c;
				cin>>c;
			}
			else if(){
				cout<<1<<i<<" "<<j<<" "<<n<<" "<<n<<endl;
				int a;
				cin>>a;
				cout<<1<<i+1<<" "<<j<<" "<<n<<" "<<n<<endl;
				int b;
				cin>>b;
				cout<<1<<i<<" "<<j+1<<" "<<n<<" "<<n<<endl;
				int c;
				cin>>c;
			}
			else{
				cout<<1<<i<<" "<<j<<" "<<n<<" "<<n<<endl;
				int a;
				cin>>a;
				cout<<1<<i+1<<" "<<j<<" "<<n<<" "<<n<<endl;
				int b;
				cin>>b;
				cout<<1<<i<<" "<<j+1<<" "<<n<<" "<<n<<endl;
				int c;
				cin>>c;
			}
		}
	}

	cout<<"2"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<endl;
		}
		cout<<endl;
	}

	int check;
	cin>>check;
	if(check==-1){
		exit(0);
	}
}

int main()
{
	/*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		*/
	int t;
	cin>>t;

	while(t--){
		caller();
	}
    return 0;
}