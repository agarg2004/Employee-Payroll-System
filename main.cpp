#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <ctype.h>
#include <mysql.h>

#define max 50

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PASS = "";
const char* DB   = "payroll";

class DBConnection {
    MYSQL* conn;
public:
    DBConnection() {
        conn = mysql_init(nullptr);
        if (!mysql_real_connect(conn, HOST, USER, PASS, DB, ****, nullptr, 0)) {
            cerr << "MySQL Connection Failed: " << mysql_error(conn) << endl;
            exit(1);
        }
    }
    ~DBConnection() { mysql_close(conn); }
    MYSQL* getConnection() { return conn; }

    void execute(const string& query) {
        if (mysql_query(conn, query.c_str())) {
            cerr << "MySQL Error: " << mysql_error(conn) << endl;
        }
    }

    MYSQL_RES* query(const string& query) {
        if (mysql_query(conn, query.c_str())) {
            cerr << "MySQL Error: " << mysql_error(conn) << endl;
            return nullptr;
        }
        return mysql_store_result(conn);
    }
};

using namespace std;

DBConnection db;


int num=0;
void gotoXY(int,int);
void Cdelay(int);
void border(int, int,int, int);
void borderNoDelay(int, int,int, int);
void loginFrame(int, int, int, int);
void intro();
void login();
void menu();
void insert();
void edit();
void editmenu();
void editname(int);
void editcode(int);
void editdes(int);
void editexp(int);
void editage(int);
void editsalary(int);
void list();
void deletes();
void search();
void setWindowSize(int,int);
void saverecords();
void getrecords();
bool isFilePresent();
void displayPayslip();


class employee
{
public:
    string name;
    int code;
    string designation;
    int exp;
    int age;
    double salary;
    char AnyLoan;

    double HRA;
    double PF;
    double tax;
    double MealAllowance;
    double TransportAllowance;
    double MedicalAllowance;
    double LoanBalance;
    double LoanDebit;
    double grosspay;
    double workingHours;
    double DA;
};

employee emp[max],tempemp[max];

void getrecords() {
    MYSQL_RES* res = db.query("SELECT * FROM employees");
    if (!res) return;

    MYSQL_ROW row;
    num = 0;

    while ((row = mysql_fetch_row(res)) && num < max) {
        emp[num].name = row[1];
        emp[num].code = atoi(row[2]);
        emp[num].designation = row[3];
        emp[num].exp = atoi(row[4]);
        emp[num].age = atoi(row[5]);
        emp[num].salary = atof(row[6]);
        emp[num].AnyLoan = row[7][0];
        emp[num].HRA = atof(row[8]);
        emp[num].PF = atof(row[9]);
        emp[num].tax = atof(row[10]);
        emp[num].MealAllowance = atof(row[11]);
        emp[num].TransportAllowance = atof(row[12]);
        emp[num].MedicalAllowance = atof(row[13]);
        emp[num].LoanBalance = atof(row[14]);
        emp[num].LoanDebit = atof(row[15]);
        emp[num].grosspay = atof(row[16]);
        emp[num].workingHours = atof(row[17]);
        emp[num].DA = atof(row[18]);
        num++;
    }

    mysql_free_result(res);
}

void saverecords() {
    char query[2048];
    for (int i = 0; i < num; i++) {
        snprintf(query, sizeof(query),
                 "INSERT INTO employees(name, code, designation, exp, age, workingHours, salary, DA, PF, tax, HRA, MealAllowance, MedicalAllowance, TransportAllowance, AnyLoan, LoanBalance, LoanDebit, grosspay) "
                 "VALUES('%s', %d, '%s', %d, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, '%c', %f, %f, %f) "
                 "ON DUPLICATE KEY UPDATE "
                 "name='%s', designation='%s', exp=%d, age=%d, workingHours=%f, salary=%f, DA=%f, PF=%f, tax=%f, HRA=%f, MealAllowance=%f, MedicalAllowance=%f, TransportAllowance=%f, AnyLoan='%c', LoanBalance=%f, LoanDebit=%f, grosspay=%f",
                 
                 // INSERT VALUES
                 emp[i].name.c_str(), emp[i].code, emp[i].designation.c_str(), emp[i].exp, emp[i].age, emp[i].workingHours, emp[i].salary,
                 emp[i].DA, emp[i].PF, emp[i].tax, emp[i].HRA, emp[i].MealAllowance, emp[i].MedicalAllowance, emp[i].TransportAllowance,
                 emp[i].AnyLoan, emp[i].LoanBalance, emp[i].LoanDebit, emp[i].grosspay,
                 
                 // UPDATE VALUES
                 emp[i].name.c_str(), emp[i].designation.c_str(), emp[i].exp, emp[i].age, emp[i].workingHours, emp[i].salary,
                 emp[i].DA, emp[i].PF, emp[i].tax, emp[i].HRA, emp[i].MealAllowance, emp[i].MedicalAllowance, emp[i].TransportAllowance,
                 emp[i].AnyLoan, emp[i].LoanBalance, emp[i].LoanDebit, emp[i].grosspay
        );

        db.execute(query);
    }
    cout << "All employees saved to database.\n";
}



