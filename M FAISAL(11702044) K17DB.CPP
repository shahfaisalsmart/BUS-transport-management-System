#include<string>
#include<fstream>
#include<windows.h>
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;


COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main();

class customer;

class medecine
{
    char m_name[25];
    char pass[25];
    int m_no;
    double m_amount;
    char star[25];
    char dest[25];
public:
	medecine()
	{
		
strcpy(pass,"dev");       // PASSWORD FOR ADMIN IS = faisal 
}

    void menu_for_admin();
    int password(char*);
    void getdata();
    void showdata();
    void write_data();
    void read_data();
    int search_data();
    int menu();
    void update_record();
    void delete_item(char*);
    void exitwindow();

};


int medecine::search_data()
{ 

  int count =0;
    char t[25];
    cin.ignore();
    cout<<"Enter Driver Name"<<endl;
    gets(t);
    ifstream fin;
    fin.open("file1.txt",ios::in|ios::binary);
    if(!fin)
    {
        cout<<"file cannot be opened"<<endl;
    }
    else
    {
	   cout<<setw(12)<<"DRIVER NAME"<<setw(12)<<"BUS NO"<<setw(12)<<"ARRIVAL TIME"<<setw(15)<<"STARTING POINT"<<setw(15)<<" DESTINATION"<<endl;
       cout<<endl;
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(!strcmp(m_name,t))
            {
			showdata();
            count=1;
			}
            fin.read((char*)this,sizeof(*this));
        }
        
		fin.close();

    }
    return count;
}



void medecine:: getdata()
{   
char g;
    do
	{
	cin.ignore();
    cout<<" "<<endl;
	cout<<"\t\t\t\tENTER THE NAME OF THE DRIVER"<<endl;
    gets(m_name);
    cout<<" "<<endl;
    cout<<"\t\t\t\tENTER THE  BUS NUMBER OF "<<m_name<<endl;
    cin>>m_no;
    cout<<" "<<endl;
    cout<<"\t\t\t\tENTER THE ARRIVAL TIME OF "<<m_name<<endl;
    cin>>m_amount;
    cout<<" "<<endl;
    fflush(stdin);
    cout<<"\t\t\t\tENTER THE STARTING POINT OF THE  "<<m_name<<endl;
    gets(star);
    cout<<" "<<endl;
    cout<<"\t\t\t\tENTER THE DESTINATION OF "<<m_name<<endl;
    gets(dest);
    
    write_data();
    cout<<"\t\t\t\t Record is successfully saved.";
    cout<<"\t\t\t\tWant to add new record????????"<<endl;
    cout<<"\t\t\t\tPress y or Y for adding and n or N main menu"<<endl;
    cin.ignore();
    cin>>g;
	}
    while(g=='y'||g=='Y');

}



void medecine::delete_item(char *t)
{
    ofstream fout;
    ifstream fin;
    fin.open("file1.txt",ios::in|ios::binary);
    if(!fin)
        cout<<"File cannot open"<<endl;
    else
    {
    fout.open("file2.txt",ios::out|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
	   if(strcmp(m_name,t))
        {
            fout.write((char*)this,sizeof(*this));
        }
        fin.read((char*)this,sizeof(*this));
    }
        fin.close();
        fout.close();
        remove("file1.txt");
        rename("file2.txt","file1.txt");
}

}



void medecine:: update_record()
{
    int count=1;
    char t[20];
    cin.ignore();
    cout<<"Enter the name of the driver to be updated"<<endl;
    gets(t);
    ifstream file;
    file.seekg(0);
    file.open("file1.txt",ios::in|ios::binary);
    file.read((char*)this,sizeof(*this));

    while(!file.eof())
    {
        if(!(strcmp(m_name,t)))
        {
		   delete_item(t);
            getdata();
            count=0;
        }
        file.read((char*)this,sizeof(*this));
    }
        if(count==1)
        cout<<"Item Not found"<<endl;
}



