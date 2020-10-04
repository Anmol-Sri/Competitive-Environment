#include <bits/stdc++.h>
using namespace std;
#define ll long int

int min_in(std::vector<int> vec){
	int index=0;
	for(int i=1;i<vec.size();i++){
		if(vec[i]<vec[index]){
			index=i;
		}
	}
	return index;
}

int max_in(std::vector<int> vec){
	int index=0;
	for(int i=1;i<vec.size();i++){
		if(vec[i]>vec[index]){
			index=i;
		}
	}
	return index;
}

vector<int> check_score(vector<int> sc,vector<int> array,bool flag){

	for(auto i:array){
		if(flag){
			sc[i]++;
		}
		else{
			sc[i]--;
		}
	}
	return sc;
}

void solve(){
	int n,m,k;
	int arr[n][k];

	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cin>>arr[i][j];
		}
	}

	int group=-1;
	int test;
	if(n==100 && m==2){
		group=1;
		test=1000;
	}
	else if(n==100 && m==4){
		group=2;
		test=1200;
	}
	else if(n==200 && m==2){
		group=3;
		test=100;
	}
	else if(n==300 && m==4){
		group=4;
		test=100;
	}
	else if(n==500 && m==9){
		group=5;
		test=300;
	}

	std::vector<vector<vector<int> > > index;
	std::vector<vector<int> > count;

	for(int i=0;i<n;i++){
		std::vector<vector<int> > fre(m);
		std::vector<int> temp(m);

		for(int j=0;j<k;j++){
			fre[arr[i][j]-1].push_back(j);
			temp[arr[i][j]-1]++;
		}

		index.push_back(fre);
		count.push_back(temp);
	}


	int min_index=-1;
	int sc=-1; 
	test=1;
	std::vector<int> final;

	for(int q=0;q<test;q++){
		/*if(q%100==0){
			srand();
		}*/
		std::vector<int> pattern;
		for(int i=0;i<n;i++){
			pattern.push_back(i);
		}

		if(q>0){
			random_shuffle(pattern.begin(), pattern.end());
		}

		std::vector<int> temp(n);
		std::vector<int> ch_score(k);
		for(int i=0;i<ch_score.size();i++){
			ch_score[i]=0;
		}

		for(int w=0;w<n;w++){
			int i=pattern[w];
			int t1=min_in(ch_score);
			min_index=t1;
			int c=arr[i][min_index];
			temp[i]=c;
			ch_score=check_score(ch_score,index[i][c-1],true);			
		}

		//int temp_ans=min_in(ch_score);
		int now=*min_element(ch_score.begin(),ch_score.end());
		random_shuffle(pattern.begin(), pattern.end());

		for(int w=0;w<n;w++){
			int i=pattern[w];
			int now_c=temp[i]-1;
			int t1=max_in(count[i]);
			int mode=t1;

			if(mode==now_c){
				continue;
			}

			ch_score=check_score(ch_score,index[i][now_c],false);	
			ch_score=check_score(ch_score,index[i][mode],true);	

			int update=*min_element(ch_score.begin(),ch_score.end());

			if(now<update){
				now=update;
				temp[i]=mode+1;
			}
			else{
				ch_score=check_score(ch_score,index[i][now_c],true);	
				ch_score=check_score(ch_score,index[i][mode],false);	
			}
		}

		if(sc<now){
			final=temp;
			sc=now;
		}
	}

	for(auto x:final){
		cout<<x<<" ";
	}
	cout<<"\n";
	return;
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