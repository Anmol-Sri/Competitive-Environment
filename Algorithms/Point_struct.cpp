struct Point{
	ll x, y;
	Point() : x(), y(){}
	Point(ll _x, ll _y) : x(_x), y(_y){}
	void scan(){
		cin >> x >> y;
	}
	Point operator + (const Point &a) const{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const{
		return Point(x - a.x, y - a.y);
	}
	ll operator * (const Point &a) const{
		return x * a.y - y * a.x;
	}
};