void medecine:: write_data()
{
    ofstream fout;
    fout.open("file1.txt",ios::app|ios::binary);
    if(!fout)
        cout<<"file cannot be written"<<endl;
    else
    { 
	fout.write((char*)this,sizeof(*this));
        cout<<"Done"<<endl;
        fout.close();
    }
}



void medecine:: read_data()
{
    ifstream fin;
    fin.open("file1.txt",ios::in|ios::binary);
    if(!fin)
        cout<<"File cannot be opened"<<endl;
    else
    {
	   cout<<setw(12)<<"DRIVER NAME"<<setw(12)<<"NUM"<<setw(12)<<"ARRIVAL TIME"<<setw(15)<<"STARTING FROM"<<setw(16)<<" DESTINATION"<<endl;
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            showdata();
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
}

}



void medecine:: showdata()
{
    cout<<setw(10)<<m_name<<setw(12)<<m_no<<setw(12)<<m_amount<<setw(15)<<star<<setw(18)<<dest<<endl;
}


int medecine::menu()
{ 
system("cls");
cout<<"\t\t\t\t*** BUS RESERVATION MANAGEMENT SYSTEM ***";
cout<<"\n\t\t\t\t\t***     MOHAMMAD FAISAL    ***";
cout<<"\n\t\t\t\t\t***        K17DB     ***";
cout<<"\n\t\t\t\t\t***  REG NO : 11702044 **";
    int a;
    cout<<"\n\nPRESS:"<<endl;
    cout<<"\t\t\t\t1:For Adding a bus"<<endl;
    cout<<"\t\t\t\t2:For Reading a bus detail"<<endl;
    cout<<"\t\t\t\t3:For Searching Bus for your Trip"<<endl;
    cout<<"\t\t\t\t4:For Updating existing BUS"<<endl;
    cout<<"\t\t\t\t5:For All passengers Bill"<<endl;
    cout<<"\t\t\t\t6:Main Menu"<<endl;
    cout<<"\t\t\t\t7:For Exit"<<endl;
cout<<" "<<endl;  
    cin>>a;
    return a;
}



void medecine::exitwindow()
{
    cout<<"Thank you have a nice day"<<endl;
    Sleep(3000);
    exit(0);
}


class customer
{
    int quantity;
    float price;
    int discount;
    int m_no;
    float grand_total;
    char m_name[25];
    float total_price;
    char customer_name[25];
    char customer_mobile_no[12];
public:
    void basket();
    void getdata();
    void write_bill();
    void read_bill(int);
    void showdata_bill();
    int delete_items_for_bill(int);
    void print_bill();
    int menu_customer();
    void menu_for_customer();
    void exitwindow();
    int search_items();
    void read_all_customer();
};



void customer::read_all_customer()
{
system("cls");
    ifstream fin;
    fin.open("bill.txt",ios::in|ios::binary);
    if(!fin)
        cout<<"File cannot be opened"<<endl;
    else
    {
	 fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
		cout<<"====================================================================================="<<endl;
        cout<<"\t\t\t\tPASSENGER'S NAME :"<<setw(15)<<customer_name<<endl;
        cout<<"\t\t\t\tPASSENGER'S MOBILE NUMBER "<<setw(11)<<customer_mobile_no<<endl;
        cout<<endl;
        cout<<"======================================================================================"<<endl;
        cout<<endl;
        cout<<setw(12)<<"DRIVER NAME"<<setw(12)<<"BUS NO."<<setw(12)<<"ARRIVAL TIME"<<setw(12)<<"STARTING POINT"<<endl;
        showdata_bill();
        cout<<"================================================================================="<<endl;
        cout<<"TOTAL AMOUNT  "<<total_price<<endl;
        cout<<"AMOUNT TO BE PAID WITH DISCOUNT = "<<grand_total<<endl;
        fin.read((char*)this,sizeof(*this));
        }
        cout<<endl;
        cout<<endl;
        cout<<"*******************************************************************************************"<<endl;
        fin.close();
}
}



