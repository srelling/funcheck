#include <type_traits>

#define DEF_FUNCHECK(call_name, func_name, func_sig) namespace funcheck { \
template<typename, typename T> \
struct func_name { \
    static_assert( \
        std::integral_constant<T, false>::value, \
        "Second template parameter needs to be of function type."); \
}; \
template<typename C, typename Ret, typename... Args> \
struct func_name <C, Ret(Args...)> { \
private: \
    template<typename T> \
    static constexpr auto check(T*) \
    -> typename \
        std::is_same< \
            decltype( std::declval<T>(). func_name ( std::declval<Args>()... ) ), \
            Ret \
        >::type; \
    template<typename> \
    static constexpr std::false_type check(...); \
    typedef decltype(check<C>(0)) type; \
public: \
    static constexpr bool value = type::value; \
}; \
template<typename C> \
bool call_name () { \
    struct Y : C {}; \
    return func_name < Y, func_sig >::value; \
} \
}

struct this_is_here_to_get_rid_of_a_warning{};