void Cdelay(int msec)
{
    long goal = msec + (clock());
    while (goal > (clock()));
}

bool isFilePresent()
{
    FILE *fp;
    fp = fopen("Records.txt","r");
    if(fp==NULL)
        return false;
    else
        return true;
}
void loginFrame1(int xLenS = 18, int yLenS = 8, int xLenE = 55, int yLenE = 15)
{
    system("cls");
    gotoXY(xLenS,yLenS);printf("%c",201);

    gotoXY(xLenS,yLenE);printf("%c",200);

    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        gotoXY(i,yLenS);
        printf("%c",205);
        gotoXY(i,yLenE);
        printf("%c",205);

    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        gotoXY(xLenS, i);
        printf("%c",186);
        //puts(style);
        gotoXY(xLenE, i);
        printf("%c",186);
    }
    printf("\n\n");
}
void login()
{

    char UserName[30],Password[30],ch;int i=0;
    gotoXY(20,10);
    printf("Enter UserName : ");

    cin>>UserName;
    gotoXY(20,12);
    cout<<"Enter Password : ";
    while(1)
    {
        ch = getch();
        if(ch==13)
            break;
        if(ch==32||ch==9)
            continue;
        else
        {
            cout<<"*";
            Password[i]=ch;
            i++;
        }
    }
    Password[i] = '\0';
    if(strcmp(UserName,"admin")==0 && strcmp(Password,"admin")==0)
    {
        system("cls");
        loginFrame1();
        gotoXY(27,10);
        cout<<"Login Success!!!";
        gotoXY(21,12);
        cout<<"Will be redirected in 3 Seconds...";
            gotoXY(56,12);
        Cdelay(1000);
        gotoXY(44,12);
        cout<<"\b \b2";
            gotoXY(56,12);
        Cdelay(1000);
        gotoXY(44,12);
        cout<<"\b \b1";
            gotoXY(56,12);
        Cdelay(1000);
    }
    else
    {
        system("cls");
        loginFrame1();
        gotoXY(27,10);
        printf("Access Denied!!!\a");
        gotoXY(21,12);
        cout<<"Will be redirected in 3 Seconds...";
            gotoXY(56,12);
        Cdelay(1000);
        gotoXY(44,12);
        cout<<"\b \b2";
            gotoXY(56,12);
        Cdelay(1000);
        gotoXY(44,12);
        cout<<"\b \b1";
            gotoXY(56,12);
        Cdelay(1000);
        system("cls");
        loginFrame1();
        login();
    }
}
void setWindowSize(int width=670,int height=445)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoXY(int X, int Y)
{
    COORD coordinates;
    coordinates.X = X;
    coordinates.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void borderNoDelay(int xLenS = 2, int yLenS = 2,int xLenE = 76, int yLenE = 24 )
{
    system("cls");
    gotoXY(xLenS,yLenS);printf("%c",201);

    gotoXY(xLenS,yLenE);printf("%c",200);

    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        gotoXY(i,yLenS);
        printf("%c",205);
        gotoXY(i,yLenE);
        printf("%c",205);
    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        gotoXY(xLenS, i);
        printf("%c",186);
        gotoXY(xLenE, i);
        printf("%c",186);
    }
    printf("\n\n");
}
void border(int xLenS = 2, int yLenS = 2,int xLenE = 76, int yLenE = 22 )
{
    system("cls");
    gotoXY(xLenS,yLenS);printf("%c",201);

    gotoXY(xLenS,yLenE);printf("%c",200);

    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        Cdelay(15);
        gotoXY(i,yLenS);
        printf("%c",205);
        gotoXY(i,yLenE);
        printf("%c",205);

    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        Cdelay(15);
        gotoXY(xLenS, i);
        printf("%c",186);
        //puts(style);
        gotoXY(xLenE, i);
        printf("%c",186);
        //puts(style);
    }
    printf("\n\n");
}
void loginFrame(int xLenS = 18, int yLenS = 8, int xLenE = 55, int yLenE = 15)
{
    border(xLenS,yLenS,xLenE,yLenE);
}
void insert()
{
    borderNoDelay();
    int i=num;
    int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal,LoanDeb,h,DA;
    char loan;
    string name;
    num+=1;
    gotoXY(28,4);
    printf("Insert New Record");
    gotoXY(10,6);
    cout<<"Name : ";
	cin>>name;
    emp[i].name=name;
    gotoXY(10,8);
    cout<<"Code : ";
    cin>>emp[i].code;
    gotoXY(10,10);
    cout<<"Designation : ";
    cin>>emp[i].designation;
    gotoXY(10,12);
    cout<<"Years of Experience : ";
    cin>>emp[i].exp;
    gotoXY(10,14);
    cout<<"Age : ";
    cin>>emp[i].age;
    gotoXY(10,16);
    cout<<"Enter Working Hours : ";
    cin>>h;
    sal = h*300;
    emp[i].workingHours = h;
    do
    {
        gotoXY(10,18);
        cout<<"Any Loan (Y/N) ?: \b \b";
        loan=getche();
        if(loan=='Y'|| loan == 'y' || loan =='n' || loan == 'N')
            break;
    }while(1);
    if(loan=='y'|| loan=='Y')
    {
    gotoXY(10,20);
    cout<<"Enter Loan Balance : ";
    cin>>LoanBal;
    }
    else
    {
        LoanBal=0;
    }
    gotoXY(14,22);
    cout<<"Recorded Succesfully...!!!";

    TAX =  0.04 * sal;
    DA = 1.20 * sal;
    PF = 0.12 * sal;
    HRA = sal * 0.27;
    MealA = 300;
    MedicalA = 300;
    TransportA = 300;
    LoanDeb = sal * 0.09;
    if(LoanDeb > LoanBal)
    {
        LoanBal = 0;
        LoanDeb = LoanBal;
    }
    emp[i].salary = sal;
    emp[i].DA = DA;
    emp[i].tax=TAX;
    emp[i].PF = PF;
    emp[i].HRA = HRA;
    emp[i].MealAllowance = MealA;
    emp[i].MedicalAllowance = MedicalA;
    emp[i].TransportAllowance = TransportA;
    emp[i].LoanBalance = LoanBal-LoanDeb;
    emp[i].AnyLoan = loan;
    emp[i].LoanDebit = LoanDeb;
    emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
//    getch();
}

