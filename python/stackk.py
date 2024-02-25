# Stack implementation in python

# Creating a stack
def create_stack():
    stack = []
    return stack

# Creating an empty stack
def check_empty(stack):
    return len(stack) == 0

# Adding items into the stack
def push(stack, item):
    stack.append(item)

# Removing an element from the stack
def pop(stack):
    if (check_empty(stack)):
        res.append(-1)
        return 
    res.append(stack[-1])
    return stack.pop()

stack = create_stack()


t = int(input())
res =[]
for i in range (0,t):
    n = input().split()
    if not n:
        break
    if "push" in n:
      push(stack, n[1])
    elif "pop" in n:
      pop(stack)

print(*res,sep=" ",end=" ")