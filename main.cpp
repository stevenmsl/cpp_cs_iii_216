#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol216;

/*
Input: k = 3, n = 7
Output: [[1,2,4]]
*/

tuple<int, int, vector<vector<int>>>
testFixture1()
{

  auto output = vector<vector<int>>{
      {1, 2, 4}};
  return make_tuple(3, 7, output);
}

/*
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

tuple<int, int, vector<vector<int>>>
testFixture2()
{

  auto output = vector<vector<int>>{
      {1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
  return make_tuple(3, 9, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.find(get<0>(f), get<1>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.find(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}