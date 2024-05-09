'''list of student who play '''
A=["ram","shyam","ajit","aniket","khushi"] # cricket
B=["ram","shyam","ganesh","shasank","shweta"]# badminton
C=["ram","ganesh","abhishek","ramesh","krsihna"]#football

def student(A,B):
    solution=[]
    for i in A:
        if i in B:
            solution.append(i)
    print("\n a.student who play both cricket and badminton: ",solution)
student(A,B)


def not_both(A,B):
    D=[]
    E=[]
    solution=[]
    D=B.copy()
    for i in A:
        if i not in B:
            D.append(i)
        if i in B:
            E.append(i)
    for i in D:
        if i not in E:
            solution.append(i) 
    print("\n b.student who play either cricket or badminton but not both are: ",solution)
not_both(A,B) 

def neither_nor(A,B,C):
    solution=[]
    for i in C:
        if i not in A:
            if i not in B:
                solution.append(i)

    print("\n c. no of students who play neither cricket nor badminton:- ",len(solution))
neither_nor(A,B,C)

def not_badminton(A,B,C):
    solution=[]
    for i in A:
        if i in C:
            if i not in B:
                solution.append(i)

    print("\n d.no of students who play cricket and football but not badminton: ",len(solution)) 
not_badminton(A,B,C)    


# program ends