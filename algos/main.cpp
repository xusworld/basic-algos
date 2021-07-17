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
