#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // print passengers için eklendi

using namespace std;

#define RESET   "\033[0m"       //yeni bir şeyler denemek istedim
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Passenger {
public: //CONSTRUCTOR AÇILACAK
    string name;
    string surname;
    char gender;
    Passenger(){
        name = "Empty";
        surname = "Empty";
        gender = 'E';
    }
    Passenger(string n, string s, char g):name(n), surname(s), gender(g){}
};
Passenger emptyPass;

char seatCode[] = { 'A', 'B', 'C', 'D' }; // indexten alacağım
class Flight {
public: //CONSTRUCTOR AÇILACAK, CONSTRUCTİONDA MAXSEATS BOYUNCA STACK'E NULL PASSENGER DOLDURULACAK, ONDAN SONRA PASSENGER EKLEYECEĞİM
    string flightNo;
    string destination;
    int maxSeats;//defaultu 40 ayarla
    int numPassengers; // BUNA DİKKAT ET, İNDEX YAPARKEN 1 AZINA BAK
    vector<Passenger> passengers;
    Flight() {
        maxSeats = 40;
        numPassengers = 0;
        flightNo = "";
        destination = "";
        passengers.resize(maxSeats);
        for (int i = 0; i < maxSeats; i++) {
            passengers[i] = emptyPass;
        }
    }
    Flight(int mS, string fN, string ds) {
        if (mS % 2 != 0 || mS > 80) {
            cout << RED << endl << "Invalid capacity! Setting to default 40." << endl << RESET;
            maxSeats = 40;
        }
        else
        {
            maxSeats = mS;
        }
        numPassengers = 0;
        flightNo = fN;
        destination = ds;
        passengers.resize(maxSeats);
        for (int i = 0; i < maxSeats; i++) {
            passengers[i] = emptyPass;
        }
    }
    void reserveSeat(const Passenger& passenger)// TAMAM
    {
        cout << RESET << "Seating Plan:" << endl
            << "---------FRONT--------" << endl;
        for (int i = 0; i < maxSeats; i++) {
            if (!(i % 4)) cout << endl;
            char mark = 'O';
            if (passengers.at(i).gender != 'E') {
                mark = 'X'; cout << BLUE;
            }
            
            cout << i / 4 + 1 << seatCode[i % 4] << " " <<mark << RESET <<"|";

        }
        string seat;
        cout <<RESET << "Which seat you want to reserve:" << YELLOW;
        cin >> seat;
        if (seat.length() < 2) {
            cout << RED << "Invalid seat!" << endl << RESET;
            return;
        }
        char column = seat.back(); // A B C D DİYE AYIR VAR MI DİYE SONRA KONTROL EDERSİN(A B C D DEĞİLSE YANİ)
        //cout << "COLUMN:" << column <<endl;
        string row = seat.substr(0, seat.length() - 1);
        int rowNum = stoi(row); // ŞİMDİ SIRA 1 2 3 4 5 6 7 DİYE GÖTÜRÜCEZ VECTORDA, 1A = 0 1B = 1 1C = 2 1D=3 2A=4 2B=5.... YANİ HER ROW NUM 1 AZALTACAĞIZ HER ROW NUM 1 ARTINCA İNTİMİZE +4 GELECEK
        //cout << "ROWNUM:" << rowNum << endl;
        int seatNumRaw = (rowNum << 2) - 4 + (column - 'A');
        //cout << "SEAT NUM RAW:" << seatNumRaw << endl;
        if (seatNumRaw >= maxSeats) {
            cout << RED << "Invalid seat!" << endl << RESET;
            return;
        }

        if (passengers.at(seatNumRaw).gender == 'E') {
            passengers.at(seatNumRaw) = passenger;
            numPassengers++;
        }
        else
        {
            cout << RED <<"This seat already reserved..." << endl << RESET;
            return;
        }
    }
    void cancelReservation(const Passenger& passenger) { //  Sanırım tamam
        for (int i = 0; i < maxSeats; i++) {
            Passenger temp = passengers.at(i);
            if (temp.name == passenger.name && temp.surname == passenger.surname && temp.gender == passenger.gender) {
                passengers.at(i) = emptyPass; 
                numPassengers--;
                cout << GREEN <<"Reservation canceled..." << endl << RESET;
                return;
            }
        }
        cout << RED <<"This passenger had no reservation in this flight" << endl << RESET;
        return;
    }
    int numberOfPassenger() { // TAMAM
        return numPassengers;
    }

