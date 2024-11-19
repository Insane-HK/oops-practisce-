#include <iostream>
#include <vector>
#include <string>

class Passenger {
public:
    Passenger(const std::string& name, const std::string& ticketNumber)
        : name(name), ticketNumber(ticketNumber) {}

    std::string getName() const {
        return name;
    }

    std::string getTicketNumber() const {
        return ticketNumber;
    }

    void display() const {
        std::cout << "Passenger(Name: " << name << ", Ticket Number: " << ticketNumber << ")\n";
    }

private:
    std::string name;
    std::string ticketNumber;
};

class TicketReservationSystem {
public:
    void addPassenger(const std::string& name, const std::string& ticketNumber) {
        Passenger newPassenger(name, ticketNumber);
        passengers.push_back(newPassenger);
        std::cout << "Added: ";
        newPassenger.display();
    }

    void displayPassengers() const {
        if (passengers.empty()) {
            std::cout << "No passengers in the system.\n";
            return;
        }
        std::cout << "List of Passengers:\n";
        for (const auto& passenger : passengers) {
            passenger.display();
        }
    }

    Passenger* searchPassengerByTicket(const std::string& ticketNumber) {
        for (auto& passenger : passengers) {
            if (passenger.getTicketNumber() == ticketNumber) {
                return &passenger;
            }
        }
        return nullptr;
    }

private:
    std::vector<Passenger> passengers;
};


int main() {
    TicketReservationSystem system;

   
    system.addPassenger("Dhruv Joshi", "6456");
    system.addPassenger("Aditya Kalal", "T67890");

    
    system.displayPassengers();

    
    std::string ticketNumberToSearch = "T12345";
    Passenger* foundPassenger = system.searchPassengerByTicket(ticketNumberToSearch);

    if (foundPassenger) {
        std::cout << "Found Passenger: ";
        foundPassenger->display();
    } else {
        std::cout << "No passenger found with ticket number: " << ticketNumberToSearch << "\n";
    }

    return 0;
}