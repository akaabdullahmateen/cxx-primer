# Statement scope

We can define variables inside the control structure of `if`, `switch`, `while` and `for` statements. Variables defined in the control structure are only visible within that statement and are out of scope after the statement ends:

```cpp
while(int i = get_num()){ // i is created and initialzied on each iteration
	cout << i << endl;
}
i = 0; // error: i is not accessible outside the loop
```

If we need access to the control variable, then that variable must be defined outside the statement:

```cpp
// find the first negative element
auto beg = v.begin();
while(beg != v.end() && *beg >= 0){
	++beg;
}
if (beg == v.end()){
	// we know that all elements in v are greater than or equal to zero
}
```

The value of an object defined in a control structure is used by that structure. Therefore, such variables must be initialized.