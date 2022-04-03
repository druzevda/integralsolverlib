#ifndef SIMPSON_RULE_INCLUDE_HXX
#define SIMPSON_RULE_INCLUDE_HXX

#include "integral_solver.hxx"
template<
    typename T = double
    >
class SimpsonRule
    :public IntegralSolver<T>
{
    T method_imp(const std::function<T(T)>& func, const T a, const T b, const int n) const final {
        const T delta = (b - a) / n;
        T res         = func(a) + func(b);
        for (int i = 1; i <= n - 1; ++i) {
            if (i % 2 == 0)
                res += 4.0 * func(a + i * delta);
            else
                res += 2.0 * func(a + i * delta);
        }
        return res * delta / 3.0;
    }
    T calc_integral(const std::function<T(T)>& func, const T a, const T b, const T eps) const {
        T resnp1 = 0.0;
        T resn   = 0.0;
        int n = 2;
        do {
            resn   = resnp1;
            resnp1 = this->method_imp(func,a,b,n);
            n *= 2;
        } while (std::abs(resn-resnp1) > eps);
        return resnp1;
    }
public:
    constexpr SimpsonRule() noexcept
        : IntegralSolver<T>()
        {}

    constexpr SimpsonRule(const SimpsonRule<T>&) noexcept = default;
    constexpr SimpsonRule(SimpsonRule<T>&&) noexcept = default;

    virtual ~SimpsonRule() noexcept = default;

    constexpr SimpsonRule<T>&
        operator=(const SimpsonRule<T>&) noexcept = default;

    constexpr SimpsonRule<T>&
        operator=(SimpsonRule<T>&&) noexcept = default;

    T get_solution(const std::function<T(T)>& func, const T a, const T b, const T eps = 1.0e-10) const {
        return this->calc_integral(func,a,b,eps);
    }
};
#endif // SIMPSON_RULE_INCLUDE_HXX