void customer::read_bill(int c)
{
system("cls");
    ifstream fin;
    fin.open("bill.txt",ios::in|ios::binary);
    if(!fin)
        cout<<"File cannot be opened"<<endl;
    else
    {
	int m,d,e;
        fin.seekg(0,ios::end);
        d=fin.tellg();
        e=c*(sizeof(customer));
        m=d-e;
        fin.seekg(m,ios::beg);
        fin.read((char*)this,sizeof(*this));
        cout<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<"                                       PASSENGER'S NAME :"<<setw(15)<<customer_name<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
		cout<<"                                   PASSENGER'S MOBILE NUMBER': "<<setw(11)<<customer_mobile_no<<endl;
        cout<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<endl;
        cout<<setw(12)<<"DRIVER NAME"<<setw(12)<<"BUS NUM"<<setw(10)<<"COST"<<setw(11)<<"QUANTITY"<<setw(10)<<"DISCOUNT"<<endl;
        while(!fin.eof())
        {
            showdata_bill();
            fin.read((char*)this,sizeof(*this));
        }
        cout<<endl;
        cout<<endl;
       
	   cout<<"********************************************************************************"<<endl;
      cout<<"                                                                    "<<endl;
     cout<<"\t\t\t\tTOTAL PRICE WITHOUT DISCOUNT :"<<total_price<<endl;
	    cout<<"\t\t\t\tGRAND TOTAL :"<<grand_total<<endl;
        cout<<"********************************************************************************"<<endl;
        fin.close();
}
}

int customer::delete_items_for_bill(int count)
{
    int a=1;
    char t[25];
    ofstream fout;
    ifstream fin;
    fin.open("bill.txt",ios::in|ios::binary);
    if(!fin)
        cout<<"File cannot open"<<endl;
    else
    {
    fout.open("tempbill.txt",ios::out|ios::binary);
    while(a==1)
        {cout<<"\t\t\t\tENTER THE NAME OF THE DRIVER TO BE DELETED"<<endl;
               cin.ignore();
               gets(t);
               fin.read((char*)this,sizeof(*this));
               while(!fin.eof())
                {   if(strcmp(m_name,t))
                            fout.write((char*)this,sizeof(*this));
                    fin.read((char*)this,sizeof(*this));
               }
         cout<<"Press 1 to delete more and 0 to exit"<<endl;
         cin>>a;
         count--;
        };
        fin.close();
        fout.close();
        remove("bill.txt");
        rename("tempbill.txt","bill.txt");
        return count;
}
}



void customer::showdata_bill()
{
    cout<<setw(10)<<m_name<<setw(12)<<m_no<<setw(10)<<price<<setw(8)<<quantity<<setw(9)<<discount<<endl;
}



int customer::menu_customer()
{
system("cls");
cout<<"\t\t\t\t*** BUS RESERVATION MANAGEMENT ***";
    int d;
    cout<<"\n\nPRESS:"<<endl;
    cout<<"1:============================ FOR SEARCHING A BUS ========"<<endl;
    cout<<"2:===================================FOR BOOKING============="<<endl;
    cout<<"3:============================FOR GOING BACK TO MAIN MENU=="<<endl;
    cout<<"4:=======================================Exit==============="<<endl;
	cin>>d;
    return d;
}



void customer::menu_for_customer()
{
system("cls");
    int a,d;
    customer c;
    medecine A;
    while(a!=-1)
    {
        switch(c.menu_customer())
        {
        case 1:
            d=(A.search_data());
            if(d==0)
            cout<<"DRIVER IS NOT AVAILABLE FOR THIS TRIP PLEASE COME AGAIN AFTER 7 DAYS"<<endl;
            cout<<"\t\t\t\t\tTHANKYOU"<<endl;
            break;
        case 2:
            c.basket();
            cout<<"\t\t\t\t\tTHANKYOU"<<endl;
            break;
            
        case 3:
            main();
        	break;
		case 4:
            exitwindow();
            break;
            
        default:
            cout<<"\t\t\t\t\tINVALID"<<endl;
            break;
        }
        cout<<"PRESS -1 to try again and -2 for Going back to Menu"<<endl;
        cin>>a;
    }


}



