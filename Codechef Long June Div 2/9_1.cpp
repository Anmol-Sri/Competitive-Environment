#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void recur(int one_start,int one_end,int second_start,int second_end){
	if(second_start<=second_end && one_start>one_end ){
		recur(second_start,(second_start+second_end)/2,(second_start+second_end)/2,second_end);
	}
	else if(one_start<=one_end && second_start>second_end){
		recur(one_start,(one_start+one_end)/2,(one_end+one_start)/2,one_end);
	}
	/*
	if(a1=='G' && a2=='G'){
			//eliminate t1 -- 0.....n -- remove 0...n/3
			start=fir+1;
			//end=n;
			fir=(start+end)/3;
			sec=2*fir;
		}
		else if(a1=='L' && a2=='G'){
			//start=1;
			end=sec-1;
			fir=(start+end)/3;
			sec=2*fir;	
		}
		else if(a1=='L' && a2=='L'){
			//start=1;
			end=sec-1;
			fir=(start+end)/3;
			sec=2*fir;
		}
		else{
			cout<<sec<<endl;
			char a3;
			cin>>a3;
			if(a3=='L'){
				//start=1;
				end=sec-1;
				fir=(start+end)/3;
				sec=2*fir;	
			}
			else{
				start=fir+1;
				//end=n;
				fir=(start+end)/3;
				sec=2*fir;
			}
			*/
	else if(second_start<=second_end && one_start<=one_end){
		int middle=(one_start+second_end)/2;
		cout<<middle<<endl;
		char ch;
		cin>>ch;
		if(ch=='L'){
			int step=0;
			char opp='G';

			for(;one_start<=one_end && second_start<=second_end;){
				int part_second_middle=second_start+(int)((second_end-second_start)*0.33);
				cout<<part_second_middle<<endl;
				char query_two;
				cin>>query_two;
				if(step==0 && query_two=='L'){
					recur(one_start,one_end,second_start,part_second_middle-1);
				}
				else if(query_two=='E'){
					exit(0);
				}
				step=1;
				if(query_two=='G' && opp=='L'){
					second_start=part_second_middle+1;
				}
				if(opp=='L' && query_two=='L'){
					second_end=part_second_middle-1;
					recur(one_start,one_end,second_start,second_end);
				}
				int part_one_middle=one_start+(int)((one_end-one_start)*0.67);
				cout<<part_one_middle<<endl;
				char query_three;
				cin>>query_three;
				opp=query_three;
				if(query_three=='L' && query_two=='G'){
					one_end=part_one_middle-1;
					second_start=part_second_middle+1;
				}
				else if(query_two=='G' && query_three=='G'){
					one_start=part_one_middle+1;
					recur(one_start,one_end,second_start,second_end);
				}
				else if(query_two=='L' && query_three=='L'){
					second_end=part_second_middle-1;
					recur(one_start,one_end,second_start,second_end);
				}
				else if(query_three=='E'){
					exit(0) ;
				}
			}
		}
		/*
		if(a1=='G' && a2=='G'){
			//eliminate t1 -- 0.....n -- remove 0...n/3
			start=fir+1;
			//end=n;
			fir=(start+end)/3;
			sec=2*fir;
		}
		else if(a1=='L' && a2=='G'){
			//start=1;
			end=sec-1;
			fir=(start+end)/3;
			sec=2*fir;	
		}
		else if(a1=='L' && a2=='L'){
			//start=1;
			end=sec-1;
			fir=(start+end)/3;
			sec=2*fir;
		}
		else{
			cout<<sec<<endl;
			char a3;
			cin>>a3;
			if(a3=='L'){
				//start=1;
				end=sec-1;
				fir=(start+end)/3;
				sec=2*fir;	
			}
			else{
				start=fir+1;
				//end=n;
				fir=(start+end)/3;
				sec=2*fir;
			}
			*/
		else if(ch=='G'){
			int step=0;
			char opp='L';

			for(;one_start<=one_end && second_start<=second_end;){
				int part_one_middle=one_start+(int)((one_end-one_start)*0.67);
				cout<<part_one_middle<<endl;
				char query_two;
				cin>>query_two;
				if(step==0 && query_two=='G'){
					recur(part_one_middle+1,one_end,second_start,second_end);
				}
				else if(query_two=='E'){
					exit(0);
				}
				step=1;
				if(query_two=='L' && opp=='G'){
					one_end=part_one_middle-1;
				}
				if(opp=='G' && query_two=='G'){
					one_start=part_one_middle+1;
					recur(one_start,one_end,second_start,second_end);
				}
				int part_second_middle=second_start+(int)((second_end-second_start)*0.33);
				cout<<part_second_middle<<endl;
				char query_three;
				cin>>query_three;
				opp=query_three;
				if(query_three=='G' && query_two=='L'){
					one_end=part_one_middle-1;
					second_start=part_second_middle+1;
				}
				else if(query_two=='G' && query_three=='G'){
					one_start=part_one_middle+1;
					recur(one_start,one_end,second_start,second_end);
				}
				else if(query_two=='L' && query_three=='L'){
					second_end=part_second_middle-1;
					recur(one_start,one_end,second_start,second_end);
				}
				else if(query_three=='E'){
					exit(0) ;
				}
			}

		}
		else{
			exit(0);
		}
	}
}

void solve(){
	int n;
	cin>>n;
	/*if(n<=120){
		for(int i=1;i<=n;i++){
			cout<<i<<endl;
			char ch;
			cin>>ch;
			if(ch=='E'){
				return ;
			}
		}
	}*/
	recur(1,n/2,n/2,n);
	return ;
	//vector<pair<int,int>> vec(3);

	/*
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
					return ;
				}
			}
		}
		char a1,a2;
		cout<<fir<<endl;
		cin>>a1;
		if(a1=='E'){
			return;
		}
		cout<<sec<<endl;
		cin>>a2;
		if(a2=='E'){
			return ;
		}
		if(a1=='G' && a2=='G'){
			//eliminate t1 -- 0.....n -- remove 0...n/3
			start=fir+1;
			//end=n;
			fir=(start+end)/3;
			sec=2*fir;
		}
		else if(a1=='L' && a2=='G'){
			//start=1;
			end=sec-1;
			fir=(start+end)/3;
			sec=2*fir;	
		}
		else if(a1=='L' && a2=='L'){
			//start=1;
			end=sec-1;
			fir=(start+end)/3;
			sec=2*fir;
		}
		else{
			cout<<sec<<endl;
			char a3;
			cin>>a3;
			if(a3=='L'){
				//start=1;
				end=sec-1;
				fir=(start+end)/3;
				sec=2*fir;	
			}
			else{
				start=fir+1;
				//end=n;
				fir=(start+end)/3;
				sec=2*fir;
			}
		}
	}
	*/
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