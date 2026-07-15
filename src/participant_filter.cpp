// list(1)

#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Participant {
    string surname;
    double height;
};

int main() {
    cout << "Enter the number of participants: ";
    int participant_count;
    cin >> participant_count;
    cout << "\n";

    list<Participant> participants(participant_count);
    list<Participant>::iterator iterator;

    for (iterator = participants.begin(); iterator != participants.end(); iterator++) {
        Participant current_participant;
        cout << "Surname: ";
        cin >> current_participant.surname;
        cout << "Height: ";
        cin >> current_participant.height;
        cout << "\n";
        *iterator = current_participant;
    }

    double average_height = 0;

    for (iterator = participants.begin(); iterator != participants.end(); iterator++) {
        average_height += iterator->height;
    }

    average_height /= participant_count;

    list<Participant> result_list;

    for (iterator = participants.begin(); iterator != participants.end(); iterator++) {
        if ((iterator->height < average_height) &&
            ((iterator->surname[0] == 'a') || (iterator->surname[0] == 'c'))) {
            result_list.push_front(*iterator);
        }
    }

    for (iterator = result_list.begin(); iterator != result_list.end(); iterator++) {
        cout << iterator->surname << "  " << iterator->height << endl;
    }

    return 0;
}
