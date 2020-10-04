#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	if(n==1){
		cout<<"FastestFinger\n";
		return ;
	}
	if(n==2){
		cout<<"Ashishgup\n";
		return ;
	}
	if(n%2==1){
		cout<<"Ashishgup\n";
		return ;
	}	

/*
	int chance=0;
	while(n>1){
		if(n==2){
			if(chance%2==0){
				cout<<"Ashishgup\n";
			}
			else{
				cout<<"FastestFinger\n";
			}
			return ;
		}
		bool ok=true;
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				if((n/i)%2==0 && (n/i)!=2){
					n=n/i;
					ok=false;
					chance++;
					break;
				}
			}		
		}
		if(ok){
			n--;
			chance++;
		}
		//cout<<n<<" - "<<chance<<"\n";
		if(n%2==1){
			if(chance%2==0){
				cout<<"Ashishgup\n";
			}
			else{
				cout<<"FastestFinger\n";
			}
			return ;
		}
		
	}

	if(chance%2==1){
		cout<<"Ashishgup\n";
	}
	else{
		cout<<"FastestFinger\n";
	}
	return ;*/


	if(!(n&(n-1))){
		cout<<"FastestFinger\n";
		return ;
	}
	/*
	bool prime=true;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			prime=false;
			break;
		}
	}
	*/
	bool prime=true;
	n/=2;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			prime=false;
			break;
		}
	}
	if(prime){
		cout<<"FastestFinger\n";
		return ;
	}
	cout<<"Ashishgup\n";
	return ;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		clock_t tStart = clock();
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
	#ifndef ONLINE_JUDGE
		cerr<<fixed<<setprecision(10)<<"Time Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
	#endif

	return 0;
}