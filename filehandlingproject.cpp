#include<stdio.h>
#include<stdlib.h>
struct stu
{
int id;
char name[20];
}
s;
int idno, found, op;
char ch;
FILE *fp, *t;

void newstu(); /* fun dec */
void enquiry();
void report();
void upd();
void del();
void line()
{
puts("--------------------------------------------------------------------");
}
int main()
{
system("cls");
line();
puts("\t\t\t STUDENTS ENROLLMENT SYSTEM");
line();
puts("\t\t\t 1. New stu");
puts("\t\t\t 2. Enquiry");
puts("\t\t\t 3. Report");

puts("\t\t\t 4. Update");
puts("\t\t\t 5. Delete");
puts("\t\t\t 6. Exit");
line();
printf("\t\t\t Enter Ur option [ ]\b\b");
scanf("%d",&op);
switch(op)
{
case 1:
newstu();
break;
case 2:
enquiry();
break;
case 3:
report();
break;
case 4:

upd();
break;
case 5:
del();
break;
case 6:
break ;
default:
puts("Invalid Option");
}
//getch();
main(); /* recursion */
}
void newstu() /* fun definition */
{
system("cls");
fp = fopen("11proj.dat","a");
while(1)

{
printf("Enter stu id, name ");
scanf("%d %s",&s.id,s.name);
fwrite(&s,sizeof(s),1,fp);
puts("1 row created");
fflush(stdin);
printf("Do you want to continue [y/n] ");
scanf("%c",&ch);
if(ch=='n'||ch=='N')
break;
}
fclose(fp);
}

void enquiry()
{
found=0;
system("cls");

fp = fopen("11proj.dat","r");
fread(&s,sizeof(s),1,fp);
printf("Enter stu id to search ");
scanf("%d",&idno);
while(!feof(fp))
{
if(idno==s.id)
{
found=1;
puts("Id\tName");
line();
printf("%d\t%s\n",s.id,s.name);
break;
}
fread(&s,sizeof(s),1,fp);
}
fclose(fp);
if(found==0)

printf("stu not found");
}

void report()
{
system("cls");
fp = fopen("11proj.dat","r");
if(fp==NULL)
puts("File not found");
else
{
puts("ID\tNAME");
line();
fread(&s,sizeof(s),1,fp);
while(!feof(fp))
{
printf("%d\t%s\n",s.id,s.name);
fread(&s,sizeof(s),1,fp);

}
fclose(fp);
}
}

void upd()
{
found=0;
system("cls");
printf("Enter stu id to update ");
scanf("%d",&idno);
fp = fopen("11proj.dat","r+"); /* read and write */
fread(&s,sizeof(s),1,fp);
while(!feof(fp))
{
if(idno==s.id)
{
found=1;

puts("Id\tName");
line();
printf("%d\t%s\n",s.id,s.name);
printf("Enter new id, name ");
scanf("%d %s",&s.id,s.name);
fseek(fp, ftell(fp)-sizeof(s),0); /* 0-current position */
fwrite(&s,sizeof(s),1,fp);
puts("One row updated");
break;
}
fread(&s,sizeof(s),1,fp);
}
fclose(fp);
if(found==0)
puts("Stu not found");
}
void del()
{

found=0;
system("cls");
fp = fopen("11proj.dat","r");
t = fopen("temp","w");
printf("Enter stu id to delete ");
scanf("%d",&idno);
fread(&s,sizeof(s),1,fp);
while(!feof(fp))
{
if(idno==s.id)
{
found=1;
puts("Id\tName");
line();
printf("%d\t%s\n",s.id,s.name);
}
else fwrite(&s,sizeof(s),1, t);
fread(&s,sizeof(s),1,fp);

}
fclose(fp);
fclose(t);
printf("R u sure to delete [y/n] ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='n'||ch=='N')
puts("Operation cancelled");
else
{
remove("11proj.dat");
rename("temp","11proj.dat");
puts("One row ,deleted");
}
}

