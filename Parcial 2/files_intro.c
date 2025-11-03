#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* I/O File Reading:

Reading files always requires a file handler. This is a pointer of type FILE.

FILE * fp;
fp = fopen ("file.txt", "w+");

rewnid (file_ptr) te regresa al inicio del archivo

Once we have our FILE pointer, we must open the file in the correct read/write mode.
After using the file, we must close it with fclose().

The modes supported by fopen are:
        for text                         | for binary mode
r   read text                            | rb
w   write text                           | wb
a   "append" writes at the end of text   | ab
r+  read and write (file must exist)     | r+b or rb+
w+  creates an empty file for read/write | w+b or wb+
a+  opens the file for read and append   | a+b or wb+


Binary
Two functions to consider:​

READ:​

fread, reads from file, count number of elements of size size. The read contents are put in ptr. Returns the number of bytes read.​

size_t fread(void *ptr, size_t size, size_t count, FILE *file)​

​

WRITE​

fwrite, writes into file the data stored in ptr, you need to specify its size and how many elements they are.​

size_t fwrite(void *ptr, size_t size, size_t count, FILE *file)

  ptr is the pointer to the variable that will catch all the data we read. Its type and size must match what we read; ptr  also needs to point to a valid address that contain the space to store the data. Meaning it WONT allocate memory for it. Must not be NULL.​

  size is the size of the data we want to read in bytes​

  count is the number of consecutive elements we want to read, this is useful if ptr is an array.​

  file is the pointer to the file in question, must be open before for reading​

  Reuturns 0 if we get to the EOF

----------------
To write data into a binary file:​

	size_t fwrite(void *ptr, size_t size, size_t count, FILE *file)​

ptr is a pointer to the data we want to write… it can be anything: variable, struct, union, array etc. ​

size  is the size of the data in bytes we want to write: sizeof.​

count the number of consecutive things we want to write (if ptr is an array).​

file pointer to the file ​

Returns the number of items written succesfully.
----------
If you want to read and write at the same time over a text file or binary file (a+ or ab+) its important to be able to move the cursor at will at the desired position.​

With the next function we can MOVE the pointer at any position we want, a number certain of bytes (offset) starting from a reference point whence​

​

	int fseek(FILE *file, long int offset, int whence)​

​

Returns 0 if movign the cursor was succesful.​

whence: can be:	 ​

	SEEK_SET (start of file), SEEK_CUR (current position),  SEEK_END(end of file).​

​

PS. You can move negative positions too. 

Option 1 : from the CURRENT position, seek back size of struct. (move negative bytes)​

	fseek(f, -sizeof(MyStruct), SEEK_CUR);​

Option 2. If we know where the struct start, we can move that many bytes from the start:​

	fseek(f, i * sizeof(MyStruct), SEEK_SET);​



*/

typedef struct student
{
  char name[20];
  int grade;
} student;

student s_arr[10];
int num;

void create_students()
{
  char name[50];
  int i, ret;

  printf("Enter number of students: ");
  ret = scanf("%d", &num);

  for(i = 0; i < num; ++i)
  {
    printf("For student%d\nEnter name: ", i+1);
    ret = scanf("%s", s_arr[i].name);

    printf("Enter grade: ");
    ret = scanf("%d", &s_arr[i].grade);

    printf("\tCreated student Name: %s with Grade %d\n", 
      s_arr[i].name, s_arr[i].grade);
  }
}

/* Example of writing with fprintf ... this is one of the easiest
ways to write to a text file. It works just like printf, 
but instead of sending output to the screen, it writes to a file.

fputc can send character by character. (honestly, not very useful)
*/
void fprintf_example()
{
  int i, ret;
  FILE *fptr;

  //w = write
  //a = append
  //Try switching between w and a ....
  //"w" will overwrite the file, "a" will move the cursor
  //to the end and write there.

  //absolute path / relative
  fptr = fopen("files_student.txt", "a");
  if(fptr == NULL)
  {
    printf("Error!");
    exit(1);
  }

  fprintf(fptr, "Students=%d\n", num); 
  for(i = 0; i < num; ++i)
  {
    printf("Writing... : \n");
    fprintf(fptr, "Name: %s\nGrade=%d\n", 
            s_arr[i].name, s_arr[i].grade);
 }
 fclose(fptr);
}



/* Example of reading from text, in this function we see the use of:
   fgets = retrieves an entire line of text at once until it finds
           a newline.

   We can put fgets in a loop as long as it does not return NULL,
   and each call will bring a complete line. The buffer receiving
   the read data must be large enough, otherwise, it will read
   only up to the buffer size.

   Try changing the size of name_r[20] to name_r[5].
*/

void fgets_example()
{
  char buffer[500];
  FILE *fptr;
  char * cret;

  printf("I am going to read ... \n");
  fptr = (fopen("files_student.txt", "r"));
  cret = fgets(buffer, sizeof(buffer), fptr);   

  printf("the first line was: %s\n", buffer);

  getchar();
  while(fgets(buffer, sizeof(buffer), fptr) != NULL)
  {
    printf("the line contains: %s", buffer);
    getchar();
  }
  fclose(fptr);
}

void fgetc_example()
{
  char c;
  FILE *fptr;
  printf("I am going to read ... \n");
  fptr = fopen("files_student.txt", "r");
  if(fptr == NULL)
  {
    printf("File not found! Error!");
    exit(1);
  }
  
  do
  {
    c = fgetc(fptr);
    printf("read: %c\n", c);
  }while (c != EOF); //END OF FILE
  fclose(fptr);
}

void fwrite_example()
{
  FILE *fptr;
  fptr = fopen("student.data", "wb");
          //3
  fwrite(&num, sizeof(int), 1, fptr);
  for(int i=0; i<num; i++)
  {
    fwrite(&s_arr[i], sizeof(student), 1, fptr);
  }
  fclose(fptr);
}

void fread_example()
{
  FILE *fptr;
  fptr = fopen("student.data", "rb");
  int num_elem, ret;
  student s;

  ret = fread(&num_elem, sizeof(int), 1, fptr);

  printf("Found %d students... \n", num_elem);

  for(int i = 0; i < num_elem; i++)
  {
    ret = fread(&s, sizeof(student), 1, fptr);
    printf("\tFound 1 student named %s with %d\n", s.name, s.grade);
  }
  /* NOTE, here we have only read the students, we reused the variable
  "s" to read them, but we have not saved them anywhere */

  fclose(fptr);
}


void fscanf_example()
{
  FILE *fptr;    //PATH
  fptr = fopen("fscanf_ejemplo.txt", "r");

  char building;
  int capacity;
  char ret;
  int count = 0;

  while((ret = fscanf (fptr, "Building %c %d students\n", 
                &building, &capacity))  !=  EOF)
  {
    count++;
    printf("%c=%d\n", building, capacity);
  };
  printf("Total of %d buildings found\n", count);
  fclose(fptr);
}

int main()
{
  int opc, ret;
  while(1)
  {
    printf("0) Create students to play with\n"
           "1) Write Students to plain text file \n"
           "2) Read from plain text file\n"
           "3) Read char by char example\n"
           "4) Write students to Binary file\n"
           "5) Read Binary file and extract students\n"
           "6) fscanf example\n");
    
    ret = scanf("%d", &opc);
    switch(opc)
    {
      case 0: create_students();
      break;
      case 1: fprintf_example();
      break;
      case 2: fgets_example();
      break;
      case 3: fgetc_example();
      break;
      case 4: fwrite_example();
      break;
      case 5: fread_example();
      break;
      case 6: fscanf_example();
      break;
    }
  }
  return 0;
}