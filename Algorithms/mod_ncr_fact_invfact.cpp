ll _MOD_;
ll add(ll x, ll y) {
	x += y;
	if (x >= _MOD_) return x - _MOD_;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + _MOD_;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % _MOD_;
}
ll inverse(ll x) {
	return powermod(x, _MOD_ - 2, _MOD_);
}

const int LIM = 1000; // change the limit according to the question

vector<ll> facs(LIM), invfacs(LIM); 

void precompute_fact_and_inverse()
{
    facs[0] = 1;
    for (ll i = 1; i < LIM; i++) facs[i] = mult(facs[i - 1], i);
    invfacs[LIM - 1] = inverse(facs[LIM - 1]);
    for (ll i = LIM - 2; i >= 0; i--) invfacs[i] = mult(invfacs[i + 1], i + 1);
}
 
int nCr(int n, int k)
{
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return mult(facs[n], mult(invfacs[k], invfacs[n-k]));
}