/*
Задача:
Реализовать синтаксис из main, чтобы проходили все static_assert.
Должно получится perfect forwarding подмножества интегральных типов (bool, int, short, long, etc.)
Ограничения:
Нет, можно пользоваться всем std::
*/

// TODO: implement

int main() {
{
  std::tuple<int, double, short, std::string> t;
  auto int_tup = take_only_integral_types(t);
  static_assert(std::is_same_v<decltype(int_tup), std::tuple<int&, short&>>);
  }
  {
  std::tuple<int, double, const short, std::string> t;
  auto int_tup = take_only_integral_types(t);
  static_assert(std::is_same_v<decltype(int_tup), std::tuple<int&, const short&>>);
  }
  {
  const std::tuple<int, double, short, std::string> t;
  auto int_tup = take_only_integral_types(t);
  static_assert(std::is_same_v<decltype(int_tup), std::tuple<const int&, const short&>>);
  }
  {
  std::tuple<int, double, short, std::string> t;
  auto int_tup = take_only_integral_types(std::move(t));
  static_assert(std::is_same_v<decltype(int_tup), std::tuple<int&&, short&&>>);
  }

  return 0;
}
