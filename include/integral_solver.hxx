#ifndef INTEGRAL_SOLVER_INCLUDE_HXX
#define INTEGRAL_SOLVER_INCLUDE_HXX

#include "basic_libs.hxx"

template<
    typename T = double
    >
class IntegralSolver{
protected:
    virtual T method_imp(const std::function<T(T)>& func, const T a, const T b, const int n) const = 0;
    virtual T calc_integral(const std::function<T(T)>& func, const T a, const T b, const T eps) const = 0;
public:
    constexpr IntegralSolver() noexcept = default;

    constexpr IntegralSolver(const IntegralSolver<T>&) noexcept = default;
    constexpr IntegralSolver(IntegralSolver<T>&&) noexcept = default;

    virtual ~IntegralSolver() noexcept = default;

    constexpr IntegralSolver<T>&
        operator=(const IntegralSolver<T>&) noexcept = default;

    constexpr IntegralSolver<T>&
        operator=(IntegralSolver<T>&&) noexcept = default;

    virtual T get_solution(const std::function<T(T)>& func, const T a, const T b, const T eps = 1.0e-10) const {
        return this->calc_integral(func,a,b,eps);
    }
};
#endif //  INTEGRAL_SOLVER_INCLUDE_HXX
