# Exercise 3.13: How many elements are there in each of the following `vector`

**What are the values of the elements?**

```cpp
vector<int> v1;
// default-initialized
// empty vector - no element
vector<int> v2(10);
// value-initialized
// 10 elements
// each element has value: 0
vector<int> v3(10, 42);
// direct-initialized with constructor
// 10 elements
// each element has value: 42
vector<int> v4{10};
// list-initialized
// 1 element
// first (and only) element has value: 10
vector<int> v5{10, 42};
// list-initialized
// 2 elements
// first has value: 10; second has value: 42
vector<string> v6{10};
// value-initialized - because no suitable conversion if possible from integral value 10 to string
// 10 elements
// each element has value: "" - empty string
vector<string> v7{10, "hi"};
// direct-initialized using constructor
// 10 elements
// each element has value: "hi"
```
