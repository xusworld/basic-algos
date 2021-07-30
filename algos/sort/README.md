

## 排序算法总结



|     排序算法    | 平均时间复杂度 | 最好时间复杂度    | 最坏时间复杂度      | 辅助空间      |    稳定性   |
| ------------   |    ---       | -------------- | ---------------- |------------- | ---------- |
|     冒泡排序    |  O(n^2)      |  O(n^2)         |    O(n^2)       | O(1)          |   稳定     |
|     选择排序    |  O(n^2)      |  O(n^2)         |    O(n^2)       | O(1)          |   不稳定    | 
|     插入排序    |  O(n^2)      |  O(n^2)         |    O(n^2)       | O(1)          |   稳定       | 
|     归并排序    |  O(nlogn)    |  O(nlog(n))     |  O(nlog(n))     | O(n)          |   稳定       | 
|     快速排序    |  O(nlogn)    |  O(nlog(n))     |    O(n^2)       | O(nlogn)      |   不稳定     | 
|     堆排序      |  O(nlogn)    | O(nlog(n))      |  O(nlog(n))     | O(1)          |   不稳定     | 
|     希尔排序    |  O(nlogn)    |  O(n(log(n))^2) |  O(n(log(n))^2) | O(1)          |   不稳定     | 
|     计数排序    |  O(n + k)    |  O(n + k)       |   O(n + k)      | O(n + k)      |   稳定       | 
|     桶排序      |  O(n + k)    |  O(n + k)       | O(n + k)        | O(n + k)      |   稳定       | 
|     基数排序    |  O(nk)      |   O(nk)          |    O(nk)        | O(n + k)      |   稳定       | 


# 1 冒泡排序

冒泡排序（英语：Bubble Sort）又称为泡式排序，是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，
如果他们的顺序错误就把他们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。
这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。


冒泡排序对n个项目需要O(n^2)的比较次数，且可以原地排序。尽管这个算法是最简单了解和实现的排序算法之一，但它对于包含大量
的元素的数列排序是很没有效率的。


冒泡排序算法的运作如下：

1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
3. 针对所有的元素重复以上的步骤，除了最后一个。
4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。


```c++

void BubbleSort(std::vector<int> &inputs) {
  int N = inputs.size();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N - 1 - i; ++j) {
      if (inputs[j] > inputs[j + 1]) {
        std::swap(inputs[j], inputs[j + 1]);
      }
    }
  }
}
```

# 2 选择排序

选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理如下。首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，
再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。

选择排序的主要优点与数据移动有关。如果某个元素位于正确的最终位置上，则它不会被移动。选择排序每次交换一对元素，它们当中至少有一个将被移到其最终
位置上，因此对n个元素的表进行排序总共进行至多 (n-1)次交换。在所有的完全依靠交换去移动元素的排序方法中，选择排序属于非常好的一种。

```c++
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
```


# 3 插入排序

插入排序（英语：Insertion Sort）是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，
找到相应位置并插入。插入排序在实现上，通常采用in-place排序（即只需用到O(1)的额外空间的排序）
，因而在从后向前扫描过程中，需要反复把已排序元素逐步向后挪位，为最新元素提供插入空间。

```c++
void InsertionSort(std::vector<int> &inputs) {
  for (int i = 1; i < inputs.size(); ++i) {
    int key = inputs[i];

    // 将 inputs[i] 插入已经排序的 inputs[0 ... i-1] 序列中
    int j = i - 1;
    // 在已经排序的元素序列中从后向前扫描
    while (j >= 0 && inputs[j] > key) {
      // 如果该元素大于新元素，将该元素移动到下一位置
      inputs[j + 1] = inputs[j];
      j--;
    }

    // 插入新元素
    inputs[j + 1] = key;
  }
}
```

# 4 归并排序

归并排序（英语：Merge sort，或mergesort），是创建在归并操作上的一种有效的排序算法，
效率为 O(nlog(n))。1945年由约翰·冯·诺伊曼首次提出。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用，且各层分治递归可以同时进行。