    void printPassengers() { // BİTMEDİ : TAMAMLADNI
        cout << YELLOW <<"Passenger List for Flight " << flightNo << ":" << endl
            << left << setw(5) << "Seat" << "|" << left << setw(15)<< "Passenger Name" << "|" << "Gender " << endl
            <<"----------------------------" << endl << RESET;
        //OTURUŞTA BÜTÜN SATIRLAR 4 KOLTUK VAR SEATING PLANDE GÖSTERİLDİĞİNE GÖRE ANCAK WIDTHTE 5 DE DEMİŞ
        for (int i = 0; i < maxSeats; i++) { // ALIGNMENTE SONRA BAKARSIN
            if (passengers[i].gender != 'E') {
                string fullname = passengers[i].name + " " + passengers[i].surname;
                string seatFull = to_string(i / 4 + 1) + seatCode[i % 4];
                cout << RESET << left << setw(5) << seatFull << "|" << left << setw(15) << fullname << "|" << passengers[i].gender << endl;
            }
             // BURADA EMPTY PASSENGERSLERİ SKİP EDİP ASIL PASSENGERLERİ YANSITACAĞIZ
            
        }
    }
    bool isFlyingTo(const string& dest) {
        if (destination == dest) return true;
        return false;
    }
};


class FlightManager {
public:
    vector<Flight> Flights;
    void addFlight(const Flight& fl) { Flights.push_back(fl); }
    void removeFlight(const string& flightNumber) {
        for (int i = 0; i < Flights.size(); i++) {
            if (Flights.at(i).flightNo == flightNumber) {
                Flight* temp = &Flights.at(i);
                Flights.erase(Flights.begin() + i);
                cout << GREEN << "Flight removed...";
                return;
            }
        }
        cout << "This Flights doesn't exists...";
        return;
    }
    void listAllFlights() {
        cout << YELLOW<< "All Flights:" << endl
            << left << setw(6) << "ID" << "| "
            << left << setw(12) << "DESTINATION" << "| "
            << left << setw(9) << "CAPACITY" << "| "
            << "AVAILABLE SEAT" << endl
            << "-----------------------------------------------" << endl;
        for (int i = 0; i < Flights.size(); i++) {
            cout  << GREEN<< left << setw(6) << Flights.at(i).flightNo << RESET << "| "
                << left << setw(12) << Flights.at(i).destination << "| "
                << left << setw(9) << Flights.at(i).maxSeats << "| "
                << GREEN<<(Flights.at(i).maxSeats - Flights.at(i).numberOfPassenger()) << endl << RESET;
        }
    }
    Flight* getFlightByNumber(const string& flightNumber) {
        for (int i = 0; i < Flights.size(); i++) {
            if (flightNumber == Flights.at(i).flightNo) {
                return &Flights.at(i);
            }

        }
        cout << RED << "Failed to find..."<<endl << RESET;
        return nullptr;
    }
    Flight* getFlightByDestination(const string& destination) {
        for (int i = 0; i < Flights.size(); i++) {
            if (Flights.at(i).destination == destination) {
                return &Flights.at(i);
            }

        }
        cout <<  RED<<"Failed to find..." << endl << RESET;
        return nullptr;
    }
    
};
void passengermanagement(Flight& fl) {
    int sel;
    string name, surname;
    char gender;
    while (true) {
        cout << RESET<< "1.Reserve a Seat" << endl
            << "2.Cancel a Reservation" << endl
            << "3.View Passenger List" << endl
            << "4.Back to Flight Management Menu" << endl
            << "Selection:" << YELLOW;
        cin >> sel;
        switch (sel) {
        case 1:
        {
            cout << RESET<< "Name:" << YELLOW;
            cin >> name;
            cout <<  RESET <<"Surname:" << YELLOW;
            cin >> surname;
            cout << RESET<< "Gender(M or F)" << YELLOW;
            cin >> gender; // IF ELSE SONRA EKLE
            if (gender != 'M' && gender != 'F')
            {
                cout << RED<< "Invalid Gender, please try again..." << YELLOW;
                break;
            }
            Passenger* p1 = new Passenger(name, surname, gender);
            fl.reserveSeat(*p1);
            break;
        }
        case 2:
        {
            cout << RESET <<"Name:" << YELLOW;
            cin >> name;
            cout << RESET << "Surname:" << YELLOW;
            cin >> surname;
            cout << RESET << "Gender(M or F)" << YELLOW;
            cin >> gender; // IF ELSE SONRA EKLE
            if (gender != 'M' && gender != 'F')
            {
                cout << RED<<"Invalid Gender, please try again..." << RESET;
                break;
            }
            Passenger* p2 = new Passenger(name, surname, gender);
            fl.cancelReservation(*p2);
            break;
        }
        case 3:
            fl.printPassengers();
            break;
        case 4:
            return;
            break;
        }

    }

}

