

#include <stdio.h>
#include <string.h>
#include <ctype.h>
// header files
// ************************************






void checkForexistance (FILE * f){
  if (f == NULL)
    {
      printf ("file not found\n");
      printf ("solutions:\n 1. Try entering the correct name");
      printf ("\n 2.Or create the file");
    }
}



int main ()
{
// variable declaration
  FILE *f;
  char test[100];
  char login[3];
  int mode;
  char fileName[100], extention[5] = ".txt";
  int i = 0;

// getting the patient details
  int n_of_record;
  int patientId;
  int age;
  float bloodSugarLevel, bloodPressureLevel;
  int password = 123456;
  int enteredPassword;
// *********************************************

/*geting the fileName*/

/*****************************
 * now we are going to implement the login part
 * hospital Login: hl;
 * patient login: pl;
************************/
    printf("Login as hospital: hl, patient:pl: ");
    scanf("%s",login);
    printf("Enter the date in DDMMYYYY:\n");
    scanf("%s",fileName);
//   *************************************************

 if(strcmp("hl",login) == 0){
     
    
     printf("password: ");
     scanf("%d",&enteredPassword);
     if(enteredPassword == password){
        printf("welcome back \n"); 
        
        printf ("Enter the mode of opening 1: write mode, 0:search \n");
        scanf ("%d", &mode);
        if (mode == 1){
            printf ("enteer the number of records for the day: ");
            scanf ("%d", &n_of_record);
        }
//  adding the extention
        strcat (fileName, extention);
        printf ("entered date is %s\n",fileName);
        printf ("********************************************************\n");
    
        (mode ==  1) ?printf("Enter the details of the patient in the order of: id age bloodSugarLevel bloodPressureLevel\n")
    : printf ("------------------------------------------\n");

//*********************************************************


    //  opening the file
        if (mode == 1){
            f = fopen (fileName, "w");
        }else if(mode == 0){
            f = fopen(fileName,"r");
            
        }else{
            printf ("enter a valid mode");
        }

    // check for existance.
    /***********************
    * This function can only be exicuted when there is mode == 'r'
    ****************************/
       checkForexistance (f);
  
  
    // writing thing to the file
     if (mode == 1) {
        for (int i = 0; i < n_of_record; i++){
	        scanf ("%d%d%f%f", &patientId, &age, &bloodSugarLevel,
		        &bloodPressureLevel);

	        fprintf (f, "patient id: %d\n", patientId);
	        fprintf (f, "age: %d\n", age);
	        fprintf (f, "bloodPressureLevel: %f\n", bloodPressureLevel);
	        fprintf (f, "bloodSugarLevel: %f\n", bloodSugarLevel);
	    }
    }
     
    /***********************************************************************
     * Now we can open the file in read mode. 
     * For that the mode need be "r"
    *************************************************************************/
    fscanf(f,"%[^\t]%*c",test);
    printf("%s",test);
    fclose (f);
    }else{
        printf("enter the correct password");
    }
     
 } 
 
/***********************************
 * now implement coustomer side.
*****************************/
if(strcmp("pl",login)==0){
   printf("Hi there!\n");
   strcat (fileName, extention);
   printf ("entered date is %s\n",fileName);
   printf ("********************************************************\n");
   f = fopen(fileName,"r");
   fscanf(f,"%[^\t]%*c",test);
   printf("%s",test);
   fclose(f);
   
}
    
  

  return 0;
}




