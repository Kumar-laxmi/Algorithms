#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
#Problem Description
#Program to convert  text sentence in CamelCase format .
#Examples:
 #1] INPUT: "this is camel case"
    #OUTPUT "thisIsCamelCase"
 #2] INPUT: "Hi Atul here"
  # OUTPUT: "HiAtulHere"
   #Example Explanation
def convert(s):      # Function to remove spaces and convert into camel case
    if(len(s) == 0):
        return
    s1 = ''
    s1 += s[0].upper()   #check for spaces in the sentence
    for i in range(1, len(s)):
        if (s[i] == ' '):
            s1 += s[i + 1].upper()     #conversion into upper case
            i += 1
        elif(s[i - 1] != ' '):         #If not space, copy character
            s1 += s[i]
    print(s1)    
# Main Function
def main():
    s = "Hii this is camel case"    #new string will be reduced by the size of spaces in the original string
    convert(s)     
if __name__=="__main__":
    main()