void main()
{
    FlightManager FlightM; // Tamam bence ya
    while (true) {
        
        cout << RESET<< "Menu Structure:" << endl
            << "Top-Level Menu:Flight Management" << endl
            << "1. Add a Flight" << endl
            << "2. Remove a Flight" << endl
            << "3. List All Flights" << endl
            << "4. Select a Flight and Manage passengers" << endl
            << "5.Exit" << endl
            << "Selection:" << YELLOW;
        int selection;
        cin >> selection;
        string fN, dS; int mS = 0;
        string selec;
        switch (selection) {
        case 1:
        {
            cout << endl << RESET<< "New Flight Number:" << YELLOW;
            cin >> fN;
            if (fN.substr(0, 2) != "TK" && fN.substr(0, 2) != "PG") {
                cout << RED << "Invalid flight number! Must start with TK or PG, Try again..." << endl << RESET;
                break;
            }
            cout <<  RESET<<"Destination:" << YELLOW;
            cin >> dS;
            cout << RESET << "Max seat:" << YELLOW;
            cin >> mS;
            Flight* flight = new Flight(mS, fN, dS);
            FlightM.addFlight(*flight);
            cout << GREEN<< "Flight created and added..." << endl << YELLOW;
            break;
        }
        case 2:
        {
            cout << endl << RESET << "Input flight code for delete the flight:" << YELLOW;
            cin >> selec; // NULL DÖNDÜRME ŞEYLERİNE BAK
            FlightM.removeFlight(selec);
            break;
        }
        case 3:
        {
            FlightM.listAllFlights();
            break;
        }
        case 4:
        {
            cout << endl << RESET <<"1.Select by Flight Number" << endl << "2.Select by Destination" << endl<<"Selection:" << YELLOW;
            int sel = 0;
            cin >> sel;
            Flight* temp;//NULL DÖNDÜRME ŞEYLERİNE BAK
            if (sel == 1) {
                cout <<RESET <<"Input flight code:" << YELLOW;
                cin >> selec;
                temp = FlightM.getFlightByNumber(selec);
                if (temp == nullptr) {
                    cout << RED<<"Failed to find flight..."<< YELLOW << endl;
                    break;
                }
                passengermanagement(*temp);
            }
            else if (sel == 2) {
                cout << RESET <<"Input flight destination:" << YELLOW;
                cin >> selec;
                temp = FlightM.getFlightByDestination(selec);
                if (temp == nullptr) {
                    break;
                }
                passengermanagement(*temp);
            }
            else
            {
                cout << RED<< "Invalid Selection." << YELLOW << endl;
                break;
            }

            
            break;
        }
        case 5:
            exit(0);
            break;
        default:
            cout << RED << "Invalid Selection. Try again..." << YELLOW;
            break;
        }
    }
    return;
    
}


