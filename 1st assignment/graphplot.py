#Graph plotter 1.0 for visualization purpose
#made by Subrata Sarkar(subrotosarkar32@gmail.com)
import numpy as np
from matplotlib import pyplot as plt
print("Graph plotter")
ch1=1
str1='''Enter value of x: 1000
Enter value of y: 245370
Enter value of x: 1000
Enter value of y: 43337
Enter value of x: 1000
Enter value of y: 35760
Enter value of x: 2000
Enter value of y: 1008467
Enter value of x: 2000
Enter value of y: 94681
Enter value of x: 2000
Enter value of y: 38760
Enter value of x: 3000
Enter value of y: 2235484
Enter value of x: 3000
Enter value of y: 149687
Enter value of x: 3000
Enter value of y: 41760
Enter value of x: 4000
Enter value of y: 3928429
Enter value of x: 4000
Enter value of y: 205356
Enter value of x: 4000
Enter value of y: 44767
Enter value of x: 5000
Enter value of y: 6298100
Enter value of x: 5000
Enter value of y: 264058
Enter value of x: 5000
Enter value of y: 47764
Enter value of x: 6000
Enter value of y: 8963559
Enter value of x: 6000
Enter value of y: 323224
Enter value of x: 6000
Enter value of y: 50764
Enter value of x: 7000
Enter value of y: 12243982
Enter value of x: 7000
Enter value of y: 382964
Enter value of x: 7000
Enter value of y: 53766
Enter value of x: 8000
Enter value of y: 15935777
Enter value of x: 8000
Enter value of y: 442886
Enter value of x: 8000
Enter value of y: 56764
Enter value of x: 9000
Enter value of y: 20215551
Enter value of x: 9000
Enter value of y: 505088
Enter value of x: 9000
Enter value of y: 59768
Enter value of x: 10000
Enter value of y: 25008830
Enter value of x: 10000
Enter value of y: 568162
Enter value of x: 10000
Enter value of y: 62769'''
list1=str1.split('\n')
print list1

while ch1==1:
    datlist=[]
    datlist2=[]
    datlist3=[]
    #a=int(raw_input("Enter number of entries you want to plot: "))
    for i in range(0,len(list1),6):
      x=int(list1[i].split()[-1])
      y=int(list1[i+1].split()[-1])
      datlist+=[[x,y]]
      x=int(list1[i+2].split()[-1])
      y=int(list1[i+3].split()[-1])
      datlist2+=[[x,y]]
      x=int(list1[i+4].split()[-1])
      y=int(list1[i+5].split()[-1])
      datlist3+=[[x,y]]
    print datlist,datlist2,datlist3
    data=np.array(datlist)
    x,y=data.T
    data1=np.array(datlist2)
    x1,y1=data1.T
    data2=np.array(datlist3)
    x2,y2=data2.T
    plt.plot(x,y,label='n^2')
    plt.plot(x1,y1,label='nlogn')
    plt.plot(x2,y2,label='countsort')
    plt.show()
    plt.scatter(x,y,label='n^2')
    plt.scatter(x1,y1,label='nlogn')
    plt.scatter(x2,y2,label='countsort')
    plt.show()
    print("Complted plotting")
    ch1=int(raw_input("Do you want to continue(1-Yes/0-No)?"))
    while (ch1!=0) and (ch1!=1):
        ch1=int(raw_input("Do you want to continue(1-Yes/0-No)?"))
