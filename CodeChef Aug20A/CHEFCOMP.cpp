#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 2e5 + 5;

vector<vector<int>> g;
ll parent[mxN];
ll part1[mxN];
ll sec[mxN];
ll final_value[mxN];
int n;
int i;

void ini(){
    memset(final_value, -1, sizeof final_value);
}

void input1(){
	g = vector<vector<int>> (n+5);
    i = 0;
    while(i < n - 1){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        i++;
    }
}

void travel(int idx, int p, ll pass, int month){
    sec[idx] -= pass;
    if(sec[idx] <= 0){
        sec[idx] = 0;
        if(final_value[idx] == -1) final_value[idx] = month;
    }
    for(auto x : g[idx]){
        if( p == x ) continue;
        travel(x, idx, pass, month);
    }
}


void out(){
	i = 1;
    while(i<=n){ cout << final_value[i] << " "; i++; }
    cout << "\n";
}

void input2(){
    i = 0;
    while(i<n) {cin >> parent[i+1]; i++; }
    i = 1;
    while(i<=n){cin >> part1[i]; i++;}
    i = 1;
    while(i<=n){ cin >> sec[i]; i++; }
}

void solve(){    
    cin >> n;
	input1();
	ini();
	input2();
    i = 1;
    while(i<=n){
        travel(parent[i],0,part1[parent[i]],i);
        for(auto x : g[parent[i]]){
            for(auto it = g[x].begin();it!=g[x].end();it++){
                if(*it == parent[i]){
                    g[x].erase(it);
                    break;
                }
            }
        }
        g[parent[i]].clear();
        i++;
    }
    out();
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

	int t = 1;
	cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}