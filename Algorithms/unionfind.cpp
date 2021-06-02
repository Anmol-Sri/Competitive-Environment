//uses both path compression and union by rank
struct UnionFind {
	vector < ll > p, rank, setSize;
	ll numSets;
    public : 
	UnionFind(ll N){
        numSets = N;
        p.resize(N);
		rank.resize(N);
		setSize.resize(N);
		for (ll i = 0; i < N; i++) {  p[i] = i; setSize[i] = 1; }
	}
	int findSet(ll i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(ll i, ll j) { return findSet(i) == findSet(j); }
	void unionSet(ll i, ll j){ 
		if (isSameSet(i, j)) return;
		numSets--; 
		ll x = findSet(i), y = findSet(j);
		if(rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
		else{
            p[x] = y; setSize[y] += setSize[x];
			if(rank[x] == rank[y]) rank[y]++; 
		} 
	}
	ll numDisjointSets() { return numSets; }
	ll sizeOfSet(ll i) { return setSize[findSet(i)]; }
};