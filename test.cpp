#include "tests.hxx"
#include "rectangle_rule.hxx"
#include "simpson_rule.hxx"
#include "trapezoid_rule.hxx"
int main(){
    using Arg = double;
    using RecSolver = RectangleRule<Arg>;
    using TrapSolver = TrapezoidRule<Arg>;
    using SimpsSolver = SimpsonRule<Arg>;

    RecSolver   rsolver;
    TrapSolver  tsolver;
    SimpsSolver ssolver;

    std::cout << "Rectangle rule:" << std::endl;
    test(rsolver);
    std::cout << "Simpson rule:" << std::endl;
    test(ssolver);
    std::cout << "Trapezoid rule:" << std::endl;
    test(tsolver);
}
