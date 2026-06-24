# 0001. Two Sum

- **LeetCode Link:** [Two Sum](https://leetcode.com/problems/two-sum/)
- **Difficulty:** Easy
- **Tags:** #Array #Hash-Table #Cpp
- **Date Processed:** 2026-06-23

---

## 1. WHY: Why address and optimize this problem?
> Understand the current constraints and acknowledge the challenge and urgency objectively.

* **Current State Analysis:** Under the constraint $2 \le \text{nums.length} \le 10^4$, a naive nested-loop approach triggers up to $10^8$ operations in the worst-case scenario. This introduces a high risk of systemic latency spikes as data scales, demanding immediate optimization.
* **Core Objective:** Identify the exact indices of two numbers that sum up to a specific `target` within the given array, ensuring zero duplicate reuse, in the shortest time possible.

---

## 2. WHAT: What is the core solution principle and design?
> Define the underlying search principle and architectural skeleton clearly without verbosity.

* **Core Principle (Complement Search):** Instead of scanning the entire array repeatedly for every element `nums[i]`, the algorithm looks back at the previously traversed path to check if the required counterpart, **`complement = target - nums[i]`**, already exists.
* **Structural Definition:** To achieve an $O(1)$ average lookup time, the algorithm dynamically stores visited elements and their corresponding indices in a **`std::unordered_map<int, int>` (Key: Element Value, Value: Index)** while traversing the array in a single-pass.

---

## 3. HOW: How is it implemented and applied step-by-step?
> Present the evolution from initial intuition to production-ready C++ code within 3 clear stages.

### Step 1: Initial Intuition (C++ Brute Force)
* The initial approach focuses on absolute spatial efficiency by avoiding extra data structures. It uses a reverse-outer loop combined with a forward-inner loop to exhaustively check every unique pair $(i, j)$.

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result{};
        for(int i = nums.size() - 1; i >= 0; i--) {
            for(int j = 0; j < i; j++){
                if ((nums[i] + nums[j]) == target) {
                    result.push_back(j);
                    result.push_back(i);    
                }
            }
        }
        return result;
    }
};
```
* **Bottleneck:** While space complexity is an optimal $O(1)$, the time complexity degrades to a lagging $O(N^2)$ due to the nested loop structure, creating high abstraction and runtime overhead.

### Step 2: Optimized Production Implementation (C++ Hash Map)
* To eliminate the nested loop overhead, a deliberate trade-off is made: allocate linear memory space using a hash map to compress the runtime dimension down to linear time.

```cpp
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map; // Key: element, Value: index
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // If the complement exists in the map, return indices immediately
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            
            // Otherwise, record the current value and its index
            num_map[nums[i]] = i;
        }
        
        return {};
    }
};
```

### Step 3: Edge Cases & Exception Verification
* **Handling Negative Numbers:** Since the logic relies on pure subtraction (`target - nums[i]`), it processes negative integers correctly without modification.
* **Identical Addends (e.g., `target = 6`, `nums = [3, 3]`):** Because the `find()` lookup occurs before committing the current element to the map, it successfully returns `[0, 1]` without throwing duplicate index conflicts or overwriting values prematurely.

---

## 4. WHAT IF: What changes occur once this approach is applied?
> Compare performance metrics and quantify trade-off outcomes realistically without exaggeration.

| Approach | Time Complexity | Space Complexity | Engineering Trade-off |
| :--- | :--- | :--- | :--- |
| Attempt 1: Brute Force | $O(N^2)$ | $O(1)$ | Preserves memory, but introduces severe execution bottlenecks as data scales. |
| **Attempt 2: Unordered Map (Selected)** | **$O(N)$** | **$O(N)$** | **Achieves linear runtime. Trade-off: Allocates extra memory to yield massive performance gains.** |

* **Quantifiable Outcome:** When the dataset expands to $10^4$ elements, total operations scale down by up to several thousand times compared to the brute-force approach. This ensures stable performance metrics for real-time production API response times.
* **Pattern Assetization:** When encountering future problems that require finding matching pairs to satisfy a specific constant, this structural design pattern can be reused immediately to eliminate nested loops via **Hash Map dimension reduction**.
