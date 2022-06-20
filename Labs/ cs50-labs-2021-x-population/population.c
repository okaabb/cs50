#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    
    int start = get_int("enter number of starting llamas \n");
    
    while(start < 9) {
        
        start = get_int("enter number greater than 9 \n");
    }
    
    // TODO: Prompt for end size
    
    int end = get_int("enter number of ending llamas \n");
    
    while(end < start){
        
        end = get_int("enter number greater than the start \n");
    }
    
    // TODO: Calculate number of years until we reach threshold
    
    int dead = 0, alive = 0, current = start , years = 0;
    
    while(current < end){ 
        
        dead = current / 4.0;
        alive = current / 3.0;
        current += alive;
        current -= dead;
        years++;
    }
    
    // TODO: Print number of years

    printf("Start size: %i\nEnd size: %i\nYears: %i\n", start, end, years);

}