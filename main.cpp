#include <iostream>
#include "rectangle_rule.hxx"
#include "trapezoid_rule.hxx"
int main(){
    constexpr double a = 0.0;
    constexpr double b = 1.0;

    const TrapezoidRule solver;

    auto f = [](const double x)
        constexpr noexcept -> double
    {
        return x;
    };
    double res = solver.get_solution(f,a,b);

    std::cout << res << std::endl;
}
