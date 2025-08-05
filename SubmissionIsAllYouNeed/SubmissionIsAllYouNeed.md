# Problem A - [Submission is All You Need](https://codeforces.com/contest/2130/problem/A)

## Problem Statement

For a multiset $T$ consisting of non-negative integers, we define:

- **sum(T)** is the sum of all elements in $T$. For example, if $T = \{0, 1, 1, 3\}$, then $sum(T) = 0 + 1 + 1 + 3 = 5$.

- **mex(T)** is the smallest non-negative integer not in $T$. For example, if $T = \{0, 1, 1, 3\}$, then $mex(T) = 2$ because $2$ is the smallest non-negative integer not present in $T$.

You are given a multiset $S$ of size $n$ consisting of non-negative integers. At first, your score is $0$. You can perform the following operations any number of times in any order (possibly zero):

- Select a subset $S' \subseteq S$ (i.e., $S'$ contains some of the elements currently in $S$), add $sum(S')$ to your score, and then remove $S'$ from $S$.
- Select a subset $S' \subseteq S$, add $mex(S')$ to your score, and then remove $S'$ from $S$.

Find the maximum possible score that can be obtained.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^3$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 50$).

The second line of each test case contains $n$ integers $S_1, S_2, \ldots, S_n$ ($0 \leq S_i \leq 50$).

## Output

For each test case, print a single integer — the maximum possible score that can be obtained.

## Example

### Input
```
2
3
0 1 1
3
1 2 3
```

### Output
```
3
6
```

## Note

In the first test case, a possible optimal strategy is as follows:

1. Select $S' = \{0, 1\}$, add $mex(S') = mex(\{0, 1\}) = 2$ to your score, and then remove $S'$ from $S$. Currently, your score is $2$ and $S = \{1\}$.
2. Select $S' = \{1\}$, add $sum(S') = sum(\{1\}) = 1$ to your score, and then remove $S'$ from $S$. Currently, your score is $3$ and $S = \emptyset$.

After that, you cannot do any further operations. It can be proven that $3$ is the maximum possible score that can be obtained.

---

**Original Problem Link:** [https://codeforces.com/contest/2130/problem/A](https://codeforces.com/contest/2130/problem/A)
