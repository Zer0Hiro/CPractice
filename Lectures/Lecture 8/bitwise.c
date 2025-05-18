// MASK
unsigned int unity = 1, res;

res = number TypeOfMask mask; // Will use Mask on number

/* TYPES OF MASK

& - AND Save all positions with 1 and puts 0 elsewhere
Example: num  = 1100101
         mask = 0000100 
         // Answer = num & mask = 100

| - OR Turns on the positions with mask 1
Example: num  = 1100001
         mask = 0000100  
        // Answer = num | mask = 1100101

~ - NOT Swaps all 1 to 0 and vice versa
Example: num  = 11101111
         mask = ~(00101000) = 11010111  
        // Answer = num & mask = 11000111 // Turned OFF bit 3 and 5

^ - XOR Swaps chosen by mask bits like a normal XOR (if number is same return 0 else 1)
Example: num  = 10101010
         mask = 00100100
        // Answer = num ^ mask = 10001110 


 

         
*/