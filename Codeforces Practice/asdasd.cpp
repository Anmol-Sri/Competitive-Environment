#include <bits/stdc++.h>
using namespace std;
#define ll long long

int fibonacci_fast(ll n) {

    ll previous = 0;
    ll current  = 1;

    for (ll i = 0; i < n - 1; ++i) {
        ll tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    return current;

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

       ll n = 0;
    std::cin >> n;

    std::cout << fibonacci_fast(n) << '\n';
    //test_solution();
    //std::cout << fibonacci_fast(n) << '\n';
    return 0;
}