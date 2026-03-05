#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <utility>
#include <type_traits>

// =====================
// 1) Value categories demo helper
// =====================
int&  returns_lvalue_ref(int& x) { return x; }        // expression is an lvalue (because it's an lvalue ref)
int&& returns_rvalue_ref(int&& x) { return std::move(x); } // expression is an xvalue (because it's an rvalue ref)

// =====================
// 2) constexpr / consteval / constinit
// =====================
constexpr int cexpr_add(int a, int b) { return a + b; }

// consteval: MUST be evaluated at compile-time (no runtime calls allowed)
consteval int must_compile_time(int x) { return x * 2; }

// constinit: requires static storage object is initialized at compile time.
// (It does NOT make it const.)
constinit int g_counter = 42;

// =====================
// 3) Inline variable (C++17)
// In real projects, this is typically in a header.
// =====================
inline constexpr std::string_view kAppName = "ValueCatsDemo";

// =====================
// 4) enum class
// =====================
enum class Color : int { Red = 1, Green = 2, Blue = 3 };

// =====================
// 5) attributes
// =====================
[[nodiscard]] int compute_important(int x) {
    return x * x;
}

[[maybe_unused]] static void debug_only() {
    // Intentionally empty: used in debug builds, etc.
}

// [[likely]] / [[unlikely]] is a hint to the compiler about branch probability
int classify(int x) {
    if (x >= 0) [[likely]] {
        return 1;
    } else [[unlikely]] {
        return -1;
    }
}

// =====================
// 6) using vs typedef
// =====================
using IntVec = std::vector<int>;      // modern alias
typedef std::vector<int> IntVec2;     // old style alias

// A key advantage of 'using': alias templates (typedef cannot do this)
template <typename T>
using Vec = std::vector<T>;

// =====================
// 7) decltype / decltype(auto)
// =====================
int g = 100;

int& global_ref() { return g; } // returns an lvalue reference

decltype(auto) forward_like_auto_return(bool want_ref) {
    if (want_ref) {
        // returning an lvalue reference expression -> decltype(auto) deduces int&
        return global_ref();
    } else {
        // returning a prvalue (temporary) -> decltype(auto) deduces int
        return 123;
    }
}

// =====================
// 8) Uniform initialization + structured bindings
// =====================
struct Point {
    int x;
    int y;

    // constexpr constructor
    constexpr Point(int ax, int ay) : x(ax), y(ay) {}
};

std::pair<int, std::string> make_pair_demo() {
    return {7, "seven"};
}

// =====================
// 9) nullptr
// std::nullptr_t 
// =====================
void f(int) { std::cout << "f(int)\n"; }
void f(void*) { std::cout << "f(void*)\n"; }

