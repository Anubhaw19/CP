from datetime import datetime 
hackathons = ['LocalHackDay', 'Hackatron', 'Hack with CW','FallFest','SIH']
# dates =  ["23 Jun 2018", "2 Dec 2017", "11 Jun 2018","01 Jan 2019", "10 Jul 2016", "01 Jan 2007"] 
hackathons.sort()
# dates.sort(key = lambda date: datetime.strptime(date, '%d %b %Y'))
print(hackathons)
# print(dates) 

dict1 = {"LocalHackDay": "30 Dec 2021",
         "Hackatron": "2 Dec 2021",
         "Hack with CW": "11 Jun 2021",
         "FallFest":"01 Jan 2021",
         "SIH":"10 Jul 2021"}
sorted_dict = {}
sorted_keys = sorted(dict1, key=dict1.get) 

for w in sorted_keys:
    sorted_dict[w] = dict1[w]

print(sorted_dict)