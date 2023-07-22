#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
#Problem Description
#Program to convert  text sentence in CamelCase format .
#Examples:
 #1] INPUT: "this is camel case"
    #OUTPUT "thisIsCamelCase"
 #2] INPUT: "Hi Atul here"
  # OUTPUT: "hiAtulHere"
   #Example Explanation

# Main Function
def main():
    N = (int(input("No of TestCases : ")))
    for _ in range(N):
        S = input("Enter a sentence : ")
        print("Original: {}".format(S))
        S = S.title() #Convert the first only the first letter of a word to uppercase and rest all to lowercase
        S = S.split() #Generates a list of words
        S[0] = S[0].lower()
        S = "".join(S) #Joins all the words
        print("Camel Casing : {}".format(S))
        print()

if __name__=="__main__":
    main()