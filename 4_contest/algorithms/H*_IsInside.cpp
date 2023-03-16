#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
namespace geometry {
struct Point {
  int64_t x_;
  int64_t y_;
  Point() : x_(0), y_(0) {
  }
  Point(int64_t x, int64_t y) : x_(x), y_(y) {
  }
  Point& operator-=(Point& v_2) {
    this->x_ = this->x_ - v_2.x_;
    this->y_ = this->y_ - v_2.y_;
    return *this;
  }
};
std::istream& operator>>(std::istream& is, Point& tmp) {
  is >> tmp.x_;
  is >> tmp.y_;
  return is;
}
class Vector {
 public:
  int64_t x_;
  int64_t y_;
  Vector(const Point& begin, const Point& end) : x_(end.x_ - begin.x_), y_(end.y_ - begin.y_) {
  }
  Vector(const Point& end) : x_(end.x_), y_(end.y_) {  //NOLINT
  }
  Vector() = default;
  Vector& operator=(const Vector& v_2) = default;
  Vector operator+(const Vector& v_2) {
    Vector tmp;
    tmp.x_ = this->x_ + v_2.x_;
    tmp.y_ = this->y_ + v_2.y_;
    return tmp;
  }
  Vector& operator-=(Vector& v_2) {
    this->x_ = this->x_ - v_2.x_;
    this->y_ = this->y_ - v_2.y_;
    return *this;
  }
  int64_t DotProduct(const Vector& v_2) const {
    return this->x_ * v_2.x_ + this->y_ * v_2.y_;
  }
  int64_t VectorProduct(const Vector& v_2) const {
    return this->x_ * v_2.y_ - this->y_ * v_2.x_;
  }
  double Module() const {
    int64_t len = this->x_ * this->x_ + this->y_ * this->y_;
    return sqrt(len);
  }
};
class Line {
 public:
  Vector v;
  int a_, b_, c_;
  Point m;
  Line(const Point& a, const Point& b) : v(Vector(a, b)), a_(v.y_), b_(-v.x_), c_(a.y_ * v.x_ - a.x_ * v.y_), m(a) {
  }
};
class Ray {
 public:
  Point p_;
  Vector v_;
  Ray(const Point& a, const Point& b) {
    this->p_ = a;
    this->v_ = Vector(a, b);
  }
};
class Segment {
 public:
  Point a_;
  Point b_;
  Segment(const Point& a, const Point& b) {
    this->a_ = a;
    this->b_ = b;
  }
};
bool CheckConvexPoligon(const std::vector<Point>& vertices) {
  Vector tmp(vertices.back(), vertices.front());
  size_t i = 0;
  while (tmp.VectorProduct(Vector(vertices[i], vertices[i + 1])) == 0) {
    tmp = Vector(vertices[i], vertices[i + 1]);
    i++;
  }
  int64_t checker = tmp.VectorProduct(Vector(vertices[i], vertices[i + 1])) /
                    std::abs(tmp.VectorProduct(Vector(vertices[i], vertices[i + 1])));
  tmp = Vector(vertices[0], vertices[1]);
  for (size_t i = 1; i < vertices.size() - 1; i++) {
    if (tmp.VectorProduct(Vector(vertices[i], vertices[i + 1])) * checker < 0) {
      return false;
    }
    tmp = Vector(vertices[i], vertices[i + 1]);
  }
  return true;
}
void CheckInside(std::vector<Vector> vertices) {
  double angle = 0;
  for (size_t i = 0; i < vertices.size(); ++i) {
    Vector a = vertices[i];
    Vector b = vertices[(i + 1) % vertices.size()];
    if (a.VectorProduct(b) == 0 && std::min(a.x_, b.x_) <= 0 && std::max(a.x_, b.x_) >= 0 &&
        std::min(a.y_, b.y_) <= 0 && std::max(a.y_, b.y_) >= 0) {
      std::cout << "YES\n";
      return;
    }
    angle += atan2(a.VectorProduct(b), a.DotProduct(b));
  }
  if (std::abs(angle) >= acosl(-1)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}
int64_t Area(const std::vector<Point>& vertices) {
  int64_t area = 0;
  Point null(0, 0);
  for (int i = 0; i < vertices.end() - vertices.begin() - 1; i++) {
    area += Vector(null, vertices[i]).VectorProduct(Vector(null, vertices[i + 1]));
  }
  area += Vector(null, vertices.back()).VectorProduct(Vector(null, vertices[0]));
  return area;
}
}  // namespace geometry

int main() {
  int n;
  auto vertices = std::vector<geometry::Vector>();
  std::cin >> n;
  geometry::Point center;
  std::cin >> center;
  geometry::Point tmp;
  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    tmp -= center;
    vertices.emplace_back(tmp);
  }
  geometry::CheckInside(vertices);
  return 0;
}