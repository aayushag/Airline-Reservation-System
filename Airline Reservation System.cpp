#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
class flight
{
 int fno;
 char fname[30];
 char destfrom[30],dest_to[30];
 char day[10];
 char arrival[5],departure[5];
 int seats1,seats2,seatsac;
 float fare1,fare2,fareac;
 public:
  void flight_details();
  void add_entry();
  void modify_entry();
  void del_entry();
  void view_entry();
  int ret()
 	{
return fno;
  	}
};		                                     // CLASS DECLARATION
 void flight :: add_entry()               // Function to add a  flight entry
 {
  clrscr();
  gotoxy(30,4);cout<<"ADD ENTRY";
  gotoxy(5,7);cout<<"Flight No.:";cin>>fno;
  gotoxy(5,9);cout<<"Air lines Name:";gets(fname);
  gotoxy(5,11);cout<<"Destination:";
  gotoxy(25,11);cout<<"From:";cin>>destfrom;
  gotoxy(45,11);cout<<"To:";cin>>dest_to;
  gotoxy(5,13);cout<<"Day Of Journey:";cin>>day;
  gotoxy(5,15);cout<<"Time:";
  gotoxy(25,15);cout<<"Arrival:";cin>>arrival;
  gotoxy(45,15);cout<<"Departure:";cin>>departure;
  gotoxy(5,17);cout<<"No. Of Seats:";
  gotoxy(25,17);cout<<"1st Class:";cin>>seats1;
  gotoxy(45,17);cout<<"Economy Class:";cin>>seats2;
  gotoxy(5,19);cout<<"Fare:";
  gotoxy(25,19);cout<<"1st Class:";cin>>fare1;
  gotoxy(45,19);cout<<"Economy Class:";cin>>fare2;
  gotoxy(5,21);cout<<"Press ENTER key to return to PLANE DETAILS MENU";
  getch();
 }

 void flight :: modify_entry()  // Function to modify an existing rentry
 {
   clrscr();
   gotoxy(30,4);cout<<"MODIFY ENTRY";
   gotoxy(5,7);cout<<"Flight Name:";gets(fname);
   gotoxy(5,9);cout<<"Destination:";
   gotoxy(25,9);cout<<"From:";cin>>destfrom;
   gotoxy(45,9);cout<<"To:";cin>>dest_to;
   gotoxy(5,11);cout<<"Day Of Journey:";cin>>day;
   gotoxy(5,13);cout<<"Time:";
   gotoxy(25,13);cout<<"Arrival:";cin>>arrival;
   gotoxy(45,13);cout<<"Departure:";cin>>departure;
   gotoxy(5,15);cout<<"No. Of Seats:";
   gotoxy(25,15);cout<<"1st Class:";cin>>seats1;
   gotoxy(45,15);cout<<"Economy Class:";cin>>seats2;
   gotoxy(5,17);cout<<"Fare:";
   gotoxy(25,17);cout<<"1st Class:";cin>>fare1;
   gotoxy(45,17);cout<<"Economy Class:";cin>>fare2;
 }

 void flight :: del_entry()   // Function to delete an existing entry
 {
   clrscr();
   gotoxy(30,4);cout<<"DELETE ENTRY";
   gotoxy(5,7);cout<<"Flight No.:";cout<<fno;
   gotoxy(5,9);cout<<"Flight Name:";cout<<fname;
   gotoxy(5,11);cout<<"Destination:";
   gotoxy(25,11);cout<<"From:";cout<<destfrom;
   gotoxy(45,11);cout<<"To:";cout<<dest_to;
   gotoxy(5,13);cout<<"Day Of Journey:";cout<<day;
   gotoxy(5,15);cout<<"Time:";
   gotoxy(25,15);cout<<"Arrival:";cout<<arrival;
   gotoxy(45,15);cout<<"Departure:";cout<<departure;
   gotoxy(5,17);cout<<"No. Of Seats:";
   gotoxy(25,17);cout<<"1st Class:";cout<<seats1;
   gotoxy(45,17);cout<<"Economy Class:";cout<<seats2;
   gotoxy(5,19);cout<<"Fare:";
   gotoxy(25,19);cout<<"1st Class:";cout<<fare1;
   gotoxy(45,19);cout<<"Economy Class:";cout<<fare2;
 }

 void flight :: view_entry()    // Function to view entry
 {
   clrscr();
   gotoxy(30,4);cout<<"VIEW ENTRY";
   gotoxy(5,7);cout<<"Flight No.:";cout<<fno;
   gotoxy(5,9);cout<<"Flight Name:";cout<<fname;
   gotoxy(5,11);cout<<"Destination:";
   gotoxy(25,11);cout<<"From:";cout<<destfrom;
   gotoxy(45,11);cout<<"To:";cout<<dest_to;
   gotoxy(5,13);cout<<"Day Of Journey:";cout<<day;
   gotoxy(5,15);cout<<"Time:";
   gotoxy(25,15);cout<<"Arrival;";cout<<arrival;
   gotoxy(45,15);cout<<"Departure:";cout<<departure;
   gotoxy(5,17);cout<<"No. Of Seats:";
   gotoxy(25,17);cout<<"1st Class:";cout<<seats1;
   gotoxy(45,17);cout<<"Economy Class:";cout<<seats2;
   gotoxy(5,19);cout<<"Fare:";
   gotoxy(25,19);cout<<"1st Class:";cout<<fare1;
   gotoxy(45,19);cout<<"Economy Class:";cout<<fare2;
 }

 void add_fentry();
 void modify_fentry();
 void del_fentry();
 void view_fentry();

 void flight_m/ain()
 { 
   int che;
   do
    {
      do
       {    
	  clrscr();
	  gotoxy(18,5);cout<<"**********FIIGHT DETAILS**********";
	  gotoxy(25,7);cout<<"1.ADD ENTRY";
	  gotoxy(25,9);cout<<"2.MODIFY ENTRY";
	  gotoxy(25,11);cout<<"3.DELETE ENTRY";
	  gotoxy(25,13);cout<<"4.VIEW ENTRY";
	  gotoxy(25,15);cout<<"5.GOTO MAIN MENU";
	  gotoxy(25,17);cout<<"Enter Your Choice:";
	  gotoxy(43,17);cin>>che;
        }while(che<1 && che>6);

      switch(che)
        {
           case 1:{
			    add_fentry();
			    break;
		    }

           case 2:{
			     modify_fentry();
			     break;
		    }

           case 3:{
	     		     del_fentry();
			     break;
		   }

          case 4:{
	  		     view_fentry();
			     break;
		  }
        }
    }while(che>=1 && che<=4);

 }

  void add_fentry()
  {fstream f;
  f.open("flight2.dat",ios::app | ios::binary);
  flight F;
  if(!f)
  {
    cout<<"\nFile not found";
	exit(0);
  }
   F.add_entry();
   f.write((char*)&F,sizeof(F));     //Write into the file
   f.close();
}

 void modify_fentry()
 {fstream f,f1;
 f.open("flight2.dat",ios::in | ios::binary);
 flight F;
 if(!f)
 {
     cout<<"\nFile not found";
     exit(0);
 }
  f1.open("temp.dat",ios::out | ios::binary);
  int flighto;
  char ans;
  gotoxy(25,18);cout<<"\nEnter the flight number you want to modify:";
  cin>>flighto;
  f.read((char*)&F,sizeof(F));
  while(!f.eof())
  {
     if(F.ret()!=flighto)            //Checks for the required book
	f1.write((char*)&F,sizeof(F));
     else
      {
          F.view_entry();
	gotoxy(13,21);cout<<"\n    Do you want to modify?";
	cin>>ans;
	if(ans=='Y' || ans=='y')
	{
            F.modify_entry();
	  f1.write((char*)&F,sizeof(F));   //Modifies the record
	}
	else
	  f1.write((char*)&F,sizeof(F));
        }f.read((char*)&F,sizeof(F));
 }
  f.close();
  f1.close();
  remove("flight2.dat");
  rename("temp.dat","flight2.dat");
}

 void del_fentry()
 {
    fstream f,f1;
    f.open("flight2.dat",ios::in | ios::binary);
    flight F;
    if(!f)
     {
        cout<<"\n File not found";
        exit(0);
     }
   f1.open("temp.dat",ios::out | ios::binary);
   int flighto;
   gotoxy(25,18);cout<<"\nEnter the flight no. to delete:";
   cin>>flighto;
   char ans;
   f.seekg(0);
   f.read((char*)&F,sizeof(F));
   while(!f.eof())
    {
          if(F.ret()!=flighto)            //Checks for the required book
	f1.write((char*)&F,sizeof(F));
         else
           {
               F.view_entry();
  	      gotoxy(4,21);cout<<"Do you want to delete?";
	      cin>>ans;
	       if(ans!='y' && ans!='Y')
	       f1.write((char*)&F,sizeof(F));
            }
          f.read((char*)&F,sizeof(F));
   }
  f.close();
  f1.close();
  remove("flight2.dat");
  rename("temp.dat","flight2.dat");
 }

 void view_fentry()
 {
   fstream f;
   f.open("flight2.dat",ios::in | ios::binary);
   flight F;
   if(!f)
   {cout<<"\nFile not found";
    exit(0);
   }
   f.seekg(0,ios::beg);
   f.read((char*)&F,sizeof(F));
   while(!f.eof())
   {
     F.view_entry();
     getch();
     f.read((char*)&F,sizeof(F));
   }
   f.close();
  }



 void delhi();
 void chennai();
 void mumbai();
 void lucknow();
 void pune();
 void hyderabad();
 void aizawl();
 void jaipur();
 void enqury_main()
 {int che;
  do
  {
   do
   {
	clrscr();
	gotoxy(20,3);cout<<"********** ENQURY **********";
	gotoxy(25,5);cout<<"1.DELHI";
	gotoxy(25,7);cout<<"2.CHENNAI";
	gotoxy(25,9);cout<<"3.MUMBAI";
	gotoxy(25,11);cout<<"4.LUCKNOW";
	gotoxy(25,13);cout<<"5.PUNE";
	gotoxy(25,15);cout<<"6.HYDERABAD";
	gotoxy(25,17);cout<<"7.AIZAWL";
	gotoxy(25,19);cout<<"8.JAIPUR";
	gotoxy(25,21);cout<<"9.GOTO MAIN MENU";
	gotoxy(25,23);cout<<"Enter Your Choice:";
	gotoxy(43,23);cin>>che;
    }while(che<1 && che>10);

    switch(che)
     {case 1:{
			 delhi();
			 break;
	        }

      case 2:{
			 chennai();
			 break;
  	       }

      case 3:{
			 mumbai();
			 break;
	        }

      case 4:{
			 lucknow();
			 break;
   	        }

      case 5:{
			 pune();
			 break;
	        }

      case 6:{
			 hyderabad();
			 break;
	        }

      case 7:{
			 aizawl();
			 break;
	         }
       case 8:{
			 jaipur();
			 break;
		}
     }
  } while(che>=1 && che<=8);

 }

 void delhi()
{clrscr();
  gotoxy(5,8);cout<<"         ARRIVAL                                  DEPARTURE";
  gotoxy(5,9);cout<<"IC-263   07-00   DAILY                  IC-401   08-55   DAILY";
  gotoxy(5,10);cout<<"9W-921   06-30   DAILY             9W-901   08-15   DAILY";
  gotoxy(5,11);cout<<"9W-902   08-55   DAILY             9W-922   19-55   DAILY";
  gotoxy(5,12);cout<<"IC-201   17-00   DAILY                IC-202   20-05   DAILY";
  gotoxy(5,13);cout<<"IC-402   18-45   DAILY                IC-402   20-00   DAILY";
  gotoxy(5,14);cout<<"S2-101   09-30   DAILY               S2-109   11-30   DAILY";
  gotoxy(5,15);cout<<"DN-402   11-45   DAILY             DN-405   13-55   DAILY";
  gotoxy(5,16);cout<<"S2-222   23-00   DAILY               S2-221   06-05   DAILY";
  gotoxy(5,17);cout<<"IT-608   11-05   DAILY                 IT-601   18-15   DAILY";
  gotoxy(5,18);cout<<"S2-010   12-55   DAILY               S2-110   13-45   DAILY";
 getch();
}
void chennai()
{clrscr();
  gotoxy(5,8);cout<<"          ARRIVAL                                  DEPARTURE";
  gotoxy(5,9);cout<<"IC-263   07-00   DAILY                  IC-401   08-55   DAILY";
  gotoxy(5,10);cout<<"9W-921   06-30   DAILY             9W-901   08-15   DAILY";
  gotoxy(5,11);cout<<"9W-902   08-55   DAILY             9W-922   19-55   DAILY";
  gotoxy(5,12);cout<<"IC-201   17-00   DAILY                IC-202   20-05   DAILY";
  gotoxy(5,13);cout<<"IC-402   18-45   DAILY                IC-402   20-00   DAILY";
  gotoxy(5,14);cout<<"S2-101   09-30   DAILY               S2-109   11-30   DAILY";
  gotoxy(5,15);cout<<"DN-402   11-45   DAILY             DN-405   13-55   DAILY";
  gotoxy(5,16);cout<<"S2-222   23-00   DAILY               S2-221   06-05   DAILY";
  gotoxy(5,17);cout<<"IT-608   11-05   DAILY                 IT-601   18-15   DAILY";
  gotoxy(5,18);cout<<"S2-010   12-55   DAILY               S2-110   13-45   DAILY";
 getch();
}
void mumbai()
{clrscr();
  gotoxy(5,8);cout<<"          ARRIVAL                                  DEPARTURE";
  gotoxy(5,9);cout<<"IC-263   07-00   DAILY                  IC-401   08-55   DAILY";
  gotoxy(5,10);cout<<"9W-921   06-30   DAILY             9W-901   08-15   DAILY";
  gotoxy(5,11);cout<<"9W-902   08-55   DAILY             9W-922   19-55   DAILY";
  gotoxy(5,12);cout<<"IC-201   17-00   DAILY                IC-202   20-05   DAILY";
  gotoxy(5,13);cout<<"IC-402   18-45   DAILY                IC-402   20-00   DAILY";
  gotoxy(5,14);cout<<"S2-101   09-30   DAILY               S2-109   11-30   DAILY";
  gotoxy(5,15);cout<<"DN-402   11-45   DAILY             DN-405   13-55   DAILY";
  gotoxy(5,16);cout<<"S2-222   23-00   DAILY               S2-221   06-05   DAILY";
  gotoxy(5,17);cout<<"IT-608   11-05   DAILY                 IT-601   18-15   DAILY";
  gotoxy(5,18);cout<<"S2-010   12-55   DAILY               S2-110   13-45   DAILY";
 getch();
}
void lucknow()
{clrscr();
  gotoxy(5,8);cout<<"           ARRIVAL                                  DEPARTURE";
  gotoxy(5,9);cout<<"IC-263   07-00   DAILY                  IC-401   08-55   DAILY";
  gotoxy(5,10);cout<<"9W-921   06-30   DAILY             9W-901   08-15   DAILY";
  gotoxy(5,11);cout<<"9W-902   08-55   DAILY             9W-922   19-55   DAILY";
  gotoxy(5,12);cout<<"IC-201   17-00   DAILY                IC-202   20-05   DAILY";
  gotoxy(5,13);cout<<"IC-402   18-45   DAILY                IC-402   20-00   DAILY";
  gotoxy(5,14);cout<<"S2-101   09-30   DAILY               S2-109   11-30   DAILY";
  gotoxy(5,15);cout<<"DN-402   11-45   DAILY             DN-405   13-55   DAILY";
  gotoxy(5,16);cout<<"S2-222   23-00   DAILY               S2-221   06-05   DAILY";
  gotoxy(5,17);cout<<"IT-608   11-05   DAILY                 IT-601   18-15   DAILY";
  gotoxy(5,18);cout<<"S2-010   12-55   DAILY               S2-110   13-45   DAILY";
 getch();
}
void pune()
{clrscr();
  gotoxy(5,8);cout<<"           ARRIVAL                                  DEPARTURE";
  gotoxy(5,9);cout<<"IC-263   07-00   DAILY                  IC-401   08-55   DAILY";
  gotoxy(5,10);cout<<"9W-921   06-30   DAILY             9W-901   08-15   DAILY";
  gotoxy(5,11);cout<<"9W-902   08-55   DAILY             9W-922   19-55   DAILY";
  gotoxy(5,12);cout<<"IC-201   17-00   DAILY                IC-202   20-05   DAILY";
  gotoxy(5,13);cout<<"IC-402   18-45   DAILY                IC-402   20-00   DAILY";
  gotoxy(5,14);cout<<"S2-101   09-30   DAILY               S2-109   11-30   DAILY";
  gotoxy(5,15);cout<<"DN-402   11-45   DAILY             DN-405   13-55   DAILY";
  gotoxy(5,16);cout<<"S2-222   23-00   DAILY               S2-221   06-05   DAILY";
  gotoxy(5,17);cout<<"IT-608   11-05   DAILY                 IT-601   18-15   DAILY";
  gotoxy(5,18);cout<<"S2-010   12-55   DAILY               S2-110   13-45   DAILY";
 getch();
}
void hyderabad()
{clrscr();
  gotoxy(5,8);cout<<"           ARRIVAL                                  DEPARTURE";
  gotoxy(5,9);cout<<"IC-263   07-00   DAILY                  IC-401   08-55   DAILY";
  gotoxy(5,10);cout<<"9W-921   06-30   DAILY             9W-901   08-15   DAILY";
  gotoxy(5,11);cout<<"9W-902   08-55   DAILY             9W-922   19-55   DAILY";
  gotoxy(5,12);cout<<"IC-201   17-00   DAILY                IC-202   20-05   DAILY";
  gotoxy(5,13);cout<<"IC-402   18-45   DAILY                IC-402   20-00   DAILY";
  gotoxy(5,14);cout<<"S2-101   09-30   DAILY               S2-109   11-30   DAILY";
  gotoxy(5,15);cout<<"DN-402   11-45   DAILY             DN-405   13-55   DAILY";
  gotoxy(5,16);cout<<"S2-222   23-00   DAILY               S2-221   06-05   DAILY";
  gotoxy(5,17);cout<<"IT-608   11-05   DAILY                 IT-601   18-15   DAILY";
  gotoxy(5,18);cout<<"S2-010   12-55   DAILY               S2-110   13-45   DAILY";
 getch();
}
void aizawl()
{clrscr();
  gotoxy(5,8);cout<<"          ARRIVAL                                  DEPARTURE";
  gotoxy(5,9);cout<<"IC-263   07-00   DAILY                  IC-401   08-55   DAILY";
  gotoxy(5,10);cout<<"9W-921   06-30   DAILY             9W-901   08-15   DAILY";
  gotoxy(5,11);cout<<"9W-902   08-55   DAILY             9W-922   19-55   DAILY";
  gotoxy(5,12);cout<<"IC-201   17-00   DAILY                IC-202   20-05   DAILY";
  gotoxy(5,13);cout<<"IC-402   18-45   DAILY                IC-402   20-00   DAILY";
  gotoxy(5,14);cout<<"S2-101   09-30   DAILY               S2-109   11-30   DAILY";
  gotoxy(5,15);cout<<"DN-402   11-45   DAILY             DN-405   13-55   DAILY";
  gotoxy(5,16);cout<<"S2-222   23-00   DAILY               S2-221   06-05   DAILY";
  gotoxy(5,17);cout<<"IT-608   11-05   DAILY                 IT-601   18-15   DAILY";
  gotoxy(5,18);cout<<"S2-010   12-55   DAILY               S2-110   13-45   DAILY";
 getch();

}
void jaipur()
{clrscr();
  gotoxy(5,8);cout<<"         ARRIVAL                                  DEPARTURE";
  gotoxy(5,9);cout<<"IC-263   07-00   DAILY                  IC-401   08-55   DAILY";
  gotoxy(5,10);cout<<"9W-921   06-30   DAILY             9W-901   08-15   DAILY";
  gotoxy(5,11);cout<<"9W-902   08-55   DAILY             9W-922   19-55   DAILY";
  gotoxy(5,12);cout<<"IC-201   17-00   DAILY                IC-202   20-05   DAILY";
  gotoxy(5,13);cout<<"IC-402   18-45   DAILY                IC-402   20-00   DAILY";
  gotoxy(5,14);cout<<"S2-101   09-30   DAILY               S2-109   11-30   DAILY";
  gotoxy(5,15);cout<<"DN-402   11-45   DAILY             DN-405   13-55   DAILY";
  gotoxy(5,16);cout<<"S2-222   23-00   DAILY               S2-221   06-05   DAILY";
  gotoxy(5,17);cout<<"IT-608   11-05   DAILY                 IT-601   18-15   DAILY";
  gotoxy(5,18);cout<<"S2-010   12-55   DAILY               S2-110   13-45   DAILY";
 getch();
 }
