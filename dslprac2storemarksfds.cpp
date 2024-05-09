marks=[]
n=int(input("enter total no of students:" ))
print("enter marks of student :")
for i in range(n):
    a=input()
    marks.append(a)
print(marks)

m=[]
for i in marks:
    if i!="absent":
        m.append(int(i))
print(m)

#Calculate Average 
def average(m):
    total=0
    for i in m:
        total=total+i
    average=total/len(m)
    print("a.Average of marks=",average)
average(m)

def high_low(m):
    high=m[0]
    low=m[0]
    for i in m:
        if i>high:
            high=i
        if i<low:
            low=i
            print("b.Highest Marks=",high_low)
            print("c.Lowest Marks=",high_low)
high_low(m)


#calculate absent students 
def absent_student(marks,m):
    print("d.Absent Students=",len(marks)-len(m))
absent_student(marks,m)


#calculate high frequency
def highest_freq(m):
    maxcount=0
    mark=0
    for i in m:
            count=0
            for j in m:
                if i==j:
                    count=count+1
            if count>maxcount:
                maxcount=count
                mark=i
    print(f"\n e.Marks with high freq {mark} and its freq is {maxcount}")
highest_freq(m) 

