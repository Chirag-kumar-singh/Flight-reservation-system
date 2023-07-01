// FLIGHT RESERVATION SYSTEM

#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
using namespace std;

void f();

class Management{
    public:
        Management(){
            f();
        }
};

int i = -1;
vector<pair<string, bool> > cust;

class Details{
    protected:
        static string name;
        string address;
        int age;
        long long int phoneNo;
        string uniqueID;

    public:
        
        void information(){
            cout << "\nEnter your name: ";
            cin.ignore();
            getline(cin, name);
            cust.push_back({name, true}); i++;
            cout << "\nEnter your age: ";
            cin >> age;
            cin.ignore();
            cout << "\nEnter your phone number: ";
            cin >> phoneNo;
            cin.ignore();
            cout << "\nEnter your unique identification card number(Adhaar/PAN/Driving Licence/...) ";
            getline(cin, uniqueID);
            cout << "\nEnter your address: ";
            getline(cin, address);

            cout << "\n\nYOUR DETAILS ARE SAVED WITH US!\n" << endl << endl;
            
        }
};

            
string Details::name;

void func();
void create();

class Payment{
protected:
    static int choice1;
    static int pch;
public:
    void payment(double c, string src, string dest){
            cout << "\n\n\t\t\t***************PAYMENT PORTAL***************" << endl;
            cout << "\n\n\n";
            cout << "Source: " << src << "\t" << "Destination: " << dest << endl;
            cout << "Class: " << "Business" << endl;
            cout << "Amount: " << c << endl << endl;

            cout << "\nSelect your Payment method : " << endl;
            cout << "\n1. Debit/Credit Card" << endl;
            cout << "2. UPI " << endl;

            // int choice;
            cin >> choice1;

            switch(choice1){
                case 1:
                {
                    string cardNo;
                    cout << "Enter your Card Number: ";
                    cin >> cardNo;
                    string cvv;
                    cout << "Enter CVV: ";
                    cin >> cvv;
                    cout << "OTP has been sent your registered mobile number: ";
                    int otp;
                    cin >> otp;

                    cout << "\nYour Payment is successfull!!!" << endl;
                    break;
                }
                case 2:
                {
                    string upi;
                    cout << "Enter UPI Id: ";
                    cin >> upi;

                    int pin;
                    cout << "Enter 6-digit UPI pin: ";
                    cin >> pin;

                    cout << "\nYOUR PAYMENT IS SUCCESSFULL!!!" << endl;
                    break;
                }
                default:
                {
                    cout << "\nPLEASE ENTER A VALID OPTION!!" << endl;
                    break;
                }
            }

            cout << "\n\nYOUR TICKET IS GENERATED" << "\n";
            cout << "\nPress 1 to print it" << endl;
            cin >> pch;
            
            create();

            if(pch == 1){
                func();
            }
            else{
                f();
            }
        }
};

int Payment::choice1;
int Payment::pch;

class Flight{
    protected:
        int choice1, choice2, back;
        unordered_map<string, list<pair<pair<string, string>, double> > > mp;
        static string source, dest, code;
        static double kharcha;
        static string choice;

    public:

        void addFlights(){
            string src, dest, code;
            double cost;
            cout << "Enter Source: ";
            cin >> src;
            cout << "Enter Destination: ";
            cin >> dest;
            cout << "Enter the flight code: ";
            cin >> code;
            cout << "Enter the price: "; cin >> cost;
            mp[src].push_back({{dest, code}, cost});
        }

        Flight(){
            // mp <src, {{dest, code}, cost}>
            mp["Delhi"].push_back({{"Chennai", "DC-101"}, 7000});
            mp["Chennai"].push_back({{"Delhi", "DC-102"}, 7000});
            mp["Chennai"].push_back({{"Kolkata", "KC-111"}, 8500});
            mp["Kolkata"].push_back({{"Chennai", "KC-112"}, 8500});
            mp["Delhi"].push_back({{"Mumbai","DM-696"}, 5500});
            mp["Mumbai"].push_back({{"Delhi","DM-697"}, 5500});
            mp["Delhi"].push_back({{"Bengaluru","BD-231"}, 6700});
            mp["Bengaluru"].push_back({{"Delhi","BD-232"}, 6700});
            mp["Lucknow"].push_back({{"Hyderabad","LH-333"}, 8100});
            mp["Hyderabad"].push_back({{"Lucknow","LH-334"}, 8100});
            mp["Hyderabad"].push_back({{"Delhi","LD-314"}, 6700});
            mp["Delhi"].push_back({{"Hyderabad","LD-315"}, 6700});
            mp["Delhi"].push_back({{"Kolkata","KD-104"}, 5678});
            mp["Kolkata"].push_back({{"Delhi","KD-103"}, 5678});
        }

