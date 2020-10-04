#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	int a,b,c,d;
	int arr[4];
	cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
	sort(arr,arr+4);
	a=arr[0];
	b=arr[1];
	c=arr[2];
	d=arr[3];
	
	int x,y,z;
	z=c;
	x=b;
	while(b<=c){
		int m=c+(b-c)/2;
		if(x+m<=z){
			b=m+1;
		}
		else{
			y=m;
			break;
		}
	}
	cout<<x<<" "<<y<<" "<<z<<"\n";
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