void customer::basket()
{
    cout<<"\t\t\t\tEnter the following details"<<endl;
    getdata();
}



void customer::getdata()
{
system("cls");
medecine ad;  
 char f;
 int i;
    int count=0,c;
        total_price=0;
        
    int a;
    float cost;
    cin.ignore();
    cout<<"\t\t\t\tENTER THE NAME OF THE PASSENGER"<<endl;
    cout<<""<<endl;
    gets(customer_name);
    cout<<"\t\t\t\tENTER PASSENGER'S MOBILE NUMBER"<<endl;
 cout<<""<<endl; 
    cin>>customer_mobile_no;
do{
	cout<<" "<<endl;
	cout<<"\t\t\t\tPRESS 1 FOR SHOWING AVAILABLE BUS(DRIVER)"<<endl;
	cout<<"===================================================================================="<<endl;
	cout<<"IF U DON'T WANT TO VIEW AVAILABLE BUSES PLEASE PRESS ANY OTHER NUMBERS RATHER THAN 1"<<endl;
	cin>>i;
	if(i==1)
	ad.read_data();
    cout<<"\n\t\t\t\t\tENTER THE NAME OF THE DRIVER"<<endl;
    cin.ignore();
    gets(m_name);
    cout<<"\t\t\t\t\tENTER THE BUS NUMBER "<<m_name<<endl;
    cin>>m_no;
    cout<<"\t\t\t\t\tPAY THE PAYMENT"<<m_name<<endl;
    cin>>price;
    cout<<"\t\t\t\t\tENTER THE NUMBER  OF PERSON'S INCLUDING YOU:"<<m_name<<endl;
    cin>>quantity;
    cout<<"\t\t\t\tENTER THE DISCOUNT PERCENTAGE % FOR :"<<m_name<<endl;
    cin>>discount;
    total_price=total_price+(float)(quantity*price);
    grand_total=total_price-((total_price*discount)/100);
	write_bill();
    count++;
    cout<<"Press -1 to add more and 0 to exit"<<endl;
    cin>>a;
	}
	while(a!=0);
      cout<<"\t\t\t\tTHE TOTAL AMOUNT IS  :"<<total_price<<" RUPEES"<<endl;
      cout<<"\t\t\t\t\t "<<endl;
      cout<<"\t\t\t\tTHE TOTAL AMOUNT INCLUDING DISCOUNT IS :"<<grand_total<<endl;
      cout<<"\t\t\t\t "<<endl;
      cout<<"=================================================================================================="<<endl;
      cout<<"=================================================================================================="<<endl;
      cout<<"\t\t\t\t"<<endl;
	  cout<<"\t\t\t\t=========AMOUNT TO BE PAID======== = "<<grand_total<<" RUPEES"<<endl;
      cout<<"\t\t\t\t "<<endl;
      cout<<"\t\t\t\tDO YOU WANT TO CHECK THE BILL"<<endl;
      cout<<"\t\t\t\t "<<endl;
      cout<<"\t\t\t\tPRESS y OR Y FOR YES AND n AND N FOR NO"<<endl;
      cin.ignore();
      cin>>f;
      if(f=='n'||f=='N')
        {
		 c=delete_items_for_bill(count);
          read_bill(c);
        }
    else
    { 
	read_bill(count);
	}
}



void customer::print_bill()
{
    showdata_bill();
}



void customer::write_bill()
{
    ofstream fout;
    
    fout.open("bill.txt",ios::app|ios::binary);
    if(!fout)
        cout<<"file cannot be written"<<endl;
    
	else
    {
    fout.write((char*)this,sizeof(*this));
    cout<<"Done"<<endl;
    fout.close();
}

}



