#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	if(n<500)
	{
		for(int i=1;i<=n;i++){
			cout<<i<<" "<<i<<"\n";
		}
	}
	else if(n==501){
		cout<<"1 1\n";
		cout<<"2 2\n";
		cout<<"3 2\n";
		for(int i=3;i<=n-2;i++){
			cout<<i<<" "<<i<<"\n";
		}
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

	for (int i = 1; i <= t; i++)
	{
	cout << "Case #" << i << ":\n";
	solve();
	}
    return 0;
}