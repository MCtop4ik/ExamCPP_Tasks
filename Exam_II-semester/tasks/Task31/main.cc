#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
    std::set<int> a1{5, 7, 8};
    std::map<std::string, int> a2{{"1", 7}, {"2", 5}, {"3", 3}};
    std::vector<int> a3{9, 9, 8, 9, 7};

    SuperSet super_set = makeSuperSet(a1, a2, a3);

    for (auto&& item : super_set) {
        std::cout << item;
    }
    std::cout << endl;
}

/*output:
5, 7, 8, {1, 7}, {2, 5}, {3, 3}, 9, 9, 8, 9, 7
*/