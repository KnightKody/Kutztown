#--------------
#Author: Kody Knight
#Creation date: 2/18/2022
#Due date: 20 Minuets (2/18/2022)
#purpose: to demonstrate reading and writing files
#------------

#----------
#function name: get_data()
#purpose: Open File and copy
#----------
def get_data(FileName):
    
    File = open(FileName)
    TempFile = open(FileName)
    return File, TempFile
    

#----------
#function name: process_data
#purpose: process filedata and store in dictionary list
#----------
def process_data(Original, Temp): 
    Line = (Temp.read()).split()
    DepartmentCount = int((len(Line)-12)/12)
    Count = 0
    Above = 0
    Below = 0
    Months = []
    AllDicts = []
    Months = Original.readline().split()
    Average = 0
    for i in range(DepartmentCount):
        Line = (Original.readline()).split()
        for x in Line:
            Average += float(x)
            if(float(x) >= float(Months[Count])):
                Above += 1
            else:
                Below += 1
                    
        Average = round(Average/12,2)

        
        if(Above >= 5):
            preform = "Satisfied"
        else:
            preform = "Unsatisfied"
        
        Dictionary = {
            "Department":Count+1,
            "Average":Average,
            "Above":Above,
            "Below":Below,
            "Performance":preform  
        }
        AllDicts.append(Dictionary)
        Count += 1
        Above = 0
        Below = 0
        Average = 0
    return AllDicts


#----------
#function name: write_to_file
#purpose: Write output to file
#----------
def write_to_file(Diction):
    Output = open("out.dat","w")
    Output.write("department|" + "Average|" + "Above|" + "Below|" + "Performance"+"\n")
    for i in Diction:
        Output.write(str(i['Department']) + " , " +str(i['Average']) + " , " + str(i['Above']) + " , " + str(i['Below']) + " , " + str(i['Performance'])+"\n")


#----------
#function name: main()
#purpose: starts program
#----------
def main():
    FileName = input("Name of input File? ")
    Original,Temp = get_data(FileName)
    FullDict = process_data(Original, Temp)
    write_to_file(FullDict)

main()