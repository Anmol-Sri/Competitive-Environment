#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int x,y,x1,x2,y1,y2;
	cin>>x>>y>>x1>>y1>>x2>>y2;

	if(x1==x2 && y1==y2){
		if(a!=0 || b!=0 || c!=0 || d!=0){
			cout<<"No\n";
			return;
		}
		else{
			cout<<"Yes\n";
			return;
		}
	}
	if(x1==x2){
		if(a!=0 || b!=0){
			cout<<"No\n";
			return;
		}
	}
	if(y1==y2){
		if(c!=0 || d!=0){
			cout<<"No\n";
			return;
		}
	}
	if(a>b){
		x=x-(a-b);
	}
	else{
		x=x+(b-a);
	}
	if(c>d){
		y=y-(c-d);
	}
	else{
		y=y+(d-c);
	}
	if(x1<=x && x<=x2 && y1<=y && y<=y2){
		cout<<"Yes\n";
		return;
	}
	else
		cout<<"No\n";
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