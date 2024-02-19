# -*- coding: utf-8 -*-
import time
import sys

#
# Complete the 'climbingLeaderboard' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY ranked
#  2. INTEGER_ARRAY player
#

def displayTime(fieldName):

    # To see all display fields available from time.localtime()
    # converted via time.strftime(), uncomment the code below
    # Example: startTime = time.struct_time(tm_year=2024, tm_mon=1,
    # tm_mday=18, tm_hour=14, tm_min=25, tm_sec=35, tm_wday=3,
    # tm_yday=18, tm_isdst=0)
    # %a Locale’s abbreviated weekday name.
    # %A Locale’s full weekday name.
    # %b Locale’s abbreviated month name.
    # %B Locale’s full month name.
    # %c Locale’s appropriate date and time representation.
    # %d Day of the month as a decimal number [01,31].
    # %H Hour (24-hour clock) as a decimal number [00,23].
    # %I Hour (12-hour clock) as a decimal number [01,12].
    # %j Day of the year as a decimal number [001,366].
    # %m Month as a decimal number [01,12].
    # %M Minute as a decimal number [00,59].
    # %p Locale’s equivalent of either AM or PM.
    # %S Second as a decimal number [00,61].
    # %U Week number of the year (Sunday as the first day of the week) as a decimal number [00,53]. All days in a new year preceding the first Sunday are considered to be in week 0.
    # %w Weekday as a decimal number [0(Sunday),6].
    # %W Week number of the year (Monday as the first day of the week) as a decimal number [00,53]. All days in a new year preceding the first Monday are considered to be in week 0.
    # %x Locale’s appropriate date representation.
    # %X Locale’s appropriate time representation.
    # %y Year without century as a decimal number [00,99].
    # %Y Year with century as a decimal number.
    # %z Time zone offset indicating a positive or negative time difference from UTC/GMT of the form +HHMM or -HHMM, where H represents decimal hour digits and M represents decimal minute digits [-23:59, +23:59]. 1
    # %Z Time zone name (no characters if no time zone exists). Deprecated. 1
    # %% A literal '%' character.
    # print(tupleT)
    # timeStr = time.strftime("%H:%M:%S", tupleT)
    # print("{} = {}".format(fieldName, timeStr))
    
    # The followng function directly takes the output of time.localtime()
    # or time.gmtime() and displays in the following format:
    # startTime = Thu Jan 18 15:52:29 2024
    # timeStr = time.asctime(tupleT)
    # print("{} = {}".format(fieldName, timeStr))
    
    # Or, you can call it without argument, which defaults to localtime()
    # timeStr = time.asctime()
    # startTime = Thu Jan 18 15:52:29 2024   
     
    # timeStr = time.asctime(time.gmtime(time.time()))
    # print("{} = {}".format(fieldName, timeStr))
    # startTime = Fri Jan 19 00:30:52 2024

    # timeStr = time.asctime(time.localtime(time.time()))
    # print("{} = {}".format(fieldName, timeStr))
    # startTime = Thu Jan 18 16:30:52 2024

    startTime = time.time()
    tupleT = time.localtime(int(round(startTime)))
    # timeStr = time.asctime(tupleT)
    # print("{} = {}".format(fieldName, timeStr))
        
    timeStr = time.strftime("%H:%M:%S", tupleT)
    print("{} = {}".format(fieldName, timeStr))

if __name__ == '__main__':

    displayTime("startTime")
