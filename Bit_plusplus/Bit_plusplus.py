# Read the number of statements
n = int(input())

x = 0

# Read n statements
for _ in range(n):
    statement = input().strip()
    
    # Check if the statement contains "++" (increment) or "--" (decrement)
    if "++" in statement:
        x += 1
    elif "--" in statement:
        x -= 1

print(x)





