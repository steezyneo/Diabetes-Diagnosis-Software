#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

class Diabetes
{
private:
    string name;
    float age;
    int weight;
    float height;
    char sex;
    string symptoms;

public:
    void welcomeScreen();
    void getValue();
    void getLevel1Symptoms();
    void getLevel2Symptoms();
    void getLevel3Symptoms();
    int analyzeSymptoms(int level);
    char displayMessage(int level, int result);
};

void clearScreen()
{
    system("CLS");
}

void Diabetes::welcomeScreen()
{
    clearScreen();
    cout << setw(55) << "DIABETES DIAGNOSIS SOFTWARE" << endl;
    cout << setw(45) << " PRESS ANY KEY TO CONTINUE " << endl;
    cin.get();
}

void Diabetes::getValue()
{
    clearScreen();
    cout << "PERSONAL INFORMATION\n\n";
    cout << "Name: ";
    getline(cin, name);
    cout << "Age: ";
    cin >> age;
    cout << "Weight: ";
    cin >> weight;
    cout << "Height: ";
    cin >> height;
    cout << "Sex (M/F): ";
    cin >> sex;
    sex = toupper(sex);
    cin.ignore();
}

void Diabetes::getLevel1Symptoms()
{
    clearScreen();
    symptoms.clear();
    char temp;
    cout << " MEDICAL DIAGNOSIS FORM \n\n";
    cout << "APPETITE (H:HIGH / L:LOW / N:NORMAL): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "FREQUENCY OF THIRST (H:HIGH / L:LOW / N:NORMAL): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "FREQUENCY OF URINATION (H:HIGH / L:LOW / N:NORMAL): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "VISION (I:IMPAIRMENT / N:NORMAL): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "URINE SUGAR (P:PRESENT / A:ABSENT): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "KETONUREA (P:PRESENT / A:ABSENT): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "FASTING BLOOD SUGAR (H:HIGH / L:LOW / N:NORMAL): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "RBS (H:HIGH / L:LOW / N:NORMAL): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "FAMILY HISTORY OF DIABETES (P:PRESENT / A:ABSENT): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "OGTT (D:DETECTED / N:NOT DETECTED): ";
    cin >> temp;
    symptoms += toupper(temp);
}

void Diabetes::getLevel2Symptoms()
{
    clearScreen();
    char temp;
    cout << "PANCREATITIS (P/A): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "CARCINOMA (P/A): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "CIRRHOSIS (P/A): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "HCTS (H/L/N): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "HEPATITIS (P/A): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "HORMONAL DISORDER (P/A): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "PANCREATECTOMY (P/A): ";
    cin >> temp;
    symptoms += toupper(temp);
}

void Diabetes::getLevel3Symptoms()
{
    clearScreen();
    char temp;
    cout << "AGE (Y:Young / M:Middle-aged / E:Elderly): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "BODY WEIGHT (N:Normal / A:Above normal / B:Below normal / O:Obese): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "DURATION (W:Weeks / M:Months / Y:Years): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "KETONUREA (P/A): ";
    cin >> temp;
    symptoms += toupper(temp);
    cout << "AUTO ANTIBODIES (P/A): ";
    cin >> temp;
    symptoms += toupper(temp);
}

int Diabetes::analyzeSymptoms(int level)
{
    int count = 0;
    switch (level)
    {
    case 1:
        if (symptoms[9] == 'D')
            return -1;
        if (symptoms[5] == 'P' && symptoms[6] == 'P' && symptoms[7] == 'H')
            return -1;
        for (char symptom : symptoms)
        {
            if (symptom == 'H' || symptom == 'P' || symptom == 'D' || symptom == 'I')
                count++;
        }
        return (count > 5) ? -1 : 0;
    case 2:
        return (symptoms[0] == 'P' || symptoms[1] == 'P' || symptoms[2] == 'P' ||
                symptoms[3] == 'H' || symptoms[4] == 'P' || symptoms[5] == 'P' || symptoms[6] == 'P')
                   ? -1
                   : 0;
    case 3:
        if ((symptoms[0] == 'Y' && symptoms[1] == 'N' && symptoms[2] == 'W' && symptoms[3] == 'P' && symptoms[4] == 'P') ||
            (symptoms[0] == 'Y' && symptoms[1] == 'B' && symptoms[2] == 'W' && symptoms[3] == 'P' && symptoms[4] == 'P') ||
            (symptoms[0] == 'Y' && symptoms[1] == 'N' && symptoms[2] == 'M' && symptoms[3] == 'P' && symptoms[4] == 'P') ||
            (symptoms[0] == 'Y' && symptoms[1] == 'N' && symptoms[2] == 'Y' && symptoms[3] == 'P' && symptoms[4] == 'P'))
            return 0;
        return -1;
    default:
        return 0;
    }
}

char Diabetes::displayMessage(int level, int result)
{
    char choice;
    clearScreen();
    switch (level)
    {
    case 1:
        if (result == 0)
        {
            cout << "THE PERSON IS NOT DIABETIC\n";
            cout << "PRESS ANY KEY TO QUIT.";
            cin.get();
            exit(0);
        }
        else
        {
            cout << "THE PERSON IS DIABETIC\n";
            cout << "PROCEED (Y/N)? ";
            cin >> choice;
        }
        break;
    case 2:
        if (result == 0)
        {
            cout << "IT IS PRIMARY DIABETES.\n";
            cout << "PROCEED (Y/N)? ";
            cin >> choice;
        }
        else
        {
            cout << "IT IS SECONDARY DIABETES\n";
            cout << "PRESS ANY KEY TO QUIT.";
            cin.get();
            cin.get();
            exit(0);
        }
        break;
    case 3:
        if (result == 0)
        {
            cout << "IT IS INSULIN DEPENDENT DIABETES\n";
            cout << "PRESS ANY KEY TO QUIT.";
            cin.get();
            cin.get();
            exit(0);
        }
        else
        {
            cout << "IT IS NON INSULIN DEPENDENT DIABETES\n";
            cout << "PRESS ANY KEY TO QUIT.";
            cin.get();
            cin.get();
            exit(0);
        }
        break;
    default:
        break;
    }
    return toupper(choice);
}

int main()
{
    Diabetes dts;
    dts.welcomeScreen();
    dts.getValue();

    int level = 1;
    int result;
    char choice;

    dts.getLevel1Symptoms();
    result = dts.analyzeSymptoms(level);
    choice = dts.displayMessage(level, result);

    while (choice == 'Y' && level < 3)
    {
        ++level;
        if (level == 2)
        {
            dts.getLevel2Symptoms();
        }
        else if (level == 3)
        {
            dts.getLevel3Symptoms();
        }
        result = dts.analyzeSymptoms(level);
        choice = dts.displayMessage(level, result);
    }

    return 0;
}