void intro()
{
    gotoXY(27,4); printf("PAYROLL MANAGEMENT SYSTEM");
    gotoXY(20,8); printf("");
    gotoXY(20,11); printf("");
    gotoXY(20,13); printf("");
    gotoXY(20,15); printf("");
    gotoXY(24,20);printf("Press Any key to continue...");
    getch();

}

void  list()
{
    //system("cls");
    borderNoDelay();
    gotoXY(20,4);
    printf("       ******** List of the Employees ********");
    gotoXY(6,6);
    cout<<"Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
    gotoXY(6,7);
    cout<<"------------------------------------------------------------------"<<endl;
    for(int i=0,j=8;i<=num-1;i++,j++)
    {
        gotoXY(6,j);
        cout<<emp[i].name;
        gotoXY(19,j);
        cout<<emp[i].code;
        gotoXY(26,j);
        cout<<emp[i].designation;
        gotoXY(47,j);
        cout<<emp[i].exp;
        gotoXY(58,j);
        cout<<emp[i].age;
        gotoXY(66,j);
        cout<<emp[i].grosspay;
    }
    getch();
}

void loading()
{
    system("cls");
    gotoXY(55,20);
    printf("Loading...");
    gotoXY(50,22);
    for(int i = 0; i<20; i++)
    {
        Cdelay(200);
        printf("%c",254);
    }
}
void menu()
{
    //system("cls");
    borderNoDelay();
    //gotoXY(0,0);
    //cout<<"Number of Records Avaliable : "<<num;
    gotoXY(16,4);
    printf("*****  Payroll Management System 1.0 ***** ");
    gotoXY(12,6);
    cout<<"Press  a ----> Add New Record.";
    gotoXY(12,8);
    cout<<"Press  u ----> Update a Record.";
    gotoXY(12,10);
    cout<<"Press  d ----> Delete a Record.";
    gotoXY(12,12);
    cout<<"Press  s ----> Search a Record.";
    gotoXY(12,14);
    cout<<"Press  l ----> List The Employee Table.";
    gotoXY(12,16);
    cout<<"Press  p ----> Print Employee PaySlip.";
    gotoXY(12,18);
    cout<<"Press  q ----> Quit Program.";
    gotoXY(16,22);
    cout<<"Select Your Option ====> ";
}

