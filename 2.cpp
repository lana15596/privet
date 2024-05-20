#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;

const int N = 3;

struct participant {
    string club;
    string city;
    string coach;
    string data;
    int budget;
    int points;
    int place;
};

void printTeam(const participant team[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "======== КОМАНДА " << i + 1 << " ==========" << endl;
        cout << " Название: " << team[i].club << endl;
        cout << " Город: " << team[i].city << endl;
        cout << " ФИО тренера: " << team[i].coach << endl;
        cout << " Дата основания клуба: " << team[i].data << endl;
        cout << " Бюджет команды: " << team[i].budget << endl;
        cout << " Текущее количество очков: " << team[i].points << endl;
        cout << " Текущее место в чемпионате: " << team[i].place << endl;
        cout << endl;
    }
}

void readTeams(participant team[]) {
    ifstream input_file("2.txt");

    if (!input_file) {
        cout << "File not found" << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        input_file >> team[i].club;
        input_file >> team[i].city;
        input_file >> team[i].coach;
        input_file >> team[i].data;
        input_file >> team[i].budget;
        input_file >> team[i].points;
        input_file >> team[i].place;
        input_file.ignore(256, '\n'); // ignore the newline character after reading the place
    }

    input_file.close();
}

void searchTeamByCity(const participant team[]) {
    string cityToSearch;
    cout << "Введите название города: ";
    getline(cin, cityToSearch);

    bool found = false;

    for (int i = 0; i < N; i++) {
        if (team[i].city == cityToSearch) {
            found = true;
            cout << "Команда с городом " << cityToSearch << ":" << endl;
            cout << "Название: " << team[i].club << endl;
            cout << "Город: " << team[i].city << endl;
            cout << "ФИО тренера: " << team[i].coach << endl;
            cout << "Дата основания: " << team[i].data << endl;
            cout << "Бюджет команды: " << team[i].budget << endl;
            cout << "Текущее количество очков: " << team[i].points << endl;
            cout << "Текущее место в чемпионате: " << team[i].place << endl;
            cout << endl;
        }
    }

    if (!found) {
        cout << "Команда с городом " << cityToSearch << " не найдена." << endl;
    }
}

void findTeamWithHighestRatio(const participant team[]) {
    float maxRatio = 0;
    int maxIndex = -1;

    for (int i = 0; i < N; i++) {
        float ratio = (float)team[i].points / team[i].budget;
        if (ratio > maxRatio) {
            maxRatio = ratio;
            maxIndex = i;
        }
    }

    if (maxIndex != -1) {
        cout << "Команда с самым высоким отношением очков к бюджету:\n";
        cout << "Название: " << team[maxIndex].club << endl;
        cout << "Город: " << team[maxIndex].city << endl;
        cout << "ФИО тренера: " << team[maxIndex].coach << endl;
        cout << "Дата основания: " << team[maxIndex].data << endl;
        cout << "Бюджет команды: " << team[maxIndex].budget << endl;
        cout << "Текущее количество очков: " << team[maxIndex].points << endl;
        cout << "Текущее место в чемпионате: " << team[maxIndex].place << endl;
        cout << endl;
    }
}

int main() {
    participant* team = new participant[N];

    readTeams(team);
    searchTeamByCity(team);
    findTeamWithHighestRatio(team);
    printTeam(team, N);

    delete[] team;
    return 0;
}