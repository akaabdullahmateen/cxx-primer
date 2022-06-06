# Exercise 5.13: Each of the programs in the code snippets below contains a common programming error. Identify and correct each error.

## Snippet a)

```cpp
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
	case ’a’: aCnt++;
	case ’e’: eCnt++;
	default: iouCnt++;
}
```

**Error:** There are no `break` statements at the end of each case, thus, execution may fall through to code in the proceding case labels.

**Correction:** Add `break` statements at the end of each case label. Although, it is not necessary to include `break` at the end of `default` label, it is recommended to do so.

```cpp
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
	case ’a’: aCnt++; break;
	case ’e’: eCnt++; break;
	default: iouCnt++; break;
}
```

## Snippet b)

```cpp
unsigned index = some_value();
switch (index) {
	case 1:
		int ix = get_value();
		ivec[ ix ] = index;
		break;
	default:
		ix = ivec.size()-1;
		ivec[ ix ] = index;
}
```

**Error:** Jump to `default` case label crosses initialization of `int ix`. Integral variable `ix` is in scope in `default` case label, but is not initialized.

**Correction:** Since, `ix` is used by both `case 1` and `default` case labels, `int ix` should be declared outside of `switch` statement.

```cpp
vector<int> ivec = {1, 2, 3, 4};
unsigned index = 2;
int ix;
switch (index) {
	case 1:
		ix = 1;
		ivec[ ix ] = index;
		break;
	default:
		ix = ivec.size()-1;
		ivec[ ix ] = index;
}
```

## Snippet c)

```cpp
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
	case 1, 3, 5, 7, 9:
		oddcnt++;
		break;
	case 2, 4, 6, 8, 10:
		evencnt++;
	break;
}
```

**Error:** The `case` label must only contain integral constant expressions, not list of integral literals.

**Correction:** Use explicit case labels for each integral value in each of the case labels.

```cpp
unsigned evenCnt = 0, oddCnt = 0;
int digit = 42 % 10;
switch (digit) {
	case 1: case 3: case 5: case 7: case 9:
		oddCnt++;
		break;
	case 2: case 4: case 6: case 8: case 10:
		evenCnt++;
	break;
}
```

## Snippet d)

```cpp
unsigned ival=512, jval=1024, kval=4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
	switch(swt) {
	case ival:
		bufsize = ival * sizeof(int);
		break;
	case jval:
		bufsize = jval * sizeof(int);
		break;
	case kval:
		bufsize = kval * sizeof(int);
		break;
}
```

**Error:** The case labels expect constant expressions, however, `ival`, `jval`, `kval` are not declared as `constexpr` or `const`.

**Correction:** Add `constexpr` or `const` qualifier to the multi-declaration of `ival`, `jval`, and `kval`.

```cpp
constexpr unsigned ival=512, jval=1024, kval=4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
	switch(swt) {
	case ival:
		bufsize = ival * sizeof(int);
		break;
	case jval:
		bufsize = jval * sizeof(int);
		break;
	case kval:
		bufsize = kval * sizeof(int);
		break;
}
```
