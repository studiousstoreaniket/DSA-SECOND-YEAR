book_list=[]
book=()
n=int(input("enter total number of book in library: "))
for i in range(n):
    book=(input("name of book:"),int(input("cost: ")))
    book_list.append(book)
print("\nBook in library are: \n",book_list)

def duplicate_entries(book_list):
    unique_list= []
    for i in book_list:
        if i not in unique_list:
            unique_list.append(i)
    return unique_list
unique=duplicate_entries(book_list)
n1=len(unique)
print("\nBooks without duplicate enteries are:\n",unique)

def ascending_order(unique,n1):
    counter =1
    while(counter<n1):
        for i in range(0,(n1-counter)):
            if(unique[i][1] > unique[i+1][1]):
                temp =unique[i]
                unique[i]= unique[i+1]
                unique[i+1]= temp
        counter= counter + 1
        print("\nBooks in ascending order based on cost:\n",unique)
ascending_order(unique,n1)

def more_than_500(unique,n1):
    count =0
    for i in range(n1):
        if unique[i][1] > 500:
            count = count + 1
    print("\nCount of books having cost more than 500: ",count)
more_than_500(unique,n1)  
   

def less_than_500(unique,n1):
    new_list =[]
    for i in range(n1):
        if(unique[i] [1] <500):
            new_list.append(unique[i])
    print("\nBooks with cost less than 500 are:\n", new_list)
less_than_500(unique,n1)  

   
