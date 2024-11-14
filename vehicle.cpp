#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

class VehicleInfo
{
private:
    int b , bq , bz ;
    string vehicle_Name, vehicle_type, company_name,vehicle_number;
    char capacity_in_cc[05];
    char milage[05];
public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};

void VehicleInfo::menu() // Start menu
{
menustart:
    int choice;
    char x,j,z;
    system("cls"); // screen/terminal clear
    
    cout << "\t\t\t VEHICLE MANAGEMENT SYSTEM" << endl;
    
         
    cout << "\t\t\t 1 Enter a Record " << endl;
    cout << "\t\t\t 2 Display Record " << endl;
    cout << "\t\t\t 3 Modify Record " << endl;
    cout << "\t\t\t 4 Delete Record \n"
         << endl;
    cout << "\t\t\t 5 Exit \n"
         << endl;

    cout << "\t\t\t Choose Option ->>  ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\n\t\t\t DO You Want To Add Another Record (Y , N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        deleted();
        break;
    case 5:
        cout << "\n\n\t\t\t Program Is Exit!! ";
        exit(0);
        break;
    default:
        cout << "\n\n\t\t\t Invalide choice.\nPlease Choice a Valid Option.";
    }
    getch(); // pauses the Output Console until a key is pressed
    goto menustart;
}

