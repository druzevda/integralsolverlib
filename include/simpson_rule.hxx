#ifndef SIMPSON_RULE_INCLUDE_HXX
#define SIMPSON_RULE_INCLUDE_HXX

#include "integral_solver.hxx"
template<
    typename ArgT = double,
    typename RetT = double
    >
class SimpsonRule
    :public IntegralSolver<ArgT,RetT>
{
    using integratedFunc = typename IntegralSolver<ArgT,RetT>::integratedFunc;

    RetT method_imp(const integratedFunc& func, const ArgT& a, const ArgT& b, const int n) const noexcept override {
        const ArgT delta = (b - a) / n;

        RetT res         = func(a) + func(b);
        RetT resOdd = RetT{0.0};
        RetT resEven = RetT{0.0};

        for (int i = 1; i <= n - 1; ++i) {
            if (i % 2 == 0)
                resEven += func(a + i * delta);
            else
                resOdd += func(a + i * delta);
        }
        res += resOdd*4.0 + resEven*2.0;

        return res * delta / 3.0;
    }
public:
    constexpr SimpsonRule() noexcept
        : IntegralSolver<ArgT,RetT>()
        {}

    constexpr SimpsonRule(const SimpsonRule<ArgT,RetT>&) noexcept = default;
    constexpr SimpsonRule(SimpsonRule<ArgT,RetT>&&) noexcept = default;

    virtual ~SimpsonRule() noexcept = default;

    constexpr SimpsonRule<ArgT,RetT>&
        operator=(const SimpsonRule<ArgT,RetT>&) noexcept = default;

    constexpr SimpsonRule<ArgT,RetT>&
        operator=(SimpsonRule<ArgT,RetT>&&) noexcept = default;
};
#endif // SIMPSON_RULE_INCLUDE_HXX
