#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;

void clrscr(){
    system("cls");
}

class bank{
private:
    int pin;
    float balance;
    string id, pass, name, fname, phone, address;
public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void already_user();
    void withdraw();
    void deposit();
    void transfer();
    void payment();
    void search();
    void edit();
    void del();
    void show_records();
    void show_payment();
    void user_balance();
    void withdraw_atm();
    void account_detail();
};

void bank::menu(){
    p:
    clrscr();
    int choice;
    cout << "\n\n\t\tControl Panel";
    cout << "\n\n 1. Bank Management";
    cout << "\n 2. ATM Management";
    cout << "\n 3. Exit";
    cout << "\n\n Enter Your Choice [1-3] : ";
    cin >> choice;
    switch(choice){
    case 1:
        clrscr();
        bank_management();
        break;
    case 2:
        atm_management();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "\n\n Invalid Value...Please Try Again";
    }
    getch();
    goto p;
}

void bank::bank_management(){
c:
    clrscr();
    int choice;
    cout<<"\n\n\t\t\tBank Management";
    cout<<"\n\n 1. New User";
    cout<<"\n\n 2. Already User";
    cout<<"\n\n 3. Deposit";
    cout<<"\n\n 4. Withdraw";
    cout<<"\n\n 5. Transfer";
    cout<<"\n\n 6. Payment";
    cout<<"\n\n 7. Search User Record";
    cout<<"\n\n 8. Edit User Record";
    cout<<"\n\n 9. Delete User Record";
    cout<<"\n\n 10. Show All Records";
    cout<<"\n\n 11. Payment All Records";
    cout<<"\n\n 12. Go Back";
    cout<<"\n\n Enter Your Choice [1-12] : ";
    cin>>choice;
    switch(choice){
    case 1 :
        new_user();
        break;
    case 2 :
        already_user();
        break;
    case 3 :
        deposit();
        break;
    case 4 :
        withdraw();
        break;
    case 5 :
        transfer();
        break;
    case 6 :
        payment();
        break;
    case 7 :
        search();
        break;
    case 8 :
        edit();
        break;
    case 9 :
        del();
        break;
    case 10 :
        show_records();
        break;
    case 11 :
        show_payment();
        break;
    case 12 :
        menu();
        break;
    default :
        cout<<"\n\n\nInvalid Choice...Please Try Again";
    goto c;
    }
}

void bank::already_user() {
    clrscr();
    fstream file;
    string tid;
    int found = 0;

    cout << "\n\n\t\t Already User Account";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error...";
    } else {
        cout << "\n\n User ID : ";
        cin >> tid;

        while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
            if (tid == id) {
                clrscr();
                cout << "\n\n\t\t Already User Account";
                cout << "\n\n User ID : " << id << " Pin Code : " << pin << " Password : " << pass;
                found++;
                break;
            }
        }
        file.close();
        if (found == 0) {
            cout << "\n\n User ID can't be found..";
        }
    }
}

void bank::atm_management(){
    c:
    clrscr();
    int choice;
    cout<<"\n\n\t\t\tATM Management";
    cout<<"\n\n 1. User Login & Check Balance";
    cout<<"\n\n 2. Withdraw Amount";
    cout<<"\n\n 3. Account Details";
    cout<<"\n\n 4. Go Back";
    cout<<"\n\n Enter Your Choice [1-4] : ";
    cin>>choice;
    switch(choice){
    case 1 :
        user_balance();
        break;
    case 2 :
        withdraw_atm();
        break;
    case 3 :
        account_detail();
        break;
    case 4 :
        menu();
        break;
    default :
        cout<<"\n\n\nInvalid Choice...Please Try Again";
    goto c;
    }
}

