#ifndef EVERFLOW_ALGOS_SEARCH_BLOCK_H_
#define EVERFLOW_ALGOS_SEARCH_BLOCK_H_

namespace algos {

// https://zhuanlan.zhihu.com/p/113651370
struct BlockInfo {
  int key;
  // 块的起始和结束为止
  int start;
  int end;
};

int search(BlockInfo *blocks, int targetKey, int *data, int numBlocks) {
  // 1、使用顺序查找确定targetKey所处的block
  int desiredBlockPosition = 0;
  int ifSuccess = 0;

  for (; desiredBlockPosition < numBlocks; desiredBlockPosition++) {
    // 由于数据是按照升序排列的
    // 所以当targetKey小于当前块最大值时查找成功
    if (targetKey <= blocks[desiredBlockPosition].key) {
      ifSuccess = 1;
      break;
    }
  }
  // 目标关键字大于所有block的最大值，所以查找失败
  if (ifSuccess == 0) {
    cout << "Failed to search block" << endl;
    return -1;
  }

  // 继续判断是否会在块内部查找成功
  ifSuccess = 0;
  // 2、在desiredBlockPosition中查找目标值位置
  for (int i = blocks[desiredBlockPosition].start;
       i <= blocks[desiredBlockPosition].end;
       i++) {
    if (data[i] == targetKey) {
      cout << "Target Key " << targetKey << "'s position is: " << i
           <<", and belong block: "<<desiredBlockPosition<<endl;
      cout << "check " << targetKey << " equal " << data[i] << endl;
      ifSuccess = 1;
      return i;
    }
  }
  // 在第一步确定的block中没有找到目标关键字
  // 说明查找失败
  if (ifSuccess == 0) {
    cout << "Search failed inside block" << endl;
    return -1;
  }
}


} // namespace algos


#endif //EVERFLOW_ALGOS_SEARCH_BLOCK_H_
