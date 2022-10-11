##
# This script.py file can get list of all system accounts on the current machine and the same script can also find and sort the system logs
# based on the search creteria specified in the projectini file and all the results generated can be saved in a file 
##

import pwd
import grp
from datetime import datetime
import socket
   

outFile = ""
sortAccountsReverse = ""
sortAccountsCriteria = ""
linesOfAccountsData = ""
sortLogsReverse = ""
logTimeFrom = ""
logTimeTo = ""
configFile = "projectini.txt"
logCriteria = ""
now = datetime.now()
date_time = now.strftime("%m/%d/%Y, %H:%M:%S")

# reading all configrations from the config file and storing in the variable instialised above
try:
    configFile = open(configFile, "r") # opening configFile in readMode 
    lines = configFile.read().splitlines() 
    for line in lines:
        subString = line.split("=")
        if subString[0] == "outFile":
            outFile = subString[1]
        elif subString[0] == "sortAccountsReverse":
            sortAccountsReverse = subString[1]
        elif subString[0] == "sortAccountsCriteria":
            sortAccountsCriteria = subString[1]
        elif subString[0] == "linesOfAccountsData":
            linesOfAccountsData = subString[1]
        elif subString[0] == "logTimeFrom":
            logTimeFrom = subString[1]
        elif subString[0] == "logTimeFrom":
            logTimeFrom = subString[1]
        elif subString[0] == "logTimeTo":
            logTimeTo = subString[1]
        elif subString[0] == "logCriteria":
            logCriteria = subString[1]
    configFile.close() # closing file 

except:
    print("Could not read config file!")


while True:
    #printing menu 
    print("\nSelection---\n")
    print("1 System accounts")
    print("2 System logs")
    print("3 Generate Report\n")
    print("Press Enter to exit\n")
    userInput = input('Enter your input here: ') # requesting users input for appropriate action 
    if(userInput==''):
        exit() # exiting script if users enters a blank input             
    elif (userInput == '1'):
        accounts = [] # creating a list to enter all data of accounts
        for p in pwd.getpwall():
            accounts.append([p[0], grp.getgrgid(p[3])[0]])
            
        accounts.sort(key=lambda x: x[1],reverse=bool(sortAccountsReverse)) # sorting list of users on basis of the sortAccountsReverse  	

        print("%-25s%-25s\n" %("Account Name", "Group Name"+'\n'))
        
        if (linesOfAccountsData=='All'):
            for item in accounts:
                print("%-25s%-25s\n" %(item[0], item[1]))
        else:
            for i in range(int(linesOfAccountsData)):
                print("%-25s%-25s\n" %(accounts[i][0], accounts[i][1]))
        
    elif (userInput == '2'):
        # getting and printing list of all system logs if user enters 2 as an input
        logFile = open('/var/log/syslog', "r")
        logList = logFile.read().splitlines()
        #printing eac item present in the log list
        for log in logList:
            logType = log.split(" ")[5]
            # only printing the log information if the search createria meets
            if(logType.startswith(logCriteria)):
                print(log+'\n')
        # closing file to release resources
        logFile.close()

    elif (userInput == '3'):
        # writing all the data into outFile 
        # try: 
            outFile = open(outFile+".txt", "w")
            outFile.write("ComputerName: "+socket.gethostname()+"\n") # writing computer name to the output file 
            outFile.write("Date and Time: "+date_time+"\n") # writing date and time to the output file 
            accounts = []
            for p in pwd.getpwall():
                accounts.append([p[0], grp.getgrgid(p[3])[0]])
                
            accounts.sort(key=lambda x: x[1],reverse=bool(sortAccountsReverse)) # sorting list of users on basis of the sortAccountsReverse  	
            outFile.write("%-25s%-25s\n" %("Account Name", "Group Name"+'\n'))
        
            if (linesOfAccountsData=='All'):
                for account in accounts:
                    outFile.write("%-25s%-25s\n" %(account[0], account[1]+'\n')) # writing account name and their associated group name to the output file 
            else:
                for i in range(int(linesOfAccountsData)):
                    outFile.write("%-25s%-25s\n" %(accounts[i][0], accounts[i][1]+'\n')) # writing account name and their associated group name to the output file 
                
            outFile.write('\n\nsystem logs\n')
            # getting and printing list of all system logs if user enters 2 as an input
            logFile = open('/var/log/syslog', "r")
            logList = logFile.read().splitlines()
            #printing each item present in the log list
            for log in logList:
                logType = log.split(" ")[5]
                # only printing the log information if the search createria meets
                if(logType.startswith(logCriteria)):
                    outFile.write(log+'\n')
            # closing file to release resources
            logFile.close()

            #closing file
            outFile.close()
        # except:
            # print("Error occured while writing data.")

    else:
        print("Invalid Option!")
        