void deletes()
{
    for(int i=0;i<num;i++)
    {
        tempemp[i]=emp[i];
    }
    //system("cls");
    borderNoDelay();
    int code;
    int check=-1;
    gotoXY(28,4);
    printf("Delete a Record");
    gotoXY(10,6);
    cout<<"Enter the JobCode To Delete That Record  :";
    cin>>code;
    int i,j;
    for(i=0;i<=num-1;i++)
    {
         if(emp[i].code==code)
        {
            check=i;
        }
    }
    if(check!=-1)
    {
        for(i=0,j=0;i<=num-1;i++,j++)
        {
            if(i==check)
            {
                i++;
            }
            emp[j]=tempemp[i];
        }
        num--;
    }
}

void search()
{
    //system("cls");
    borderNoDelay();
    int jobcode;
    bool found = false;
    gotoXY(10,4);
    cout<<"You can Search only through the Jobcode of an Employee";
    gotoXY(10,6);
    cout<<"Enter Code Of the Employee : ";
    cin>>jobcode;
    for(int i=0;i<=num-1;i++)
    {
        if(emp[i].code==jobcode)
        {
            gotoXY(6,8);
            cout<<"Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
            gotoXY(6,9);
            cout<<"------------------------------------------------------------------"<<endl;
            gotoXY(6,11);
            cout<<emp[i].name;
            gotoXY(19,11);
            cout<<emp[i].code;
            gotoXY(26,11);
            cout<<emp[i].designation;
            gotoXY(47,11);
            cout<<emp[i].exp;
            gotoXY(58,11);
            cout<<emp[i].age;
            gotoXY(66,11);
            cout<<emp[i].grosspay;
            found = true;
        }
    }
    if(!found)
    {
        gotoXY(26,11);
        cout<<"No records Found...!!!\a";
    }
    getch();
}



void editmenu()
{
    //system("cls");
    borderNoDelay();
    gotoXY(28,4);
    printf("Edit An Entry");
    gotoXY(10,6);
    cout<<"What Do You Want To edit";
    gotoXY(12,8);
    cout<<"n ---------> Name ";
    gotoXY(12,9);
    cout<<"c ---------> Code ";
    gotoXY(12,10);
    cout<<"d ---------> Designation";
    gotoXY(12,11);
    cout<<"e ---------> Experience ";
    gotoXY(12,12);
    cout<<"a ---------> Age";
    gotoXY(12,13);
    cout<<"s ---------> Salary";
    gotoXY(12,14);
    cout<<"q ---------> QUIT";
    gotoXY(10,16);
    cout<<"Enter Choice ---->>>  ";
}

void editname(int i)
{
    gotoXY(10,18);
    cout<<"Enter New Name----->  ";
    cin>>emp[i].name;
}

void editcode(int i)
{
    gotoXY(10,18);
    cout<<"Enter New Job Code----->  ";
    cin>>emp[i].code;
}
void editdes(int i)
{
    gotoXY(10,18);
    cout<<"enter new designation----->  ";
    cin>>emp[i].designation;
}

void editexp(int i)
{
    gotoXY(10,18);
    cout<<"Enter new Years of Experience";
    cin>>emp[i].exp;
}
void editage(int i)
{
    gotoXY(10,18);
    cout<<"Enter new Age ";
    cin>>emp[i].age;
}

