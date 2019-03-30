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
str2='''for 1 x , linearsearch = 16298 , sort linearsearch= 2 and binarysearch= 41
for 3 x , linearsearch = 106950 , sort linearsearch= 18 and binarysearch= 44
for 5 x , linearsearch = 61974 , sort linearsearch= 32 and binarysearch= 41
for 20 x , linearsearch = 88824 , sort linearsearch= 130 and binarysearch= 41
for 30 x , linearsearch = 1088 , sort linearsearch= 200 and binarysearch= 44'''
str3='''1 Linear 11740     Binary 7010930
3 Linear 202106    Binary 7011024
5 Linear 336224    Binary 7011121
50 Linear 2574845   Binary 7012978
60 Linear 3177030   Binary 7013442
70 Linear 3019226   Binary 7013847
80 Linear 4142649   Binary 7014280
100 Linear 5209384   Binary 7015037
1000 Linear 53229862          Binary 7052833
2000 Linear 104004031         Binary 7094707'''
str4='''1 Linear 5143      Binary 7010740
3 Linear 148515    Binary 7010840
5 Linear 341736    Binary 7010898
50 Linear 2360740   Binary 7012783
60 Linear 3147195   Binary 7013215
70 Linear 3802112   Binary 7013608
80 Linear 4056226   Binary 7014078
100 Linear 5426817   Binary 7014910
1000 Linear 51368606          Binary 7052788
2000 Linear 103577825         Binary 7094275'''
list1=str4.split('\n')
print list1

while ch1==1:
    datlist=[]
    datlist2=[]
    datlist3=[]
    #a=int(raw_input("Enter number of entries you want to plot: "))
    for i in range(0,len(list1),1):
      x=int(list1[i].split()[0])
      y=int(list1[i].split()[2])
      datlist+=[[x,y]]
      x=int(list1[i].split()[0])
      y=int(list1[i].split()[4])
      datlist2+=[[x,y]]
      #x=int(list1[i].split()[0])
      #y=int(list1[i].split()[13])
      #datlist3+=[[x,y]]
    print datlist
    print datlist2
    #print datlist3
    data=np.array(datlist)
    x,y=data.T
    data1=np.array(datlist2)
    x1,y1=data1.T
    #data2=np.array(datlist3)
    #x2,y2=data2.T
    plt.plot(x,y,label='linear search',color='red')
    plt.plot(x1,y1,label='linear search',color='green')
    #plt.plot(x2,y2,label='binary search',color='blue')
    plt.show()
    plt.scatter(x,y,label='linear search',color='red')
    plt.scatter(x1,y1,label='linear search',color='green')
    #plt.scatter(x2,y2,label='binary search',color='blue')
    plt.show()
    print("Complted plotting")
    ch1=int(raw_input("Do you want to continue(1-Yes/0-No)?"))
    while (ch1!=0) and (ch1!=1):
        ch1=int(raw_input("Do you want to continue(1-Yes/0-No)?"))
