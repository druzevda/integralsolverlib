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

    RetT method_imp(const integratedFunc& func, const ArgT& a, const ArgT& b, const int n) const noexcept override {
        const ArgT& delta = (b - a) / n;
        RetT res         = RetT{0};
        for (int i = 0; i < n; ++i) {
            res += func(a + i * delta + delta / 2);
            // res += func(a + i * delta + delta );
            // res += func(a + i * delta );
        }
        return res * delta;
    }
public:
    constexpr RectangleRule() noexcept
        :IntegralSolver<ArgT,RetT>()
    {}

    constexpr RectangleRule(const RectangleRule<ArgT,RetT>&) noexcept = default;
    constexpr RectangleRule(RectangleRule<ArgT,RetT>&&) noexcept = default;

    virtual ~RectangleRule() noexcept = default;

    constexpr RectangleRule<ArgT,RetT>&
        operator=(const RectangleRule<ArgT,RetT>&) noexcept = default;

    constexpr RectangleRule<ArgT,RetT>&
        operator=(RectangleRule<ArgT,RetT>&&) noexcept = default;
};
#endif // RECTANGLE_RULE_INCLUDE_HXX
