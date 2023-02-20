#include <iostream>
#include <cmath>
#include <iomanip>
struct Dot {
  float x;
  float y;
  Dot(float x_c, float y_c) {
    this->x = x_c;
    this->y = y_c;
  }
};

class Line {
 public:
  float a, b, c;
  void SetNormal();
  void RelLines(Line l_2);
  Dot SetPoint(Line l_2);
  float Distance(Line l_2);
  bool IsDetNull(Line l_2);
};
bool Line::IsDetNull(Line l_2) {
  return this->a * l_2.b - this->b * l_2.a == 0;
}
void Line::SetNormal() {
  std::cout << std::fixed << std::setprecision(6) << this->b << ' ' << -this->a << '\n';
}
void Line::RelLines(Line l_2) {
  if (this->IsDetNull(l_2)) {
    std::cout << std::fixed << std::setprecision(6) << this->Distance(l_2) << '\n';
  } else {
    std::cout << std::fixed << std::setprecision(6) << this->SetPoint(l_2).x << ' ' << this->SetPoint(l_2).y << '\n';
  }
}
float Line::Distance(Line l_2) {
  return (abs(l_2.c * (this->a / l_2.a) - this->c) / sqrt(this->a * this->a + this->b * this->b));
}
Dot Line::SetPoint(Line l_2) {
  float delta = this->a * l_2.b - this->b * l_2.a;
  float delta_2 = this->a * l_2.c - this->c * l_2.a;
  float delta_1 = this->c * l_2.b - this->b * l_2.c;
  Dot sol((-delta_1 / delta), (-delta_2 / delta));
  return sol;
}
int main() {
  Line l_1;
  Line l_2;
  std::cin >> l_1.a >> l_1.b >> l_1.c;
  std::cin >> l_2.a >> l_2.b >> l_2.c;
  l_1.SetNormal();
  l_2.SetNormal();
  l_1.RelLines(l_2);
  return 0;
}