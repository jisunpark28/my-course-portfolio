---
topic: C++ Copy vs Move Semantics
tags: C++, move, copy, OOP
---

동적 배열 `IntArray`에서 Copy는 새 힙을 할당해 값을 복사하고, Move는 포인터만 넘긴 뒤 원본을 빈 상태로 만든다.

## 핵심 차이

| | Copy | Move |
|---|------|------|
| 비용 | O(n) | O(1) |
| 원본 | 유지 | 비어 있음 |

```cpp
J = std::move(I);        // Move Assignment
IntArray K = std::move(J); // Move Constructor
```

- move 후 원본은 dummy 상태가 된다
- copy 후에는 원본과 사본이 모두 같은 데이터를 가진다
