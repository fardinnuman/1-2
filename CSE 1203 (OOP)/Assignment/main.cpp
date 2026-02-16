#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <conio.h>
#include <windows.h> // ← ADD THIS LINE (for colors)

using namespace std;

// ========================== Global Constants & Structures =====================
const string MEMBER_FILE = "members.txt";
const string HISTORY_FILE = "history.txt";

// Transaction types for history
enum TranType
{
    CASH_IN,
    CASH_OUT,
    SEND_MONEY,
    PAY_BILL
};

// Bill types
enum BillType
{
    GAS = 1,
    ELECTRICITY,
    WATER,
    INTERNET
};

// ========================== Class History =====================================
class History
{
private:
    int tranID;
    string customerMobile;
    TranType type;
    double amount;
    double balanceAfter;
    string dateTime;

public:
    // Constructor
    History(int id, string mobile, TranType t, double amt, double bal)
    {
        tranID = id;
        customerMobile = mobile;
        type = t;
        amount = amt;
        balanceAfter = bal;

        // Get current date-time
        time_t now = time(0);
        char *dt = ctime(&now);
        dateTime = string(dt);
        dateTime.pop_back(); // remove newline
    }

    // Save to file
    void saveToFile()
    {
        ofstream fout(HISTORY_FILE, ios::app);
        if (fout)
        {
            fout << tranID << "," << customerMobile << "," << type << ","
                 << amount << "," << balanceAfter << "," << dateTime << endl;
            fout.close();
        }
    }

    // Static method to display history for a mobile
    static void showHistory(string mobile)
    {
        ifstream fin(HISTORY_FILE);
        if (!fin)
        {
            cout << "No history found.\n";
            return;
        }

        cout << "\n=== Transaction History ===\n";
        cout << "Tran ID\tDescription\t\tAmount\tBalance\n";

        string line;
        bool hasHistory = false;
        while (getline(fin, line))
        {
            stringstream ss(line);
            string token;
            vector<string> tokens;

            while (getline(ss, token, ','))
                tokens.push_back(token);

            if (tokens.size() >= 6 && tokens[1] == mobile)
            {
                hasHistory = true;
                int ttype = stoi(tokens[2]);
                string desc;
                switch (ttype)
                {
                case CASH_IN:
                    desc = "Cash-in";
                    break;
                case CASH_OUT:
                    desc = "Cash-out";
                    break;
                case SEND_MONEY:
                    desc = "Send Money";
                    break;
                case PAY_BILL:
                    desc = "Bill Payment";
                    break;
                }
                cout << " " << tokens[0] << "\t" << desc;
                if (desc.length() < 8)
                    cout << "\t"; // Tab alignment
                cout << "\t\t" << tokens[3] << "\t" << tokens[4] << endl;
            }
        }
        fin.close();

        if (!hasHistory)
        {
            cout << "No transactions found.\n";
        }
    }

    // Generate new transaction ID (simple incremental from file)
    static int generateNewTranID()
    {
        ifstream fin(HISTORY_FILE);
        int maxID = 100;
        string line;
        while (getline(fin, line))
        {
            stringstream ss(line);
            string idStr;
            getline(ss, idStr, ',');
            int id = stoi(idStr);
            if (id > maxID)
                maxID = id;
        }
        fin.close();
        return maxID + 1;
    }
};

// ========================== Class Member ======================================
class Member
{
private:
    string mobile;
    string name;
    double amount;
    string pin;

public:
    Member() {}
    Member(string m, string n, double a, string p)
    {
        mobile = m;
        name = n;
        amount = a;
        pin = p;
    }

    // Getters
    string getMobile() const { return mobile; }
    string getName() const { return name; }
    double getAmount() const { return amount; }
    string getPin() const { return pin; }

    // Setters
    void setName(string n) { name = n; }
    void setPin(string p) { pin = p; }
    void setAmount(double a) { amount = a; }

    // Save member to file (append)
    void saveToFile() const
    {
        ofstream fout(MEMBER_FILE, ios::app);
        if (fout)
        {
            fout << mobile << "," << name << "," << amount << "," << pin << endl;
            fout.close();
        }
    }

