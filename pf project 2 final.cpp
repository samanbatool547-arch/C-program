#include<iostream>
#include<windows.h>
using namespace std;

void fareMenu()
{
    cout << "\n========== ROUTE & FARE MENU ==========\n";

    cout << "1. Lahore to Islamabad\n";
    cout << "   Economy Fare: 3000\n\n";

    cout << "2. Lahore to Karachi\n";
    cout << "   Economy Fare: 7000\n\n";

    cout << "3. Lahore to Multan\n";
    cout << "   Economy Fare: 2000\n\n";
    cout << "4. Lahore to Faisalabad\n";
    cout << "   Economy Fare: 1500\n\n";

}


void displaySeats(int seats[], string names[], string type[],
                  string route[], string timing[],
                  int fare[], int size)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "\n========== SEAT STATUS ==========\n";

    for(int i = 0; i < size; i++)
    {
        cout << "Seat " << i + 1 << " : ";

        
        if(i >= 0 && i <= 9)
            cout << "(VIP) ";
        else if(i >= 10 && i <= 24)
            cout << "(Business) ";
        else
            cout << "(Economy) ";

        if(seats[i] == 1)
        {
            SetConsoleTextAttribute(h,12);

            cout << "[BOOKED] ";

            SetConsoleTextAttribute(h,7);

            cout << " | Name: " << names[i];
            cout << " | Type: " << type[i];
            cout << " | Route: " << route[i];
            cout << " | Fare: " << fare[i];
            cout << " | Timing: " << timing[i];
        }
        else
        {
            SetConsoleTextAttribute(h,10);

            cout << "[Available]";

            SetConsoleTextAttribute(h,7);
        }

        cout << endl;
    }
}


void bookSeat(int seats[], string names[], string type[],
              string route[], string timing[],
              int fare[], int size)
{
    int seatNo;

    cout << "VIP Seats      : 1 - 10\n";
    cout << "Business Seats : 11 - 25\n";
    cout << "Economy Seats  : 26 - 70\n\n";
     
    cout << "Seat Class Extra Charges:\n";
    cout << "VIP      = +2000\n";
    cout << "Business = +1000\n";
    cout << "Economy  = +0\n";
    
    cout << "Enter seat number to book: ";
    cin >> seatNo;

    if(seatNo < 1 || seatNo > size)
    {
        cout << "Invalid seat number!\n";
        return;
    }

    if(seats[seatNo - 1] == 1)
    {
        cout << "Seat already booked!\n";
    }
    else
    {
        seats[seatNo - 1] = 1;

        cin.ignore();

        cout << "Enter customer name: ";
        getline(cin, names[seatNo - 1]);

        
        if(seatNo >= 1 && seatNo <= 10)
        {
            type[seatNo - 1] = "VIP";
        }
        else if(seatNo >= 11 && seatNo <= 25)
        {
            type[seatNo - 1] = "Business";
        }
        else
        {
            type[seatNo - 1] = "Economy";
        }

        cout << "Seat Type Automatically Assigned: "
             << type[seatNo - 1] << endl;

        
        fareMenu();

        int option;
        int baseFare = 0;

        cout << "Select Route Option: ";
        cin >> option;

        switch(option)
        {
            case 1:
                route[seatNo - 1] = "Lahore to Islamabad";
                baseFare = 3000;
                timing[seatNo - 1] = "8:00 AM";
                break;

            case 2:
                route[seatNo - 1] = "Lahore to Karachi";
                baseFare = 7000;
                timing[seatNo - 1] = "10:00 PM";
                break;

            case 3:
                route[seatNo - 1] = "Lahore to Multan";
                baseFare = 2000;
                timing[seatNo - 1] = "2:00 PM";
                break;

            case 4:
                route[seatNo - 1] = "Lahore to Faisalabad";
                baseFare = 1500;
                timing[seatNo - 1] = "6:00 PM";
                break;

            default:
                cout << "Invalid option!\n";
                seats[seatNo - 1] = 0;
                return;
        }

        
        if(type[seatNo - 1] == "VIP")
        {
            fare[seatNo - 1] = baseFare + 2000;
        }
        else if(type[seatNo - 1] == "Business")
        {
            fare[seatNo - 1] = baseFare + 1000;
        }
        else
        {
            fare[seatNo - 1] = baseFare;
        }

        cout << "\nSeat booked successfully!\n";
        cout << "Total Fare: " << fare[seatNo - 1] << endl;
    }
}


void cancelSeat(int seats[], string names[], string type[],
                string route[], string timing[],
                int fare[], int size)
{
    int seatNo;

    cout << "Enter seat number to cancel: ";
    cin >> seatNo;

    if(seatNo < 1 || seatNo > size)
    {
        cout << "Invalid seat number!\n";
        return;
    }

    if(seats[seatNo - 1] == 0)
    {
        cout << "Seat already empty!\n";
    }
    else
    {
        seats[seatNo - 1] = 0;

        names[seatNo - 1] = "";
        type[seatNo - 1] = "";
        route[seatNo - 1] = "";
        timing[seatNo - 1] = "";
        fare[seatNo - 1] = 0;

        cout << "Booking cancelled successfully!\n";
    }
}


void bookingRecords(int seats[], string names[], string type[],
                    string route[], string timing[],
                    int fare[], int size)
{
    cout << "\n========== BOOKING RECORDS ==========\n";

    bool found = false;

    for(int i = 0; i < size; i++)
    {
        if(seats[i] == 1)
        {
            cout << "Seat No: " << i + 1 << endl;
            cout << "Customer Name: " << names[i] << endl;
            cout << "Seat Type: " << type[i] << endl;
            cout << "Route: " << route[i] << endl;
            cout << "Fare: " << fare[i] << endl;
            cout << "Timing: " << timing[i] << endl;
            cout << "Reserved: YES\n";

            cout << "-----------------------------\n";

            found = true;
        }
    }

    if(found == false)
    {
        cout << "No bookings found!\n";
    }
}

int main()
{
    const int SIZE = 70;

    int seats[SIZE] = {0};

    string names[SIZE];
    string type[SIZE];
    string route[SIZE];
    string timing[SIZE];

    int fare[SIZE] = {0};

    int choice;

    do
    {
        cout << "\n========== Welcome To Skyways ==========\n\n";

        cout << "1. View All Seats\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. View Booking Records\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displaySeats(seats, names, type,
                             route, timing, fare, SIZE);
                break;

            case 2:
                bookSeat(seats, names, type,
                         route, timing, fare, SIZE);
                break;

            case 3:
                cancelSeat(seats, names, type,
                           route, timing, fare, SIZE);
                break;

            case 4:
                bookingRecords(seats, names, type,
                               route, timing, fare, SIZE);
                break;

            case 5:
                cout<< "thanks for your better services\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}
