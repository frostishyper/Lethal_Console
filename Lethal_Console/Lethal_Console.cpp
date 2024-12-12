#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

//Global Variables
string Moon = "Space";
int Money = 1000;

void Loading();
void Moons();
void Shop();
void Wallet();
void Console();



int main() {
    Loading();
    Console();

    system("pause");
    return 0;
}



void Loading() {
    const int width = 64; // Total width of the box
    const string border = "||";

    cout << "================================================================" << endl;

    // Function to print a line with dynamic content
    auto printLine = [&](const string& content) {
        int padding = width - content.length() - 4; // 4 for "||" on both sides
        cout << border << " " << content;
        cout << string(padding, ' ') << border << endl;
    };

    printLine("Lethal Company Salvage Crew System v0.13"); 
    printLine("Copyright (C) 2000-2025, Advanced Micro Devices, Inc. (AMD)."); 

    cout << "================================================================" << endl;

    printLine("CPU Type : Ryzen 9 9950X3D at 5700 MHz "); 
    printLine("UEFI Standard Boot v1.0"); 
    printLine("(C) 2025 Distributioner"); 
    printLine("Detecting Deep Learning Super Sampling (DLSS) : OK"); 
    printLine("Detecting Ray Tracing Texel eXtreme (RTX) : OK "); 
    printLine("Detecting Video Super Resolution (VSR) : OK"); 

    cout << "================================================================" << endl;

    // Loading Bar
    cout << border << " Loading: ";
    cout << "[" << string(width, ' ') << "] 0%"; // Initial empty loading bar
    cout.flush(); // Ensure the output is displayed immediately

    for (int i = 0; i <= width; ++i) {
        // Calculate percentage
        int percentage = (i * 100) / width;

        // Clear the loading bar line
        cout << "\r" << border << " Loading: [" << string(i, '/') << string(width - i, ' ') << "] " << percentage << "%";
        cout.flush(); // Ensure the output is displayed immediately

        // Sleep for a short duration to simulate loading
        this_thread::sleep_for(chrono::milliseconds(100)); // Adjust the sleep duration as needed
    }
    cout << endl; // Move to the next line after loading is complete

    cout << "================================================================" << endl;
}

void Moons() {
    const int moonCount = 11;
    string moonCodes[] = {"41", "220", "56", "21", "61", "20", "85", "7", "8", "68", "5"};
    string moonNames[moonCount] = {
        "Experimentation",   // 41
        "Assurance",         // 220
        "Vow",               // 56
        "Offence",           // 21
        "March",             // 61
        "Adamance",          // 20
        "Rend",              // 85
        "Dine",              // 7
        "Titan",             // 8
        "Artifice",          // 68
        "Embryon"            // 5
    };

    string riskLevels[] = {"B", "D", "C", "B", "B", "B", "A", "S", "S+", "S++", "S"};
    int travelCosts[] = {0, 0, 0, 0, 0, 0, 550, 600, 700, 1500, 150};

    while (true) {
        string input;
        cout << "================================================================" << endl;
        cout << "Welcome to the Navigator." << endl;
        cout << "Enter the Moon's code or its Name to travel, or type 'Exit' to return to the main menu." << endl;
        cout << "---------------------------------------------------" << endl << endl;

        // Display the list of moons with full information
        for (int i = 0; i < moonCount; ++i) {
            cout << " * " << moonCodes[i] << " - " << moonNames[i] << " // Risk Level: " << riskLevels[i] << " // $" << travelCosts[i] << endl;
        }

        cin >> input;

        if (input == "Exit" || input == "exit") {
            Console();
            return;
        }

        // Check if input is a valid moon code or name
        int moonIndex = -1;
        for (int i = 0; i < moonCount; ++i) {
            if (input == moonCodes[i] || input == moonNames[i]) {
                moonIndex = i;
                break;
            }
        }

        if (moonIndex == -1) {
            cout << "Moon does not exist. Please choose a valid moon." << endl;
            continue;
        }

        // Proceed with travel
        int travelCost = travelCosts[moonIndex];
        string moonName = moonNames[moonIndex];
        string threatLevel = riskLevels[moonIndex]; // Adjusted to use string for risk levels

        cout << "Confirm travel to " << moonName << " costing $" << travelCost << " risk level " << threatLevel << "? (confirm/exit): ";

        cin >> input;
        if (input == "confirm") {
            if (Money >= travelCost) {
                Money -= travelCost;
                Moon = moonName;
                cout << "Travel successful! You are now on " << Moon << "." << endl;
            } else {
                cout << "Not enough funds to travel." << endl;
            }
        } else if (input == "exit") {
            continue; // Return to the moon selection menu
        } else {
            cout << "Invalid input. Please try again." << endl;
        }

        cout << "================================================================" << endl;
    }
}




