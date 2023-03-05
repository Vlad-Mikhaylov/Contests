#include <iostream>
#include <cmath>
#include <iomanip>
namespace geometry {
struct Point {
  int x_;
  int y_;
  Point() {
    this->x_ = 0;
    this->y_ = 0;
  }
};
class Vector {
 public:
  int x_;
  int y_;
  Vector(Point begin, Point end) {
    this->x_ = end.x_ - begin.x_;
    this->y_ = end.y_ - begin.y_;
  }
  Vector() = default;
  Vector operator+(Vector v_2) {
    Vector tmp;
    tmp.x_ = this->x_ + v_2.x_;
    tmp.y_ = this->y_ + v_2.y_;
    return tmp;
  }
  int DotProduct(Vector v_2) {
    return this->x_ * v_2.x_ + this->y_ * v_2.y_;
  }
  int VectorProduct(Vector v_2) {
    return this->x_ * v_2.y_ - this->y_ * v_2.x_;
  }
};
class Line {
 public:
  int a, b, c;
  Line(Point a, Point b) {
    Vector v = Vector(a, b);
    this->a = v.y_;
    this->b = -v.x_;
    this->c = a.y_ * v.x_ - a.x_ * v.y_;
  }
};
class Ray {
 public:
  Point p_;
  Vector v_;
  Ray(Point a, Point b) {
    this->p_ = a;
    this->v_ = Vector(a, b);
  }
};
class Segment {
 public:
  Point a_;
  Point b_;
  Segment(Point a, Point b) {
    this->a_ = a;
    this->b_ = b;
  }
};
bool BeLine(Point p, Line l) {
  return l.a * p.x_ + l.b * p.y_ + l.c == 0;
}
bool BeRay(Point p, Ray r) {
  Point zero;
  zero.x_ = 0;
  zero.y_ = 0;
  Vector op(zero, p);
  return ((r.v_.DotProduct(op) >= 0) && (r.v_.VectorProduct(op) == 0));
}
bool BeSegment(Point p, Segment s) {
  Vector r_1(s.a_, p);
  Vector r_2(p, s.b_);
  return ((r_1.VectorProduct(r_2) == 0) && (r_1.DotProduct(r_2) >= 0));
}
}  // namespace geometry

int main() {
  geometry::Point a;
  geometry::Point b;
  geometry::Point c;
  std::cin >> b.x_ >> b.y_ >> c.x_ >> c.y_ >> a.x_ >> a.y_;
  geometry::Line l(b, c);
  geometry::Ray r(b, c);
  geometry::Segment s(b, c);
  geometry::BeLine(a, l) ? std::cout << "YES" << '\n' : std::cout << "NO" << '\n';
  geometry::BeRay(a, r) ? std::cout << "YES" << '\n' : std::cout << "NO" << '\n';
  geometry::BeSegment(a, s) ? std::cout << "YES" << '\n' : std::cout << "NO" << '\n';
  return 0;
}