void bank::new_user() {
c:
    system("cls");

    fstream file;
    string n, f, pa, a, ph, i;
    int p;
    float b;

    cout << "\n\n\t\t\tADD NEW USER";
    cout << "\n\n\t\t User Id : ";
    cin >> id;
    cin.ignore(); // Discard the newline character left in the buffer

    cout << "\n\n\t\t Name : ";
    getline(cin, name);

    cout << "\n\n\t\t Father Name : ";
    getline(cin, fname);

    cout << "\n\n\t\t Address : ";
    getline(cin, address);

    cout << "\n\n\t\t Pin Code (5 Digit) : ";
    cin >> pin;
    cin.ignore();

    cout << "\n\n\t\t Password (5 Digit) : ";
    cin >> pass;

    cout << "\n\n\t\t Phone No. : ";
    cin >> phone;

    cout << "\n\n\t\t Current Balance : ";
    cin >> balance;

    file.open("bank.txt", ios::in);
    if (!file) {
        file.open("bank.txt", ios::app | ios::out);
        file << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
        file.close();
    } else {
        bool idExists = false;
        while (file >> i >> n >> f >> a >> p >> pa >> ph >> b) {
            if (i == id) {
                idExists = true;
                break;
            }
        }
        file.close();

        if (idExists) {
            cout << "\n\n User ID Already Exists...";
            system("pause");
            goto c;
        } else {
            file.open("bank.txt", ios::app | ios::out);
            file << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
            file.close();
        }
    }

    cout << "\n\n New User Added Successfully...";
}

void bank::deposit() {
    fstream file, file1;
    string tid;
    float dep;
    int found = 0;

    system("cls");
    cout << "\n\n\t\t\t Deposit Amount Option";

    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error..";
    } else {
        cout << "\n\n User ID : ";
        cin >> tid;

        file1.open("bank1.txt", ios::app | ios::out);

        while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
            if (tid == id) {
                cout << "\n\n Amount For Deposit : ";
                cin >> dep;
                balance += dep;
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
                cout << "\n\n\t\t\t Your Amount " << dep << " Successfully Deposited...";
                found++;
            } else {
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
            }
        }
        file.close();
        file1.close();

        if (remove("bank.txt") != 0) {
            perror("Error deleting file");
            return;
        }

        if (rename("bank1.txt", "bank.txt") != 0) {
            perror("Error renaming file");
            return;
        }

        if (found == 0) {
            cout << "\n\n User ID can't be found..";
        }
    }
}

void bank::withdraw() {
    fstream file, file1;
    string tid;
    float with;
    int found = 0;

    system("cls");
    cout << "\n\n\t\t\t Withdraw Amount Option";

    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error..";
    } else {
        cout << "\n\n User ID : ";
        cin >> tid;

        file1.open("bank1.txt", ios::app | ios::out);

        while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
            if (tid == id) {
                cout << "\n\n Amount For Withdraw : ";
                cin >> with;
                if (with <= balance) {
                    balance -= with;
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
                    cout << "\n\n\t\t\t Your Amount " << with << " Successfully Withdrawn...";
                } else {
                    cout << "\n\n\t\t\t Insufficient Balance";
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
                }
                found++;
            } else {
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
            }
        }
        file.close();
        file1.close();

        if (remove("bank.txt") != 0) {
            perror("Error deleting file");
            return;
        }

        if (rename("bank1.txt", "bank.txt") != 0) {
            perror("Error renaming file");
            return;
        }

        if (found == 0) {
            cout << "\n\n User ID can't be found..";
        }
    }
}

