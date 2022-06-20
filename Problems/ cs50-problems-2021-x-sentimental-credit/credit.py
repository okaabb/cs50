from cs50 import get_int


def main():
    card = get_int("Enter card number: ")
    length = len(str(card))
    flag = 0
    visa = 0
    mc = 0
    ax = 0
    if length < 13 or length > 16:
        flag = 1
        
    else:
        
        if length == 13 or length == 14:
            
            temp = card
            while len(str(temp)) != 1:
                temp = int(temp / 10)
                
            if temp == 4:
                returnType = counting(card)
                
                if returnType == 1:
                    visa = 1
                else: 
                    flag = 1
                
            else: 
                flag = 1
            
        elif length == 15:
            
            temp = card
            while len(str(temp)) != 2:
                temp = int(temp / 10)
                
            firstTemp = int(temp / 10)
            if temp == 34 or temp == 37 or firstTemp == 4:
                returnType = counting(card)
                if returnType == 1:
                    if firstTemp == 4:
                        visa = 1
                    else:
                        ax = 1
                else: 
                    flag = 1
            else: 
                flag = 1
            
        else:
            
            temp = card
            while len(str(temp)) != 2:
                temp = int(temp / 10)
                
            firstTemp = int(temp / 10)
            
            if temp == 51 or temp == 52 or temp == 53 or temp == 54 or temp == 55 or firstTemp == 4:
                returnType = counting(card)
                if returnType == 1:
                    if firstTemp == 4:
                        visa = 1
                    else:
                        mc = 1
                else:
                    flag = 1
              
            else:
                flag = 1
    if flag == 1:
        print("INVALID")
    elif visa == 1:
        print("VISA")
    elif ax == 1:
        print("AMEX")
    else:
        print("MASTERCARD")


def counting(cardNum):
    cnt = 1
    total = 0
    
    while cardNum != 0:
        n = cardNum % 10
        
        if cnt % 2 == 0:
            n *= 2
            
        while n != 0:
            total += (n % 10)
            n = int(n/10)
            
        cnt += 1
        cardNum = int(cardNum / 10)    

    if total % 10 == 0:
        return 1
    else:
        return 0
    
    
main()