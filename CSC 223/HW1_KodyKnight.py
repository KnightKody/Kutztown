#--------------------------------------#
#Author: Kody Knight
#Major: Computer Science
#Creation date: 2/9/2022
#Due Date: 2/11/2022
#Course: Advanced programming
#Prof name: P. earl
#Assignment: uno (#1)
#Filename: hw1_payroll.py
#purpose: takes in name, hours total, and wage. spits out total money earned, taxes, and owned
#--------------------------------------#
StateTax = .0307
FICA = .0886
Count = 0
information = []
Count = 0

#-----------------------------------#
#Function name: Calculations
#Description: Calculate all nesseary values like withholding, grosspay, and netpay
#Parameters: Total hours, and Earnings per hours
#Returns nothing but print staments
#-----------------------------------#
def Calculations(hours,EPH):
    GrossPay = int(hours)*int(EPH)
    print("The Employee's Gross pay is $" + str(round(GrossPay,2)))
    Federal_Tax = .25
    if(GrossPay < 5000.00):
        Federal_Tax = .15
    WithHolding = (GrossPay*Federal_Tax)+(GrossPay*StateTax)+(GrossPay*FICA)
    print("The Employee's WithHolding amount is $" + str(round(WithHolding,2)))
    print("There Netpay is $" + str(round(GrossPay - WithHolding,2)))
    
#-----------------------------------#
#Function name: Output
#Description: Outputs employee name
#Parameters: array of information, and number of runs from while loop
#Returns nothing but print stament
#-----------------------------------#
def Output(info,num):
    i = 0
    while(num*3 > i):
       print("Employees name: " + info[i] + ".")
       Calculations(info[i+1],info[i+2])
       i = i+3
       print()



while(True):
    Employee = input("What is the employee's name? ")

    if(Employee == "done"):
        print()
        break
    print("thier name is " + Employee+".")
    print()


    Hour = 0
    for i in range(5):
        Hour += int(input("How many hours did you work on day " + str(i+1) + ". "))

    print(Employee + ", has worked " + str(Hour) + " hours.")
    print()

    Wages = float(input("What is your hourly wage? "))
    print(Employee + ", worked " + str(Hour) + " hours, at a pay of $"+ str(Wages) + " per hour.")
    print()
    
    information.append(Employee)
    information.append(Hour)
    information.append(Wages)
    Count = Count +1
    print()

Output(information,Count)