class reserve
{private:
			char name[20];
			int age;
			char sex;
			char add[50];
			long int phno;

			int fno;
			char fname[30];
			char destfrom[30],dest_to[30];
			char clas[10];
			int seat;
			float fare;
			int tkno;

 public:
			void reservation();
			void add_rentry();
			void modify_rentry();
			void view_rentry();
			int retu()
			{return tkno;
			}
};                                                                               // CLASS DECLARATION

 void reserve :: add_rentry()                                     //member function of class
 {
  clrscr();
  gotoxy(30,1);cout<<"ADD RESERVATION";
  gotoxy(30,3);cout<<"PASSENGER DETAILS";
  gotoxy(5,5);cout<<"Name:";gets(name);
  gotoxy(5,6);cout<<"Age:";cin>>age;
  gotoxy(5,7);cout<<"Contact Address:";gets(add);
  gotoxy(5,8);cout<<"Contact Phone No:";cin>>phno;
  gotoxy(30,10);cout<<"FLIGHT DETAILS";
  gotoxy(5,12);cout<<"Flight No.:";cin>>fno;
  gotoxy(5,14);cout<<"Destination:";
  gotoxy(25,14);cout<<"From:";cin>>destfrom;
  gotoxy(45,14);cout<<"To:";cin>>dest_to;
  gotoxy(5,15);cout<<"Class of Flight:";cin>>clas;
  gotoxy(5,16);cout<<"No. Of Seats:";cin>>seat;
  gotoxy(5,17);cout<<"Fare:";cin>>fare;
  gotoxy(5,18);cout<<"Ticket No:";cin>>tkno;
  gotoxy(5,19);cout<<"Press ENTER key to return to RESERVATION DETAILS MENU";
  getch();
 }

 void reserve :: modify_rentry()      //member func of class
 {
  clrscr();
  gotoxy(30,1);cout<<"MODIFY RESERVATION";
  gotoxy(30,3);cout<<"PASSENGER DETAILS";
  gotoxy(5,5);cout<<"Name:";gets(name);
  gotoxy(5,6);cout<<"Age:";cin>>age;
  gotoxy(5,7);cout<<"Contact Address:";cin>>add;
  gotoxy(5,8);cout<<"Contact Phone No:";cin>>phno;
  gotoxy(30,10);cout<<"FLIGHT DETAILS";
  gotoxy(5,12);cout<<"Flight No.:";cin>>fno;
  gotoxy(5,14);cout<<"Destination:";
  gotoxy(25,14);cout<<"From:";cin>>destfrom;
  gotoxy(45,14);cout<<"To:";cin>>dest_to;
  gotoxy(5,15);cout<<"Class of Flight:";cin>>clas;
  gotoxy(5,16);cout<<"No. Of Seats:";cin>>seat;
  gotoxy(5,17);cout<<"Fare:";cin>>fare;
 }

