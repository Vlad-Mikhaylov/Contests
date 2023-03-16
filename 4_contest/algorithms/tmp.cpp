#include<iostream>
#include<cmath>
#include<vector>

class Vector {
public:
 long long x = 0;
 long long y = 0;

 Vector() = default;

 Vector(const Vector&) = default;

 ~Vector() = default;

 Vector& operator+=(const Vector& other) {
  x += other.x;
  y += other.y;
  return *this;
 }

 Vector& operator-=(const Vector& other) {
  x -= other.x;
  y -= other.y;
  return *this;
 }

 long long Scalar(const Vector& other) const {
  return x * other.x + y * other.y;
 }

 long long Mixed(const Vector& other) const {
  return x * other.y - y * other.x;
 }

 friend bool operator==(const Vector& a, const Vector& b) {
  return a.x == b.x && a.y == b.y;
 }
};

int main() {
 int n;
 std::cin >> n;
 Vector center;
 std::cin >> center.x >> center.y;
 std::vector<Vector> vec(n);

 for (int i = 0; i < n; i++) {
  std::cin >> vec[i].x >> vec[i].y;
  vec[i] -= center;
 }

 double angle = 0;
 for (int i = 0; i < n; ++i) {
  Vector a = vec[i];
  Vector b = vec[(i + 1) % n];
  if (a.Mixed(b) == 0 && std::min(a.x, b.x) <= 0 && std::max(a.x, b.x) >= 0 && std::min(a.y, b.y) <= 0 && std::max(a.y, b.y) >= 0) {
   std::cout << "YES\n";
   return 0;
  }
  angle += atan2(a.Mixed(b), a.Scalar(b));
 }
 if (std::abs(angle) >= acosl(-1)) {
  std::cout << "YES\n";
 }
 else {
  std::cout << "NO\n";
 }
}