void bank::transfer() {
    fstream file, file1;
    string tid1, tid2;
    float transfer;
    int found1 = 0, found2 = 0;

    system("cls");
    cout << "\n\n\t\t\t Transfer Amount Option";

    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error..";
    } else {
        cout << "\n\n User ID (Sender) : ";
        cin >> tid1;
        cout << "\n\n User ID (Receiver) : ";
        cin >> tid2;

        file1.open("bank1.txt", ios::app | ios::out);

        while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
            if (tid1 == id) {
                cout << "\n\n Amount For Transfer : ";
                cin >> transfer;
                if (transfer <= balance) {
                    balance -= transfer;
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
                    found1++;
                } else {
                    cout << "\n\n\t\t\t Insufficient Balance";
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
                }
            } else if (tid2 == id) {
                balance += transfer;
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
                found2++;
            } else {
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
            }
        }
        file.close();
        file1.close();

        if (remove("bank.txt") != 0) {
            perror("Error deleting file");
            return;
        }

        if (rename("bank1.txt", "bank.txt") != 0) {
            perror("Error renaming file");
            return;
        }

        if (found1 == 0 || found2 == 0) {
            cout << "\n\n User ID(s) can't be found..";
        } else {
            cout << "\n\n\t\t\t Amount " << transfer << " Successfully Transferred...";
        }
    }
}

void bank::payment() {
    ifstream file;
    ofstream file1, file2;
    string id, name, fname, address, pin, pass, phone;
    float balance;
    string tid, service_provider;
    float amount;
    int x;
    int found = 0;

    system("cls");
    cout << "\n\n\t\t\t Payment Option";

    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error..";
        return;
    }

    cout << "\n\n User ID : ";
    cin >> tid;

    cout << "\n\n Service Provider : ";
    cin >> service_provider;

    cout << "\n\n Amount For Payment : ";
    cin >> amount;

    file1.open("bank1.txt", ios::app | ios::out);

    bool userFound = false;

    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
        if (tid == id) {
            userFound = true;
            if (amount <= balance) {
                balance -= amount;
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;

                // Get current time for bill
                time_t now = time(0);
                tm *ltm = localtime(&now);

                file2.open("bill.txt", ios::app | ios::out);
                file2 << tid << " " << service_provider << " " << amount << " " << ltm->tm_mday << " " << 1 + ltm->tm_mon << " " << 1900 + ltm->tm_year << endl;
                file2.close();

                cout << "\n\n\t\t\t Your Payment of " << amount << " to " << service_provider << " was Successful...";
            } else {
                cout << "\n\n\t\t\t Insufficient Balance";
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
            }
        } else {
            file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
        }
    }
    file.close();
    file1.close();

    if (remove("bank.txt") != 0) {
        perror("Error deleting file");
        return;
    }

    if (rename("bank1.txt", "bank.txt") != 0) {
        perror("Error renaming file");
        return;
    }

    if (!userFound) {
        cout << "\n\n User ID can't be found..";
    }
}

void bank::search() {
    clrscr();
    fstream file;
    string tid;
    int found = 0;
    cout << "\n\n\t\t\tSearch User Record";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error...";
    } else {
        cout << "\n\n User ID : ";
        cin >> tid;

        while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
            if (tid == id) {
                clrscr();
                cout << "\n\n\t\t\tSearch User Record";
                cout << "\n\n\n User ID : " << id;
                cout << "\n\n Name : " << name;
                cout << "\n\n Father Name : " << fname << endl;
                cout << "\n Address : " << address;
                cout << "\n Pin : " << pin;
                cout << "\n Password : " << pass << endl;
                cout << "\n Phone Number : " << phone;
                cout << "\n Current Balance : " << balance;
                found++;
                break; // Exit the loop once the user is found
            }
        }
        file.close();
        if (found == 0) { // Change the condition to check for not found
            cout << "\n\n User ID can't be found..";
        }
    }
}