void customer::exitwindow()
{  
     cout<<""<<endl;
    cout<<"\t\t\t\tHOPE YOU LIKED OUR SERVICE"<<endl;
    Sleep(3000);
    exit(0);
}



void medecine::menu_for_admin()

{
 system("cls");
    medecine A;
    int c;
    while(c!=-1)
{
        switch(A.menu())
        {
   
        case 1:
            cout<<"\t\t\t\tENTER THE REQUIRED DETAILS"<<endl;
            A.getdata();
            cout<<"\t\t\t\tTHANKYOU"<<endl;
            break;
        case 2:
            cout<<"\t\t\t\tTHE PREVIOUS RECORDS ARE"<<endl;
            A.read_data();
            cout<<"\t\t\t\tThank you"<<endl;
            break;
        case 3:
            int e;
            e=A.search_data();
            if(e==0)
            cout<<"Items not found"<<endl;
            break;
        case 4:
            cout<<"Provide the following details for the update-ion for the BUS"<<endl;
            A.update_record();
            cout<<"\t\t\t\tThank you"<<endl;
            break;
        case 5:
            customer c;
            c.read_all_customer();
            break;
//        case 6:
//           	char *itemName;
//           	cin>>itemName;
//		   delete_item(itemName); 
       case 7:
            main();
            break;
    
        case 8:
        	exitwindow();
        	break;
        	
        default:
            cout<<"\t\t\t\tINVALID SELECTION"<<endl;
            cout<<"\t\t\t\tTRY AGAIN"<<endl;
        }
        cout<<"\t\t\t\tDO U WANT O TRY AGAIN"<<endl;
        cout<<"\t\t\t\tPress -1 to end the program and -2 for menu"<<endl;
        cin>>c;
}

}



int medecine::password(char *t)
{
    int d;
    d=strcmp(pass,t);
    return d;
}



int main()
{ system("color 04");
gotoxy(30,15);
cout<<"loading.";
Sleep(1000);
cout<<".";
Sleep(1000);
cout<<".";
Sleep(1000);
cout<<".";
Sleep(1000);
cout<<".";
int s;
system("color 0a");
int a;
system("cls");
cout<<"\t\t\t\t*** BUS RESERVATION MANAGEMENT SYSTEM ***";
cout<<"\n\t\t\t\t***      MOHAMMAD FAISAL    ***";
cout<<"\n\t\t\t\t***        K17DB    ***";
cout<<"\n\t\t\t\t***  REG NO : 1172044 **"<<endl;
cout<<"\t\t\t "<<endl;
    
char t[25];
    medecine A;
    customer c;
    while(a!=-1)
    {
    	cout<<"\t\t\tWELCOME TO OUR BUS RESERVATION MANAGEMENT SYSTEM"<<endl;
    	cout<<"\t\t\t "<<endl;
    cout<<"\n\t\t\t\t1.ENTER 1 FOR ADMIN "<<endl;

    cout<<"\n\t\t\t\t2.ENTER 2 FOR USER "<<endl;
    cout<<"\n\t\t\t========ENTER YOUR CHOICE PLEASE :=========="<<endl;
	    cin>>s;
    if(s==1)
    {
        cout<<"\n\t\t\t\tENTER THE ADMINISTRATOR PASSWORD"<<endl;
        cin.ignore();
        gets(t);
        int f;
        f=A.password(t);
        if(!f)
             A.menu_for_admin();
        else
		{
        	MessageBox(0,"THE PASSWORD YOU ENTERED IS WRONG","Error",MB_OK);
        	system("color 47");
            cout<<"=======================WRONG PASSWORD=========================="<<endl;
            cout<<"==============================================================="<<endl;
            cout<<"=============THE PROGRAM IS GOING TO CLOSE NOW=================="<<endl;
            Sleep(2000);
            exit(0);
    }
   	}
    
	if(s==2)
    c.menu_for_customer();
    cout<<"Thank you :"<<endl;
    cout<<"Press -1 to shutdown the program and any key for working"<<endl;
    cin>>a;
    }
}

