#import libaries
import csv
import json

#variables
AllTitles = []
DesTitles = []
Movies = []
Shows = []
FileName = "netflix_titles.csv"

#name: OpenFile()
#param - N/a
#return N/a
#purpose: opens the file and organizes the data inside using csv libary
def OpenFile():
    with open(FileName, newline='') as CsvFile:
        reader = csv.DictReader(CsvFile)
        for row in reader:
            if(row["type"] == "TV Show"):
                id = row["show_id"]
                title = row["title"]
                director = row["director"]
                country = row["country"]
                date_added = row["date_added"]
                duration = row["duration"]
                Netflix = {
                    "show_id":id,
                    "title":title,
                    "director":director,
                    "country":country,
                    "date_added":date_added,
                    "duration":duration
                }
                AllTitles.append(Netflix)
    Sort()

#name: Sort()
#param - N/a
#return N/a
#purpose: organizesd the data in the array in decreasing order
def Sort():
    for i in range(len(AllTitles)):
        for j in range(len(AllTitles)):
            if(AllTitles[j]["duration"] > AllTitles[i]["duration"]):
                temp = AllTitles[j]
                AllTitles[j] = AllTitles[i]
                AllTitles[i] = temp
    CountOne = len(AllTitles)-1
    while(CountOne != -1):
        print(CountOne)
        DesTitles.append(AllTitles[CountOne])
        CountOne -= 1
    WriteFile()

#name: WriteFile()
#param - N/a
#return N/a
#purpose: Write data to json file using json libary
def WriteFile():
    with open("netflix_titles.json",'w') as JsonFile:
        json.dump(DesTitles, JsonFile, indent=4)

OpenFile()