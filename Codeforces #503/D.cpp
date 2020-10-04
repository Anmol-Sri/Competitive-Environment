#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int query(int student){
	cout<<"? "<<student<<endl;
	int value;
	cin>>value;
	return value;
}

void finish(int number){
	cout<<"! "<<number<<endl;
	exit(0);
}
int sign(int number){
	return number>0?+1:-1;
}

void solve(){
	int n;
	cin>>n;
	n/=2;
	int difference=query(1)-query(n+1);
	if(difference==0){
		finish(1);
	}
	if(difference%2!=0){
		finish(-1);
	}

	int low=2;
	int high=n;
	while(low<=high){
		int mid=low+(high-low)/2;
		int diff=query(mid)-query(mid+n);
		if(diff==0){
			finish(mid);
		}
		if(sign(diff)==sign(difference)){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return;
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}