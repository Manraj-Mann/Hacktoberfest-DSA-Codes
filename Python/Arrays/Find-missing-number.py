#Approch of getting missing numbers in an array by using N natural numbers Summation Method....

def getting_missing_summation(a):
    n = a[-1]
    sum1=0
    total=n*(n+1)//2
    sum1=sum(a)
    print(total - sum1)
      
a = [1,2,3,5,6,7,8,9] 
getting_missing_summation(a)

    
