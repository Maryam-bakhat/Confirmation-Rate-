#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// Structure to store signup information
struct Signup {
    int user_id;
    char time_stamp[20];
};
// Structure to store confirmation information
struct Confirmation {
    int user_id;
    char time_stamp[20];
    char action[10];
};
// Function to calculate and display the confirmation rate

void calculateConfirmationRate(Signup signups[], int signupCount, Confirmation confirmations[], int confirmationCount) {

int maxUserId = 0;

    // Find the maximum user_id to size arrays properly
    for (int i = 0; i < signupCount; i++) {
        if (signups[i].user_id > maxUserId) {
            maxUserId = signups[i].user_id;
        }
    }

    // Arrays to store counts
    int totalRequests[maxUserId + 1] = {0};
    int confirmedRequests[maxUserId + 1] = {0};

    // Count total requests and confirmed actions
    for (int i = 0; i < confirmationCount; i++) {
        int user_id = confirmations[i].user_id;
        totalRequests[user_id]++;
        if (strcmp(confirmations[i].action, "confirmed") == 0) {
            confirmedRequests[user_id]++;
        }
    }

// Print the header
    cout << "+---------+-------------------+" << endl;
    cout << "| user_id | confirmation_rate |" << endl;
    cout << "+---------+-------------------+" << endl;

    // Calculate and display confirmation rates
    for (int i = 0; i < signupCount; i++) {
        int user_id = signups[i].user_id;
        double confirmationRate = 0.0;
        if (totalRequests[user_id] > 0) {
            confirmationRate = static_cast<double>(confirmedRequests[user_id]) / totalRequests[user_id];
        }
        cout << "| " << setw(7) << user_id
             << " | " << setw(17) << fixed << setprecision(2) << confirmationRate << " |" << endl;
    }

    cout << "+---------+-------------------+" << endl;
}int main() {
    int signupCount, confirmationCount;

    // Input for signups
    cout << "Enter the number of signups: ";
    cin >> signupCount;
    Signup signups[signupCount];

    for (int i = 0; i < signupCount; i++) {
        cout << "Enter user_id for signup " << i + 1 << ": ";
        cin >> signups[i].user_id;
        cout << "Enter time_stamp (YYYY-MM-DD HH:MM:SS) for signup " << i + 1 << ": ";
        cin.ignore();
        cin.getline(signups[i].time_stamp, 20);
    }

// Input for confirmations
    cout << "Enter the number of confirmations: ";
    cin >> confirmationCount;
    Confirmation confirmations[confirmationCount];

    for (int i = 0; i < confirmationCount; i++) {
        cout << "Enter user_id for confirmation " << i + 1 << ": ";
        cin >> confirmations[i].user_id;
        cout << "Enter time_stamp (YYYY-MM-DD HH:MM:SS) for confirmation " << i + 1 << ": ";
        cin.ignore();
        cin.getline(confirmations[i].time_stamp, 20);
        cout << "Enter action (confirmed/timeout) for confirmation " << i + 1 << ": ";
        cin >> confirmations[i].action;
    }

    // Calculate and display confirmation rates
    calculateConfirmationRate(signups, signupCount, confirmations, confirmationCount);

    return 0;
}


