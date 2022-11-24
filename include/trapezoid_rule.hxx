#ifndef TRAPEZOID_RULE_INCLUDE_HXX
#define TRAPEZOID_RULE_INCLUDE_HXX

#include "integral_solver.hxx"
template<
    typename ArgT = double,
    typename RetT = double
    >
class TrapezoidRule
    :public IntegralSolver<ArgT,RetT>
{
    using integratedFunc = typename IntegralSolver<ArgT,RetT>::integratedFunc;

    RetT method_imp(const integratedFunc& func, const ArgT& a, const ArgT& b, const int n) const noexcept final {
        const ArgT delta = (b - a) / n;
        RetT res                = (func(a) + func(b)) / 2;
        for (int i = 1; i < n; ++i) {
            res += func(a + i * delta);
        }
        return res * delta;
    }
public:
    constexpr TrapezoidRule() noexcept
        : IntegralSolver<ArgT,RetT>()
        {}

    constexpr TrapezoidRule(const TrapezoidRule<ArgT,RetT>&) noexcept = default;
    constexpr TrapezoidRule(TrapezoidRule<ArgT,RetT>&&) noexcept = default;

    virtual ~TrapezoidRule() noexcept = default;

    constexpr TrapezoidRule<ArgT,RetT>&
        operator=(const TrapezoidRule<ArgT,RetT>&) noexcept = default;

    constexpr TrapezoidRule<ArgT,RetT>&
        operator=(TrapezoidRule<ArgT,RetT>&&) noexcept = default;
};
#endif // TRAPEZOID_RULE_INCLUDE_HXX
