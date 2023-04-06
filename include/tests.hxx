#ifndef INTEGRAL_TESTS_INCLUDE_HXX
#define INTEGRAL_TESTS_INCLUDE_HXX
#include "integral_solver.hxx"
template<typename T = double>
constexpr bool are_equal(const T lhs, const T rhs, const T eps = 1e-7){
    return std::abs(lhs-rhs) < eps;
}

template<
    typename ArgT = double,
    typename RetT = double
    >
class IntegralTest{
  using integratedFunction = std::function<RetT(ArgT)>;
  using exactSolution      = std::function<RetT(ArgT,ArgT)>;
  const integratedFunction integrFunct;
  const exactSolution      exSolution;

  public:
  IntegralTest(const integratedFunction& iF, const exactSolution& eS)
    :integrFunct{iF}
    ,exSolution{eS}
    {}

  bool operator()(const IntegralSolver<ArgT,RetT>& solver, const ArgT& left, const ArgT& right){
    const RetT calced = solver.get_solution(integrFunct,left,right);
    const RetT exact = exSolution(left,right);
    return are_equal(calced,exact);
  }

  IntegralTest()=delete;
  IntegralTest(const IntegralTest&)=delete;
  IntegralTest(IntegralTest&&)=delete;
  IntegralTest& operator=(const IntegralTest&)=delete;
  IntegralTest& operator=(IntegralTest&&)=delete;
};
#endif // INTEGRAL_TESTS_INCLUDE_HXX
