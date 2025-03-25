# 万能头文件

`#include<bits/stdc++.h>`  

# 常用算法

## 排序 查找

- `sort(first，last [，比较器])`  '
  - 使用快速排序对地址 $[\text{ first, last})$ 内的元素进行排序  
  - 默认为升序排序，传入比较器`greater<int>`为降序排序  
- `lower_bound(first, last, 目标值)`    
  - 返回 $[\text{ first, last})$ 中最后一个小于等于目标值的元素的迭代器  
- `upper_bound(first, last, 目标值)`   
  - 返回 $[\text{ first, last})$ 中第一个大于目标值的元素的迭代器  
  - lower_bound和upper_bound都仅应应用于 **升序排序** 的容器中  

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int target = 30;

    vector<int> vec1 = {10, 20, 30, 40, 50};
    auto lb1 = lower_bound(vec1.begin(), vec1.end(), target);
    // 此时lb指向30

    vector<int> vec2 = {10, 20, 40, 50};
    auto lb2 = lower_bound(vec2.begin(), vec2.end(), target);
    // 此时lb指向20

    vector<int> vec3 = {10, 20, 30, 40, 50};
    auto ub = upper_bound(vec3.begin(), vec3.end(), target);    
    // 此时ub指向40

    cout << "upper_bound for 30 in vec3 is at index: " << (ub - vec3.begin()) << endl;  // 值为3，即索引    
    // 使用 ub-vec.begin() 可以获得迭代器指向的元素的索引
}
```

- `reverse(first, last)`  
  - 反转 $[\text{ first, last})$ 内的元素顺序   
- `min(a, b)`，`min({1, 2, ..., n})`    
  - 取最小值，同理有`max`  
- `unique(first, last)`     
  - 将 $[\text{ first, last})$ 中 **相邻的重复元素** 移到容器末尾，并返回指向无重复部分下一位的迭代器  

```cpp
// unique结合erase消除结尾无效数据

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {10, 20, 20, 30, 40, 40, 50};

    // 1. 排序
    sort(vec.begin(), vec.end());

    // 2. 使用 unique，返回不重复部分的末尾
    auto it = unique(vec.begin(), vec.end());
    // 此时 vec = {10, 20, 30, 40, 50, 20, 40}
    // it 指向 20

    // 3. 使用 erase 删除多余的元素
    vec.erase(it, vec.end());  // 删除20，40

    // 打印结果
    for (int v : vec) {
        cout << v << " ";
    }
}
```

## DFS（回溯法）

DFS，深度优先搜索

模板

```cpp
int a[N];
bool used[N];

void dfs(int depth) {
  // 只有正确的解能到达第n+1层
  if(depth == n+1) { 
    for(int i = 1; i <= n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
    return;
  }

  // 遍历所有可能的选择
  for(int i = 1; i <= n; i++) {
    if(!used[i]) { // 排除不合法情况
      a[depth] = i; // 更新内容
      used[i] = true;
      dfs(depth + 1); // 递归
      used[i] = false; // 恢复状态，允许回溯
    }
  }
}

```