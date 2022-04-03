#ifndef INTEGRAL_TESTS_INCLUDE_HXX
#define INTEGRAL_TESTS_INCLUDE_HXX
#include "integral_solver.hxx"
template<typename T = double>
constexpr bool are_equal(const T lhs, const T rhs, const T eps = 1e-7){
    return std::abs(lhs-rhs) < eps;
}
template<typename T = double>
void test(const IntegralSolver<T>& solver);

template<typename T = double>
void test(const IntegralSolver<T>& solver){
    constexpr T a1 = 0.0;
    constexpr T b1 = 1.0;
    const auto func1     = []     (const T x){return x                ;};
    const auto exact1    = [a1,b1](         ){return (b1*b1-a1*a1)/2.0;};
    const T    calc1 = solver.get_solution(func1,a1,b1);
    const T    real1 = exact1();
    assert(are_equal(calc1,real1));
    std::cout << "\tTest1+" << std::endl;
}
#endif // INTEGRAL_TESTS_INCLUDE_HXX
