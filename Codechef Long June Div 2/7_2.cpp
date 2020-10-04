#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e5+2;
#include <stdio.h>

long int minimumOfRatio(long int a,long int b,long int c){
	return min(a,min(b,c));
}

long int minimumOfDiff(long int a,long int b,long int c){
	return min(a,min(b,c));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    int testcase, steps;
    long int p, q, r, a, b, c;
    long int diff;
    //scanf("%d", &testcase);
    cin>>testcase;
    while(testcase){
        cin>>p>>q>>r;
		cin>>a>>b>>c;	
        steps = 0;
        while(p != a || q != b || r != c){
            if((a/p) * p == a && (b/q) * q == b && (c/r) * r == c){
                diff = minimumOfRatio(a/p, b/q, c/r);
                if(diff >= 2){
                    if(p != a && p*diff <= a){
                        p *= diff;
                    }
                    if(q != b && q*diff <= b){
                        p *= diff;
                    }
                    if(r != c && r*diff <= c){
                        r *= diff;
                    }
                }
                else{
                    diff = minimumOfDiff(a-p, b-q, c-r);
                    if(p != a){
                        p += diff;
                    }
                    if(q != b){
                        q += diff;
                    }
                    if(c != r){
                        r += diff;
                    }
                }
            }
            else{
                diff = minimumOfDiff(a-p, b-q, c-r);
                if(p != a){
                    p += diff;
                }
                if(q != b){
                    q += diff;
                }
                if(c != r){
                    r += diff;
                }
            }
            steps++;
        }
        printf("%d\n", steps);
        testcase--;
    }
    return 0;
}

/*

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}*/