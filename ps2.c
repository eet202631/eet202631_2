    #include <stdio.h>
    #include <stdlib.h> // For exit() function
    int matchPassword(char name,char pass);
    int main() {
        char c[1000];
        FILE *fptr1, *fptr2;
        if ((fptr1 = fopen("password.txt", "w")) == NULL) {
            printf("Error! opening file");
            // Program exits if file pointer returns NULL.
            exit(1);
        }
        if ((fptr2 = fopen("AdmitList.txt", "w")) == NULL) {
            printf("Error! opening file");
            // Program exits if file pointer returns NULL.
            exit(1);
        }

        int i=0;
        while (i==0)
        {
        char name[10];
        char pass[10];
        printf("Enter Name :  ");
        scanf("%s",name);
        printf("Enter password: ");
        scanf("%s",pass);
        
        if(matchPassword(name,pass)==1){

        }else{
            printf("Wrong Username Password, please enter the correct Username and password");
        }

        }
        
        fclose(fptr1);
        fclose(fptr2);
        return 0;
    }

    int matchPassword(char name,char pass){ 

        FILE *fptr1;
        char buf[1000];

        if ((fptr1 = fopen("password.txt", "r")) == NULL) {
            printf("Error! opening file");
            // Program exits if file pointer returns NULL.
            exit(1);
        }
        while (fgets(buf,1000, fptr1)!=NULL){
            char *array[20];
            int i = 0;
            char *p = strtok (buf, "_");
            while (p != NULL)
            {   
                array[i++] = p;
                p = strtok (NULL, "_");
            }
            if(array[1]==name)
            {
                if(array[0]=="admin"){
                    if(array[2]==pass){
                        printf("Admin logged in successfully");
                        return 1;
                    }
                    else{
                        printf("Admin password incorrect");
                    }
                }
                else{
                    if(array[0]=="patient")
                        {
                        if(array[2]==pass){
                            printf("%s logged in successfully",name);
                            return 1;
                        }
                    else{
                        printf("Patient password incorrect");
                    }

                }

                }
            }
            else{
                printf("Name not found in database");
            }
        }
        return 0;
    }