    // Update member in file (rewrite entire file)
    static void updateInFile(const vector<Member> &members)
    {
        ofstream fout(MEMBER_FILE);
        if (fout)
        {
            for (const Member &m : members)
            {
                fout << m.mobile << "," << m.name << "," << m.amount << "," << m.pin << endl;
            }
            fout.close();
        }
    }

    // Display member info
    void display() const
    {
        cout << "Mobile: " << mobile << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << amount << endl;
    }
};

// ========================== Global Variables & Helper Functions ==============
vector<Member> allMembers;

// Load all members from file into vector
void loadAllMembers()
{
    allMembers.clear();
    ifstream fin(MEMBER_FILE);
    if (!fin)
        return;

    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        string mobile, name, pin;
        double amount;
        getline(ss, mobile, ',');
        getline(ss, name, ',');
        string amtStr;
        getline(ss, amtStr, ',');
        amount = stod(amtStr);
        getline(ss, pin, ',');
        allMembers.push_back(Member(mobile, name, amount, pin));
    }
    fin.close();
}

// Find member by mobile, return index or -1
int findMemberIndex(string mobile)
{
    for (int i = 0; i < allMembers.size(); i++)
    {
        if (allMembers[i].getMobile() == mobile)
            return i;
    }
    return -1;
}

// Check if mobile is valid (11 digits, starts with 01)
bool isValidMobile(string mobile)
{
    if (mobile.length() != 11)
        return false;
    if (mobile.substr(0, 2) != "01")
        return false;
    for (char c : mobile)
        if (!isdigit(c))
            return false;
    return true;
}

// Generate 4-digit OTP
int generateOTP()
{
    return 1000 + rand() % 9000;
}

// Validate OTP with time (2 minutes = 120 seconds)
bool validateOTP(int generatedOTP, int enteredOTP, time_t generatedTime)
{
    if (generatedOTP != enteredOTP)
    {
        cout << "Error: OTP does NOT matched (Message 5)\n";
        return false;
    }
    time_t now = time(0);
    if (difftime(now, generatedTime) > 120)
    {
        cout << "Error: OTP time has expired (Message 6)\n";
        return false;
    }
    return true;
}

// Hide PIN input
string getHiddenPin()
{
    string pin = "";
    char ch;
    while ((ch = _getch()) != '\r')
    {
        if (ch == '\b' && pin.length() > 0)
        {
            cout << "\b \b";
            pin.pop_back();
        }
        else if (isdigit(ch))
        {
            pin += ch;
            cout << '*';
        }
    }
    cout << endl;
    return pin;
}

// Clear input buffer
void clearInputBuffer()
{
    cin.clear();
    cin.ignore(10000, '\n'); // Simple alternative
}

// ===== COLOR FUNCTIONS - ADD THIS =====
void setYellowColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14); // Yellow
}

void setDefaultColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7); // Back to white
}

// ========================== Transaction Functions ============================
void registerMember()
{
    cout << "\n--- Register New Member ---\n";

    string mobile, name, pin, confirmPin;
    cout << "Enter Mobile No. (11-digit): ";
    cin >> mobile;

    if (!isValidMobile(mobile))
    {
        cout << "Error: Invalid Mobile Number (Message 4)\n";
        return;
    }

    if (findMemberIndex(mobile) != -1)
    {
        cout << "Error: Member already exists (Message 1)\n";
        return;
    }

    clearInputBuffer();
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter pin (5-digit): ";
    pin = getHiddenPin();
    if (pin.length() != 5)
    {
        cout << "PIN must be 5 digits.\n";
        return;
    }

    cout << "Reconfirm pin: ";
    confirmPin = getHiddenPin();

    if (pin != confirmPin)
    {
        cout << "Error: Pins must be same (Message 7)\n";
        return;
    }

    // OTP verification for registration
    srand(time(0));
    int otp = generateOTP();
    time_t otpTime = time(0);
    setYellowColor();
    cout << "myCash OTP: " << otp << endl;
    setDefaultColor();
    cout << "Enter OTP: ";
    int userOTP;
    cin >> userOTP;

    if (!validateOTP(otp, userOTP, otpTime))
    {
        return;
    }

    Member newMember(mobile, name, 0.0, pin);
    newMember.saveToFile();
    allMembers.push_back(newMember);
    cout << "Registration is Successful.\nPress any key to go to main menu....";
    _getch();
}

