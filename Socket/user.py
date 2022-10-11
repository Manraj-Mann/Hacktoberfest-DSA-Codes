import os 
import socket
from datetime import datetime
import psutil
from operator import itemgetter

filePath = "/home/testing/Desktop/sentfile.txt"
fileMode = "w"
systemUsername = os.getlogin()
systemName = socket.gethostname()
date=datetime.now().strftime("%H:%M:%S %m/%d/%Y ")
allProcess = []
processList = []
listSorted = []
file = open(filePath,fileMode ) 
file.write("\n%-30s%-30s"%("Username: " , systemUsername)) 
file.write("\n%-30s%-30s"%("Computer Name: " + systemName)) 
file.write("\n%-30s%-30s"%("Date and Time: "+date)) 

for aProcess in psutil.process_iter():
    processList = aProcess.as_dict(attrs=['pid', 'name'])
    processList['vms'] = aProcess.memory_info().vms / (1024 * 1024)
    allProcess.append(processList)

for item in allProcess:
    processList.append([item['name'],item['pid'],item['vms']])

listSorted = sorted(processList,key=itemgetter(2), reverse=True)


def writeData():
    file.write("\n%-15s%-15s"%("\nTotal number of process:",len(listSorted)))
    file.write("\n%-15s%-15s%-15s"%("\nName","Process ID","Process Memory"))

    for i in range(0,10,1):
        file.write("\n%-15s%-15s%-15s"%(listSorted[i][0],listSorted[i][1],round(listSorted[i][2],2)))

   
writeData()