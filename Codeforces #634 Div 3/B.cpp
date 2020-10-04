#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	string ans="";
	if(b==1){
		char ch='a';
		for(int i=0;i<n;i++){
			cout<<ch;
		}
		cout<<"\n";
		return;
	}
	else if(a==b){
		char ch=char(int('a')-1);
		for(int i=0;i<n;i++){
			ch++;
			cout<<(ch);
			if(ch=='z'){
				ch=char(int('a')-1);;
			}
		}
		return;
	}
	for(int i=0;i<b;i++){
		ans=ans+(char)('a'+i);
	}
	int count=0;
	for(int i=b;i<a;i++){
		ans=ans+ans[count%b];
		count++;
	}
	int i;
	for( i=a;i<(n/a)*a;i++){
		ans=ans+ans;
	}
	for( i=0;i<n%a;i++){
		ans=ans+ans[i];
	}
	cout<<ans<<"\n";
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