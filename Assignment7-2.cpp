//****************************************************************************************************
//     File:               Assignment7-2.cpp
// 
//     Student:            Anna Sargsyan
// 
//     Assignment:         Program #7 Part II
// 
//     Course Name:        Programming II
// 
//     Course Number:      COSC 1560-01
// 
//     Due:                October 30, 2023
//
//     This program creates a struct named Speaker, and keeps track of speakers.
//
//****************************************************************************************************

#include <iostream>
#include <string>

using namespace std;

struct Speaker
{
    string name;
    string phoneNumber;
    string topic;
    double feeRequired;
};

void inputSpeakers(Speaker[], int, int&);
void updateSpeaker(Speaker[], int, const string&);
void displaySpeakerInfo(Speaker[], int, const string&);
void displaySpeakersByTopic(Speaker[], int, const string&);
void displayAllSpeakers(Speaker[], int);

//****************************************************************************************************

int main()
{
    int totalSpeakers;
    cout << "Enter the number of speakers: ";
    cin >> totalSpeakers;

    int numSpeakers = 0;

    Speaker* speakers = new Speaker[totalSpeakers];

    int choice;
    string name,
        topic;

    while (true)
    {
        cout << "1. Add a new speaker\n";
        cout << "2. Update speaker information\n";
        cout << "3. Display specific speaker information\n";
        cout << "4. Display speakers by topic\n";
        cout << "5. Display all speakers\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            inputSpeakers(speakers, totalSpeakers, numSpeakers);
            break;
        case 2:
            cout << "Enter the name of the speaker to update: ";
            cin >> name;
            updateSpeaker(speakers, totalSpeakers, name);
            break;
        case 3:
            cout << "Enter the name of the speaker to display: ";
            cin >> name;
            displaySpeakerInfo(speakers, totalSpeakers, name);
            break;
        case 4:
            cout << "Enter the topic to search for: ";
            cin >> topic;
            displaySpeakersByTopic(speakers, totalSpeakers, topic);
            break;
        case 5:
            displayAllSpeakers(speakers, numSpeakers);
            break;
        case 6:
            delete[] speakers;
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

//****************************************************************************************************

void inputSpeakers(Speaker members[], int totalSpeakers, int& numSpeakers)
{
    if (numSpeakers >= totalSpeakers)
    {
        cout << "The list of speakers is full. Cannot add more speakers." << endl;
        return;
    }

    Speaker newSpeaker;
    cout << "Enter Speaker Name: ";
    cin >> newSpeaker.name;
    cout << "Enter Telephone Number: ";
    cin >> newSpeaker.phoneNumber;
    cout << "Enter Topic: ";
    cin >> newSpeaker.topic;
    cout << "Enter Fee Required(USD): ";
    cin >> newSpeaker.feeRequired;

    if (newSpeaker.feeRequired < 0)
    {
        cout << "Fee cannot be negative. Setting it to 0." << endl;
        newSpeaker.feeRequired = 0;
    }

    members[0] = newSpeaker;
    numSpeakers++;
}

//****************************************************************************************************

void updateSpeaker(Speaker members[], int numSpeakers, const string& speakerName)
{
    for (int i = 0; i < numSpeakers; i++)
    {
        if (members[i].name == speakerName)
        {
            cout << "Enter new Telephone Number: ";
            cin >> members[i].phoneNumber;
            cout << "Enter new Topic: ";
            cin >> members[i].topic;
            cout << "Enter new Fee Required: ";
            cin >> members[i].feeRequired;

            if (members[i].feeRequired < 0)
            {
                cout << "Invalid fee. Fee cannot be negative" << endl;
                members[i].feeRequired = 0;
            }

            cout << "Speaker information updated successfully." << endl;
            return;
        }
    }
    cout << "Speaker not found." << endl;
}

//****************************************************************************************************

void displaySpeakerInfo(Speaker members[], int numSpeakers, const string& speakerName)
{
    for (int i = 0; i < numSpeakers; i++)
    {
        if (members[i].name == speakerName)
        {
            cout << "Name: " << members[i].name << endl;
            cout << "Telephone Number: " << members[i].phoneNumber << endl;
            cout << "Topic: " << members[i].topic << endl;
            cout << "Fee Required: " << members[i].feeRequired << endl;
            return;
        }
    }
    cout << "Speaker not found." << endl;
}

//****************************************************************************************************

void displaySpeakersByTopic(Speaker members[], int numSpeakers, const string& topic)
{
    bool found = false;
    for (int i = 0; i < numSpeakers; i++)
    {
        if (members[i].topic == topic)
        {
            cout << "Name: " << members[i].name << endl;
            cout << "Telephone Number: " << members[i].phoneNumber << endl;
            cout << "Topic: " << members[i].topic << endl;
            cout << "Fee Required: " << members[i].feeRequired << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No speakers found for the given topic." << endl;
    }
}

//****************************************************************************************************

void displayAllSpeakers(Speaker members[], int numSpeakers)
{
    for (int i = 0; i < numSpeakers; i++)
    {
        cout << "Name: " << members[i].name << endl;
        cout << "Telephone Number: " << members[i].phoneNumber << endl;
        cout << "Topic: " << members[i].topic << endl;
        cout << "Fee Required: " << members[i].feeRequired << endl;
        cout << endl;
    }
}

//****************************************************************************************************
/*

Enter the number of speakers: 12
1. Add a new speaker
2. Update speaker information
3. Display specific speaker information
4. Display speakers by topic
5. Display all speakers
6. Exit
Enter your choice: 1
Enter Speaker Name: Anna
Enter Telephone Number: 95670745
Enter Topic: Chess
Enter Fee Required(USD): 100
1. Add a new speaker
2. Update speaker information
3. Display specific speaker information
4. Display speakers by topic
5. Display all speakers
6. Exit
Enter your choice: 5
Name: Anna
Telephone Number: 95670745
Topic: Chess
Fee Required: 100

1. Add a new speaker
2. Update speaker information
3. Display specific speaker information
4. Display speakers by topic
5. Display all speakers
6. Exit
Enter your choice: 6

D:\Classes\COSC 1560 Programming II\Assignment 7 Part 2\Assignment7-2\x64\Debug\Assignment7-2.exe (process 22384) exited with code 0.
Press any key to close this window . . .

*/