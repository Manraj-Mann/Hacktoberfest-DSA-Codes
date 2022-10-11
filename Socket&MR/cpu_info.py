"""
PseudoCode

STEP1: IMPORT THE LIBRARIES REQUIRED FOR THE PROJECT
STEP2: OPEN THE REQUIRED TXT FILE TO STORE THE DATA COLLECTED
STEP3: FETCH THE MACHINE NAME
STEP4: FETCH THE GROUP AND ITS USERS
STEP5: FETCH THE CPU INFORMATION
STEP6: FETCH THE INFORMATION OF SERVICES INSTALLED 
STEP7: CLOSE THE FILE AND END

VARIABLES USED:
1. file - used to manipulate the txt file
2. command_cpu_info - used to store the command to fetch cpu information
3. cpu_info - used to store complete cpu information about the machine
4. command_service_info - used to store the command to fetch information about services installed
5. service_info - used to store all the services installed in the machine

DATA TYPES USED:
1. string [ command_cpu_info, cpu_info, command_service_info, service_info ]
"""

# importing required libraries for the script
import pwd, grp, socket, subprocess, re

# open the text file to write the information
file = open('project1.txt','w')

# fetches the machine name
file.write(f"MACHINE_NAME: {socket.gethostname()}\n")
 

#fetches the groups and then using groupid fetches the users
for p in pwd.getpwall():
     file.write(f"{p[0]}:\n\t{grp.getgrgid(p[3])[0]}\n")

 
#fetches the cpu information using the below command and convert it into string and the decode it from binary format  
command_cpu_info = "cat /proc/cpuinfo"
cpu_info = subprocess.check_output(command_cpu_info, shell = True).strip().decode()

for line in cpu_info.split('\n'):
	if 'processor' in line:
		file.write("\n")
		file.write(f'Processor: {re.sub(".*processor.*:", "", line)}\n')
	if 'vendor_id' in line:
		file.write(f'Vendor_id: {re.sub(".*vendor_id.*:", "", line)}\n')
	if 'model\t' in line:
		file.write(f'Model: {re.sub(".*model.*:", "", line)}\n')
	if 'model name' in line:
		file.write(f'Model_name: {re.sub(".*model name.*:", "", line)}\n')
	if 'cache size' in line:
		file.write(f'Cache: {re.sub(".*cache size.*:", "", line)}\n')
	
#fetches the information about services installed using the below command and convert it into string and the decode it from binary format  
file.write('\n')
command_service_info = "systemctl list-units --type=service -all" 
service_info = subprocess.check_output(command_service_info, shell = True).strip().decode()
file.write(service_info)

file.close()