roll =[]
m=len(roll)
num=()
n=int(input("number of students attend program:"))
for i in range (n):
    num=int(input("roll no:"))
    roll.append(num)
print("roll no of students attending program:",roll)

x=int(input("Enter roll no needed to be searched: "))

def linear_search(roll,x):
    for i in range(len(roll)):
        if(roll[i]==x):
            return i
    return -1
result=linear_search(roll,x)
if result==-1:
    print("Element not found")
else:
    print("Element found at index: ",result)

x=int(input("Enter roll no needed to be searched:"))

def sentinel(roll,x):
    i=0
    while(roll[i]!=x):
        i+=1
    if(i==n):
        return none
    else:
        return i
sentinel(roll,x)
print("Index is: ",sentinel(roll,x))


def ascending_order(roll,m):
    for i in range(n):
        for j in range(0,n-i-1):
            if roll[j]>roll[j+1]:
                small=roll[j]
                roll[j]=roll[j+1]
                roll[j+1]=small
ascending_order(roll,m)
print("sorted list: ",roll)

def binary_search(roll,low,high,x):
    if high>=low:
        mid=(high+low)//2
        if roll[mid]==x:
            return mid
        elif roll[mid]>x:
            return binary_search(roll,low,mid-1,x)
        else:
            return binary_search(roll,mid+1,high,x)
    else:
        return -1
result=binary_search(roll,0,len(roll)-1,x)

if result!=-1:
    print("element present at index :", str(result))
else:
    print("element is not present in array")


def fibonacci_search(roll,m,key):
    f2=0
    f1=1
    newm=f2+f1
    
    while(newm<m):
        f2 =f1
        f1=newm
        newm =f2+f1
    offset=-1
    
    while(newm>1):
        i=min(offset+f2,m-1)
        if(roll[i]<key):
            newm=f1
            f1=f2
            f2=newm-f1
            offset=i
        elif(roll[i]>key):
            newm=f2
            f1= f1-f2
            f2=newm-f1
        else:
            return i
    if(f1 and roll[m-1]==key):
        return m-1
    return -1
key =int(input("Enter Roll number to  search: "))
result = fibonacci_search(roll,m,key)
if(result >= 0):
    print(f"Roll number {key} attended the training program.")
else:
    print(f"Roll number {key} did not attend the training program.")