void bank::edit(){
clrscr();
cout<<"\n\n\t\t\tEdit User Record";
fstream file,file1;
string tid,n,fn,ad,ph,pa;
int found =0,p;
file.open("bank.txt",ios::in);
if(!file){
    cout<<"\n\n File Opening Error";
}else{
    cout<<"\n\n User ID : ";
    cin>>tid;
    file1.open("bank1.txt",ios::app|ios::out);
    file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
    while (!file.eof()) {
            if (tid == id) {
                    cin.ignore();
                     cout << "\n\n\t\t Name : ";
    getline(cin, n);

    cout << "\n\n\t\t Father Name : ";
    getline(cin, fn);

    cout << "\n\n\t\t Address : ";
    getline(cin, ad);

    cout << "\n\n\t\t Pin Code (5 Digit) : ";
    cin >> p;
    cin.ignore();

    cout << "\n\n\t\t Password (5 Digit) : ";
    cin >> pa;

    cout << "\n\n\t\t Phone No. : ";
    cin >> ph;

                file1 << id << " " << n << " " << fn << " " << ad << " " << p << " " << pa << " " << ph << " " << balance << endl;
                cout<<"\n\n\n\t\t\tRecord Edit Successfully..";
                found++;
        }else{
        file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
        }
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
    }
    file.close();
    file1.close();
    if (remove("bank.txt") != 0) {
            perror("Error deleting file");
            return;
        }

    if (rename("bank1.txt", "bank.txt") != 0) {
        perror("Error renaming file");
            return;
        }
        if(found=0){
            cout<<"\n\n User ID can't be Found...";
        }
}
}

void bank::del(){
clrscr();
cout<<"\n\n\t\t\tEdit User Record";
fstream file,file1;
string tid,n,fn,ad,ph,pa;
int found =0,p;
file.open("bank.txt",ios::in);
if(!file){
    cout<<"\n\n File Opening Error";
}else{
    cout<<"\n\n User ID : ";
    cin>>tid;
    file1.open("bank1.txt",ios::app|ios::out);
    file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
    while (!file.eof()) {
            if (tid == id) {
                cout<<"\n\n\n\t\t\tRecord Deleted Successfully..";
                found++;
        }else{
        file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
        }
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
    }
    file.close();
    file1.close();
    if (remove("bank.txt") != 0) {
            perror("Error deleting file");
            return;
        }

    if (rename("bank1.txt", "bank.txt") != 0) {
        perror("Error renaming file");
            return;
        }
        if(found=0){
            cout<<"\n\n User ID can't be Found...";
        }
}
}

void bank::show_records() {
    clrscr(); // Assuming clrscr() is defined somewhere to clear the screen
    ifstream file("bank.txt");
    int found = 0;

    cout << "\n\n\t\t\tShow All User's Records";

    if (!file) {
        cout << "\n\n File Opening Error";
    } else {
        while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
            cout << "\n\n User ID : " << id;
            cout << "\n Name : " << name;
            cout << "\n Father Name : " << fname;
            cout << "\n Address : " << address;
            cout << "\n Pin : " << pin;
            cout << "\n Password : " << pass;
            cout << "\n Phone Number : " << phone; // Corrected capitalization of 'Phone' to 'phone'
            cout << "\n Balance : " << balance;
            cout << "\n\n==================================";
            found++;
        }

        file.close();

        if (found == 0) {
            cout << "\nDatabase is empty";
        }
    }
}

void bank::show_payment() {
    clrscr(); // Assuming clrscr() is defined somewhere to clear the screen
    ifstream file("bill.txt");
    int found = 0;
    float amount;
    string name, id;
    int cDay, cMonth, cYear;

    cout << "\n\n\t\t\tShow All Payments Records";

    if (!file) {
        cout << "\n\n File Opening Error";
    } else {
        while (file >> id >> name >> amount >> cDay >> cMonth >> cYear) {
            cout << "\n User ID : " << id;
            cout << "\n Bill Name : " << name;
            cout << "\n Amount : " << amount;
            cout << "\n Date : " << cDay << "/" << cMonth << "/" << cYear; // Corrected date formatting
            cout << "\n\n==================================";
            found++;
        }

        file.close();

        if (found == 0) {
            cout << "\nDatabase is empty";
        }
    }
}


