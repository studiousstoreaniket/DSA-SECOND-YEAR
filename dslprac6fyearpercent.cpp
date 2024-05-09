percentage =[]
n=int(input("Enter total number of students : "))
print("Enter Percentage: ")
for i in range (n):
    m=float(input(" "))
    percentage.append(m)
print(percentage) 

percentage =[]
n=int(input("Enter total number of students : "))
print("Enter Percentage: ")
for i in range (n):
    m=float(input(" "))
    percentage.append(m)
print(percentage)

def selection_sort(percentage,n):
    s1 = percentage.copy()
    for i in range(n-1):
         for j in range(i+1,n):
            if(s1[j]<s1[i]):
                s1[i], s1[j] = s1[j] , s1[i]
    print("Sorted data: ",s1)
selection_sort(percentage,n)

def bubble_sort(percentage,n):
    s2= percentage.copy()
    counter =1
    while(counter<n):
        for i in range(n-counter):
            if(s2[i]>s2[i+1]):
                s2[i] ,s2[i+1] = s2[i+1], s2[i]
        counter = counter + 1
    return s2
b=bubble_sort(percentage,n)
print("Sorted Data:",b)
print("top five scores are: ")
for i in range (-1,-6,-1):
     print(b[i])

