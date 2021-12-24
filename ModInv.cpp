
/* ---- ModInv (begin) ---- */

struct ModInv {
private:
	long long A, B, M;
	long long gcd(const long long a, const long long b) const;
	void ext_gcd(const long long a, const long long b, long long& x, long long& y) const;
public:
	ModInv();
	ModInv(const long long a, const long long b, const long long m);
	bool exist() const;
	long long X() const;
};

long long ModInv::gcd(const long long a, const long long b) const {
	assert(a >= 0 && b >= 0);
	if (b == 0) return a;
	return gcd(b, a % b);
}

void ModInv::ext_gcd(const long long a, const long long b, long long& x, long long& y) const {
	assert(a >= 0 && b >= 0);
	if (b == 0) {
		x = 1;
		y = 1;
		return;
	}
	ext_gcd(b, a % b, y, x);
	y -= a / b * x;
	return;
}

ModInv::ModInv(): A(0), B(0), M(0) {};

ModInv::ModInv(const long long a, const long long b, const long long m) {
	long long g = gcd(gcd(a, b), m);
	A = a / g;
	B = b / g;
	M = m / g;
}

bool ModInv::exist() const {
	return gcd(A, M) == 1;
}

long long ModInv::X() const {
	if (exist() == false) return -1;
	long long x, y;
	ext_gcd(A, M, x, y);
	x *= B;
	x = (x % M + M) % M;
	return x;
}

/* ---- ModInv (end) ---- */

