#include<stdio.h>
#include<math.h>
#include<string.h>

char arr1[20];
char arr2[20];

int deci_count;

char* basefinal(double,int);
double base10(char*,int); // Convert the input base to base 10
void baseconvertor(); // Function for interconverting bases

int main(){
    printf("Hi! welcome to the utility app\n\n");
    printf("What would you like to do (select choice)\n1.Base convertor for base 2 to base 36: \n");
    int choice; //Take the choice
    scanf("%d",&choice);
    if(choice==1)
    {
        baseconvertor(); 
    }
}


void baseconvertor()
{
    int base1;
    int base2;
    int basecheck=0;  //To check if input numbers is not greater than base1
    printf("Enter the positive number for conversion for base (2 to 36):\n");
    scanf("%s",arr1);//Take the input number for conversion
    printf("Enter the base of the input number: \n");
    scanf("%d",&base1);
    printf("Enter the target base: \n");
    scanf("%d",&base2);

    for(int i=0;i<strlen(arr1);i++) // This loop is for checking the input if entered number lies in base1
    {
        char ch=arr1[i];
        if(ch>='0' && ch<='9')
        {
            int a=(int)ch-'0';
            if(a>=base1)
            {
            basecheck++;
            break;
            }
        }

        if(ch>='A' && ch<='Z')
        {
            int a=(int)ch-'A'+10;
            if(a>=base1)
            {
            basecheck++;
            break;
            }
        }
    }

    if(base1>1 && base1<37 && base2>=1 && base2<37 && basecheck==0)
    {
       char* ans= basefinal(base10(arr1,base1),base2);
       printf("The required answer is: %s \n", ans);
    }
    

    else
    {
        printf("Invalid input, program terminated\n");
    }

}



double base10(char* arr1,int base1)
{
    int size=strlen(arr1);
    char dot='.';
    int count=0; // number of integers before decimal
    double sum1=0; // answer of decimal values before decimal
    double sum2=0; // answer of decimal values after decimal
    
    while(arr1[count]!='.')
    {
        count++;
        if((count>size-1))
        {
            break;
        }
    } 
    count=count-1;
    //printf("\ncount is  %d\n",count);
    //printf("\nsize is  %d\n",size);
    for(int i=count,j=0;j<size;j++,i--)
    {
        char ch;
        ch=arr1[j];
        if(ch=='.')
        {
            break;
        }

        if(ch>='0' && ch<='9')
        {
            sum1+=pow(base1,(double)i)*((int)ch-'0');
        }

        if(ch>='A' && ch<='Z')
        {
            sum1+=pow(base1,(double)i)*((int)ch-'A'+10);
        }
        //printf("\ni is  %d\n",i);
        //printf("\nj is  %d\n",j);
        //printf("\nsum is  %lf\n",sum1);
        //printf("\nchar is  %c\n",arr1[j]);
        
    }

    int check_dot=0;
    for(int i=0;i<size;i++)
    {
        if(arr1[i]=='.')
        {
            check_dot=1;
            break;
        }
    }

    if(check_dot==0)
    {
        return sum1;
    }

    else if(check_dot==1)
    {
    deci_count=size-count-2; // number of digits after decimal points
    
    //printf("\ncount %d deci count %d size %d\n",count,deci_count,size);
    for(int i=-1,j=size-deci_count;j<size;j++,i--)//
    {
        char ch;
        ch=arr1[j];

        if(ch>='0' && ch<='9')
        {
            sum2+=pow(base1,i)*((int)ch-'0');
        }

        if(ch>='A' && ch<='Z')
        {
            sum2+=pow(base1,i)*((int)ch-'A'+10);
        }

    }

    double roundedans=sum1+sum2;
    roundedans=round(roundedans*pow(10,deci_count))/pow(10,deci_count);// if number of values after point is 5 then return 4 values


    return(roundedans);
    }
    
}


char* basefinal(double num1,int base2)
{
    int whole=(int)num1; //integer part of num1
    int count=0; // count number of elements in arr2
    
    for(int i=0;whole!=0;i++)
    {
        int val1=whole%base2;
        whole=whole/base2;

        if(val1<=9)
        {
            arr2[count]=(char)(val1+48);
            count+=1;
        }

        else if(val1>9)
        {
            arr2[count]=(char)(val1+55);
            count+=1;
        }   
    }

    for(int i=0;i<count/2;i++)
    {
        char temp=arr2[i];
        arr2[i]=arr2[count-i-1];
        arr2[count-i-1]=temp;
    }

    arr2[count]='.';
    count+=1;

    double decinum=num1-(int)num1;
    double val1;
    int num3;
    

    for(int i=0;i<deci_count;i++)
    {
        val1=decinum*base2;
        num3=(int)val1;
        for(int i = 0; i < deci_count; i++)
        {
           val1 = decinum * base2;
           num3 = (int)val1;

        if(num3 <= 9)
        {
           arr2[count] = (char)(num3 + '0');
           count++;
        }

       else
        {
        arr2[count] = (char)(num3 + 'A' - 10);
        count++;
        }

        decinum = val1 - num3;

        if(i=deci_count-1)
        {
            break;
        }

        }

    }
    
    return arr2;
}