Member *login()
{
    cout << "\n--- Login ---\n";
    string mobile, pin;
    cout << "Enter Mobile No. (11-digit): ";
    cin >> mobile;
    cout << "Enter pin: ";
    pin = getHiddenPin();

    int idx = findMemberIndex(mobile);
    if (idx == -1)
    {
        cout << "Error: Member NOT exists (Message 2)\n";
        return nullptr;
    }

    if (allMembers[idx].getPin() != pin)
    {
        cout << "Error: Invalid login (Message 8)\n";
        return nullptr;
    }

    cout << "Login is Successful.\n";
    return &allMembers[idx];
}

void updateMember(Member *user)
{
    cout << "\n--- Update Member ---\n";
    string newName, newPin, confirmPin;
    clearInputBuffer();

    cout << "Old Name: " << user->getName() << endl;
    cout << "New Name (enter to ignore): ";
    getline(cin, newName);

    if (!newName.empty())
    {
        user->setName(newName);
        cout << "Name updated successfully.\n";
    }

    cout << "Old pin: *****\n";
    cout << "New pin (enter to ignore): ";
    newPin = getHiddenPin();

    if (!newPin.empty())
    {
        if (newPin.length() != 5)
        {
            cout << "PIN must be 5 digits.\n";
            return;
        }

        cout << "Confirm New pin: ";
        confirmPin = getHiddenPin();

        if (newPin != confirmPin)
        {
            cout << "Error: Pins must be same (Message 7)\n";
            return;
        }

        // OTP for PIN change
        srand(time(0));
        int otp = generateOTP();
        time_t otpTime = time(0);
        setYellowColor();
        cout << "myCash OTP: " << otp << endl;
        setDefaultColor();
        cout << "Enter OTP: ";
        int userOTP;
        cin >> userOTP;

        if (!validateOTP(otp, userOTP, otpTime))
        {
            return;
        }

        user->setPin(newPin);
        // cout << "PIN updated successfully.\n";
    }

    // Update in file
    Member::updateInFile(allMembers);
    cout << "Update is Successful\n";
}

void removeMember(Member *user)
{
    cout << "\n--- Remove Account ---\n";

    // OTP verification
    srand(time(0));
    int otp = generateOTP();
    time_t otpTime = time(0);
    setYellowColor();
    cout << "myCash OTP: " << otp << endl;
    setDefaultColor();
    cout << "Enter OTP: ";
    int userOTP;
    cin >> userOTP;

    if (!validateOTP(otp, userOTP, otpTime))
    {
        return;
    }

    // char confirm;
    // cout << "Are you sure? (Y/N): ";
    // cin >> confirm;

    // if (confirm != 'Y' && confirm != 'y')
    // {
    //     if (confirm != 'N' && confirm != 'n')
    //     {
    //         cout << "Error: Enter Y or N (Message 11)\n";
    //     }
    //     else
    //     {
    //         cout << "Account removal cancelled.\n";
    //     }
    //     return;
    // }

    // Remove from vector
    int idx = findMemberIndex(user->getMobile());
    if (idx != -1)
    {
        allMembers.erase(allMembers.begin() + idx);
        Member::updateInFile(allMembers);
        cout << "Remove is Successful\n";
        cout << "Back to MyCash Login Menu\n";
    }
}

void cashIn(Member *user)
{
    cout << "\n--- Cash-in ---\n";
    double amount;
    cout << "Enter Amount: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount. Amount must be positive.\n";
        return;
    }

    cout << "Cash-in " << amount << endl;
    cout << "Are you sure(Y/N)? ";
    char choice;
    cin >> choice;

    if (choice != 'Y' && choice != 'y')
    {
        if (choice != 'N' && choice != 'n')
        {
            cout << "Error: Enter Y or N (Message 11)\n";
        }
        else
        {
            cout << "Cash-in cancelled.\n";
        }
        return;
    }

    user->setAmount(user->getAmount() + amount);

    // Update file
    Member::updateInFile(allMembers);

    // Add history
    History h(History::generateNewTranID(), user->getMobile(),
              CASH_IN, amount, user->getAmount());
    h.saveToFile();

    cout << "Cash-in is Successful\n";
}

