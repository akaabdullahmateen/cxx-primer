# Exercise 2.25: Determine the types and values of each of the following variables

```cpp
int* ip, i, &r = i;
int i, *ip = 0;
int* ip, ip2;
```

## a) `int* ip, i, &r = i;`

| **Identifier** | **Type** | **Value** |
|----------------|----------|-----------|
| `ip`           | `int *`  | undefined |
| `i`            | `int`    | undefined |
| `r`            | `int &`  | undefined |

## b) `int i, *ip = 0;`

| **Identifier** | **Type** | **Value** |
|----------------|----------|-----------|
| `i`            | `int`    | undefined |
| `ip`           | `int *`  | null      |

## c) `int* ip, ip2;`

| **Identifier** | **Type** | **Value** |
|----------------|----------|-----------|
| `ip`           | `int *`  | undefined |
| `ip2`          | `int`    | undefined |