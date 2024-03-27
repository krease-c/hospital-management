#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    std::string name;
    std::string info;
};

class Patient : public Person {
public:
    std::string medicalRecord;
};

class Doctor : public Person {
public:
    std::string specialization;
};

class Appointment {
public:
    Patient patient;
    Doctor doctor;
    std::string time;
};

class Invoice {
public:
    std::string patientName;
    double amount;
    bool paid;
};

class Hospital {
private:
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Appointment> appointments;
    std::vector<Invoice> invoices;

public:
    void addPatient(Patient p) {
        patients.push_back(p);
    }

    void addDoctor(Doctor d) {
        doctors.push_back(d);
    }

    void scheduleAppointment(Appointment a) {
        appointments.push_back(a);
    }

    void addInvoice(Invoice inv) {
        invoices.push_back(inv);
    }

    void displayPatients() {
        for (std::vector<Patient>::const_iterator it = patients.begin(); it != patients.end(); ++it) {
            std::cout << "Name: " << it->name << ", Info: " << it->info << ", Medical Record: " << it->medicalRecord << std::endl;
        }
    }

    void displayDoctors() {
        for (std::vector<Doctor>::const_iterator it = doctors.begin(); it != doctors.end(); ++it) {
            std::cout << "Name: " << it->name << ", Info: " << it->info << ", Specialization: " << it->specialization << std::endl;
        }
    }

    void displayAppointments() {
        for (std::vector<Appointment>::const_iterator it = appointments.begin(); it != appointments.end(); ++it) {
            std::cout << "Patient: " << it->patient.name << ", Doctor: " << it->doctor.name << ", Time: " << it->time << std::endl;
        }
    }

    void displayInvoices() {
        for (std::vector<Invoice>::const_iterator it = invoices.begin(); it != invoices.end(); ++it) {
            std::cout << "Patient: " << it->patientName << ", Amount: " << it->amount;
            if (it->paid) {
                std::cout << " (Paid)" << std::endl;
            } else {
                std::cout << " (Unpaid)" << std::endl;
            }
        }
    }
};

int main() {
    Hospital hospital;
    int choice;

    std::cout << "Welcome to Hospital Management System\n\n";

    while(true) {
        std::cout << "1. Add patient\n2. Add doctor\n3. Schedule appointment\n4. Display all patients' information\n5. Display all doctors' information\n6. Display all scheduled appointments\n7. Generate invoice\n8. Display all invoices\n9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                Patient patient;
                std::cout << "Enter patient name: ";
                std::cin >> patient.name;
                std::cout << "Enter patient info: ";
                std::cin >> patient.info;
                std::cout << "Enter patient medical record: ";
                std::cin >> patient.medicalRecord;
                hospital.addPatient(patient);
                std::cout << "Patient added successfully.\n";
                break;
            }
            case 2: {
                Doctor doctor;
                std::cout << "Enter doctor name: ";
                std::cin >> doctor.name;
                std::cout << "Enter doctor info: ";
                std::cin >> doctor.info;
                std::cout << "Enter doctor specialization: ";
                std::cin >> doctor.specialization;
                hospital.addDoctor(doctor);
                std::cout << "Doctor added successfully.\n";
                break;
            }
            case 3: {
                Appointment appointment;
                std::cout << "Enter patient name: ";
                std::cin >> appointment.patient.name;
                std::cout << "Enter doctor name: ";
                std::cin >> appointment.doctor.name;
                std::cout << "Enter appointment time: ";
                std::cin >> appointment.time;
                hospital.scheduleAppointment(appointment);
                std::cout << "Appointment scheduled successfully.\n";
                break;
            }
            case 4:
                hospital.displayPatients();
                break;
            case 5:
                hospital.displayDoctors();
                break;
            case 6:
                hospital.displayAppointments();
                break;
            case 7: {
                Invoice invoice;
                std::cout << "Enter patient name for invoice: ";
                std::cin >> invoice.patientName;
                std::cout << "Enter amount: ";
                std::cin >> invoice.amount;
                invoice.paid = false;
                hospital.addInvoice(invoice);
                std::cout << "Invoice generated successfully.\n";
                break;
            }
            case 8:
                hospital.displayInvoices();
                break;
            case 9:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 9.\n";
        }

        std::cout << "\nPress any key to return to the main menu...";
        std::cin.ignore();
        std::cin.get();
        std::cout << "\n\n";
    }

    return 0;
}
