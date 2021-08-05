<!--
 * @Date: 2021-06-30 16:59:26
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-05 14:34:03
-->

# ch2 贪心算法 Greedy Algorithm

## 1. 算法解释

**全局最优解** = *局部最优解* + *局部最优解* + *局部最优解* + ...

全局最优解为局部最优解的线性表示，且局部最优解结果互不相干。

## 2. 分配问题

### 455. Assign Cookies(Easy)

### 135. Candy(hard)

#### description:
一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
有孩子至少要有一个糖果。求解最少需要多少个糖果。

#### solution:
虽然这也是一道贪心策略的题目，但我们只需要前后遍历两次数组即可得到最优解，因为只考虑相邻条件是否成立即可。

```cc
  int CandyBestSolu(std::vector<int> &ratings)
  {
    vector<int> cnt(ratings.size(), 1);
    int res = 0;
    for (size_t i = 0; i < ratings.size() - 1; ++i)
    {
      if (ratings[i] < ratings[i + 1]) {
        cnt[i + 1] = cnt[i] + 1;
      }
    }
    for (size_t i = ratings.size() - 1; i > 0; --i)
    {
      if (ratings[i - 1] > ratings[i] && cnt[i - 1] <= cnt[i]) {
        cnt[i - 1] = cnt[i] + 1;
      }
    }
    for(auto cand: cnt) {
      res += cand;
    }
    return res;
  }
```


### 435. Non-overlapping Internals(Medium)

#### description:
给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。

#### input/output:
输入是一个数组，数组由多个长度固定为 2 的数组组成，表示区间的开始和结尾。输出一个
整数，表示需要移除的区间数量。

> Input: [[1,2], [2,4], [1,3]]
> Output: 1

在这个样例中，我们可以移除区间 [1,3]，使得剩余的区间 [[1,2], [2,4]] 互不重叠。

#### Solutions:
只需要对区间末尾进行排序，如果区间末尾足够小则可以保留，反正如果在会发生重叠的情况下，区间末大于前者则可以移除

```cc
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  if (intervals.empty()) {
    return 0;
  }
  int n = intervals.size();
  sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
    {
    return a[1] < b[1];
    });
  int removed = 0, prev = intervals[0][1];
  for (int i = 1; i < n; ++i) {
    if (intervals[i][0] < prev) {
      ++removed;
    } else {
      prev = intervals[i][1];
    }
  }
  return removed;
}
```


### 练习场--基础版

#### 605. Can Place Flowers(Easy)

采取什么样的贪心策略，可以种植最多的花朵呢？

假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给你一个整数数组  flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false。

#### input/output

示例 1：

输入：flowerbed = [1,0,0,0,1], n = 1
输出：true
示例 2：

输入：flowerbed = [1,0,0,0,1], n = 2
输出：false

#### Solutions

```cc
public boolean canPlaceFlowers(int[] flowerbed, int n) {
    int count = 0;
    int m = flowerbed.length;
    int prev = -1;
    for (int i = 0; i < m; i++) {
        if (flowerbed[i] == 1) {
            if (prev < 0) {
                count += i / 2;
            } else {
                count += (i - prev - 2) / 2;
            }
            if (count >= n) {
                return true;
            }
            prev = i;
        }
    }
    if (prev < 0) {
        count += (m + 1) / 2;
    } else {
        count += (m - prev - 1) / 2;
    }
    return count >= n;
}
```

#### 452. 用最少的箭引爆气球

#### description:
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。

一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。

#### input/output:

示例 1：

输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球
示例 2：

输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4
示例 3：

输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2
示例 4：

输入：points = [[1,2]]
输出：1
示例 5：

输入：points = [[2,3],[2,3]]
输出：1

提示：

1 <= points.length <= 104
points[i].length == 2
-2^31 <= x_start < x_end <= 2^31 - 1

#### Solutions:

```cc
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
        });
        int pos = points[0][1];
        int ans = 1;
        for (const vector<int>& balloon: points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++ans;
            }
        }
        return ans;
    }
};
```

#### 763. 划分字母区间

#### 122. 买卖股票的最佳时机 II

```cc
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int earn = 0, own = prices[0], prev = own;
        // stack<int> s;
        // s.push(own);
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] >= prev) {
                prev = prices[i];
            } else {
                earn += prev - own;
                own = prices[i];
                prev = own;
            }
        }
        earn += prev - own;
        return earn;
    }
};
```

#### 406. 根据身高重建队列 medium ✔️

假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等
于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中
 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。


示例 1：

输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
解释：
编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。

示例 2：

输入：people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
输出：[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]


提示：

1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
题目数据确保队列可以被重建


#### Solutions:
先排序，后插队。

#### 665. 非递减数列 ✔️

给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。



示例 1:

输入: nums = [4,2,3]
输出: true
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
示例 2:

输入: nums = [4,2,1]
输出: false
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
 

提示：

1 <= n <= 10 ^ 4
- 10 ^ 5 <= nums[i] <= 10 ^ 5

#### Solutions:

```cpp
bool checkPossibility(vector<int>& nums) {
    if (nums.size() <= 2) {
      return true;
    }
    int flag = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] > nums[i]) {
        if ((i + 1 >= nums.size() || nums[i + 1] >= nums[i - 1]) ||
            i < 2 || nums[i - 2] <= nums[i]) {
          flag++;
        } else {
          return false;
        }
      }
      if (flag > 1) {
          return false;
      }
    }
    return true;
}
```

