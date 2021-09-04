#include<bits/stdc++.h>
using namespace std;

//int y[500];
int n=5;
char reminder[500] ;
int slidingf(int , int );
char* crc(char *fram,char gen[]);
int errorcheck(char* input,char cr[]);
char frames[1000][1000];
//bool errorcheck(char ,char );
//char crc(char *fram,char );

int main()
{
    int i;
    ifstream file;
    file.open("E:\\Local Disk G\\8th Semester\\CSE350\\Project\\input.txt");
    char x[500];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=49; j++)
            file>>x[j];
        strcpy(frames[i],x);
    }
    int w;
    cout<<"ENTER THE SIZE OF WINDOW: ";
    cin>>w;
    i=0;
    while(i<n)
    {
        i=slidingf(i,min(i+w-1,n-1));
    }
    return 0;
}
int slidingf(int left, int right)
{
    cout<<"\n\nSending Frames from :"<<left<<" to "<<right<<endl<<endl<<endl;
    for (int i=left; i<=right; i++)
    {
        char crc16[]="11000000000000101";
        cout<<"Data that Frame ["<<i<<"]Contains are: ";
        for(int j=0;j<=49;j++)
            cout<<frames[i][j];
        cout<<endl<<endl;
        cout<<"Value of CRC16 is: "<<crc16<<endl<<endl;
        system("pause");
        if(errorcheck(frames[i],crc16))
        {
            cout<<"Frame ["<<i<<"]Received Successfully.....\n\n";
            cout<<"Positive Acknowledgment[ACK-"<<i+1<<"] has been sent\n\n";
            system("pause");
            system("cls");
        }
        else
        {
            cout<<"There is an error in frame "<<i<< "...!!!\n"<<endl;
            cout<<"Negative Acknowledgment [ACK- "<<i<<"] has been sent\n\n";
            system("pause");
            system("cls");
            return i;
        }
    }
    system("cls");
    cout<<"Acknowledgment["<<right+1<<"] has been sent"<<endl<<endl;
    system("pause");
    return right+1;

}


int errorcheck(char* input,char cr[])
{
    srand(time(NULL));
    char te[1000];
    int ran1,ran2;
    strcpy(te,crc(input,cr));
    //cout<<"ckerr"<<zz;

    ran1=rand()%4;

    ran2=rand()%10;

    if(ran1!=0)
    {
        if(te[ran2]=='0')
            te[ran2]='1';
        else
            te[ran2]='0';
    }
    strcpy(te,crc(te,cr));
    printf("\nResultant Reminder:  %s\n\n\n",reminder);
    for(int i=0; reminder[i]!='\0'; i++)
        if(reminder[i]=='1')
            return 0;
    return 1;
}
char* crc(char *fram,char gen[])
{
    char rem[500],gen1[500],div[500],quot[100];
    int i,j;
    int genlen,framelen;
    static char hold[500];
    genlen=strlen(gen);
    framelen=strlen(fram);
    strcpy(gen1,gen);
    for (i=0; i<genlen; i++)
        div[i]=fram[i];
    for (i=0; i<genlen-1; i++)
        fram[framelen+i]='0';
    for (i=0; i<framelen; i++)
    {
        quot[i]=div[0];
        if(quot[i]=='0')
        {
            for (j=0; j<genlen; j++)
                gen[j]='0';
        }
        else
        {
            for (j=0; j<genlen; j++)
                gen[j]=gen1[j];
        }

        for (j=genlen-1; j>0; j--)
        {
            if(div[j]==gen[j])
                rem[j-1]='0';
            else
                rem[j-1]='1';
        }

        rem[genlen-1]=fram[i+genlen];
        strcpy(div,rem);
    }

    strcpy(rem,div);
    for (i=0; i<genlen-1; i++)
        reminder[i]=rem[i];
    for (i=0; i<framelen; i++)
        hold[i]=fram[i];
    for (j=0; i<genlen+framelen-1; j++)
    {
        hold[i]=rem[j];
        i++;
    }
    //cout<<"crc"<<endl;
    //for(int i=0;yy[i]!='\0';i++)
    //cout<<yy<<" ";
    // cout<<strlen(yy)<<"\n";
    return hold;
}



