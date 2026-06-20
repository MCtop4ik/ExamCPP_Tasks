#include <type_traits>
#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <utility>
#include <cstddef>

template <typename T>
struct is_http_response {
    // TODO
};

struct GoodResponse {
    int code;
    std::string body;
    std::vector<std::string> headers;
};

struct GoodResponse2 {
    short code;
    const char* body;
    std::map<std::string, std::string> headers;
};

struct BadNoCode {
    std::string body;
    std::vector<std::string> headers;
};

struct BadCodeType {
    std::string code;
    std::string body;
    std::vector<std::string> headers;
};

struct BadBodyType {
    int code;
    int body;
    std::vector<std::string> headers;
};

struct BadNoHeaders {
    int code;
    std::string body;
};

int main() {
    static_assert(is_http_response<GoodResponse>::value);
    static_assert(is_http_response<GoodResponse2>::value);

    static_assert(!is_http_response<BadNoCode>::value);
    static_assert(!is_http_response<BadCodeType>::value);
    static_assert(!is_http_response<BadBodyType>::value);
    static_assert(!is_http_response<BadNoHeaders>::value);
}
