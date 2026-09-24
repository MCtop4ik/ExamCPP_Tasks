#include <cassert>
#include <filesystem>
#include <iostream>
#include <string>

// Условие: реализуйте FileHashMap<K, V> — хеш-таблицу, в которой ключи хранятся
// в оперативной памяти, а значения — на диске в одном файле. Тип V — trivially copyable.
//   - find и insert работают за O(1);
//   - поддерживается range-based for;
//   - значение можно прочитать и перезаписать по ключу: map[k] = new_value.

// TODO: implement
template <typename K, typename V>
class FileHashMap {};

int main() {
    FileHashMap<std::string, int> map(std::filesystem::temp_directory_path() / "file_hash_map.bin");

    map.insert("a", 1);
    map.insert("b", 2);
    map.insert("c", 3);

    assert(static_cast<int>(map["a"]) == 1);
    map["a"] = 42; // перезапись значения по ключу
    assert(static_cast<int>(map["a"]) == 42);

    map["d"] = 7;
    assert(map.contains("d"));
    assert(map.find("zzz") == map.end());

    long sum = 0;
    for (auto e : map) sum += static_cast<int>(e.value);
    assert(sum == 54);

    std::cout << "ok\n";
}
