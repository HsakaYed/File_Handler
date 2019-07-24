#include<stdio.h>
#include<strings.h>
#include<windows.h>
void main()
{
	//sets the default console foreground color
	system("color a");
	//sets the window title for the command prompt window
	system("title FILE HANDLER");
	SYSTEMTIME sTime;
	GetSystemTime(&sTime);
	char ch;
	printf("-----------------------------------Today's date----------------------------------");
	printf("\n%d/%d/%d",sTime.wDay,sTime.wMonth,sTime.wYear);
    printf("\n---------------------------------------------------------------------------------");
    printf("\n----------------------------------Constraints------------------------------------");
	printf("\n*Make sure all the files must be in text mode\n");
	printf("*Your file name shouldn't exceed 30 characters\n");
	printf("*All your files must be saved in '.txt' extension");
	printf("\n---------------------------------------------------------------------------------");
	do
    {
	FILE *fp;
	char st[100],old_name[30],new_name[30],file1[30],file2[30],file3[30];
    int value,i;
	printf("\n");
	printf("------------------------------------Options--------------------------------------");
	printf("\n*Enter '1' for reading content from the file"
           "\n*Enter '2' for erasing previous content from the file and write new content"
           "\n*Enter '3' to merge contents of two files into a third file"
           "\n*Enter '4' to write additional content to your file"
           "\n*Enter '5' to change the name of your file"
           "\n*Enter '6' to permanently delete the file");
	printf("\n---------------------------------------------------------------------------------");
	printf("\n");
	printf("\nEnter your choice: ");
	scanf("%d",&i);
	switch(i)
	{
    case 1:
	//clear the input buffer
	fflush(stdin);
	printf("\nEnter the name of the file: ");
	scanf("%s",file1);
	//open the file in read-mode
	fp=fopen(file1,"r");
	if(fp==NULL)
	{
		perror("Error: ");
		exit(1);
	}
    printf("\n");
    while(!feof(fp))
    {
        ch=fgetc(fp);
        printf("%c",ch);
    }
    //close the file
    fclose(fp);
    break;
    case 2:
    printf("Enter the name of your file: ");
    scanf("%s",file1);
    //open the file in write-mode
    fp=fopen(file1,"w");
    if(fp==NULL)
    {
        // to print descriptive error message
        perror("Error: ");
        exit(1);
    }
    printf("Enter the content: ");
    gets(st);
    fputs(st[i],fp);
    //close the file
    fclose(fp);
    break;
    case 3:
    printf("\nEnter the name of first file: ");
    scanf("%s",file1);
    printf("\nEnter the name of second file: ");
    scanf("%s",file2);
    printf("\nEnter the name of third file: ");
    scanf("%s",file3);
    //open file1 and file2 in read-mode
    fp=fopen(file1,"r");
    FILE *fp2=fopen(file2,"r");
    //open file3 in write-mode
    FILE *fp3=fopen(file3,"w");
    if(fp==NULL || fp2==NULL || fp3==NULL)
    {
        perror("Error: ");
        //terminate the program
        exit(1);
    }
    while(!feof(fp))
    {
        ch=fgetc(fp);
        fputc(ch,fp3);
    }
    while(!feof(fp))
    {
        ch=fgetc(fp2);
        fputc(ch,fp3);
    }
    fclose(fp);
    fclose(fp2);
    fclose(fp3);
    printf("Do you want to read the content of the third file after merging?"
           "Enter 'y' for yes"
           "Enter 'n' for no");
    scanf("%c",&ch);
    if(ch=='y')
    {
        //open the third file in read-mode
        fp=fopen(file3,"r");
        if(fp==NULL)
        {
            printf("Error: ");
            //terminate the program where '1' represents abnormal termination
            exit(1);
        }
        while(!feof(fp))
        {
            ch=fgetc(fp);
            printf("%c",ch);
        }
        fclose(fp);
    }
    break;
    case 4:
    printf("Enter the name of your file: ");
    scanf("%s",file1);
    //open the file append-mode
    fp=fopen(file1,"a");
    if(fp==NULL)
    {
        perror("Error: ");
        exit(1);
    }
    printf("\nEnter the additional content: ");
    fflush(stdin);
    gets(st);
    //enters string in the file
    fputs(st,fp);
    //close the file
    fclose(fp);
    break;
    case 5:
    //fflush(stdin);
    printf("Enter the name of your existing file: ");
    scanf("%s",old_name);
    fflush(stdin);
    printf("\nEnter the new name: ");
    scanf("%s",new_name);
    value=rename(old_name,new_name);
    if(!value)
            printf("File name changed successfully");
        else
            perror("Error: ");
    break;
    case 6:
    //fflush(stdin);
    printf("Enter the name of your file: ");
    scanf("%s",old_name);
    if(remove(old_name)==0)
            printf("File deleted successfully.");
        else
            perror("Error: ");
    break;
    default:
    printf("Invalid Choice");
    }
    fflush(stdin);
    printf("\n");
    printf("\nDo you want to continue?"
           "\nEnter 'y' for yes"
           "\nEnter 'n' for no"
           "\n");
    scanf("%c",&ch);
    }
    while(ch=='y');
    getch();
}
