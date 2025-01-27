#ifndef INTEGRAL_SOLVER_INCLUDE_HXX
#define INTEGRAL_SOLVER_INCLUDE_HXX

#include "basic_libs.hxx"

template<
    typename ArgT = double,
    typename RetT = double
    >
class IntegralSolver{
protected:
    using integratedFunc = std::function<RetT(const ArgT&)>;
    virtual RetT method_imp(const integratedFunc& func, const ArgT& a, const ArgT& b, const int n) const noexcept = 0;
    virtual RetT calc_integral(const integratedFunc& func, const ArgT& a, const ArgT& b, const RetT& eps) const noexcept{
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
    constexpr IntegralSolver() noexcept = default;

    constexpr IntegralSolver(const IntegralSolver<ArgT,RetT>&) noexcept = default;
    constexpr IntegralSolver(IntegralSolver<ArgT,RetT>&&) noexcept = default;

    virtual ~IntegralSolver() noexcept = default;

    constexpr IntegralSolver<ArgT,RetT>&
        operator=(const IntegralSolver<ArgT,RetT>&) noexcept = default;

    constexpr IntegralSolver<ArgT,RetT>&
        operator=(IntegralSolver<ArgT,RetT>&&) noexcept = default;

    virtual RetT get_solution(const integratedFunc& func, const ArgT& a, const ArgT& b, const RetT& eps = 1.0e-10) const noexcept {
        return this->calc_integral(func,a,b,eps);
    }
};
#endif //  INTEGRAL_SOLVER_INCLUDE_HXX
