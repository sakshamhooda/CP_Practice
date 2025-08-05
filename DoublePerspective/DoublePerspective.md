# Double Perspective

**Problem Link:** [Codeforces Contest 2130 Problem C](https://codeforces.com/contest/2130/problem/C)

## Problem Statement

For a set of pairs $S = \{(a_1, b_1), (a_2, b_2), \ldots, (a_m, b_m)\}$, where $a_i < b_i$ for all $1 \leq i \leq m$, we define $f(S)$ and $g(S)$ as follows:

- **$f(S)$**: Treating each $(a_i, b_i)$ as a segment on the number line, $f(S)$ is the length of their union. Formally, $f(S)$ is the number of integers $x$ such that there exists an $i$ $(1 \leq i \leq m)$ where $[x, x+1] \subseteq [a_i, b_i]$.

- **$g(S)$**: Treating each $(a_i, b_i)$ as an undirected edge in a graph, $g(S)$ is the number of nodes that lie on at least one simple cycle with at least 3 edges. Formally, $g(S)$ is the number of nodes $x_1$ such that there exists a path $x_1 \rightarrow x_2 \rightarrow \ldots \rightarrow x_k \rightarrow x_1$ in the graph, where $k \geq 3$ and all $x_1, x_2, \ldots, x_k$ are distinct.

### Example

For $S = \{(1, 2), (2, 4), (1, 4), (4, 5), (6, 7)\}$, we get:
- $f(S) = 5$
- $g(S) = 3$

## Task

You are given $n$ distinct pairs. Your task is to select a subset $S'$ of these pairs such that $f(S') - g(S')$ is maximized. You need to output the indices of the selected pairs.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ $(1 \leq t \leq 10^4)$. The description of the test cases follows.

The first line of each test case contains an integer $n$ $(1 \leq n \leq 3 \cdot 10^3)$.

Next $n$ lines each contain two integers $a_i$ and $b_i$ $(1 \leq a_i < b_i \leq 2n)$, representing a pair.

**Constraints:**
- It is guaranteed that all pairs are distinct within the same test case.
- It is guaranteed that the sum of $n^2$ over all test cases will not exceed $9 \cdot 10^6$.

## Output

For each test case:
- The first line contains an integer $k$ $(0 \leq k \leq n)$ — the size of the subset $S'$.
- Next line contains $k$ integers $i_1, i_2, \ldots, i_k$ $(1 \leq i_1, i_2, \ldots, i_k \leq n)$ — the indices of the selected pairs. Note the indices must be distinct.

## Example

### Input
```
2
1
1 2
4
1 2
2 3
1 3
3 5
```

### Output
```
1
1
3
1 2 4
```

### Note

In the first test case:
- If no pair is selected (i.e., $S' = \emptyset$), $f(S') - g(S') = 0 - 0 = 0$
- If the first pair is selected, $f(S') - g(S') = 1 - 0 = 1$

So the optimal solution is to select the first pair.

---

*This problem is from Codeforces Contest 2130. The original problem can be found at: [https://codeforces.com/contest/2130/problem/C](https://codeforces.com/contest/2130/problem/C)*