void cashOut(Member *user)
{
    cout << "\n--- Cash-out ---\n";
    double amount;
    cout << "Enter Amount: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount. Amount must be positive.\n";
        return;
    }

    if (user->getAmount() < amount)
    {
        cout << "Error: Insufficient Fund (Message 3)\n";
        return;
    }

    cout << "Cash-out " << amount << endl;
    cout << "Are you sure(Y/N)? ";
    char choice;
    cin >> choice;

    if (choice != 'Y' && choice != 'y')
    {
        if (choice != 'N' && choice != 'n')
        {
            cout << "Error: Enter Y or N (Message 11)\n";
        }
        else
        {
            cout << "Cash-out cancelled.\n";
        }
        return;
    }

    // OTP verification for cash-out
    srand(time(0));
    int otp = generateOTP();
    time_t otpTime = time(0);
    setYellowColor();
    cout << "myCash OTP: " << otp << endl;
    setDefaultColor();
    cout << "Enter OTP: ";
    int userOTP;
    cin >> userOTP;

    if (!validateOTP(otp, userOTP, otpTime))
    {
        return;
    }

    user->setAmount(user->getAmount() - amount);
    Member::updateInFile(allMembers);

    // Add history
    History h(History::generateNewTranID(), user->getMobile(),
              CASH_OUT, amount, user->getAmount());
    h.saveToFile();

    cout << "Cash-out is Successful\n";
}

void sendMoney(Member *sender)
{
    cout << "\n--- Send Money ---\n";
    string destMobile;
    cout << "Enter Destination no. (11-digit): ";
    cin >> destMobile;

    if (!isValidMobile(destMobile))
    {
        cout << "Error: Destination Mobile no. is invalid (Message 9)\n";
        return;
    }

    if (destMobile == sender->getMobile())
    {
        cout << "Error: Cannot send money to yourself.\n";
        return;
    }

    int idx = findMemberIndex(destMobile);
    if (idx == -1)
    {
        cout << "Error: Member NOT exists (Message 2)\n";
        return;
    }

    double amount;
    cout << "Enter Amount: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount. Amount must be positive.\n";
        return;
    }

    if (sender->getAmount() < amount)
    {
        cout << "Error: Insufficient Fund (Message 3)\n";
        return;
    }

    cout << "Sending " << amount << " to " << destMobile << endl;
    cout << "Are you sure(Y/N)? ";
    char choice;
    cin >> choice;

    if (choice != 'Y' && choice != 'y')
    {
        if (choice != 'N' && choice != 'n')
        {
            cout << "Error: Enter Y or N (Message 11)\n";
        }
        else
        {
            cout << "Send money cancelled.\n";
        }
        return;
    }

    // OTP verification for send money
    srand(time(0));
    int otp = generateOTP();
    time_t otpTime = time(0);
    setYellowColor();
    cout << "myCash OTP: " << otp << endl;
    setDefaultColor();
    cout << "Enter OTP: ";
    int userOTP;
    cin >> userOTP;

    if (!validateOTP(otp, userOTP, otpTime))
    {
        return;
    }

    // Perform transaction
    sender->setAmount(sender->getAmount() - amount);
    allMembers[idx].setAmount(allMembers[idx].getAmount() + amount);

    // Update file
    Member::updateInFile(allMembers);

    // Add history for sender
    History h1(History::generateNewTranID(), sender->getMobile(),
               SEND_MONEY, amount, sender->getAmount());
    h1.saveToFile();

    // Add history for receiver
    History h2(History::generateNewTranID(), destMobile,
               SEND_MONEY, amount, allMembers[idx].getAmount());
    h2.saveToFile();

    cout << "Send Money is Successful\n";
}

