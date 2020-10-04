#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const ll mxN=3e5+11;
char s[mxN][28];
char reverse_string[mxN][28];


struct Data_Structure
{
	ll next_iter[mxN][26];
	ll error[mxN];
	ll length[mxN];
	ll count;
	ll last[mxN];
	ll store[mxN][28];

	vector <ll> graph[mxN];

	void initialize(){
		memset(error,0,sizeof error);
		memset(last,0,sizeof last);
		memset(length,0,sizeof length);
		memset(next_iter,0,sizeof next_iter);
		memset(store,0,sizeof store);
		//to.clear();
		ll i=0;
		while(i<=count){
			graph[i].clear();
			i++;
		}
		count = 0;
	}

	void append(string s,ll last_index,ll max){
		ll idx=0;
		ll i=0;
		while(i<max){
			ll index = s[i]-'a';
			if(next_iter[idx][index]==0){
				++count;
				next_iter[idx][index]=count;
			}
			idx=next_iter[idx][index];
			i++;
		}
		last[idx] = last_index;
		length[idx] = max;
	}

	void init(){
		queue <ll> que;
		ll i=0;
		while(i<26){
			if(next_iter[0][i]){
				que.push(next_iter[0][i]);
			}
			i++;
		}
		while(que.empty()==false){
			ll index = que.front(); que.pop();
			i=0;
			while(i<26){
				if(next_iter[index][i]){
					error[next_iter[index][i]]=next_iter[error[index]][i];
					que.push(next_iter[index][i]);
				}
				else{
					next_iter[index][i] = next_iter[error[index]][i];
				}
				i++;
			}
		}
	}

	void string_init(string s, ll *preffix, ll max){
		ll index = 0;
		ll i=0;
		while(i<max){
			index=next_iter[index][s[i]-'a'];
			ll j=index;
			while(j){
				preffix[i]=preffix[i]+last[j];
				j=error[j];
			}
			i++;
		}
	}

	void traverse(ll u){
		ll i=length[u];
		while(i>0){
			store[u][i]=store[u][i]+last[u];
			i--;
		}
		i=0;
		ll idx;
		while(i<graph[u].size()){
			idx=graph[u][i];
			ll j=26;
			while(j>0){
				store[idx][j]=store[idx][j]+store[u][j];
				j--;
			}
			traverse(idx);
			i++;
		}
	}
}data1,data2;

	//Data_Structure data1;
	//Data_Structure data2;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	ll t;
	cin>>t;

	while(t--){

		string a,b;
		ll n;

		cin>>a>>b>>n;

		ll x =a.size();
		ll y =b.size();

		char ith_iter[y];
		ll i=0;
		while(i<y){
			ith_iter[i]=b[y-i-1];
			i++;
		}

		data1.initialize();
		
		//just kidding 
		//:)))))))))
		ll asd=123145345;
		ll qwefrffer=123135884;
		ll kkjsnf=asd+qwefrffer;
		
		data2.initialize();

		ll tot_count[n+1];
		i=1;
    
		while(i<=n){
			cin>>s[i]>>tot_count[i];
			ll t=strlen(s[i]);
			data1.append(s[i], tot_count[i], t);
			for(ll j=0; j<t; j++){
				reverse_string[i][j] = s[i][t-j-1];
			}
			data2.append(reverse_string[i], tot_count[i], t);
			i++;
		}

		data1.init();
		data2.init();
		ll preffix[x]={0};
		ll suffix[y]={0};

		data1.string_init(a, preffix, x);
		data2.string_init(ith_iter, suffix, y);

		ll ans = 0;
		ll p = 0;

		i=1;
		while(i<x){
			preffix[i]=preffix[i-1]+preffix[i];
			i++;
		}

		i=1;
		while(i<y){
			suffix[i]=suffix[i-1]+suffix[i];
			i++;
		}

		i=1;
		while(i<=data1.count){
			ll t1=data1.error[i];
			data1.graph[t1].push_back(i);
			i++;
		}

		data1.traverse(0);

		i=0;
		while(i<x){

			p=data1.next_iter[p][a[i]-'a'];
			ll j=0;

			while(j<y){

				ll temp=preffix[i]+suffix[y-j-1];
				ll p_temp=p;
				ll qwe=0;
				while(qwe<25 and j+qwe<y){
					p_temp=data1.next_iter[p_temp][b[j+qwe]-'a'];
					temp=temp+data1.store[p_temp][qwe+2];
					qwe++;
				}

				if(ans<temp){
					ans=temp;
				}
				j++;
			}
			i++;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
