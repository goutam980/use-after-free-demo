// vulnerable.c – Fixed Version
   #include <stdio.h>
   #include <stdlib.h>

   void fixed_function() {
       int *ptr = malloc(sizeof(int) * 10);
       if (ptr == NULL) {
           perror("malloc failed");
           exit(1);
       }
       ptr[0] = 42;
       printf("Value before free: %d\n", ptr[0]);

       free(ptr);
       ptr = NULL;  // Fix: reset pointer after freeing memory
       printf("Memory freed and pointer reset.\n");
   }

   int main(void) {
       fixed_function();
       return 0;
   }