void reserve :: view_rentry()         //member func of class
{
  clrscr();
  gotoxy(30,1);cout<<"VIEW RESERVATION";
  gotoxy(30,3);cout<<"PASSENGER DETAILS";
  gotoxy(5,5);cout<<"Name:";cout<<name;
  gotoxy(5,6);cout<<"Age:";cout<<age;
  gotoxy(5,7);cout<<"Contact Address:";cout<<add;
  gotoxy(5,8);cout<<"Contact Phone No:";cout<<phno;
  gotoxy(30,10);cout<<"FLIGHT DETAILS";
  gotoxy(5,12);cout<<"Flight No.:";cout<<fno;
  gotoxy(5,13);cout<<"Flight Name:";cout<<fname;
  gotoxy(5,14);cout<<"Destination:";
  gotoxy(25,14);cout<<"From:";cout<<destfrom;
  gotoxy(45,14);cout<<"To:";cout<<dest_to;
  gotoxy(5,15);cout<<"Class of Plane:";cout<<clas;
  gotoxy(5,16);cout<<"No. Of Seats:";cout<<seat;
  gotoxy(5,17);cout<<"Fare:";cout<<fare;
  gotoxy(5,18);cout<<"Ticket No:";cout<<tkno;
 }

 void add_record();
 void modify_record();
 void view_record();

 void reservation_main()
 {int ch;
  do
  {
  do
  {
	clrscr();
	gotoxy(18,5);cout<<"********** RESERVATION DETAILS **********";
	gotoxy(25,7);cout<<"1.ADD RESERVATION";
	gotoxy(25,9);cout<<"2.MODIFY RESERVATION";
	gotoxy(25,11);cout<<"3.VIEW RESERVATION";
	gotoxy(25,13);cout<<"4.GOTO MAIN MENU";
	gotoxy(25,15);cout<<"Enter Your Choice:";
	gotoxy(43,15);cin>>ch;
  }while(ch<1 && ch>4);

  switch(ch)
  {case 1:{
			  add_record();
			  break;
			 }

	case 2:{
			  modify_record();
			  break;
			 }

	case 3:{
			  view_record();
			  break;
			 }
  }
  }while(ch>=1 && ch<=3);
 }


 void add_record()
 {fstream f;
  f.open("reserve1.dat",ios::app | ios::binary);
  reserve R;
  if(!f)
  {cout<<"\nFile not found";
	exit(0);
  }
  R.add_rentry();
  f.write((char*)&R,sizeof(R));     //Write into the file
  f.close();
 }


