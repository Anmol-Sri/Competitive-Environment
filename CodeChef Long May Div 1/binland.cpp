#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MOD=1e9+7;
const int mxN=3e5+10;

int N;
int c,d;
int r;
ll ans;
std::vector<std::vector<int> >matrix;

void count( int row, int col){
        //base case
        //check if last cell is reached since after that only one path
		if(col>N-1 || col<0){
			return ;
		}
        if(row==r-1 and col==d){
            ans++;
            return;
        }
        int chance=d-col;
        int qwe=N-1-row;
        /*
        if(qwe>	chance){
        	return;
        }*/
        if(row!=r-1 and matrix[row+1][col+1]==matrix[0][c]){
            count( row+1, col+1);
        }
        if(row!=r-1 and matrix[row+1][col-1]==matrix[0][c]){
             count( row+1, col-1);
        }
        if(row!=r-1 and matrix[row+1][col]==matrix[0][c]){
             count( row+1, col);
        }

        return;
    }


void solve()
{
	string s;
	cin>>s;

	if(s[0]=='a'){

		vector<int> row;
		char x;
		for(int i=0;i<N;i++){
			cin>>x;
			if (x=='1')
				row.push_back(1);
			else
				row.push_back(0);
		}
		matrix.push_back(row);

		//print_matrix();
		return ;
	}
	else if(s[0]=='r'){
		if(matrix.size()==0){
			return ;
		}
		matrix.erase(matrix.begin());
		return ;
	}
	else{
		r=matrix.size();
		int x,y;
		cin>>x>>y;
		if(r==0){
			cout<<"0\n";
			return ;
		}
		else if(r==1){
			if(x==y){
				cout<<"1\n";
				return;
			}
			else{
				cout<<"0\n";
				return ;
			}
		}
		else if(matrix[0][x-1]!=matrix[r-1][y-1]){
			cout<<"0\n";
			return ;
		}
		
		c=x;
		d=y;
		c--;
		d--;
		ans=0;
		count(0,c);
		cout<<ans%MOD<<"\n";
	}
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

	int Q;
	cin>>N>>Q;

	while(Q--){
		solve();
	}
    return 0;
}