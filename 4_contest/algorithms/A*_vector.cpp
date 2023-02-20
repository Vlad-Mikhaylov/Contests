#include <iostream>
#include <cmath>
#include <iomanip>
class V {
 public:
  float x_1, y_1, x_2, y_2;
  void FullFill();
  float x_c = x_2 - x_1;
  float y_c = y_2 - y_1;
  float Length();
  V operator+(V v_2);
  float DotProduct(V v_2);
  float VectorProduct(V v_2);
  float TriangleArea(V v_2);
};
void V::FullFill() {
  this->x_c = this->x_2 - this->x_1;
  this->y_c = this->y_2 - this->y_1;
}
float V::Length() {
  return sqrt(pow(this->x_1 - this->x_2, 2) + pow(this->y_1 - this->y_2, 2));
}
V V::operator+(V v_2) {
  V tmp;
  tmp.x_1 = this->x_1 + v_2.x_1;
  tmp.y_1 = this->y_1 + v_2.y_1;
  tmp.y_2 = this->y_2 + v_2.y_2;
  tmp.x_2 = this->x_2 + v_2.x_2;
  tmp.FullFill();
  return tmp;
}

float V::DotProduct(V v_2) {
  this->FullFill();
  v_2.FullFill();
  return this->x_c * v_2.x_c + this->y_c * v_2.y_c;
}

float V::VectorProduct(V v_2) {
  this->FullFill();
  v_2.FullFill();
  return this->x_c * v_2.y_c - this->y_c * v_2.x_c;
}

float V::TriangleArea(V v_2) {
  return float(abs(this->VectorProduct(v_2))) / 2;
}

int main() {
  V v_1;
  V v_2;
  std::cin >> v_1.x_1 >> v_1.y_1 >> v_1.x_2 >> v_1.y_2;
  std::cin >> v_2.x_1 >> v_2.y_1 >> v_2.x_2 >> v_2.y_2;
  v_1.FullFill();
  v_2.FullFill();
  std::cout << std::fixed << std::setprecision(6) << v_1.Length() << ' ' << v_2.Length() << '\n';
  V tmp = v_1 + v_2;
  std::cout << std::fixed << std::setprecision(6) << tmp.x_c << ' ' << tmp.y_c << '\n';
  std::cout << std::fixed << std::setprecision(6) << v_1.DotProduct(v_2) << ' ' << v_1.VectorProduct(v_2) << '\n';
  std::cout << std::fixed << std::setprecision(6) << v_1.TriangleArea(v_2);
  return 0;
}