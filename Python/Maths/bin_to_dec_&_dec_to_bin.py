def main ():
    while True :
        print("\n1) Binary to decimal \t2)Decimal to Binary  \t3)Exit") #The list of choices user can enter
        Enter = input("\nEnter your choice : ")
    
        if Enter == '1':
          Binary = input("\nEnter a binary number: ")
          Binary_To_Decimal( Binary)  #This function returns decimal equivalent of given binary number 
        
        elif Enter =='2':
          Decimal = input("\nEnter a decimal number : ")
          Decimal_To_Binary(int(Decimal))  #This function returns binary equivalent of given decimal number 
          
        elif Enter == '3':
            break
          
        else : 
          print("\nEnter valid input")
        
        
def Binary_To_Decimal(Binary):
    decimal = int(Binary, 2)  #Built in "int()" function to convert binary to decimal , 2 is taken as the base of the number for binary
    print("\nThe Decimal equivalent of" " " + str(Binary) + " is: ", decimal)
    

def Decimal_To_Binary(Decimal):
    binary = bin(Decimal)[2:] # "bin()" function to convert decimal to binary
    print("\nThe Binary equivalent of" " "+ str(Decimal) + " is: ", binary)
    


if __name__ == "__main__":
    main()
    

    
