#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol216;
using namespace std;

/*takeaways
  - refer to questions 39 and 40 for more information
 */

void Solution::_find(
    int start, int size, int target,
    vector<int> &combination, vector<vector<int>> &result)
{
  /* the size has to be k, and the sum has to be n */
  if ((int)combination.size() == size)
  {
    if (target == 0)
      result.push_back(combination);
    return;
  }

  for (auto picked = start; picked <= 9; picked++)
  {
    if (picked > target)
      break;

    combination.push_back(picked);
    /* start from picked + 1 as each number can only be used once
     */
    _find(picked + 1, size, target - picked, combination, result);
    combination.pop_back();
  }
}

vector<vector<int>> Solution::find(int k, int n)
{
  auto result = vector<vector<int>>();
  auto c = vector<int>();

  _find(1, k, n, c, result);

  return result;
}
