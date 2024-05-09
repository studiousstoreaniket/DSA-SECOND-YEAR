#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Define the Patient structure
struct Patient {
    string name;
    int priority; // 1 for serious, 2 for non-serious, 3 for general checkup

    // Overloading '<' operator for comparing priorities
    bool operator<(const Patient& other) const {
        // Higher priority patients should come before lower priority patients
        return priority > other.priority;
    }
};

int main() {
    // Define the priority queue to hold patients
    priority_queue<Patient> patientQueue;

    // Variables to store user input
    string name;
    char condition;

    // Collect user input for patients until they're done
    while (true) {
        cout << "Enter patient's name: ";
        cin >> name;

        cout << "Enter patient's condition (S for Serious, N for Non-serious, G for General checkup): ";
        cin >> condition;

        int priority;
        switch (condition) {
            case 'S':
            case 's':
                priority = 1;
                break;
            case 'N':
            case 'n':
                priority = 2;
                break;
            case 'G':
            case 'g':
                priority = 3;
                break;
            default:
                cout << "Invalid condition entered. Please try again." << endl;
                continue; // Restart loop for this invalid input
        }

        // Enqueue the patient with the collected information
        patientQueue.push({name, priority});

        char choice;
        cout << "Do you want to add another patient? (Y/N): ";
        cin >> choice;
        if (choice == 'N' || choice == 'n')
            break;
    }

    // Dequeue and serve patients based on priority
    cout << "\nPatients being served:\n";
    while (!patientQueue.empty()) {
        // Get the highest priority patient
        Patient currentPatient = patientQueue.top();
        // Serve the patient
        cout << "Serving patient: " << currentPatient.name << " (Priority: " << currentPatient.priority << ")" << endl;
        // Remove the served patient from the queue
        patientQueue.pop();
    }

    return 0;
}
