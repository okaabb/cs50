#include <stdio.h>
#include <cs50.h>

int main(void){

    //asking user for number
    
    long long number=get_long("Number: \n");
    
    //variables
    
    int cnt = 1, type = 0;
    long long total_sum, sum_product = 0, sum_digits = 0;
    
    //getting each digit in the number by dividing by 10 until it reaches 0
    
    while(number != 0){
        
        // checking if the number consists of 2 digits only to detect card type
        
        if(number / 100 == 0 && type == 0)
           type = number;

        // if cnt: odd dont multiply but sum else multiply
        
        if(cnt % 2 != 0){ 
            
            // add to the sum the last digit
            
            sum_digits += (number % 10);
            
        }
        else {
            //assign last digit in a variable
            
            int digit = (number % 10);
            
            // multiply digit by 2 and loop through it to add its digits
            
            digit *= 2;
            
            while(digit != 0){
                sum_product += (digit % 10);
                digit /= 10;
            }
            
        }
        
        // constantly removing last digit of the number
        
        number /= 10; 
        cnt++;
    }
    
    total_sum = sum_product + sum_digits;
     
     //if it ends with 0 valid else invalid
     
     if(total_sum % 10 == 0 && cnt > 12) { 
         
         if( type % 100 == 34 || type % 100 == 37)
           printf("AMEX\n");
           
        else if( type % 100 == 51 || type % 100 == 52 || type % 100 == 53 || type % 100 == 54 || type %100 == 55)
                    printf("MASTERCARD\n");
        else {
            type /= 10;
            if(type % 10 == 4)
                       printf("VISA\n");
            else printf("INVALID\n");

        }

     }
     else printf("INVALID\n");
    
}