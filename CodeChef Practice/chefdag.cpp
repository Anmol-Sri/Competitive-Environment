#include<bits/stdc++.h>
using namespace std;
bool sizecheck(vector<int> vec[],int n){
	for(int i=0;i<n;i++){
		if(vec[i].size()!=0) return true;
	}
	return false;
}

bool areequal(std){

}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[k][n];
		int ans[n];
		int check[n][n];
		memset(ans,-1,sizeof(ans));
		memset(check,-1,sizeof(check));
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
				arr[i][j]--;
				for(int q=0;q<=j;q++){
					check[arr[i][j]][arr[i][q]]=1;
				}
			}
		}

		
/*		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				for(int q=0;q<j;q++){
					check[arr[i][j]][arr[i][q]]=1;
				}
			}
		}
*/

		std::vector<int> vec[n];

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(check[i][j]==-1) vec[i].push_back(j);
			}
		}
		for(int i=0;i<n;i++){
			sort(vec[i].begin(), vec[i].end());
		}
		/*
		std::vector<pair<int,int>> svec;
		for(int i=0;i<n;i++){
			svec.push_back(make_pair(vec[i].size(),i));
		}

		sort(svec.begin(), svec.end());
		*/
		/*for(int i=0;i<n;i++){
			if(vec[i].size()==0){
				ans[i]=0;
				for(int j=0;j<n;j++){
					vec[j].erase(ans[i])
				}
			}
			else if(vec[i].size()==1){
				ans[i]=vec[i][0];
				for(int j=0;j<n;j++){
					vec[j].erase(ans[i])
				}
			}
		}*/
		/*for(int i=0;i<n;i++){
			for(int j=0;j<vec[i].size();j++){
				cout<<vec[i][j]<<" ";
			}
			cout<<"\n";
		}*/


		while(sizecheck(vec,n)){
			for(int i=0;i<n;i++){
				if(vec[i].size()==0){
					ans[i]=0;
					for(int j=0;j<n;j++){
						//vec[j].erase(ans[i]);
						for(int q=0;q<vec[i].size();q++){
							if(vec[i][q]==ans[i]) {vec[i].erase(vec[i].begin()+q);break;}
						}
					}
				}
				else if(vec[i].size()==1){
					ans[i]=vec[i][0];
					for(int j=0;j<n;j++){
						//vec[j].erase(ans[i]);
						for(int q=0;q<vec[i].size();q++){
							if(vec[i][q]==ans[i]) {vec[i].erase(vec[i].begin()+q);break;}
						}
					}
				}
				else{
					for(int i=0;i<n;i++){
						
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			if(ans[i]!=-1) ans++;
		}
		for(int i=0;i<k;i++){
			ans[arr[i][n-1]]=0;
		}
		int inans=0;
		for(int i=0;i<n;i++){
			if(ans[i]==0) inans++;
		}
		cout<<inans<<"\n";
		for(int i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}