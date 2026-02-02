#include <stdio.h>

double fabs(double x) { return x >= 0 ? x : -x; }

double cbrt_newton(double x, double eps) {
  if (x < 0.0) {
    return 0;
  }
  if (x == 0.0)
    return 0.0;

  // Khởi tạo tránh 0
  double y = (x >= 1.0) ? x : 1.0;

  // Lặp Newton: y_{n+1} = (2*y + x/(y*y)) / 3
  // Tiêu chí dừng: |y_{n+1} - y_n| <= eps
  // Thêm limit để tránh treo nếu eps không phù hợp.
  const int MAX_ITERS = 1000000;
  for (int k = 0; k < MAX_ITERS; ++k) {
    double y2 = y * y;
    double next = (2.0 * y + x / y2) / 3.0;
    if (fabs(next - y) <= eps) {
      return next;
    }
    y = next;
  }
  // Nếu đến đây tức là chưa đạt eps, trả về xấp xỉ tốt nhất đang có
  return y;
}

int main(void) {
  double xs[] = {0.0, 1.0, 8.0, 27.0, 0.125, 1e-12, 1e12};
  double eps = 1e-12;
  for (int i = 0; i < (int)(sizeof(xs) / sizeof(xs[0])); ++i) {
    double r = cbrt_newton(xs[i], eps);
    printf("cbrt(%g) ≈ %.15f (kiểm tra: r^3 = %.15f)\n", xs[i], r, r * r * r);
  }
  return 0;
}
