#include <iostream>

#include<fstream>

#include<time.h>

#include<string.h>

using namespace std;

/************STRUCTURE********/
struct date {
  int dd, mm, yy;
};
typedef struct date Date;
/************Function prototypes********/
void menu();
int alotPNO();
void book();
void update();
void diagnosis();
void showPatient();
void showAll();
Date getTimefx();
int Login();
/********************/

/************Class********/
class record {
  char name[30];
  int age;
  char gender;
  char apointment_time;
  int pno;
  char problem[100];
  char diagnose[100];


public:
 int dd, mm, yy;
    void savePno(int n)
    {
      pno=n;
    }
  void getTime(){
      Date get;
      get = getTimefx();
      dd=get.dd;
      mm=get.mm;
      yy=get.yy;
  }
  void book() {
    char ch=' ';
    cin.get(ch);
    cout << "Enter the patient name: ";
    cin.getline(name, 30);
    cout << "Enter the patient's age: ";
    cin>>age;
    cout << "Enter the patient's gender(M/F): ";
    cin>>gender;
    cin.get(ch);
    cout << "Enter problem(<100 characters): ";
    cin.getline(problem, 100);
    getTime();
    cout<<"Appointment date "<<dd<<"-"<<mm<<"-"<<yy<<endl;



  }
  void diagnosisfx()
  { char ch=' ';
  cin.get(ch);
  cout<<"Enter Diagnosis Information"<<endl;
  cin.getline(diagnose,100);
  }
  void show()
  {
cout<<"Patient ("<<pno<<") Details"<<endl;
cout<<"Name: "<<name<<endl;
cout<<"Age: "<<age<<endl;
cout<<"Gender: "<<gender<<endl;
cout<<"Problem: "<<problem<<endl;
cout<<"Appointment date "<<dd<<"-"<<mm<<"-"<<yy<<endl;
cout<<"Diagnosis Information: "<<endl;
cout<<diagnose;

  }
  void updatefx()
  {
  char cho;
  char ch=' ';
      cout<<"\n\nWant to Update NAME?(Y/N)"<<endl;
      cin>>cho;
      if(cho=='Y' || cho=='y')
      {

      cin.get(ch);
      cout << "Enter the NEW name: ";
      cin.getline(name, 30);
      }

      cout<<"Want to Update AGE?(Y/N)"<<endl;
      cin>>cho;
      if(cho=='Y' || cho=='y')
      {
      cout << "Enter the new age: ";
      cin>>age;
      }

      cout<<"Want to Update GENDER?(Y/N)"<<endl;
      cin>>cho;
      if(cho=='Y' || cho=='y')
      {
      cout << "Enter new gender(M/F): ";
      cin>>gender;
      }

      cout<<"Want to Update PROBLEM?(Y/N)"<<endl;
      cin>>cho;
      if(cho=='Y' || cho=='y')
      {
      cin.get(ch);
      cout << "Enter new problem(<100 characters): ";
      cin.getline(problem, 100);
      }

      cout<<"Want to Update DIAGNOSIS INFORMATION?(Y/N)"<<endl;
      cin>>cho;
      if(cho=='Y' || cho=='y')
      {
      cin.get(ch);
      cout<<"Enter new Diagnosis Information"<<endl;
      cin.getline(diagnose,100);
      }


  }
  };
/********************/

int main(){
cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t@@|                                           		                                  |@@\n";
cout<<"\t@@|                                           		                                  |@@\n";
cout<<"\t@@|                                           		                                  |@@\n";
cout<<"\t@@|                                           		                                  |@@\n";
cout<<"\t@@|                                           		                                  |@@\n";
cout<<"\t@@|                                           		                                  |@@\n";
cout<<"\t@@|                                  WELCOME TO                                           |@@\n";
cout<<"\t@@|                                                                                       |@@\n";
cout<<"\t@@|                           HOSPITAL MANAGEMENT SYSTEM                                  |@@\n";
cout<<"\t@@|                                                                                       |@@\n";
cout<<"\t@@|                                                                                       |@@\n";
cout<<"\t@@|                                                                                       |@@\n";
cout<<"\t@@|                                                                                       |@@\n";
cout<<"\t@@|                                                                                       |@@\n";
cout<<"\t@@|                                                                                       |@@\n";
cout<<"\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\t\t\t\t\t"<<endl;
system("pause");
system("CLS");
int login=Login();
while(login==1)
{menu();
cout<<endl<<endl;
system("pause");
system("CLS");
}

    return 0;
}

