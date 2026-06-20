#include <cassert>
#include <filesystem>
#include <iostream>
#include <string>

// Условие: реализуйте FileHashMultiMap<K, V> — мультимапу (одному ключу может
// соответствовать несколько значений). Ключи хранятся в оперативной памяти,
// значения — на диске в одном файле. Тип V — trivially copyable.
//   - добавление значения insert(k, v) работает за O(1);
//   - потребление оперативной памяти пропорционально числу КЛЮЧЕЙ и НЕ зависит
//     от числа значений (у ключа может быть сколько угодно значений);
//   - интерфейс в духе std::multimap: find(k) возвращает итератор на первый
//     элемент ключа (или end(), если ключа нет), equal_range(k) — пару
//     итераторов [first, last) по всем значениям ключа;
//   - поддерживается range-based for по всем парам (ключ, значение);
//   - значение можно перезаписать по месту (через ссылку/прокси).

// TODO: implement
template <typename K, typename V>
class FileHashMultiMap {};

int main() {
    FileHashMultiMap<std::string, int> mm(std::filesystem::temp_directory_path() /
                                          "file_hash_multimap.bin");

    mm.insert("a", 1);
    mm.insert("a", 2);
    mm.insert("a", 3);
    mm.insert("b", 10);

    assert(mm.find("a") != mm.end());

    auto [first, last] = mm.equal_range("a");
    int a_sum = 0, a_count = 0;
    for (auto i = first; i != last; ++i) {
        a_sum += static_cast<int>((*i).value);
        ++a_count;
    }
    assert(a_count == 3 && a_sum == 6);

    auto [b_first, b_last] = mm.equal_range("b");
    for (auto i = b_first; i != b_last; ++i) (*i).value = 99; // перезапись по месту
    assert(static_cast<int>((*mm.find("b")).value) == 99);

    long total = 0;
    std::size_t count = 0;
    for (auto e : mm) {
        total += static_cast<int>(e.value);
        ++count;
    }
    assert(count == 4 && total == 105);

    assert(mm.find("zzz") == mm.end());
    assert(mm.keys() == 2);
    std::cout << "ok\n";
}
