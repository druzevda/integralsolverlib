#ifndef RECTANGLE_RULE_INCLUDE_HXX
#define RECTANGLE_RULE_INCLUDE_HXX

#include "integral_solver.hxx"
template<
    typename T = double
    >
class RectangleRule
    :IntegralSolver<T>
{
    T method_imp(const std::function<T(T)>& func, const T a, const T b, const int n) const final {
        const T delta = (b - a) / n;
        T res         = 0.0;
        for (int i = 0; i < n; ++i) {
            res += func(a + i * delta + delta / 2);
            // res += func(a + i * delta + delta );
            // res += func(a + i * delta );
        }
        return res * delta;
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
    constexpr RectangleRule() noexcept = default;

    constexpr RectangleRule(const RectangleRule<T>&) noexcept = default;
    constexpr RectangleRule(RectangleRule<T>&&) noexcept = default;

    virtual ~RectangleRule() noexcept = default;

    constexpr RectangleRule<T>&
        operator=(const RectangleRule<T>&) noexcept = default;

    constexpr RectangleRule<T>&
        operator=(RectangleRule<T>&&) noexcept = default;

    T get_solution(const std::function<T(T)>& func, const T a, const T b, const T eps = 1.0e-10) const {
        return this->calc_integral(func,a,b,eps);
    }
};
#endif // RECTANGLE_RULE_INCLUDE_HXX
