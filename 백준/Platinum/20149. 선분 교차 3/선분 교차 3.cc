#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;

struct Point {
	ll x, y;

	auto operator<=>(const Point&) const = default;
};

int ccw(Point& a, Point& b, Point& c) {
	long long op = 1L * (b.x - a.x) * (c.y - a.y)
				 - 1L * (b.y - a.y) * (c.x - a.x);
	if (op > 0) return 1;
	if (op < 0) return -1;
	return 0;
}

// 반환값: 0 = 없음, 1 = 한 점, 2 = 구간 겹침
int isCrossed(Point& A, Point& B, Point& C, Point& D) {
    int ab_c = ccw(A, B, C), ab_d = ccw(A, B, D);
    int cd_a = ccw(C, D, A), cd_b = ccw(C, D, B);

    long long std1 = 1LL * ab_c * ab_d;
    long long std2 = 1LL * cd_a * cd_b;

    // 교차 가능성 없음
    if (!(std1 <= 0 && std2 <= 0)) return 0;

    // 공선
	if (ab_c == 0 && ab_d == 0 && cd_a == 0 && cd_b == 0) {
        auto a0 = min(A, B), a1 = max(A, B);
        auto b0 = min(C, D), b1 = max(C, D);

        Point L = max(a0, b0); // 겹치는 시작점
        Point R = min(a1, b1); // 겹치는 끝점

        if (R < L) return 0;       // 실제로는 안 겹침
        if (L == R) return 1;      // 한 점에서만 만남
        return 2;                  // 구간으로 겹침
    }

    // 비공선 교차 → 무조건 한 점에서 교차(끝점 포함)
    return 1;
}

Point a, b, c, d;


pair<double, double> getPoint(Point& A, Point& B, Point& C, Point& D) {
    int ab_c = ccw(A, B, C);
    int ab_d = ccw(A, B, D);

    // 공선 → 한 점만 공유하는 경우
    if (ab_c == 0 && ab_d == 0) {
        auto a0 = min(A, B);
        auto a1 = max(A, B);
        auto b0 = min(C, D);
        auto b1 = max(C, D);
        Point L = max(a0, b0);
        // 여기서 L == R == 한 점
        return { L.x, L.y };
    }

    // 비공선 → 직선 방정식으로 교점 계산
    double a1_coef = B.y - A.y;
    double b1_coef = A.x - B.x;
    double c1_coef = a1_coef * A.x + b1_coef * A.y;

    double a2_coef = D.y - C.y;
    double b2_coef = C.x - D.x;
    double c2_coef = a2_coef * C.x + b2_coef * C.y;

    double det = a1_coef * b2_coef - a2_coef * b1_coef;

    double x = (b2_coef * c1_coef - b1_coef * c2_coef) / det;
    double y = (a1_coef * c2_coef - a2_coef * c1_coef) / det;

    return { x, y };
}

int main(void) {
	cin >> a.x >> a.y >> b.x >> b.y;
	cin >> c.x >> c.y >> d.x >> d.y;

	int res = isCrossed(a, b, c, d);
	if (res == 1) {
		cout << 1 << '\n';
        auto res = getPoint(a, b, c, d);
        printf("%.10f %.10f\n", res.first, res.second);
	}
	else if (res == 0)
		cout << 0;
	else
		cout << 1;
}