void VehicleInfo::insert() // ADD Vehicle Info
{
    int z , y;
    system("cls");
    fstream file;
    cout << "\t\t\t Add Vehicle Details " << endl;
    // string vehicle_Name, vehicle_type, company_name, capacity_in_cc, milage, vehicle_number;

    cout << "\t\t\tEnter Vehicle Type: ";
    cin >> vehicle_type;
    cout << "\t\t\tEnter the name of company: ";
    cin >> company_name;
    cout << "\t\t\tEnter the Name of Vehicle: ";
    cin >> vehicle_Name;
    cout << "\t\t\tCapacity of the Vehicle in CC: ";
    cin >> capacity_in_cc;
    z=strlen(capacity_in_cc);
       for ( int j = 0; j <z ; j++)
        {
        if ((capacity_in_cc[j]>='a'&&capacity_in_cc[j]<='z')||((capacity_in_cc[j])<'1'))
        {


            cin.clear();
            cin.ignore(512,'\n');
            cout<<"Invalid input";
            cout << "\t\t\tCapacity of the Vehicle in CC: ";
            cin >> capacity_in_cc;
            j=-1;
            z=strlen(capacity_in_cc);
            //cout<<bquan;
           continue;
        }
        }



    bq=atoi(capacity_in_cc);


    cout << "\t\t\tMilage: ";
    cin >> milage;
    y=strlen(milage);
    for ( int g = 0; g <y ; g++)
    {
    if ((milage[g]>='a'&&milage[g]<='z')||(milage[g])<'1')
        {


            cin.clear();
            cin.ignore(512,'\n');
            cout<<"Invalid input";
            cout << "\t\t\tMilage: ";
            cin >> milage;
            g=-1;
            y=strlen(milage);
            //cout<<bquan;
           continue;
        }
        }


    bz=atoi(milage);




    cout << "\t\t\tVehicle Number: ";
    cin >> vehicle_number;

    file.open("VehicleRecord.txt", ios::app | ios::out);
    file << " " << vehicle_type << " " << company_name << " " << vehicle_Name << " " << capacity_in_cc << " " << milage << " " << vehicle_number << "\n";
    file.close();
}
void VehicleInfo::display() // Display data of student
{
    system("cls");
    ifstream file;
    int total = 1;
    cout<<"Vehicle Record Table"<<endl;
    string x;
    file.open("VehicleRecord.txt");
    while(file.eof()==0)
{
    getline(file,x);
    cout<<x<<endl;
}
    if (total == 0)
        {
            cout << "\n\t\t\tNo Date Is Present" << endl;
        }
    else
    {

        file >> vehicle_type >> company_name >> vehicle_Name >> capacity_in_cc >> milage >> vehicle_number;
        while (!file.eof())
        {

             file >> vehicle_type >> company_name >> vehicle_Name >> capacity_in_cc >> milage >> vehicle_number;
            cout << " \n\n\t\t\t Serial No. : " << total++ << endl;
            cout << "\t\t\t Vheicle Type : " << vehicle_type << endl;
            cout << "\t\t\t Company Name : " << company_name << endl;
            cout << "\t\t\t Vehicle Name : " << vehicle_Name << endl;
            cout << "\t\t\t Vehicle Capacity : " << capacity_in_cc << endl;
            cout << "\t\t\t Vehicle's Milage : " << milage << endl;
            cout << "\t\t\t Vehicle Number : " << vehicle_number << endl;

             file >> vehicle_type >> company_name >> vehicle_Name >> capacity_in_cc >> milage >> vehicle_number;
        }
        
    }
    file.close();
}
void VehicleInfo::modify()
{
    system("cls");
    ifstream file;
    ofstream file1;
    string vehiclenumber;
    int found = 0;
    cout << "\t\t\t  Modify Vehicle Details " << endl;
    file.open("VehicleRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present.";
        file.close();
    }
    else
    {
        cout << "\nVehicle Number ";
        cin >> vehiclenumber;
        file1.open("record.txt", ios::out);
        file >> vehicle_type >> company_name >> vehicle_Name >> capacity_in_cc >> milage >> vehicle_number;
        while (!file.eof())
        {
            if (vehiclenumber != vehicle_number)
                file1 << " " << vehicle_type << " " << company_name << " " << vehicle_Name << " " << capacity_in_cc << " " << milage << " " << vehicle_number << "\n";

            else
            {
                int num;
                cout << "\t\t\t1)For updating vehicle type" << endl;
                cout << "\t\t\t2)For updating company name" << endl;
                cout << "\t\t\t3)For updating vehicle name" << endl;
                cout << "\t\t\t4)For updating vehicle capacity" << endl;
                cout << "\t\t\t5)For updating  vehicle mileage" << endl;
                cout << "\t\t\t6)For updating  vehicle number" << endl;
                cout << "Enter the option: ";
                cin >> num;
                switch (num)
                {
                case 1:
                {
                    cout << "Enter your vehicle type : ";
                    cin >> vehicle_type;
                    file1 << " " << vehicle_type << " " << company_name << " " << vehicle_Name << " " << capacity_in_cc << " " << milage << " " << vehicle_number << "\n";

                    break;
                }
                case 2:
                {
                    cout << "Enter your company name : ";
                    cin >> company_name;
                    file1 << " " << vehicle_type << " " << company_name << " " << vehicle_Name << " " << capacity_in_cc << " " << milage << " " << vehicle_number << "\n";

                    break;
                }
                case 3:
                {
                    cout << "Enter your vehicle name : ";
                    cin >> vehicle_Name;
                    file1 << " " << vehicle_type << " " << company_name << " " << vehicle_Name << " " << capacity_in_cc << " " << milage << " " << vehicle_number << "\n";

                    break;
                }
                case 4:
                {
                    cout << "Enter your  vehicle capacity : ";
                    cin >> capacity_in_cc;
                    file1 << " " << vehicle_type << " " << company_name << " " << vehicle_Name << " " << capacity_in_cc << " " << milage << " " << vehicle_number << "\n";

                    break;
                }
                case 5:
                {
                    cout << "Enter your  vehicle mileage : ";
                    cin >> milage;
                    file1 << " " << vehicle_type << " " << company_name << " " << vehicle_Name << " " << capacity_in_cc << " " << milage << " " << vehicle_number << "\n";

                    break;
                }
                case 6:
                {
                    cout << "Enter your  vehicle number : ";
                    cin >> vehicle_Name;
                    file1 << " " << vehicle_type << " " << company_name << " " << vehicle_Name << " " << capacity_in_cc << " " << milage << " " << vehicle_number << "\n";

                    break;
                }
                default:
                {
                    cout << "Please enter num in (1-6) range" << endl;
                }
                }

                 cout << "\t\t\tEnter Vehicle Type -> ";
                cin >> vehicle_type;
                 cout << "\t\t\tEnter the name of company -> ";
                 cin >> company_name;
                 cout << "\t\t\tEnter the Name of Vehicle -> ";
                 cin >> vehicle_Name;
                 cout << "\t\t\tCapacity of the Vehicle in CC -> ";
                 cin >> capacity_in_cc;
                 cout << "\t\t\tMilage -> ";
                 cin >> milage;
                 cout << "\t\t\tVehicle Number -> ";
                 cin >> vehicle_number;
            }
            file >> vehicle_type >> company_name >> vehicle_Name >> capacity_in_cc >> milage >> vehicle_number;
        }
        if (found == 0)
        {
             cout << "\n\n\t\t\tNot Found....";
        }
        file1.close();
        file.close();
        remove("VehicleRecord.txt");
        rename("record.txt", "VehicleRecord.txt");
    }
}
 void VehicleInfo::search()
{

}
void VehicleInfo::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string VNum;
    cout << "\t\t\t ||| Delete Vehicle Details |||" << endl;

    file.open("VehicleRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present.";
        file.close();
    }
    else
    {
        cout << "\t\t\tVehicle Number -> ";
        cin >> VNum;
        file1.open("record.txt", ios::app | ios::out);
        file >> vehicle_type >> company_name >> vehicle_Name >> capacity_in_cc >> milage >> vehicle_number;
        while (!file.eof())
        {
            if (VNum != vehicle_number)
            {
                file1 << " " << vehicle_type << " " << company_name << " " << vehicle_Name << " " << capacity_in_cc << " " << milage << " " << vehicle_number << "\n";
            }
            else
            {
                found++;
                cout << "\n\n\t\t\tDate has been Deleted Successfully";
            }
            file >> vehicle_type >> company_name >> vehicle_Name >> capacity_in_cc >> milage >> vehicle_number;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tNot Found....";
        }
        file1.close();
        file.close();
        remove("VehicleRecord.txt");
        rename("record.txt", "VehicleRecord.txt");
    }
}
int main()
{
    VehicleInfo project; // object
    project.menu();      // object calling
    return 0;
}