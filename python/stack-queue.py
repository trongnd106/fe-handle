# set up QUEUE use ARRAY
'''
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
        return -1

    return stack.pop(0)

stack = create_stack()

 # Driver Code Starts
q=int(input())
q1=[int(x) for x in input().split()]
res = []
i=0
while(i<len(q1)):
    if(q1[i]==1):
        push(stack, str(q1[i+1]))
        i=i+2
    elif(q1[i]==2):
        print(pop(stack),end=" ")
        i=i+1
    elif(check_empty(stack)):
        print(-1)
        i=i+1
# } Driver Code Ends
'''


# set up QUEUE use LINKED LIST
'''
# A linked list (LL) node 
# to store a queue entry 
class Node: 
      
    def __init__(self, data): 
        self.data = data 
        self.next = None
        
class MyQueue:
    def __init__(self):
        self.front=self.rear=None
    
    #Function to push an element into the queue.
    def push(self, item):
        tmp=Node(item)
        if(self.front==None):
            self.front=self.rear=tmp
        else:
            self.rear.next=tmp
            self.rear=tmp
    
    #Function to pop front element from the queue.
    def pop(self):
        if(self.front==None):
            return -1
        tmp=self.front.data
        self.front=self.front.next
        return tmp
         
         #add code here

#{ 
 # Driver Code Starts
s=MyQueue()
q=int(input())
q1=list(map(int,input().split()))
i=0
while(i<len(q1)):
    if(q1[i]==1):
        s.push(q1[i+1])
        i=i+2
    elif(q1[i]==2):
        print(s.pop(),end=" ")
        i=i+1
    elif(s.isEmpty()):
        print(-1)
        i=i+1
print()   
# } Driver Code Ends
'''

