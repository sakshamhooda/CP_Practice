# Pathless

**Problem Link:** [Codeforces Contest 2130 Problem B](https://codeforces.com/contest/2130/problem/B)

## Problem Statement

There is an array $a_1, a_2, \ldots, a_n$ consisting of values $0$, $1$, and $2$, and an integer $s$. It is guaranteed that $a_1, a_2, \ldots, a_n$ contains at least one $0$, one $1$, and one $2$.

Alice wants to start from index $1$ and perform steps of length $1$ to the right or to the left, and reach index $n$ at the end. While Alice moves, she calculates the sum of the values she is visiting, and she wants the sum to be exactly $s$.

Formally, Alice wants to find a sequence $[i_1, i_2, \ldots, i_m]$ of indices, such that:

- $i_1 = 1$, $i_m = n$
- $1 \leq i_j \leq n$ for all $1 \leq j \leq m$
- $|i_j - i_{j+1}| = 1$ for all $1 \leq j < m$
- $a_{i_1} + a_{i_2} + \ldots + a_{i_m} = s$

However, Bob wants to rearrange $a_1, a_2, \ldots, a_n$ to prevent Alice from achieving her target. Determine whether it is possible to rearrange $a_1, a_2, \ldots, a_n$ such that Alice cannot find her target sequence (even if Alice is smart enough). If it is possible, you also need to output the rearranged array $a_1, a_2, \ldots, a_n$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ $(1 \leq t \leq 10^3)$. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $s$ $(3 \leq n \leq 50, 0 \leq s \leq 1000)$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ $(0 \leq a_i \leq 2)$.

**Constraints:**
- It is guaranteed that $a$ contains at least one $0$, one $1$, and one $2$.

## Output

For each test case, if it is possible to rearrange $a$ such that Alice cannot find her target sequence, output $n$ integers — such rearrangement of $a$. Otherwise, output $-1$ instead.

## Example

### Input
```
6
3 2
0 1 2
3 3
0 1 2
3 6
0 1 2
3 4
0 1 2
3 10
0 1 2
5 1000
2 0 1 1 2
```

### Output
```
0 1 2
-1
-1
0 2 1
-1
-1
```

### Note

- **First test case**: Any rearrangement of $a$ can prevent Alice from achieving her target.
- **Second test case**: Regardless of rearranging $a$, Alice can always find the sequence $[1, 2, 3]$ as her target sequence.
- **Third test case**: There is no rearrangement of $a$ that can prevent Alice from achieving her target. For example, for $a = [0, 2, 1]$, Alice can find the sequence $[1, 2, 3, 2, 3]$ as her target sequence.

## Key Insights

1. **Alice's Movement**: Alice can move left or right by 1 step at a time, starting from index 1 and ending at index n.
2. **Path Sum**: Alice needs to find a path where the sum of visited elements equals exactly $s$.
3. **Bob's Goal**: Bob wants to rearrange the array to make it impossible for Alice to achieve her target.
4. **Decision Problem**: Determine if Bob can prevent Alice from achieving her goal, and if so, provide a valid rearrangement.

---

*This problem is from Codeforces Contest 2130. The original problem can be found at: [https://codeforces.com/contest/2130/problem/B](https://codeforces.com/contest/2130/problem/B)*
