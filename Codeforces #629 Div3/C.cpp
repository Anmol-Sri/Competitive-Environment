#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	char ans1[n];
	char ans2[n];
	int i;
	bool counter=true;
	for(i=0;i<n;i++){
		char ch=str[i];
		if(counter){
			if(ch=='1'){
				ans1[i]='1';
				ans2[i]='0';
				counter=false;
			}
			else if(ch=='2'){
				ans1[i]='1';
				ans2[i]='1';
			}
			else if(ch=='0'){
				ans1[i]='0';
				ans2[i]='0';
			}
		}
		else{
			if(ch=='1'){
				ans1[i]='0';
				ans2[i]='1';
				counter=false;
			}
			else if(ch=='2'){
				ans1[i]='0';
				ans2[i]='2';
			}
			else if(ch=='0'){
				ans1[i]='0';
				ans2[i]='0';
			}
		}
	}
	for(i=0;i<n;i++){
		cout<<ans1[i];
	}
	cout<<"\n";
	for(i=0;i<n;i++){
		cout<<ans2[i];
	}
	cout<<"\n";
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