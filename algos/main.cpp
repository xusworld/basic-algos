#include <vector>

#include "binary_search_tree.h"
#include "algos/log.h"

using namespace algo;

int main() {

  algo::LOGF << "cool project.";

  auto inputs = std::vector<int>();
  inputs.push_back(2);
  inputs.push_back(1);
  inputs.push_back(3);

  BinarySearchTree<int> bst = algo::BinarySearchTree<int>();
  bst.BuildBST(inputs);

  getchar();
  return 0;
}

double division(int a, int b) {
  if (b == 0) {
    throw "Division by zero condition!";
  }
  return (a / b);
}

上面的代码会捕获一个类型为 ExceptionName 的异常。如果您想让 catch 块能够处理 try 块抛出的任何类型的异常，则必须在异常声明的括号内使用省略号 ...，如下所示:

try {
// 保护代码
}
catch(...) {
// 能处理任何异常的代码
}