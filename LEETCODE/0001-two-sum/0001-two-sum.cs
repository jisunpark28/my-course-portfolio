public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> lookup = new Dictionary<int, int>();
        for (var i = 0; i < nums.Length; i++) {
            if (lookup.ContainsKey(target - nums[i])) {
                return new int[] { lookup[target - nums[i]], i };
            }
            lookup[nums[i]] = i;
        }
        return new int[] { };
    }
}


// Hash Table/Map
//     : saving specific value for mapping a key to a value
//     : direct jump to memory. No loops, no if comparisons.
// public/pravate/protected (Access Modifiers)
//     c++: used with function/variable (Scope-based)
//     c#: used with class (Element-based)
//     : encapsulation
// array
//     c++: int* nums, int nums[] --> static memory (stack)
//     c#: int[] nums --> dynamic memory (heap)
//     : safety (prevent buffer overflow)
// Generic
//     : the data type is undefined until used
//     : Dictionary<K, V>
//     : type safety, code reuse
// Array getter/setter (indexer)
//     : lookup[key] --> get_Item(key)
//     :lookup[key] = value --> set_Item(key, value)