#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007;

ll N;

using Matrix = vector<vector<ll>>;

// 행렬 곱셈
Matrix multiply(const Matrix& A, const Matrix& B) {
    int size = A.size();
    Matrix result(size, vector<ll>(size, 0));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            for (int k = 0; k < size; ++k) {
                result[i][j] += A[i][k] * B[k][j];
                 result[i][j] %= MOD;
            }
    return result;
}

// 행렬 거듭제곱
Matrix power(Matrix base, ll exp) {
    int size = base.size();
    Matrix result(size, vector<ll>(size, 0));
    for (int i = 0; i < size; ++i)
        result[i][i] = 1;

    while (exp > 0) {
        if (exp % 2)
            result = multiply(result, base);
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

// 점화식 f(x) = 3f(x-2) + 2f(x-4) + 2f(x-6) + ... + 2f(0)
ll compute_fx(ll x) {
    if (x % 2 == 1) return 0;
    if (x == 0) return 1;
    ll n = x / 2;

    // 전이 행렬 정의
    Matrix T = {
        {3, 0, 2},
        {1, 0, 0},
        {1, 0, 1}
    };

    // 초기 상태벡터 [f(2), f(0), S(0)] = [3, 1, 1]
    vector<ll> init = { 3, 1, 1 };

    // T^(n - 1)
    Matrix Tn = power(T, n - 1);

    // f(x) = Tn[0] * init
    ll fx = 0;
    for (int i = 0; i < 3; ++i) {
        fx += Tn[0][i] * init[i];
         fx %= MOD;
    }

    return fx;
}

int main(void) {
	cin >> N;
	cout << compute_fx(N);
}