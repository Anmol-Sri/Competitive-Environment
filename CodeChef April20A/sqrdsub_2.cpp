#include <bits/stdc++.h>
using namespace std;
#define ll long int

int power(int n){
    if(n % 2 == 1) return 0;
    if(n % 4 == 0) return 2;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;  
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    } //original array
    int p[n];               //powers of 2
    int b[n][2];            //b[i][0] to b[i][1]

    for(int i = 0; i < n; i++) {
        p[i] = power(a[i]);
        b[i][0] = -1; b[i][1] = -1;
    }

    int last0 = -1;
    int last1 = -1;

    for(int i = 0; i < n; i++){
        if(p[i] == 0){
            if(last0 == -1) last0 = i;
        }
        else if(p[i] == 1){ 
            if(last0 != -1){
                //cout<<last0<<endl;
                b[last0][0] = last0;
                b[last0][1] = i;
                last0 = -1;
            }
            if(last1 != -1){
                //cout<<last1<<endl;
                b[last1][0] = i;
                b[last1][1] = n;
            }
            last1 = i;
        }
        else if(p[i] == 2){
            b[i][0] = i; b[i][1] = n;
            if(last0 != -1){
               // cout<<last0<<endl;
                b[last0][0] = last0;
                b[last0][1] = i;
                last0 = -1;
            }
            if(last1 != -1){
                //cout<<last1<<endl;
                b[last1][0] = i;
                b[last1][1] = n;
                last1 = -1;
            }
        } 
    }

for(int i = 0; i < n; i++) {
      cout<<p[i]<<" - "<<b[i][0]<<" - "<<b[i][1]<<endl;
    }
    int sum = 0;

    for(int i = 0; i < n; i++) {
        if(p[i] == 0){
            //cout<<p[i]<<":\n";
            if(p[b[i][1]] == 1){
                int l = (b[i][1] - b[i][0]);
                //sequences only with 0
                int sequences = (l * (l + 1))/2;
                sum += sequences;

                //sequences starting from -1
                int pos1 = b[i][1];
                if(b[pos1][0] != -1) {
                    int seq1 = b[pos1][1] - b[pos1][0];
                    seq1 = (seq1  * (seq1 + 1)) / 2;
                    sum += seq1 * sequences;
                }
            }
            else{
                int l = (n - i);
                int sequences = (l * (l + 1))/2;
                sum += sequences - 1;
                //cout<<"\tadding "<<sequences - 1<<endl;
            }
            i = p[b[i][1]]-1;
        }
        else if(p[i] == 1) { 
            //cout<<p[i]<<":\n";
            if(b[i][0] != -1){
                int l = (b[i][1] - b[i][0]);    
                sum += (l * (l + 1))/2;
                //cout<<"\tadding "<<(l * (l + 1))/2<<endl;
            }
        }

        else if(p[i] == 2) {
            //cout<<p[i]<<":\n";
            int l = (n - i);
            sum += l;
            //cout<<"\tadding "<<l<<endl;
        }
    }



    cout<<sum<<endl;
    return 0;
}