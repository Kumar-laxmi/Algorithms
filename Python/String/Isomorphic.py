#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
def isIsomorphic(s: str, t: str) -> bool:
    # Create two dictionaries to store the mappings between s and t, and t and s
    s_to_t = {}
    t_to_s = {}
    # Iterate through each character in the strings and compare their corresponding mappings
    for i in range(len(s)):
        # If there is a mismatch in either of the dictionaries, the strings are not isomorphic
        if s[i] in s_to_t and s_to_t[s[i]] != t[i]:
            return False
        if t[i] in t_to_s and t_to_s[t[i]] != s[i]:
            return False
        # Add the new mappings to both dictionaries
        s_to_t[s[i]] = t[i]
        t_to_s[t[i]] = s[i]
    # If we reach the end of the strings without finding a mismatch, the strings are isomorphic
    return True
if __name__ == '__main__':
    # Take input from the user
    s = input("Enter the first string: ")
    t = input("Enter the second string: ")
    # Check if the strings are isomorphic and print the result
    if isIsomorphic(s, t):
        print("The strings are isomorphic.")
    else:
        print("The strings are not isomorphic.")