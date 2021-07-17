#ifndef EVERFLOW_ALGOS_SEARCH_SEQUENCE_SEARCH_H_
#define EVERFLOW_ALGOS_SEARCH_SEQUENCE_SEARCH_H_

namespace algos {

int SequenceSearch(std::vector<int> &inputs, int target) {
  for (int i = 0; i < inputs.size(); ++i) {
    if (inputs[i] == target) {
      return i;
    }
  }
  return -1;
}

}

#endif //EVERFLOW_ALGOS_SEARCH_SEQUENCE_SEARCH_H_