void bank::user_balance() {
    clrscr(); // Assuming clrscr() is defined somewhere to clear the screen
    ifstream file("bank.txt");
    string tid, tpin, tpass;
    char ch;
    int found = 0;

    cout << "\n\n\t\t\tUser Login & Check Balance";

    if (!file) {
        cout << "\n\n File Opening Error...";
    } else {
        cout << "\n\n User ID : ";
        cin >> tid;

        cout << "\n\n Pin Code : ";
        tpin = "";
        for (int i = 0; i < 5; i++) {
            ch = getch();
            tpin += ch;
            cout << "*";
        }

        cout << "\n\n Password : ";
        tpass = "";
        for (int i = 0; i < 5; i++) {
            ch = getch();
            tpass += ch;
            cout << "*";
        }

        string id, name, fname, address, pin, pass, phone;
        float balance;

        while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
            if (tid == id && tpin == pin && tpass == pass) {
                cout << "\n\n\t\t\t Your current Balance is : " << balance;
                found++;
                break; // Exit loop once user is found
            }
        }

        file.close();

        if (found == 0) {
            cout << "\n\n Your pin, user id & password are Invalid...";
        }
    }
}

void bank::withdraw_atm() {
    clrscr(); // Assuming clrscr() is defined somewhere to clear the screen
    ifstream file;
    ofstream file1;
    string tid, tpin, tpass;
    char ch;
    float with;
    int found = 0;

    cout << "\n\n\t\t\t Withdraw Amount Option";

    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error..";
    } else {
        cout << "\n\n User ID : ";
        cin >> tid;

        cout << "\n\n Pin Code : ";
        tpin = "";
        for (int i = 0; i < 5; i++) {
            ch = getch();
            tpin += ch;
            cout << "*";
        }

        cout << "\n\n Password : ";
        tpass = "";
        for (int i = 0; i < 5; i++) {
            ch = getch();
            tpass += ch;
            cout << "*";
        }

        file1.open("bank1.txt", ios::app | ios::out);

        string id, name, fname, address, pin, pass, phone;
        float balance;

        while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
            if (tid == id && tpin == pin && tpass == pass) {
                cout << "\n\n Amount For Withdraw : ";
                cin >> with;
                if (with <= balance) {
                    balance -= with;
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
                    cout << "\n\n\t\t\t Your Amount " << with << " Successfully Withdrawn...";
                } else {
                    cout << "\n\n\t\t\t Insufficient Balance";
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
                }
                found++;
            } else {
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << endl;
            }
        }

        file.close();
        file1.close();

        if (remove("bank.txt") != 0) {
            perror("Error deleting file");
            return;
        }

        if (rename("bank1.txt", "bank.txt") != 0) {
            perror("Error renaming file");
            return;
        }

        if (found == 0) {
            cout << "\n\n User ID can't be found..";
        }
    }
}

void bank::account_detail(){
    clrscr();
    ifstream file;
    string tid, tpin, tpass;
    char ch;
    int found = 0;

    cout << "\n\n\t\t\t Check Details Option";

    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error..";
    } else {
        cout << "\n\n User ID : ";
        cin >> tid;

        cout << "\n\n Pin Code : ";
        tpin = "";
        for (int i = 0; i < 5; i++) {
            ch = getch();
            tpin += ch;
            cout << "*";
        }

        cout << "\n\n Password : ";
        tpass = "";
        for (int i = 0; i < 5; i++) {
            ch = getch();
            tpass += ch;
            cout << "*";
        }
        string id, name, fname, address, pin, pass, phone;
        float balance;

        while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
            if (tid == id && tpin == pin && tpass == pass) {
                cout << "\n\n User ID : " << id;
                cout << "\n Name : " << name;
                cout << "\n Father Name : " << fname;
                cout << "\n Address : " << address;
                cout << "\n Pin : " << pin;
                cout << "\n Password : " << pass;
                cout << "\n Phone Number : " << phone; // Corrected capitalization of 'Phone' to 'phone'
                cout << "\n Balance : " << balance;
                cout << "\n\n==================================";
                found++;
            }
        }

        file.close();
        if (found == 0) {
            cout << "\n\n User ID can't be found..";
        }
    }
}

int main() {
    bank b;
    b.menu();
    return 0;
}


