lst= []
n=int(input("Enter total numbers of friends: "))
for i in range(n):
    t=(input("Name: "),int(input("Number: ")))
    lst.append(t)
print("Unsorted data: ",lst)

#sort data:
counter=1
while(counter<n):
    for i in range(n-counter):
         if (lst[i][0] > lst[i+1] [0]):
             small = lst[i]
             lst[i]=lst[i+1]
             lst[i+1]=small
    counter = counter + 1
print("\nSorted data: ",lst) 

#Recursive Binary Search:
print("Recursive Binary Search- ")
key = input("Enter name of friend to search: ")
low =0
high=n-1
def rec_binary_search(lst,key,low,high):
    if high>=low:
        flag=0 
        mid = (low+high)//2
        if(lst[mid][0]==key):
            print(f"Friend found: {lst[mid]}.")
        elif(lst[mid][0]>key):
            rec_binary_search(lst,key,low,mid-1)
        else:
            rec_binary_search(lst,key,mid+1,high)
    else:
        print("Friend not found.")
        print("Add name...")
        t =(key,int(input("Number:")))
        lst.append(t)
        lst.sort()
        print(lst)
rec_binary_search(lst,key,low,high)

#Non_recursive Binary Search:
print("Binary Search- ")
key = input("Enter name of friend to search: ")
low=0
high=n-1
def binary_search(lst,key,low,high):
    while(high>=low):
        flag = 0
        mid = (low + high) //2
        if(lst[mid][0]==key):
            print(f"Friend found: {lst[mid]}.")
            break
        elif(lst[mid] [0]>key):
            high=mid - 1
        else:
            low =mid + 1
    else:   
            print("Friend not found.")
            print("Add name...")
            t= (key,int(input("Number:")))
            lst.append(t)
            lst.sort()
            print(lst)
binary_search(lst,key,low,high)

# que5 B
data =[]
n= int(input("Enter total number of friends: "))
for i in range(n):
    t= (input("Name: "), int(input("Number: ")))
    data.append(t)
print("Unsorted data:", data)

#sort data:
counter =1
while(counter<n):
    for i in range(n-counter):
        if (data[i][0] > data [i+1] [0]):
            temp = data[i]
            data[i]=data[i+1]
            data[i+1] =temp
    counter = counter + 1
print("Sorted data: ",data)


print("FIBONACCI SEARCH")
key = input("Enter name of friend to search:")

def fibonacci_search(data,n,key):
    f2=0
    f1=1
    newn=f2+f1
    
    while(newn<n):
        f2=f1
        f1=newn
        newn=f2+f1
    offset =-1
    
    while(newn>1):
        i= min(offset+f2,n-1)
        if(data[i] [0]<key):
            newn=f1
            f1=f2
            f2=newn-f1
            offset=i
        elif(data[i][0]>key):
                newn =f2
                f1=f1-f2
                f2=newn-f1
        else:
            return i
    if(f1 and data[n-1][0]==key):
        return n-1
    return -1
result = fibonacci_search(data,n,key)
if(result >= 0):
    print(f"Friend found: {data[i]}.")
else:
    print("Friend not found.")
    print("Add name...")
    t= (key,int(input("Enter Number: ")))
    data.append(t)
    data.sort()
    print(data)

