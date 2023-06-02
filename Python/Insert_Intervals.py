#Name: Aryaman Singh
#Repository name: Algorithms

#Problem Statement: Given a sorted array of non-overlapping intervals where intervals[i]=[starti,endi] and a new interval=[start,end], insert the new interval 
# into the array while maintaining the sort order and ensuring that there are no overlapping intervals. Return the updated array after the insertion.

#Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
#Output: [[1,2],[3,10],[12,16]]


def insert(intervals, newInterval):
    
    # initialize an empty list mergedIntervals to store the merged intervals after inserting the new Interval
    mergedIntervals = []
    n = len(intervals)

    # i is set to 0 as a counter variable for the loops.
    i = 0

    # This while loop iterates over the intervals that come before the new interval.
    while i < n and intervals[i][1] < newInterval[0]:
        mergedIntervals.append(intervals[i])
        i += 1

    # This while loop merges the overlapping intervals.
    while i < n and intervals[i][0] <= newInterval[1]:
        newInterval[0] = min(newInterval[0], intervals[i][0])
        newInterval[1] = max(newInterval[1], intervals[i][1])
        i += 1

    # it adds the final merged interval (new interval) to the mergedIntervals list.
    mergedIntervals.append(newInterval)

    # This while loop adds the remaining intervals that come after the new interval to the mergedIntervals list.
    while i < n:
        mergedIntervals.append(intervals[i])
        i += 1

    return mergedIntervals

# Main function
intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]]
newInterval = [4, 8]

final = insert(intervals, newInterval)

for interval in final:
    print(interval)
