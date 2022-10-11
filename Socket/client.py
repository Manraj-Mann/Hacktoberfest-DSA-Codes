import socket #Module for making the connection
import os 
soc = socket.socket() 
soc.connect(("192.168.56.1",5800)) #Build connection with admin machines.
filehandler = open ("/home/testing/Desktop/sentfile.txt", "rb") #Reading file that needs to be sent
sendLine = filehandler.read(1024) #Port number
print("Sending file.")
while (sendLine):
    soc.send(sendLine) #sending the file's lines one by one
    sendLine = filehandler.read(1024)
print("Task Completed!")
soc.close() #closing connection after completing tasks
print("Connection closed!")