void payBill(Member *user)
{
    cout << "\n--- Pay Bill ---\n";
    cout << "Enter Bill Type (Gas/Electricity/Water/Internet-1/2/3/4): ";

    int billType;
    cin >> billType;

    if (billType < 1 || billType > 4)
    {
        cout << "Invalid bill type.\n";
        return;
    }

    string billNames[] = {"Gas", "Electricity", "Water", "Internet"};
    // Fixed demo bill amounts
    double billAmounts[] = {850.0, 1250.0, 480.0, 1000.0}; // Internet 1000 as per snapshot

    double billAmount = billAmounts[billType - 1];
    cout << "Your " << billNames[billType - 1] << " Bill: " << billAmount << endl;

    cout << "Want to pay(Y/N)? ";
    char choice;
    cin >> choice;

    if (choice != 'Y' && choice != 'y')
    {
        if (choice != 'N' && choice != 'n')
        {
            cout << "Error: Enter Y or N (Message 11)\n";
        }
        else
        {
            cout << "Bill payment cancelled.\n";
        }
        return;
    }

    if (user->getAmount() < billAmount)
    {
        cout << "Error: Insufficient Fund (Message 3)\n";
        return;
    }

    // OTP verification for bill payment
    srand(time(0));
    int otp = generateOTP();
    time_t otpTime = time(0);
    setYellowColor();
    cout << "myCash OTP: " << otp << endl;
    setDefaultColor();
    cout << "Enter OTP: ";
    int userOTP;
    cin >> userOTP;

    if (!validateOTP(otp, userOTP, otpTime))
    {
        return;
    }

    user->setAmount(user->getAmount() - billAmount);
    Member::updateInFile(allMembers);

    // Add history
    History h(History::generateNewTranID(), user->getMobile(),
              PAY_BILL, billAmount, user->getAmount());
    h.saveToFile();

    // cout << billNames[billType - 1] << " Bill Payment is Successful\n";
    cout << "Bill Payment is Successful\n";
}

void checkBalance(Member *user)
{
    cout << "\n--- Check Balance ---\n";
    cout << "Balance: " << user->getAmount() << endl;
}

// ========================== Main Function =====================================
int main()
{
    // Initialize random seed
    srand(time(0));

    // Load existing members from file
    loadAllMembers();

    Member *currentUser = nullptr;
    int option;

    while (true)
    {
        if (!currentUser)
        {
            // Login Menu
            cout << "***MyCash Login***\n";
            cout << "1. Login\n2. Register\n3. Exit\n";
            cout << "   Enter Your Option: ";

            if (!(cin >> option))
            {
                cin.clear();
                clearInputBuffer();
                cout << "Error: Invalid Option (Message 10)\n";
                continue;
            }

            switch (option)
            {
            case 1:
                currentUser = login();
                if (currentUser)
                {
                    cout << "Welcome, " << currentUser->getName() << "!\n";
                }
                break;
            case 2:
                registerMember();
                loadAllMembers(); // Reload members after registration
                break;
            case 3:
                cout << "\nThank you for using myCash. Goodbye!\n";
                return 0;
            default:
                cout << "Error: Invalid Option (Message 10)\n";
            }
        }
        else
        {
            // Main Menu
            cout << "\n********** MyCash Menu ********\n";
            cout << "1. Update Me\n2. Remove Me\n3. Send Money\n";
            cout << "4. Cash-in\n5. Cash-out\n6. Pay Bill\n";
            cout << "7. Check Balance\n8. History\n9. Logout\n";
            cout << "   Enter Your Option (1-9): ";

            if (!(cin >> option))
            {
                cin.clear();
                clearInputBuffer();
                cout << "Error: Invalid Option (Message 10)\n";
                continue;
            }

            switch (option)
            {
            case 1:
                updateMember(currentUser);
                loadAllMembers(); // Reload after update
                // Update currentUser pointer after reload
                {
                    int idx = findMemberIndex(currentUser->getMobile());
                    if (idx != -1)
                    {
                        currentUser = &allMembers[idx];
                    }
                }
                break;

            case 2:
                removeMember(currentUser);
                loadAllMembers();      // Reload after removal
                currentUser = nullptr; // Auto logout after removal
                break;

            case 3:
                sendMoney(currentUser);
                break;

            case 4:
                cashIn(currentUser);
                break;

            case 5:
                cashOut(currentUser);
                break;

            case 6:
                payBill(currentUser);
                break;

            case 7:
                checkBalance(currentUser);
                break;

            case 8:
                History::showHistory(currentUser->getMobile());
                break;

            case 9:
                currentUser = nullptr;
                cout << "Successfully logged out.\n";
                break;

            default:
                cout << "Error: Invalid Option (Message 10)\n";
            }

            if (option != 9 && currentUser != nullptr)
            {
                cout << "\nPress any key to go to main menu.....";
                _getch();
            }
        }
    }

    return 0;
}