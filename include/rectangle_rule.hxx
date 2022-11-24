#ifndef RECTANGLE_RULE_INCLUDE_HXX
#define RECTANGLE_RULE_INCLUDE_HXX

#include "integral_solver.hxx"
template<
    typename ArgT = double,
    typename RetT = double
    >
class RectangleRule
    : public IntegralSolver<ArgT,RetT>
{
    using integratedFunc = typename IntegralSolver<ArgT,RetT>::integratedFunc;

    RetT method_imp(const integratedFunc& func, const ArgT& a, const ArgT& b, const int n) const override {
        const ArgT& delta = (b - a) / n;
        RetT res         = RetT{0};
        for (int i = 0; i < n; ++i) {
            res += func(a + i * delta + delta / 2);
            // res += func(a + i * delta + delta );
            // res += func(a + i * delta );
        }
        return res * delta;
    }
    RetT calc_integral(const integratedFunc& func, const ArgT& a, const ArgT& b, const RetT& eps) const override{
        RetT resnp1 = 0.0;
        RetT resn   = 0.0;
        int n = 2;
        do {
          resn   = resnp1;
          resnp1 = this->method_imp(func,a,b,n);
          n *= 2;
        } while (std::abs(resn-resnp1) > eps);
        return resnp1;
    }
public:
    constexpr RectangleRule()
        :IntegralSolver<ArgT,RetT>()
    {}

    constexpr RectangleRule(const RectangleRule<ArgT,RetT>&) noexcept = default;
    constexpr RectangleRule(RectangleRule<ArgT,RetT>&&) noexcept = default;

    virtual ~RectangleRule() noexcept = default;

    constexpr RectangleRule<ArgT,RetT>&
        operator=(const RectangleRule<ArgT,RetT>&) noexcept = default;

    constexpr RectangleRule<ArgT,RetT>&
        operator=(RectangleRule<ArgT,RetT>&&) noexcept = default;

    RetT get_solution(const integratedFunc& func, const ArgT& a, const ArgT& b, const RetT& eps = 1.0e-10) const {
        return this->calc_integral(func,a,b,eps);
    }
};
#endif // RECTANGLE_RULE_INCLUDE_HXX
