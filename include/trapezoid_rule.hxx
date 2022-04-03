#ifndef TRAPEZOID_RULE_INCLUDE_HXX
#define TRAPEZOID_RULE_INCLUDE_HXX

#include "integral_solver.hxx"
template<
    typename T = double
    >
class TrapezoidRule
    :IntegralSolver<T>
{
    T method_imp(const std::function<T(T)>& func, const T a, const T b, const int n) const final {
        const T delta = (b - a) / n;
        T res                = (func(a) + func(b)) / 2;
        for (int i = 1; i < n; ++i) {
            res += func(a + i * delta);
        }
        return res * delta;
    }
    T calc_integral(const std::function<T(T)>& func, const T a, const T b, const T eps) const final {
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
    constexpr TrapezoidRule() noexcept = default;

    constexpr TrapezoidRule(const TrapezoidRule<T>&) noexcept = default;
    constexpr TrapezoidRule(TrapezoidRule<T>&&) noexcept = default;

    virtual ~TrapezoidRule() noexcept = default;

    constexpr TrapezoidRule<T>&
        operator=(const TrapezoidRule<T>&) noexcept = default;

    constexpr TrapezoidRule<T>&
        operator=(TrapezoidRule<T>&&) noexcept = default;

    T get_solution(const std::function<T(T)>& func, const T a, const T b, const T eps = 1.0e-10) const {
        return this->calc_integral(func,a,b,eps);
    }
};
#endif // TRAPEZOID_RULE_INCLUDE_HXX
