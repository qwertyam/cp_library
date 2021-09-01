struct ModInv {
private:
    int A, B, M;
    long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    void ext_gcd(long long a,long long b, long long& x, long long& y) {
        if (b == 0) {
            x = 1;
            y = 1;
            return;
        }
        ext_gcd(b, a % b, y, x);
        y -= a / b * x;
        return;
    }
public:
    ModInv(long long a, long long b, long long m) {
        long long g = gcd(gcd(a, b), m);
        A = a / g;
        B = B_input / g;
        M = M_input / g;
    }
    bool exist() {
        return (gcd(A, M) == 1 ? true : false);
    }
    long long X() {
        if (exist() == false) {
            return -1;
        }
        long long x, y;
        ext_gcd(A, M, x, y);
        x *= B;
        x = (x % M + M) % M;
        return x;
    }
};