void editsalary(int i)
{
    int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal=emp[i].LoanBalance,LoanDeb,DA;
    char loan;
    gotoXY(10,18);
    cout<<"Enter new Salary ";
    cin>>sal;
    DA = 0.50 * sal;
    TAX =  0.1 * sal;
    PF = 0.12 * sal;
    HRA = 4000;
    MealA = 300;
    MedicalA = 3000;
    TransportA = 3000;
    LoanDeb = sal * 0.09;
    if(LoanDeb > LoanBal)
    {
        LoanBal = 0;
        LoanDeb = LoanBal;
    }
    emp[i].salary = sal;
    emp[i].tax=TAX;
    emp[i].PF = PF;
    emp[i].HRA = HRA;
    emp[i].MealAllowance = MealA;
    emp[i].MedicalAllowance = MedicalA;
    emp[i].TransportAllowance = TransportA;
    emp[i].LoanBalance = LoanBal;
    emp[i].AnyLoan = loan;
    emp[i].LoanDebit = LoanDeb;
    emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
}

void edit()
{
    //system("cls");
    borderNoDelay();
    int jobcode;
    gotoXY(28,4);
    printf("Edit a Record");
    int i;
    char option;
    gotoXY(10,6);
    cout<<"Enter the jobcode To Edit : ";
    cin>>jobcode;
    editmenu();
    for(i=0;i<=num-1;i++)
    {
        if(emp[i].code==jobcode)
        {
            while((option=cin.get())!='q')
            {
                switch(option)
                {
                    case 'n':
                        editname(i);
                        break;
                    case 'c':
                        editcode(i);
                        break;
                    case 'd':
                        editdes(i);
                        break;
                    case 'e':
                        editexp(i);
                        break;
                    case 'a':
                        editage(i);
                        break;
                    case 's':
                        editsalary(i);
                        break;
                }
                   editmenu();
            }
        }
    }
}


void displayPayslip()
{
    system("cls");
    borderNoDelay();
    gotoXY(10,4);
    int code,i;
    cout<<"Enter Employee Job Code :";
    cin>>code;
    for(i=0;i<=num-1;i++)
    {
        if(emp[i].code==code)
        {
            gotoXY(12,6);
            cout<<"Name : "<<emp[i].name;
            gotoXY(45,6);
            cout<<"Working Hours : "<<emp[i].workingHours<<" Hrs";
            gotoXY(6,8);
            cout<<"Earnings :-";
            gotoXY(8,10);
            cout<<"Basic Pay : "<<emp[i].salary<<endl;
            gotoXY(8,12);
            cout<<"HRA(27% of Basic): "<<emp[i].HRA<<endl;
            gotoXY(8,14);
            cout<<"DA (120% of Basic):"<<emp[i].DA;
            gotoXY(8,16);
            cout<<"Meal Allowance : "<<emp[i].MealAllowance<<endl;
            gotoXY(8,18);
            cout<<"Medical Alowance : "<<emp[i].MedicalAllowance<<endl;
            gotoXY(8,20);
            cout<<"Transport Allowance : "<<emp[i].TransportAllowance<<endl;
            gotoXY(40,8);
            cout<<"Deductions :- "<<endl<<endl;
            gotoXY(42,10);
            cout<<"PF : "<<emp[i].PF<<endl;
            gotoXY(42,12);
            cout<<"Tax : "<<emp[i].tax<<endl;
            gotoXY(42,14);
            int l = emp[i].AnyLoan;
            char l2 = toupper(l);
            cout<<"Loan Status : "<<l2<<endl;
            gotoXY(42,16);
            cout<<"Loan Debit This Month : "<<emp[i].LoanDebit<<endl;
            gotoXY(42,18);
            cout<<"Loan Balance : "<<emp[i].LoanBalance<<endl;
            gotoXY(32,22);
            cout<<"Total Gross Pay : "<<emp[i].grosspay;
        }
    }
    getch();
}


int main()
{
	getrecords();  

    setWindowSize();
    border();
    intro();
//    loading();
//    loginFrame();
//    login();
    menu();
    getrecords();
    char option;
    if(emp[0].code==0 && isFilePresent())
        num--;
    while(1)
    {
        option=getch();
        switch(option)
        {
            case 'l':
                list();
                break;
            case 'a':
                insert();
                break;
            case 'd':
                deletes();
                break;
            case 'u':
                edit();
                break;
            case 's':
                search();
                break;
            case 'p':
                displayPayslip();
                break;
            case 'q':
                saverecords();
                exit(0);
        }
        menu();
    }


    return 0;
}