//Item Shop
void Shop() {
    cout << endl << endl;

    // {ID, Price}
    int Catalogue[17][2] = {
        {1, 12},   // 1 - Walkie-Talkie 
        {2, 15},   // 2 - Flashlight
        {3, 30},   // 3 - Shovel
        {4, 20},   // 4 - Lock-Picker
        {5, 25},   // 5 - Pro-Flashlight
        {6, 30},   // 6 - Stun-Grenade
        {7, 60},   // 7 - Boom-Box
        {8, 400},   // 8 - Zap-Gun
        {9, 900},   // 9 - Jetpack
        {10, 60},  // 10 - Extension-Ladder
        {11, 60},  // 11 - Radar-Booster
        {12, 25},  // 12 - Weed-Killer
        {13, 45},  // 13 - Belt-Bag
        {14, 100},  // 14 - Loud-Horn
        {15, 375},  // 15 - Teleporter
        {16, 425},  // 16 - Inverse-Teleporter
        {17, 255}   // 17 - Signal-Translator
    };

    string itemNames[17] = {
        "Walkie-Talkie", "Flashlight", "Shovel", "LockPicker", "Pro-Flashlight", 
        "Stun-Grenade", "Boom-Box", "Zap-Gun", "Jetpack", "Extension-Ladder", 
        "Radar-Booster", "Weed-Killer", "Belt-Bag", "Loud-Horn", "Teleporter", 
        "Inverse-Teleporter", "Signal-Translator"
    };

    while (true) {
        string Purchase;

        cout << endl << "================================================================" << endl;

        cout << "Welcome To Company Store." << endl;
        cout << "Insert KEYWORD to buy an item or type 'back' to return to the main menu." << endl;
        cout << "---------------------------------------------------" << endl << endl;

        cout << "TOOLS & UTILITY" << endl;

        // Display each item and its price
        for (int i = 0; i < 13; ++i) {
            cout << " * " << itemNames[i] << " // $" << Catalogue[i][1] << endl;
        }

        cout << endl << "SHIP UPGRADES" << endl;

        // Display each ship upgrade and its price
        for (int i = 13; i < 17; ++i) {
            cout << " * " << itemNames[i] << " // $" << Catalogue[i][1] << endl;
        }

        cin >> Purchase;

        if (Purchase == "back") {
            Console();
            return;
        }

        // Validate the purchase input
        int itemIndex = -1;
        for (int i = 0; i < 17; ++i) {
            if (itemNames[i] == Purchase) {
                itemIndex = i;
                break;
            }
        }

        if (itemIndex == -1) {
            cout << "Invalid item. Please try again." << endl;
            continue;
        }

        int price = Catalogue[itemIndex][1];

        if (itemIndex < 13) { // For tools and utilities
            int quantity = 0;
            while (true) {
                cout << "Enter quantity: ";
                cin >> quantity;

                if (cin.fail() || quantity <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid quantity. Please enter a positive integer." << endl;
                } else {
                    break;
                }
            }

            int totalCost = price * quantity;
            cout << "Purchase: " << itemNames[itemIndex] << " (" << quantity << ") Total: $" << totalCost << endl;
            cout << "Type 'confirm' to proceed or 'cancel' to go back: ";

            string confirmation;
            cin >> confirmation;

            if (confirmation == "confirm") {
                if (Money >= totalCost) {
                    Money -= totalCost;
                    cout << "Purchase successful! Remaining balance: $" << Money << endl;
                } else {
                    cout << "Insufficient funds. Please top up your wallet." << endl;
                }
            } else {
                cout << "Transaction cancelled." << endl;
            }
        } else { // For ship upgrades
            cout << "Purchase: " << itemNames[itemIndex] << " Price: $" << price << endl;
            cout << "Type 'confirm' to proceed or 'cancel' to go back: ";

            string confirmation;
            cin >> confirmation;

            if (confirmation == "confirm") {
                if (Money >= price) {
                    Money -= price;
                    cout << "Purchase successful! Remaining balance: $" << Money << endl;
                } else {
                    cout << "Insufficient funds. Please top up your wallet." << endl;
                }
            } else {
                cout << "Transaction cancelled." << endl;
            }
        }
    }

    cout << endl << "================================================================" << endl;
}


void Console() {
    cout << endl << endl;

    string input;

    cout << "================================================================" << endl;

    cout << endl << "$ : " << Money;
    cout << endl << "Location : " << Moon << endl << endl;

    cout << endl << ">" << "Moons" << endl << endl;
    cout << endl << ">" << "Shop" << endl << endl;
    cout << endl << ">" << "Wallet" << endl << endl;
    cout << endl << ">" << "Quit" << endl << endl;

    cin >> input;
    if (input == "Moons" || input == "moons") {
        Moons();
    } 
    else if (input == "Shop" || input == "shop") {
        Shop();
    } 
    else if (input == "Wallet" || input == "wallet") {
        Wallet();
    } 
    else if (input == "Quit" || input == "quit") {
        cout << "Exiting the program. Goodbye!" << endl;
        return; // Exit the program
    }
    else {
        cout << "No Matching Valid Input";
    }

    cout << "================================================================" << endl;
}


//Top-Up Wallet
void Wallet() {
    cout << endl << endl;
    while (true) {
        string input;
        int topUpAmount = 0;

        cout << "================================================================" << endl;

        cout << "Insert Amount To Top Up Wallet (or type 'main' to return to Main Menu):" << endl;
        cout << "================================================================" << endl;
        cin >> input;

        // Check if user wants to return to Main Menu
        if (input == "main") {
            Console();
            return;
        }

        // Validate input as an integer
        try {
            topUpAmount = stoi(input);

            if (topUpAmount < 0) {
                throw invalid_argument("Negative value not allowed.");
            }

            // Successful top-up
            Money += topUpAmount;
            cout << "Top Up Success! New Balance: $" << Money << endl;

        } catch (const exception& e) {
            // Invalid input handling
            cout << "Invalid Input! Please try again." << endl;
        }
    }
}



