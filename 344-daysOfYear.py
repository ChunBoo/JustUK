"""_summary_
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD,
   return the day number of the year.
Example 1:
Input: date = “2019-01-09”
Output: 9
Explanation: Given date is the 9th day of the year in 2019.

Example 2:
Input: date = “2019-02-10”
Output: 41

Example 3:
Input: date = “2003-03-01”
Output: 60

Example 4:
Input: date = “2004-03-01”
Output: 61

Constraints:
date.length == 10
date[4] == date[7] == ‘-‘, and all other date[i]’s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
"""

def daysInYear(year):
    year,month,date=year.split("-")
    isLeapYear= 1 if (int(year))%4==0 else 0
    daysOfFeb=29 if isLeapYear else 28
    dayDict={1:31,2:daysOfFeb,3:31,4:30,5:31,6:30,7:31,8:31,9:30,10:31,11:30,12:31}
    days=0
    for k,v in dayDict.items():
        if(k<int(month)):
            days+=v
            
    return days+int(date)


# date="2004-03-01"
date="2003-03-01"
print(daysInYear(date))
    