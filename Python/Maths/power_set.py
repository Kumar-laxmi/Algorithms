# @author : Muhammad Abdullahi

"""
In set theory, the power set (or power set) of a Set A is defined
as the set of all subsets of the Set A including the Set itself
and the null or empty set. It is denoted by P(A). 
Basically, this set is the combination of all subsets 
including null set, of a given set.
the power_set function below 
Return the power set of the original set.
"""

original_set = ["a","b","c"]

def power_set(original_set: list):  
    #convertiing each term in original element to str,
    #To take care of int list  
    original_set = [str(x) for x in original_set]
    power_set = [[]]
    n = len(original_set)
    loop_count = (2**n)

    for i in range(1, loop_count):
        subset = []
        # convertting loop_count to binary
        count_bin = bin(i)
        #removes 0b from the binary
        count_bin = count_bin.split('b')
        count_bin_list = list(count_bin[1])
        set_combination= ''
        #Iterating through the binary
        for j in range(-len(count_bin_list), 0, 1):
            #checking if the current bit position == 1
            if count_bin_list[j] == '1' :
                set_combination+= original_set[j]
        #add 
        subset.append(set_combination)
        #  
        power_set.append(subset)    
    return(power_set)

print(power_set(original_set))