        void display(){
            cout << "\n\n\n\n";
            // cout << "\t\t\t\t\tThe available flights are\n" << endl;
            cout << "\n____________________________________________________\n\n";
            cout << "----------------------------------------------------\n";
            cout << "|SOURCE|    " << "|DESTINATION|    " << "|FLIGHT CODE|  " << "  |FARE| \n";
            cout << "----------------------------------------------------\n";
            cout << "____________________________________________________\n\n";

            for(auto i: mp){
                int sp = 12;
                for(auto j: i.second){
                    int len1 = i.first.length();
                    int k = sp - len1;
                    
                    cout << i.first;
                    while(k){cout << " "; k--;}
                    int len2 = j.first.first.length();
                    int l = sp - len2;
                    cout << j.first.first; while(l){cout << " "; l--;}
                    cout << "     " << j.first.second << "\t      " << j.second << endl; 
                }
            }
            cout << "____________________________________________________" << endl;
            cout << "\n\n\n\n";
        }


        void flights(){
            cout << "\nEnter Source: ";
            cin >> source;
            cout << "\nEnter Destination: ";
            cin >> dest;
            
            
            bool found = false;
            for(auto i: mp){
                auto src = i.first;
                int sp = 12;
                for(auto j: i.second){
                    if(src == source && j.first.first == dest){
                        found = true;
                        code = j.first.second;
                        kharcha = j.second;
                        int len1 = i.first.length();
                        int k = sp - len1;
                        cout << "\n\n\n" << "Source      " << "Destination      " << "Flight Code    " << "  Fare  " << endl;
                        cout << src;
                        while(k){cout << " "; k--;}
                        int len2 = j.first.first.length();
                        int l = sp - len2;
                        cout << j.first.first; while(l){cout << " "; l--;}
                        cout << "      " << j.first.second << "\t      " << j.second << endl;
                    }
                }
            }
            if(found == false) {
                cout << "\n\nNO FLIGHTS AVAILABLE\n" << endl;
                f();
            }
            else{
                
                cout<< "\n\n\nWe have two classes available : \nBusiness\nEconomy"<<endl ; 
                cout << "\n\nEnter your choice : ";
                cin>>choice;
                cout << endl;
                cout << "\n\nEnter passenger details" << endl;
                Details d;
                d.information();

                Payment p;
                p.payment(kharcha, source, dest);


            }
        }
};

string Flight::code;
string Flight::source;
string Flight::dest;
double Flight::kharcha;
string Flight::choice;

class Ticket: public Details, public Flight, public Payment{
    public:

        void print(){
            cout << endl << endl << endl;
            cout << "\t\t\t__________________________________________________" << endl;
            cout << "\t\t\t__________________BOARDING PASS___________________" << endl;
            
            cout << "\t\t\tPassenger Name: " << Details::name << endl;
            cout << "\t\t\tTicket No. " << i + 1000 << "\t\t" << "Flight Code: " << Flight::code << endl;
            time_t now = time(0);
            tm *ltm = localtime(&now);
            
            cout << "\t\t\tFrom: " << Flight::source << "\t"  << "To: " << Flight::dest << "\t" << "Timing: " << ltm -> tm_hour << ":" << ltm -> tm_min << endl;
            cout << "\t\t\tBoarding Date: " << 1 + ltm -> tm_mday << "/" << 1 + ltm -> tm_mon << "/" << 1900 + ltm -> tm_year << endl;
            int n = 150;
            cout << "\t\t\tSeat: " << 1 + (rand() % n) << "\t\t" << "Class: " << choice<<endl;
            if(Payment::choice1 == 1){
                cout << "\t\t\tPayment Method: Card" << endl;
            }
            else if(Payment::choice1 == 2){
                cout << "\t\t\tPayment Method: UPI" << endl;
            }
            cout << "\t\t\tAmount: " << Flight::kharcha << endl; 


            cout << "\n\n\n\n\n";
        }
};

class File: public Ticket{
    public:

         void Makefile(){
            // // |CustomerID|    |Customer Name|   |Source|    |Destination|    |Flight Code|   |Fare|
           ofstream out;

            out.open("file.txt", ios::app);

            if(!out){
                cout << "\nCAN'T OPEN FILE" << endl;
                return;
            }
        
            out << "|Ticket No: " << i + 1000 << "|"  << "|Customer Name: " << Details::name << "|" <<"|Source: "<< Flight::source << "|"  <<"|Destination: "<< Flight::dest << "|" << "|Flight No: " << Flight::code << "|" << "|Amount: " << Flight::kharcha << "||||"<< endl;  
            out.close();
        }

