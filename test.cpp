#include "tests.hxx"
#include "rectangle_rule.hxx"
#include "simpson_rule.hxx"
#include "trapezoid_rule.hxx"
int main(){
    using ArgT = double;
    using RetT = ArgT;
    using RecSolver = RectangleRule<ArgT,RetT>;
    using TrapSolver = TrapezoidRule<ArgT,RetT>;
    using SimpsSolver = SimpsonRule<ArgT,RetT>;

    std::vector<IntegralSolver<ArgT,RetT>*> solvers;

    RecSolver   rsolver;
    TrapSolver  tsolver;
    SimpsSolver ssolver;

    solvers.push_back(&rsolver);
    solvers.push_back(&tsolver);
    solvers.push_back(&ssolver);

    using integratedFunction = IntegralTest<ArgT,RetT>::integratedFunction;
    using exactSolution      = IntegralTest<ArgT,RetT>::exactSolution;

    const integratedFunction iF= []([[maybe_unused]]const ArgT& x)->RetT{
        return 1;
    };
    const exactSolution eS = [](const ArgT& a, const ArgT& b)->RetT{
        return b-a;
    };

    IntegralTest test1{iF,eS};
    for(const auto& solver : solvers){
      assert(test1(*solver,0,1));
    }

}
