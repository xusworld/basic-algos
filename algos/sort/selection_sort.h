#ifndef EVERFLOW_ALGOS_SORT_SELECTION_SORT_H_
#define EVERFLOW_ALGOS_SORT_SELECTION_SORT_H_

namespace algos {

// 维基百科上给出的实现，非常简单
void selection_sort(int a[], int len) {
  int i, j, temp;

  for (i = 0; i < len - 1; i++) {
    int min = i;
    for (j = i + 1; j < len; j++)     //走訪未排序的元素
    {
      if (a[j] < a[min])    //找到目前最小值
      {
        min = j;    //紀錄最小值
      }
    }
    if (min != i) {
      temp = a[min];  //交換兩個變數
      a[min] = a[i];
      a[i] = temp;
    }
    /* swap(&a[min], &a[i]);  */   //做交換
  }
}

/*
void swap(int *a,int *b) //交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/



}

#endif //EVERFLOW_ALGOS_SORT_SELECTION_SORT_H_
