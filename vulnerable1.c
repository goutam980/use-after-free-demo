  // vulnerable.c – Vulnerable Version (Legacy)
   #include <stdio.h>
   #include <stdlib.h>

   void vulnerable_function() {
       int *ptr = malloc(sizeof(int) * 10);
       if (ptr == NULL) {
           perror("malloc failed");
           exit(1);
       }
       ptr[0] = 42;
       printf("Value before free: %d\n", ptr[0]);

       free(ptr);
       // BUG: Accessing freed memory causes use-after-free error
       printf("Value after free: %d\n", ptr[0]);
   }

   int main(void) {
       vulnerable_function();
       return 0;
   }
