
#include <string>
#include <vector>
using namespace std;
int main() {
  // 初始化
  vector<int> v1;
  vector<int> v2(v1);
  vector<int> v3(26);
  vector<int> v4(26, 1);
  vector<int> v5 = vector<int>(26, 3);
  vector<int> v6 = vector<int>();
  vector<int> v7 = {};

  // insert
  v2.insert(v2.begin(), v3.begin(), v3.begin() + 3);
  v2.insert();
  return 0;
}