采用分治法:

分割：递归地把当前序列平均分割成两半。
集成：在保持元素顺序的同时将上一步得到的子序列集成到一起（归并）。

## 归并操作
归并操作（merge），也叫归并算法，指的是将两个已经排序的序列合并成一个序列的操作。归并排序算法依赖归并操作。

### 递归法（Top-down）
1. 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
2. 设定两个指针，最初位置分别为两个已经排序序列的起始位置
3. 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
4. 重复步骤3直到某一指针到达序列尾
5. 将另一序列剩下的所有元素直接复制到合并序列尾


### 迭代法（Bottom-up）
原理如下（假设序列共有n个元素）：

1. 将序列每相邻两个数字进行归并操作，形成 ceil(n/2)个序列，排序后每个序列包含两/一个元素
2. 若此时序列数不是1个则将上述序列再次归并，形成 ceil(n/4) 个序列，每个序列包含四/三个元素
3. 重复步骤2，直到所有元素排序完毕，即序列数为1


```c++
void Merge(std::vector<int> &inputs, int front, int mid, int end) {
  // 切分左右子数组
  std::vector<int> left(inputs.begin() + front, inputs.begin() + mid + 1);
  std::vector<int> right(inputs.begin() + mid + 1, inputs.begin() + end + 1);
  // 合并两个有序数组
  int lidx = 0;
  int ridx = 0;
  // 插入"哨兵"
  left.insert(left.end(), 2147483647);
  right.insert(right.end(), 2147483647);
  for (int i = front; i <= end; ++i) {
    if (left[lidx] < right[ridx]) {
      inputs[i] = left[lidx++];
    } else {
      inputs[i] = right[ridx++];
    }
  }
}

void MergeSort(std::vector<int> &inputs, int front, int end) {
  if (front >= end)
    return;

  int mid = front + (end - front) / 2;
  MergeSort(inputs, front, mid);
  MergeSort(inputs, mid + 1, end);
  Merge(inputs, front, mid, end);
}

```

# 5 快速排序
快速排序（英语：Quicksort），又称分区交换排序（partition-exchange sort），简称快排，一种排序算法，最早由东尼·霍尔提出。
在平均状况下，排序 n 个项目要 O(nlog n)次比较。在最坏状况下则需要 O(n^2)次比较，但这种状况并不常见。

快速排序使用分治法（Divide and conquer）策略来把一个序列（list）分为较小和较大的2个子序列，然后递归地排序两个子序列。

步骤为：

1. 挑选基准值：从数列中挑出一个元素，称为“基准”（pivot），
2. 分割：重新排序数列，所有比基准值小的元素摆放在基准前面，所有比基准值大的元素摆在基准后面（与基准值相等的数可以到任何一边）。在这个分割结束之后，对基准值的排序就已经完成，
3. 递归排序子序列：递归地将小于基准值元素的子序列和大于基准值元素的子序列排序。
递归到最底部的判断条件是数列的大小是零或一，此时该数列显然已经有序。

选取基准值有数种具体方法，此选取方法对排序的时间性能有决定性影响。


```c++

int Partition(std::vector<int> &inputs, int first, int last) {
  // 使用第一个元素作为 主元 (pivot element)
  int key = inputs[first];

  int begin = first;
  int end = last;
  while (begin < end) {
    while (begin < end && inputs[end] > key) {
      end--;
    }

    while (begin < end && inputs[begin] < key) {
      begin++;
    }

    if (begin < end)
      std::swap(inputs[begin], inputs[end]);

  }

  inputs[first] = inputs[begin];
  inputs[begin] = key;
  return begin;
}

void QuickSort(std::vector<int> inputs, int first, int last) {
  if (first < last) {
    int pivot = Partition(inputs, first, last);
    QuickSort(inputs, first, pivot);
    QuickSort(inputs, pivot + 1, last);
  }
}

```


# 6 堆排序

# 7 希尔排序

# 8 计数排序

# 9 桶排序

# 10 基数排序