/*********FUNCTIONS***********/
//MENU
void menu() {
  int opt;
  cout << "Please Select an option!!!" << endl;
  cout << "1. Book Appointment\n" <<
          "2. Update Patient information\n" <<
          "3. Enter patient Diagnosis information\n" <<
          "4. Show patient information\n" <<
          "5. Show all records\n";
  cin >> opt;

  switch (opt) {
  case 1:
    book();
    break;
  case 2:
    update();
    break;
  case 3:
    diagnosis();
    break;
  case 4:
    showPatient();
    break;
  case 5:
    showAll();
    break;
  default:
    cout << "Incorrect option!!!!" << endl;

  }
}
//TO AUTOMATICALLY ALLOT PATIENT'S NUMBER
int alotPNO() {
  int PNO = 1000;
  ifstream fin;
  fin.open("patient\\" + std::to_string(PNO) + ".dat");
  if (fin.fail())
    {PNO = 1000;}
  else
  {

    while (1)
{
      fin.close();
      ifstream fin("patient\\" + std::to_string(PNO) + ".dat");
      if (!fin.fail())
        PNO++;
      else break;
}
  }

  fin.close();

  return PNO;
}
//TO ALLOT APPOINTMENT TIME
Date getTimefx(){
  record s1;
  Date dat;
  time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  dat.dd=timeinfo->tm_mday;
  dat.mm=timeinfo->tm_mon+1;
  dat.yy=timeinfo->tm_year+1900;
  int PNO = 1000,ct=1;
  ifstream fin;
  fin.open("patient\\" + std::to_string(PNO) + ".dat");
  if (fin.fail()) {
    timeinfo = localtime (&rawtime);
    dat.dd=timeinfo->tm_mday;
    dat.mm=timeinfo->tm_mon+1;
    dat.yy=timeinfo->tm_year+1900;

  }
  else
{

while (1)
    {
      fin.close();
      ifstream fin("patient\\" + std::to_string(PNO) + ".dat");
      if (!fin.fail())
        {PNO++;}
      else break;

    }
    PNO--;
    fin.close();
    ifstream fin("patient\\" + std::to_string(PNO) + ".dat");
    fin.read((char*)&s1,sizeof(s1));
    int ht=s1.dd;
    int mt=s1.mm;
    int yt=s1.yy;

while(1)
{
    ifstream fin("patient\\" + std::to_string(PNO) + ".dat");
    fin.read((char*)&s1,sizeof(s1));
    if (fin.fail())
        {
         break;
        }

    if(ht==s1.dd)
    {
    ct++;
    PNO--;


    }
    else
    {fin.close();
    break;
    }
}

    if(ct<=5)
    {
       dat.dd=ht;
    }
    else
  {
    if((ht+1)>30)
    {
    dat.dd=1;
    if((mt+1)>12)
    {
      dat.yy=yt+1;
    }
    else dat.mm=mt+1;

    }
   else dat.dd=ht+1;
  }

}

  fin.close();

  return dat;
  }
  //TO BOOK APPOINTMENT
void book() {
  record rw;
  rw.book();
  int p = alotPNO();
  cout << "THE ALLOTED PATIENT'S NUMBER: "<<p;
  rw.savePno(p);
  ofstream fout;
  fout.open("patient\\" + std::to_string(p) + ".dat");
  fout.write((char * ) & rw, sizeof(rw));
  fout.close();
}
//TO UPDATE DETAILS
void update() {
   record s1;
   int PNO;
   cout<<"Enter Patient's Number to be updated: "<<endl;
   cin>>PNO;
   ifstream fin;
   fin.open("patient\\" + std::to_string(PNO) + ".dat");
   fin.read((char*)&s1, sizeof(s1));
   s1.show();
   s1.updatefx();
   fin.close();
   ofstream fout;
   fout.open("patient\\" + std::to_string(PNO) + ".dat");
   fout.write((char * ) & s1, sizeof(s1));
   fout.close();

}
//TO ENTER DIAGNOSIS INFORMATION
void diagnosis() {
    int PNO;
    record s1;
    cout<<"Enter the patient No. whose diagnosis information you wish to enter"<<endl;
    cin>>PNO;
    ifstream fin("patient\\" + std::to_string(PNO) + ".dat");
    fin.read((char*)&s1,sizeof(s1));
    s1.diagnosisfx();
    fin.close();
    ofstream fout;
    fout.open("patient\\" + std::to_string(PNO) + ".dat");
    fout.write((char*)&s1, sizeof(s1));
    fout.close();
}
// TO SHOW A PATIENT'S DETAILS
void showPatient() {
    record s1;
    int PNO;
    cout<<"Enter Patient's Number: "<<endl;
    cin>>PNO;
    ifstream fin;
    fin.open("patient\\" + std::to_string(PNO) + ".dat");
    fin.read((char*)&s1, sizeof(s1));
    s1.show();
    fin.close();
}
//TO SHOW ALL DETAILS
void showAll() {
    int PNO=1000;
    record s1;
    while (1) {
    ifstream fin("patient\\" + std::to_string(PNO) + ".dat");
    if (!fin.fail())
    {
        PNO++;
        fin.close();
    }

else  break;


}
for(int i=1000;i<PNO;i++)
{
    ifstream fin("patient\\" + std::to_string(i) + ".dat");
    fin.read((char*)&s1, sizeof(s1));
    cout<<"\n\n";
    s1.show();
    cout<<"\n\n--------------------------------------";
    fin.close();
}

}
//FUNCTION FOR LOGIN
int Login(){
   char pass[3];
   cout<<"\n\n\n\n\n\n\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
   cout<<"\t\t\t------------------------------";
   cout<<"\n\t\t\t\t     LOGIN \n";
   cout<<"\t\t\t------------------------------\n\n";
   cout << "\t\tEnter Password: ";
   cin>>pass;
   cout<<pass;
   if(strcmp(pass,"pass")==0){
      cout << "\n\n\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
      return 1;
     }
   else{
      cout << "\n\n\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      Login();
   }
}
