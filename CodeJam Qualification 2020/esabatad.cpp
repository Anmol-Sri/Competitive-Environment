#include <bits/stdc++.h>
using namespace std;
#define ll long int

int t,b,arr[100];
int oper1,oper2;

void takevalue(int i){
	cout<<i+1<<endl;
	cout.flush();
	cin>>arr[i];
	cout<<b-i<<endl;
	cout.flush();
	cin>>arr[b-i-1];
	if(arr[i]==arr[b-i-1]){
		if(oper1==-1){
			oper1=i;
		}
	}
	else{
		if(oper2==-1){
			oper2=i;
		}
	}
}
int accept(int n){
	int ans;
	cout<<n+1<<endl;
	cout.flush();
	cin>>ans;
	return ans;
}
void calc(){
	bool flag=false;
	if(oper1!=-1 && arr[oper1]!=accept(oper1)){
		flag=true;
	}
	bool check=flag;
	if(oper2!=-1 && arr[oper2]!=accept(oper2)){
		check=!flag;
	}
	if(flag){
		for(int i=0;i<b;i++){
			arr[i]=!arr[i];
		}
	}
	if(check){
		for(int i=0;i<b/2;i++){
			swap(arr[i],arr[b-i-1]);
		}
	}
}

void solve(){
	oper1=oper2=-1;;
	int c=0;
	while(c<5){
		takevalue(c);
	}
	calc();

	while(c<b/2){
		int i=0;
		for(;i<4 && c<b/2;++c,++i)
			takevalue(c);
		if(i==4){
			calc();
		}
	}
	for(int i=0;i<b;i++){
		cout<<arr[i];
	}
	cout<<endl;
	cout.flush();
	char pro;
	cin>>pro;
	if(pro=='N'){
		exit(0);
	}

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>t>>b;

	while(t--){
		solve();
	}
    return 0;
}