void modify_record()
{fstream f,f1;
 f.open("reserve1.dat",ios::in | ios::binary);
 reserve R;
 if(!f)
 {cout<<"\nFile not found";
  exit(0);
 }
 f1.open("temp.dat",ios::out | ios::binary);
 int ticno;
 char ans;
 gotoxy(5,16);cout<<"\nEnter the ticket number you want to modify:";
 cin>>ticno;
 f.read((char*)&R,sizeof(R));
 while(!f.eof())
 {if(R.retu()!=ticno)            //Checks for the required book
	f1.write((char*)&R,sizeof(R));
  else
  {R.view_rentry();
	gotoxy(5,19);cout<<"\n    Do you want to modify?";
	cin>>ans;
	if(ans=='Y' || ans=='y')
	{R.modify_rentry();
	 f1.write((char*)&R,sizeof(R));   //Modifies the record
	}
	else
	 f1.write((char*)&R,sizeof(R));
  }
  f.read((char*)&R,sizeof(R));
 }
 f.close();
 f1.close();
 remove("reserve1.dat");
 rename("temp.dat","reserve1.dat");
}


void view_record()
{fstream f;
 f.open("reserve1.dat",ios::in | ios::binary);
 reserve R;
 if(!f)
 {cout<<"\nFile not found\n";
  exit(0);
 }
 f.seekg(0,ios::beg);
 f.read((char*)&R,sizeof(R));
 while(!f.eof())
 {
  R.view_rentry();
  getch();
  f.read((char*)&R,sizeof(R));
 }
 f.close();
}

