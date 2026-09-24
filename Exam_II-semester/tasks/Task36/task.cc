// напишите адаптер enumerate. ranges запрещены

// 1. Обычный вектор
std::vector<int> v{10, 20, 30};
for (auto&& [i, x] : v | enumerate) {
    assert(i == &x - v.data());  // индекс совпадает с позицией
}

// 2. Модификация через enumerate
for (auto&& [i, x] : v | enumerate) {
    x += static_cast<int>(i);
}
assert((v == std::vector<int>{10, 21, 32}));

// 3. Const-диапазон
const std::vector<int> cv{1, 2, 3};
for (auto&& [i, x] : cv | enumerate) {
    static_assert(std::is_const_v<std::remove_reference_t<decltype(x)>>);
}

// 4. C-массив
int arr[] = {5, 6, 7};
for (auto&& [i, x] : arr | enumerate) { /* ... */ }

// 5. Random access: operator[] и арифметика
auto e = v | enumerate;
auto it = e.begin();
assert(std::get<0>(it[2]) == 2);
assert(std::get<0>(*(it + 1)) == 1);