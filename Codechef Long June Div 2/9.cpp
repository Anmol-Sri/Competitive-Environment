#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	if(n<=120){
		for(int i=1;i<=n;i++){
			cout<<i<<endl;
			char ch;
			cin>>ch;
			if(ch=='E'){
				exit(0);
			}
		}
	}

	//vector<pair<int,int>> vec(3);

	
	int start=1;
	int end=n;
	int fir=(start+end)/3;
	int sec=2*fir;
	while(true){
		if(end-start<=9){
			char ch;
			for(int i=start;i<=end;i++){
				cout<<i<<endl;
				cin>>ch;
				if(ch=='E'){
					exit(0) ;
				}
			}
		}
		char a1,a2;
		cout<<fir<<endl;
		cin>>a1;
		if(a1=='E'){
			exit(0);
		}
		cout<<sec<<endl;
		cin>>a2;
		if(a2=='E'){
			exit(0) ;
		}
		if(a1=='G' && a2=='G'){
			//eliminate t1 -- 0.....n -- remove 0...n/3
			start=fir+1;
			//end=n;
			int dif=end-start;
			fir=start + (dif)/3;
			sec=start + 2*((dif)/3);
		}
		else if(a1=='L' && a2=='G'){
			//start=1;
			end=sec-1;
			int dif=end-start;
			fir=start + (dif)/3;
			sec=start + 2*((dif)/3);	
		}
		else if(a1=='L' && a2=='L'){
			//start=1;
			end=sec-1;
			int dif=end-start;
			fir=start + (dif)/3;
			sec=start + 2*((dif)/3);
		}
		else{
			cout<<sec<<endl;
			char a3;
			cin>>a3;
			if(a3=='L'){
				//start=1;
				end=sec-1;
				int dif=end-start;
				fir=start + (dif)/3;
				sec=start + 2*((dif)/3);
			}
			else{
				/*
				start=fir+1;
				//end=n;
				int dif=end-start;
				fir=start + (dif)/3;
				sec=start + 2*((dif)/3);*/
				cout<<sec<<endl;
				char a4;
				cin>>a4;
				if(a4=='L'){
					start=fir+1;
					end=sec-1;
					int dif=end-start;
					fir=start + (dif)/3;
					sec=start + 2*((dif)/3);
				}
				else{
					start=fir+1;
					int dif=end-start;
					fir=start + (dif)/3;
					sec=start + 2*((dif)/3);
				}
			}
		}

		if(start>=end)
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
	int t=1;
	while(t--){
		solve();
	}
    return 0;
}