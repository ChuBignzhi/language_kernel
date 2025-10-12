#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆
    for (int num : arr) {
        if (minHeap.size() < k) {
            minHeap.push(num); // 堆未满，直接插入
        } else if (num > minHeap.top()) {
            minHeap.pop(); // 替换堆顶元素
            minHeap.push(num);
        }
    }
    return minHeap.top(); // 返回堆顶元素
}