#include <iostream>
#include <cmath>
#include <iomanip>
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
  int a_, b_, c_;
  Point m;
  Vector v;
  Line(const Point& a, const Point& b) : a_(v.y_), b_(-v.x_), c_(a.y_ * v.x_ - a.x_ * v.y_), m(a), v(Vector(a, b)) {
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
bool BeSegment(Point p, Segment s) {
  Vector r_1(s.a_, p);
  Vector r_2(p, s.b_);
  return ((r_1.VectorProduct(r_2) == 0) && (r_1.DotProduct(r_2) >= 0));
}
bool IsSegCrossing(const Segment& first, const Segment& second) {
  return ((Vector(first.a_, first.b_).VectorProduct(Vector(first.a_, second.a_)) *
               Vector(first.a_, first.b_).VectorProduct(Vector(first.a_, second.b_)) <
           0) &&
          (Vector(second.a_, second.b_).VectorProduct(Vector(second.a_, first.a_)) *
               Vector(second.a_, second.b_).VectorProduct(Vector(second.a_, first.b_)) <
           0)) ||
         (BeSegment(first.a_, second) || BeSegment(first.b_, second) ||
          (BeSegment(second.a_, first) || BeSegment(second.b_, first)));
}
}  // namespace geometry

int main() {
  geometry::Point a;
  geometry::Point b;
  geometry::Point c;
  geometry::Point d;
  std::cin >> a.x_ >> a.y_ >> b.x_ >> b.y_ >> c.x_ >> c.y_ >> d.x_ >> d.y_;
  geometry::Segment s(a, b);
  geometry::Segment r(c, d);
  geometry::IsSegCrossing(s, r) ? std::cout << "YES" : std::cout << "NO";
  return 0;
}