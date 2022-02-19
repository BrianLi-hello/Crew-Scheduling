#include <iostream>
#include <string>
#include <math.h>
#include "Aircrew.h"
using namespace std;
// USE THE DIFF LINUX COMMAND TO COMPARE OUTPUT

        Aircrew::Aircrew(std::string name_str) : nm(name_str) {} // base constructor with an intialization list
        Pilot::Pilot(std::string name_str) : Aircrew(name_str) {}  // derived constructor with an initlization list
        Attendant::Attendant(std::string name_str) : Aircrew(name_str) {}  // derived constructor with an initlization list
        TaggedAttendant::TaggedAttendant(std::string name_str) : Aircrew(name_str) {}  // derived constructor with an initlization list

        const std::string Pilot::type(void) const {  // returning the name of aircrew
            return "Pilot";
        }

        const std::string Attendant::type(void) const {  // returning the name of aircrew
            return "Attendant";
        }

        const std::string TaggedAttendant::type(void) const {  // returning the name of aircrew
            return "TaggedAttendant";
        }

        void TaggedAttendant::scheduleFlight(int f, double h) const {  // checking if T can be scheduled
            // f is # of flights, h is # of hours
            // Note: A tagged attendant can only register for 3.5 hours (half of 7 hours)

            cout << "Attempting to schedule a flight for " << f << " stop(s) " << h << " hours flight..." << endl;
            if ((hoursWorked + (h / 2) < maxHours()) && flightsTaken + f < maxFlights())   {
                cout << "This crew member can be scheduled" << endl;
            } else { 
                cout << "This crew member should be replaced" << endl;
            }
        }

        const int Pilot::maxFlights(void) const {
            return 5;  // can be overridden because this is a pure virtual function
        } 

        const int Attendant::maxFlights(void) const {
            return 8;  // can be overridden because this is a pure virtual function
        } 

        const int TaggedAttendant::maxFlights(void) const {
            return 8;  // can be overridden because this is a pure virtual function
        } 

        const double Aircrew::maxHours(void) const {
            return 60;
        }

        const std::string Aircrew::name(void) const {
            return nm; // idk // returning the name of the aircrew
        }

        void Aircrew::setFlights(int i) {  // setter function
            flightsTaken = i;
        }

        void Aircrew::setHours(double h) {  // setter function
            hoursWorked = h;
        }

        void Aircrew::print(void) const {  // printing relevant information
            cout << type() << ": " << nm << " has operated " << flightsTaken << " for a total of " << hoursWorked << " hours this week" << endl;

            if (flightsTaken >= maxFlights())
                cout << "Available flights: 0" << endl;
            else 
                cout << "Available flights: " << maxFlights() - flightsTaken << endl;

            if (hoursWorked >= maxHours())
                cout << "Available hours: 0" << endl;
            else 
                cout << "Available hours: " << maxHours() - hoursWorked << endl;
        }

        void Aircrew::scheduleFlight(int f, double h) const {  // f is # of flights, h is # of hours
            cout << "Attempting to schedule a flight for " << f << " stop(s) " << h << " hours flight..." << endl;
            if (flightsTaken + f < maxFlights())
                cout << "This crew member can be scheduled" << endl;
            else
                cout << "This crew member should be replaced" << endl;
            cout << "Done scheduling " << name() << endl;
        }

        Aircrew* Aircrew::makeAircrew(char ch, std::string name_str) {
            if (ch == 'P') {
                return new Pilot(name_str);  // creating a Pilot object with name_str as its parameter
            } else if (ch == 'A') {
                return new Attendant(name_str);  // creating an Attendant object with name_str as its parameter
            } else if (ch == 'T') {
                return new TaggedAttendant(name_str);  // creating a TaggedAttendant object with name_str as its parameter
            } else {
                return nullptr;
            }
        }
        Aircrew::~Aircrew(void) {}

/*
class Pilot : public Aircrew {
    public:
        Pilot(std::string name_str) : Aircrew(name_str) {}  // calling the parent constructor
        virtual const std::string type(void) const {
            return "Pilot";
        }
        virtual const int maxFlights(void) const {
            return 5;
        }
};

class Attendant : public Aircrew {
    public: 
        Attendant(std::string name_str) : Aircrew(name_str) {}  // calling the parent constructor
        virtual const std::string type(void) const {
            return "Attendant";
        }
        virtual const int maxFlights(void) const {
            return 8;
        }
};

class TaggedAttendant : public Aircrew {
    public: 
        TaggedAttendant(std::string name_str) : Aircrew(name_str) {}  // calling the parent constructor
        virtual const std::string type(void) const {
            return "TaggedAttendant";
        }
        virtual const int maxFlights(void) const {
            return 8;  // might need to change
        }
        virtual void scheduleFlight(int f, double h) const {
            cout << "Attempting to schedule for "; // ... 
            
            
            // if statement to see if the crew member can be scheduled or not
        }
};
*/