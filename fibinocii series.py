
num=int(input("Enter the number of terms in the Fibonacci series: "))
a=0
b=1
print(a)
print(b)
for i in range(2,num):
 c=a+b
 a=b
 b=c
 print(c)