        void readFile(){

            ifstream in("file.txt");
            string s;
            while(!in.eof()){
                getline(in, s);
                cout << s << endl;
            }
            in.close();
        }

        void update(){
            
        }

};

void create(){
    File f;
    f.Makefile();
}

void func(){
    Ticket t;
    t.print();
}

void f(){
    int c1, c2, back;
    cout << endl << endl;
    cout << "\t\t\t\t           INDIAN AIRLINES              " << endl;
    cout << "\t\t\t_______________________________________________________" << endl;
    cout << endl; 
    cout << "\t\t\t\t\tWELCOME TO INDIAN AIRLINES" << endl;
    cout << "\t\t\t_._._._._._._._._._._.MAIN MENU_._._._._._._._._._._._.\n" << endl;
    cout << "\t\t\tYou can book your Flight (Press 1) " << endl;
    cout << "\t\t\tKnow your current booking status (Press 2)" << endl;
    cout << "\t\t\tCancel Ticket (Press 3)" << endl;
    cout << "\t\t\tPress 4 to exit" << endl;
    cout << "\t\t\t_______________________________________________________" << endl;

    cout << "\nEnter your choice: ";
    cin >> c1;

    Details d;
    Flight fl;
    Ticket t;
    switch(c1){
        case 1:
        {
            cout << "\n\n________________BOOK YOUR FLIGHT USING THIS PORTAL__________________\n\n" << endl;
            
            fl.flights();

            break;
            
        }

        case 2:
        {
            cout << "Enter the Ticket No: ";
            int n;
            cin >> n;

            n = n - 1000;
            if(cust[n].second){
                cout << "\n\nCONFIRMED!!!\n" << endl;
                cout << "Wish you a Happy and a Safe journey :)\n\n";

                cout << "Press 1 to print your Boarding Pass\n";
                int ch;
                cin >> ch;
                if(ch == 1){
                    Ticket t;
                    t.print();
                }
                else{
                    f();
                }
            }
            else{
                cout << "\n\nNO SUCH BOOKING EXIST\n\n";
            }

            break;
        }

        case 3:
        {
            cout << "Enter the ticket number: ";
            int ch;
            cin >> ch;

            if(cust[ch-1000].second){

                cout << "Are your sure you want to cancel your booking? [Yes/No]" << endl;
                string s;
                cin >> s;
                if(s == "Yes"){
                    cust[ch-1000].second = false;
                    cout << "\nYOUR BOOKING IS SUCCESSFULLY CANCELLED!\n" << endl;
                }
                else{
                    cout << "\n\n\t\t________THANK YOU________\n\n\n" << endl;
                }
            }

            break; 
        }
        case 4:
        {
            cout << "\n\n\t\t________THANK YOU________\n\n\n" << endl;
            break;
        }

        default:
        {
            cout << "\nINVALID INPUT, Please try again!\n" << endl;
            f();
            break;
        }
    }
}

int main(){

    cout << "\n\n";

    cout<<"                                   \t\t WELCOME TO INDIAN AIRLINES\n\n\n";
    cout <<"                                  \t\tYOUR COMFORT IS OUR DUTY\n\n\n";
    cout<<"                            \t\t\tPRESS ENTER TO CONTINUE....\n\n";
     if(cin.get()=='\n'){
        int choice,ch1,ch2;
        File obj;
        Flight f;
    MAIN:
      
        cout << "\n\nWho are You?\n";
        cout << "1. ADMIN\n";
        cout << "2. USER\n\n";
        cout << "Enter any other key for exit\n\n\n";
        cout << "Enter Your Option\n";
        cin >> choice;
        switch(choice) {
            case 1:
            ADMIN:
                    
                    cout<<"\n\nWELCOME ADMIN :) \n\n";
                    cout<<"Enter your option: \n";
                    cout<<"1. Booking Details\n";
                    cout<<"2. Flight Details\n";
                    cout << "3. Add Flights\n";
                    cout<<"Enter any other key to go back to Main Menu\n\n";
                    cout<<"\nENTER UR CHOICE: ";
                    cin>>ch1;
                    switch(ch1){
                        case 1:
                            obj.readFile();
                            break;
                        case 2:
                            f.display();
                            break;
                        case 3:
                            f.addFlights();
                            break;
                        default:
                            goto MAIN;
                    }
                cout << "Press 1 to go back to Main menu!" << endl;
                cout << "Else go back to Admin interface!" << endl;
                cin >> ch1;
                if (ch1 == 1) goto MAIN;
                else goto ADMIN;
                break;
            case 2:
            {    
                Management m;
                goto MAIN;
                break;
            }
            default:
                cout << "\n\n\t\t________THANK YOU________\n\n\n" << endl;
                exit(0);
        }
    }
    
    return 0;
}
