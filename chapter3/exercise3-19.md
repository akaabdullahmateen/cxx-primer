# Exercise 3.19: List three ways to define a vector and give it ten elements, each with the value 42.

**Indicate whether there is a preferred way to do so and why.**

```cpp
vector<int> v1 = {42,42,42,42,42,42,42,42,42,42}
vector<int> v2(10, 42);
vector<int> v3;
for(decltype(v3.size()) idx = 0; idx < 10; ++idx){
    v3.push_back(42);
}
```

**Preferred:** Direct initializer of `v2` using constructor of the form `vector<typeT> vec(n, val)` which constructs `vec` with `n` `typeT` objects, each with value `val`.

**Why:** Because, it achieves the task in the fewest keystrokes, and there is the least possibility of error.