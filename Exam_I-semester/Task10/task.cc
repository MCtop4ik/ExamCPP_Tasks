// След код должен компилироваться и работать без ошибок
// std запрещен
#include <assert.h>
int main() {

int i = 1;
for(auto* op : {make_increment<int>(), make_twice<int>()})
i = (*op)(i);

assert(i == 4);
}