void main()
{clrscr();
 gotoxy(34,10);cout<<"WELCOME TO";
 gotoxy(26,13);cout<<"AIRLINE MANAGEMENT SOFTWARE";
 gotoxy(1,21);cout<<"Press any key to continue";
 getch();
 int ch;
 do{
 do{
 clrscr();
gotoxy(20,1);cout<<"**********  MAIN MENU  **********";
 gotoxy(25,5);cout<<"1.FLIGHT DETAILS";
 gotoxy(25,7);cout<<"2.RESERVATION DETAILS";
 gotoxy(25,9);cout<<"3.ENQURY";
 gotoxy(25,11);cout<<"4.EXIT";
 gotoxy(25,13);cout<<"Enter Your Choice: ";
 gotoxy(43,13);cin>>ch;
 }while(ch<0 && ch>5);
 switch(ch)
 {
  case 1: {			flight_main();
				break;			  }

	case 2: {			reservation_main();
				break;		  }
	case 3:{			enqury_main();
				break;			}

	case 4: {clrscr();		gotoxy(31,8);cout<<"THANK YOU";
				gotoxy(31,10);cout<<"FOR USING";
				gotoxy(23,13);cout<<"AIRLINE MANAGEMENT SOFTWARE";
				exit(0);
				break;
				}
 }
 }while(ch>=0 && ch<5);
}
