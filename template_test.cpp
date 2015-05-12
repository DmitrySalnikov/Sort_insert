#include "../gtest/gtest/gtest.h"
#include "sort_template.h"
/*
using f_dd2b = bool (*)(double, double);

bool less(double a, double b) {
  return a < b;
}
*/
bool is_sorted(const double * a, const double * b) {
  for (auto p = a + 1; p < b; ++p)
    if (less(*p, *(p - 1))) 
      return false;
  return true;
}

bool is_empty(double a) {
  sort(&a, &a);
  return true;
}

bool one_element(double * a) {
  sort(a, a + 1);
  return true;
}

TEST(is_sorted, true) {
  double arr[] = {546, 0, 4564987, 213.234165, 1, 
    87, 546, 0, 64, 9798};
  const size_t len = sizeof(arr) / sizeof(arr[0]);
  sort<double>(arr, arr + len);

  EXPECT_TRUE(is_sorted(arr, arr + len));
}

TEST(empty, true) {
  double a = 0;
  EXPECT_TRUE(one_element(&a));
}

TEST(one_element, true) {
  double a = 0;
  EXPECT_TRUE(is_empty(a));
}

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS(); 
}
