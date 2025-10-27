/* Practice:

  Declare a struct "vehicle" with the following attributes:
  -brand, a 20 char array to store the maker info ("ford, honda, vw, etc")
  -year, an integer to store its model year (1999, 2020, 2025 etc)
  
  Use a typedef whenever possible
  ej.  "Honda", 2001

  In the main loop create an array of 4 vehicles variables.
  Create a function "vehicle_set" that receives the address of a vehicle struct
  and sets their properties accordingly.
  
  Initialize vehicle 1, without using pointers, but ask the data to the user
  Intialize vehicles 2, 3 and 4 using your newly created function like this:

  ex.  vehicle_set(car_ptr, "Ford", 2020);
       vehicle_set(&vehicle_array[3], name1var, year);

  PRACTICE as many combinations or way to pass your vehicles to your function
  Will it be a good idea to verify and print the contents after each vehicle_set?
  DEBUG your code.

  Feel free to either use preset values, or ask again the user if you want.

  Finally, create a function called "print_lot" that receives the entire vehicle 
  array and WITHOUT USING BRACKETS, prints in the screen all the cars. 
  The same function should return which car is the Oldest of the lot, to do this:
     -return, as an integer the year
     -write the name of the car, in an output buffer passed by the user.
  
  How do you determine how many vehicles to print? What else besides the array
  do you need? Remember this are not NULL terminated strings.

  oldest_year  print_lot ( IN : Vehicle Array,   OUT : Oldest vehicle name);

  Expected usage:
    
     1: char oldest_buffer[20];
     2: int oldest_year = print_lot (YOUR_VECHILE_ARRAY, oldest_buffer);

     After executing line 2, oldest_year will be populated and oldest_buffer 
     will contain the name

  Use NULL pointer validations whenever possible to prevent the user causing a 
  SEGMENTATION FAULT

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


   typedef struct vehicle{
   char brand[20];
   int year;
   } vehicle;

void vehicle_set(vehicle* car_ptr,char* name ,int year){
   strcpy(car_ptr->brand,name);
   car_ptr->year = year;
}

void print_lot(vehicle * car_ptr, int len){

   for(int i = 0; i<len;i++){
      printf("Brand: %s, year %d\n", (car_ptr+i)->brand, (car_ptr+i)->year);
   }

};

int oldest_year(vehicle * car_ptr, int len){

   int old = 9999;
   char oldest_buffer[20];

   for (int i = 0; i<len; i++){
      if ((car_ptr+i)->year < old) {
         old= (car_ptr+i)->year;
         strcpy(oldest_buffer,(car_ptr+i)->brand);
      }
   }

   printf("Oldest car: %s \n",oldest_buffer);
   return old;

};

int main(){
   
   vehicle vehicle_array [4];

   vehicle *car_ptr = vehicle_array;

   vehicle v1;
   strcpy(v1.brand,"Ford");
   v1.year = 2001; 

   *car_ptr = v1;

   int len = sizeof(vehicle_array)/sizeof(vehicle_array[0]);

   for (int i = 1; i<len; i++){
      char marca[20];
      char * ptr_marca = marca;
      int anio;

      printf("Escribe la marca del auto %d: ",i);
      scanf("%s", marca);
      fflush(stdout);
   


      printf("Escribe el anio del auto %d: ",i);
      scanf("%d", &anio);
      fflush(stdout);
    

      vehicle_set(car_ptr+i,ptr_marca,anio);

   }

   print_lot(car_ptr,len);
   oldest_year(car_ptr,len);

   return 0;
}
