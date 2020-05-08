# include <stdio.h> // I/O operations
# include <string.h> // string operations

// Display the word addresses and integer contents of len slots of given array
void display_array(char* name, // string name for array
                   int* array, // array of ints is pointer to (word address of) int in 0th slot
                   int len) // need to pass length of array separately
{  
  int i = 0; // initialize index to 0
  int* end = array + len; // end is address of word after last array slot
  for (; array < end; array++) 
  { // Loop iterates through word addresses of array slots.
    // Incrementing adds 4 to the address b/c array is int pointer
    printf("%x %s[%i]: %i (int);\t%x (hex)\n", array, name, i, *array, *array);
      // *array is contents of current slot
    i++; // increment index in sync with address of next slot
  } 
}

// Display the byte addresses and character contents of all slots in given string
void display_chars(char* str) // str is pointer to char in 0th slot
{ 
  while (*str != 0) // Loop while terminating null byte hasn’t been reached
  { 
    printf("%x: %c (char), %x (hex)\n", str, *str, *str);
    str++; // Incrementing adds 1 to address b/c str is a char pointer
  } 
}

// Return the maximum of two integers
int max (int a, int b) { if (a > b) return a; else return b; }

// Program entry point
int main (int argn, char** argv) // argn and argv are ignored in this program
{ 
  int a[2] = {1,2}; // Allocate integer arrays on stack
  int b[3] = {3,4,5};
  int c[4] = {6,7,8,9};
  char command[8]; // Stack space allocated for command string character buffer.
                   // No one would type more than 8 characters, would they? ;-)
  int index; // Stack space allocated for "setb" command index
  int value; // Stack space allocated for "setb" command value

  // Read/eval/print loop: read a command from user, perform action, and repeat
  while (1) { // 1 is how "true" is written in C; "infinite" loop exited via "quit" command
    printf("Enter one of these three commands: display, setb, quit:\n> "); // Prompt for command
    scanf("%s", &command); // Read command into character buffer
    if (strcmp(command,"display")==0) // strcmp compares strings; 0 result means they’re equal
    { 
      // Display the addresses and contents of slots in all arrays
      display_array("a", a, 2);
      display_array("b", b, 3);
      display_array("c", c, 4);
    } 
    else if (strcmp(command,"setb")==0) // Change slots in array b
    { 
      printf("Choose an index for array b: "); // Prompt for index of array b to change
      scanf("%i", &index); // Store it into index variable
      index = max(index,0); // Don’t allow negative indices; convert negative index to 0
      printf("Choose a new value for b[%i]: ", index); // Prompt for new value at index
      scanf("%i", &value); // Store it into value variable
      b[index] = value; // Change the indexth slot of b to new value
    } 
    else if (strcmp(command,"quit")==0) 
    {
      return 0; // Exit loop by returning from main function
    } 
    else // Case for unrecognized commands
    { 
      printf("\"%s\" is not a recognized command.\n");
      display_chars(command);  // Display the addresses and contents of characters in command
      printf("Try again.\n");
    } 
  }
}