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
bool BeLine(Point p, Line l) {
  return (l.a_ * p.x_ + l.b_ * p.y_ + l.c_ == 0);
}
bool BeRay(Point p, Ray r) {
  Vector op(r.p_, p);
  return ((r.v_.DotProduct(op) >= 0) && (r.v_.VectorProduct(op) == 0));
}
bool BeSegment(Point p, Segment s) {
  Vector r_1(s.a_, p);
  Vector r_2(p, s.b_);
  return ((r_1.VectorProduct(r_2) == 0) && (r_1.DotProduct(r_2) >= 0));
}
float DistanceLine(Point p, Line l) {
  Vector op(l.m, p);
  return std::abs((float(l.v.VectorProduct(op))) / (l.v.Module()));
}
float DistanceSegment(Point p, Segment s) {
  if (Vector(s.a_, p).DotProduct(Vector(s.a_, s.b_)) <= 0) {
    return Vector(s.a_, p).Module();
  }
  if (Vector(s.b_, p).DotProduct(Vector(s.b_, s.a_)) <= 0) {
    return Vector(s.b_, p).Module();
  }
  return DistanceLine(p, Line(s.a_, s.b_));
}
float DistanceRay(Point p, Ray r) {
  Vector op(r.p_, p);
  return (r.v_.DotProduct(op) > 0 ? std::abs((float(r.v_.VectorProduct(op)) / float(r.v_.Module()))) : op.Module());
}
}  // namespace geometry

int main() {
  geometry::Point a;
  geometry::Point b;
  geometry::Point c;
  std::cin >> a.x_ >> a.y_ >> b.x_ >> b.y_ >> c.x_ >> c.y_;
  geometry::Line l(b, c);
  geometry::Ray r(b, c);
  geometry::Segment s(b, c);
  std::cout << std::fixed << std::setprecision(6) << geometry::DistanceLine(a, l) << '\n';
  std::cout << std::fixed << std::setprecision(6) << geometry::DistanceRay(a, r) << '\n';
  std::cout << std::fixed << std::setprecision(6) << geometry::DistanceSegment(a, s) << '\n';
  return 0;
}