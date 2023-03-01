# 计数类DP

## 整数划分



- [整数划分](https://www.acwing.com/activity/content/problem/content/1008/)



![整数划分](./picture/整数划分.png)



#### 思路：

##### 完全背包解法：

- 状态表示：f[i, j] 表示前 i 个整数（1,2…,i）恰好拼成 j 的方案数
  - 集合：1 ～ i 中，体积恰好是 j
  - 属性：数量

- 状态计算：类比完全背包



```c++
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N]; // 表示体积为 N 时，装入背包方案的数量

int main() {
    
    cin >> n;
    
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            f[j] = (f[j] + f[j - i]) % mod;
        }
    }
    
    cout << f[n] << endl;
    
    return 0;
}
```





##### 其他解法：

- 状态表示：f[i, j]
  - 集合：所有总和是 i，并且恰好表示成 j 个数的和
  - 属性：数量
- 状态计算：
  - 最小值是 1:f[i-1\][j-1]
  - 最小值大于 1:f[i-j\][j\] (因为每个数都是大于 1， 所以可以把每个数都减去 1，即i-j)



```c++
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N][N]; // 表示所有总和是i，并且恰好表示成 j 个数

int main() {
    
    cin >> n;
    
    f[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            f[i][j] = (f[i-1][j-1] + f[i-j][j]) % mod;
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = (res + f[n][i]) % mod;
    
    cout << res << endl;
    
    return 0;
}
```

