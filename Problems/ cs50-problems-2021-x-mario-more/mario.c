#include <stdio.h>
#include <cs50.h>

int main(void){
    //asking for height
    
    int height = get_int("enter height: \n");
    
    while(height <= 0 || height > 8){
        
        height = get_int("enter positive height: \n");
        
    }
    
    //printing building
    
    for(int i = 1 ; i <= height ; i++){
         
        int spaces = height - i; 
        
        // printing spaces before blocks 
        
        for(int j = 1; j <= spaces ; j++){
            printf(" ");
        }
        
        // print left blocks then a space then right blocks
        
        for(int hashes = 1; hashes<= i; hashes++){
            printf("#");
        }
        
        printf("  ");
        
        for(int hashes = 1; hashes<= i; hashes++){
            printf("#");
        }
        
        printf("\n");
        
    }
    
}