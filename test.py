# By Websten from forums
#
# Given your birthday and the current date, calculate your age in days. 
# Account for leap days. 
#
# Assume that the birthday and current date are correct dates (and no 
# time travel). 
#


def daysinyear (year):
    if year % 4 == 0:
        days = 366
        if year % 100 == 0 and year % 400 !=0:
            days = 365
            return days
        return days
    days = 365
    return days

def daysbwwholeyears(year1,year2):
    i=year1
    days=0
    while i<=year2:
        days = daysinyear(i) + days
        i=i+1
    return days
    

def daystodate (month,day,year):
    days = summonth (month - 1,year) + day
    return days
    
def summonth (month,year):#is mahine ke end tak kitne din ho chuke
    if year % 4 == 0:
        daysinmonth = [31,29,31,30,31,30,31,31,30,31,30,31]
        days = 0
        i=0
        while i< month:
            days = days + daysinmonth[i]
            i=i+1
        return days
    
    daysinmonth = [31,28,31,30,31,30,31,31,30,31,30,31]
    days = 0
    i=0
    while i< month:
        days = days + daysinmonth[i]
        i=i+1
    return days
    
def daysBetweenDates(year1, month1, day1, year2, month2, day2):
    if year2 - year1 ==0:
        days = daystodate(month2,day2,year2) - daystodate(month1,day1,year1)
        return days
        
    if year2 - year1 ==1:
        days = daysinyear(year1) - daystodate(month1,day1,year1) + daystodate(month2,day2,year2)
        return days
    

    days = daysbwwholeyears(year1+1,year2-1) + daysinyear(year1) - daystodate(month1,day1,year1) + daystodate(month2,day2,year2)
    return days

# Test routine

def test():
    test_cases = [((2012,1,1,2012,2,28), 58), 
                  ((2012,1,1,2012,3,1), 60),
                  ((2011,6,30,2012,6,30), 366),
                  ((2011,1,1,2012,8,8), 585 ),
                  ((1900,1,1,1999,12,31), 36523)]
    for (args, answer) in test_cases:
        result = daysBetweenDates(*args)
        if result != answer:
            print "Test with data:", args, "failed"
        else:
            print "Test case passed!"

test()
