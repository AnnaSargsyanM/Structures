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

const int MAX_SPEAKERS = 10;

void inputSpeakers(Speaker[], int, int&);
void updateSpeaker(Speaker[], int, const string&);
void displaySpeakerInfo(Speaker[], int, const string&);
void displaySpeakersByTopic(Speaker[], int, const string&);
void displayAllSpeakers(Speaker[], int);

int main() 
{
    Speaker speakers[MAX_SPEAKERS];
    int numSpeakers = 0;

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
            inputSpeakers(speakers, MAX_SPEAKERS, numSpeakers);
            break;
        case 2:
            cout << "Enter the name of the speaker to update: ";
            cin >> name;
            updateSpeaker(speakers, numSpeakers, name);
            break;
        case 3:
            cout << "Enter the name of the speaker to display: ";
            cin >> name;
            displaySpeakerInfo(speakers, numSpeakers, name);
            break;
        case 4:
            cout << "Enter the topic to search for: ";
            cin >> topic;
            displaySpeakersByTopic(speakers, numSpeakers, topic);
            break;
        case 5:
            displayAllSpeakers(speakers, numSpeakers);
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

//****************************************************************************************************

void inputSpeakers(Speaker members[], int size, int& numSpeakers) 
{
    if (numSpeakers >= size) 
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

    members[numSpeakers] = newSpeaker;
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
Enter your choice: 6

*/