int main() {
    std::cout << "App: " << kAppName << "\n\n";

    // ------------------------------------------------------------
    // 1) Value categories: lvalue, rvalue, xvalue, prvalue
    // ------------------------------------------------------------
    int a = 10;

    // lvalue: has identity (named object), can appear on left of '='
    int& lref = a; // ok

    // prvalue: pure rvalue (temporary value like literal 5, or a+b)
    int pr = a + 5; // (a+5) is prvalue; it materializes into pr

    // xvalue: "expiring value" (typically a moved-from object or rvalue ref expression)
    int&& rref = 20;             // 20 is prvalue, binds to rvalue ref
    int&& xref = std::move(a);   // std::move(a) is an xvalue expression

    (void)lref; (void)pr; (void)rref; (void)xref;

    // ------------------------------------------------------------
    // 2) auto type deduction
    // ------------------------------------------------------------
    int x = 1;
    const int cx = 2;
    int& rx = x;

    auto v1 = x;      // int
    auto v2 = cx;     // int  (top-level const dropped)
    auto v3 = rx;     // int  (reference dropped)
    const auto v4 = cx; // const int

    auto& r1 = x;     // int&
    auto& r2 = cx;    // const int& (because binding to const)
    auto& r3 = rx;    // int&

    auto&& u1 = x;       // int&  (universal/forwarding ref binds to lvalue -> lvalue ref)
    auto&& u2 = 99;      // int&& (binds to rvalue -> rvalue ref)

    (void)v1; (void)v2; (void)v3; (void)v4;
    (void)r1; (void)r2; (void)r3;
    (void)u1; (void)u2;

    // ------------------------------------------------------------
    // 3) decltype and decltype(auto)
    // ------------------------------------------------------------
    // decltype(expr):
    // - if expr is an lvalue of type T -> decltype(expr) is T&
    // - if expr is an xvalue of type T -> decltype(expr) is T&&
    // - if expr is a prvalue of type T -> decltype(expr) is T
    decltype(x) d1 = 5;    // decltype(x) where x is a variable -> int
    decltype((x)) d2 = x;  // decltype((x)) where (x) is an lvalue expr -> int&

    d2 = 123; // modifies x through reference

    // decltype(auto): deduces *exactly like decltype* on the returned expression
    auto val_or_ref1 = forward_like_auto_return(false); // returns int
    auto val_or_ref2 = forward_like_auto_return(true);  // BUT auto here copies, so this becomes int

    decltype(auto) exact1 = forward_like_auto_return(false); // int
    decltype(auto) exact2 = forward_like_auto_return(true);  // int&

    exact2 = 999; // modifies global g
    std::cout << "global g after exact2 assignment: " << g << "\n\n";

    (void)d1; (void)val_or_ref1; (void)val_or_ref2; (void)exact1;

    // ------------------------------------------------------------
    // 4) Uniform initialization {} vs ()
    // ------------------------------------------------------------
    int n1(5);    // direct initialization
    int n2{5};    // list initialization

    // Braces prevent narrowing:
    // int bad{3.14}; // ERROR: narrowing
    int ok = 3.14; // allowed (but truncates)

    std::vector<int> vec1(3, 9); // 3 elements, each 9
    std::vector<int> vec2{3, 9}; // elements are [3, 9]

    std::cout << "vec1 size=" << vec1.size() << " (constructed as (3,9))\n";
    std::cout << "vec2 size=" << vec2.size() << " (constructed as {3,9})\n\n";

    // ------------------------------------------------------------
    // 5) Structured bindings (C++17)
    // ------------------------------------------------------------
    auto [num, word] = make_pair_demo(); // copies out
    std::cout << "structured binding: num=" << num << ", word=" << word << "\n";

    Point p{10, 20};
    auto [px, py] = p; // copies p.x and p.y
    std::cout << "Point copy binding: px=" << px << ", py=" << py << "\n";

    auto& [rxp, ryp] = p; // references p.x and p.y
    rxp = 111;
    std::cout << "Point ref binding changed p.x -> " << p.x << "\n\n";

    // ------------------------------------------------------------
    // 6) constexpr (variables, functions, constructors)
    // ------------------------------------------------------------
    constexpr int c1 = 10;
    constexpr int c2 = cexpr_add(c1, 5); // compile-time
    constexpr Point cp{1, 2};            // constexpr ctor
    std::cout << "constexpr computed c2=" << c2 << ", cp=(" << cp.x << "," << cp.y << ")\n\n";

    // ------------------------------------------------------------
    // 7) consteval, constinit (C++20)
    // ------------------------------------------------------------
    constexpr int forced = must_compile_time(21); // OK: compile-time
    std::cout << "consteval forced=" << forced << "\n";
    std::cout << "constinit g_counter initial=" << g_counter << "\n\n";

    // ------------------------------------------------------------
    // 8) Inline variables (already used kAppName)
    // ------------------------------------------------------------

    // ------------------------------------------------------------
    // 9) enum class
    // ------------------------------------------------------------
    Color c = Color::Green;
    // int ci = c; // ERROR: no implicit conversion
    int ci = static_cast<int>(c); // explicit conversion
    std::cout << "enum class Color::Green as int=" << ci << "\n\n";

    // ------------------------------------------------------------
    // 10) Attributes: [[nodiscard]], [[maybe_unused]], [[likely]]
    // ------------------------------------------------------------
    (void)classify(-5);

    // If you compile with warnings, ignoring this may warn because of [[nodiscard]]:
    // compute_important(10);
    int important = compute_important(10);
    std::cout << "compute_important(10)=" << important << "\n\n";

    // ------------------------------------------------------------
    // 11) nullptr
    // ------------------------------------------------------------
    // nullptr is its own type (std::nullptr_t) and chooses pointer overload safely
    f(nullptr); // calls f(void*)
    // f(0);     // calls f(int) - ambiguous in intent
    // f(NULL);  // can be int on some platforms -> risky
    std::cout << "\n";

    // ------------------------------------------------------------
    // 12) Range-based for
    // ------------------------------------------------------------
    IntVec data{1, 2, 3};
    for (int& e : data) { // by reference to modify
        e *= 10;
    }
    for (const int e : data) { // by value (copy)
        std::cout << e << " ";
    }
    std::cout << "\n\n";

    // ------------------------------------------------------------
    // 13) using vs typedef (shown at top)
    // ------------------------------------------------------------
    Vec<std::string> names{"Ada", "Bjarne"};
    std::cout << "Vec<string> names[0]=" << names[0] << "\n";

    return 0;
}