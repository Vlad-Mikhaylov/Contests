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
};
class Vector {
 public:
  int64_t x_;
  int64_t y_;
  Vector(const Point& begin, const Point& end) : x_(end.x_ - begin.x_), y_(end.y_ - begin.y_) {
  }
  Vector() = default;
  Vector& operator=(const Vector& v_2) = default;
  Vector operator+(const Vector& v_2) {
    Vector tmp;
    tmp.x_ = this->x_ + v_2.x_;
    tmp.y_ = this->y_ + v_2.y_;
    return tmp;
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
  
  for (int i = 0; i < vertices.end() - vertices.begin() - 1; i++) {
    area += Vector(null, vertices[i]).VectorProduct(Vector(null, vertices[i + 1]));
  }
  area += Vector(null, vertices.back()).VectorProduct(Vector(null, vertices[0]));
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
  auto vertices = std::vector<geometry::Point>();
  std::cin >> n;
  geometry::Point tmp;
  for (int i = 0; i < n; i++) {
    std::cin >> tmp.x_ >> tmp.y_;
    vertices.emplace_back(tmp);
  }
  int64_t area = geometry::Area(vertices) >= 0 ? geometry::Area(vertices) : -geometry::Area(vertices);
  int64_t real_area = area / 2;
  if (area % 2 == 0) {
    std::cout << real_area << ".0";
  } else {
    std::cout << real_area << ".5";
  }
  return 0;
}