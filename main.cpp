#include "headers\manager.h"
#include "headers\patient.h"

void countTreatedPeople(vector<Account>& data, int peopleCount, int &beingTreatedCount, int &wasTreatedCount) {
    for (int i = 0; i < peopleCount; i++) {
        if (data[i].type == "patient"){
            wasTreatedCount++;
            if (data[i].client.beingTreated == true) {
                beingTreatedCount++;
            }
        } 
    }
}

void showPersonal (int peopleCount, vector<Account>& data) {
    for (int i = 0; i < peopleCount; i++) {
        cout << "\t"
            << data[i].ID << " | "
            << data[i].type << " | " 
            << data[i].login << " | " 
            << data[i].password << " | " 
            << data[i].name << " | " 
            << data[i].surname << " | " 
            << data[i].height << " | "
            << data[i].weight << " | " 
            << data[i].birthday << " | " 
            << endl;
    }
    cout << endl << endl;
}

int main()
{
    vector <int> todaysDate = {17, 3, 23};
    int peopleCount = 11; //just for primary code testing.
    int diseasesCount = 9; //just for primary code testing.
    vector <Account> data(peopleCount); 
    vector <Diseases> diseases(diseasesCount);
    fillDiseases(diseases); //filling diseases database
    dataBase(data, diseases); //filling personal database
    showPersonal(peopleCount, data);
    bool typeStatus = false;
    bool loginStatus = false;
    bool programStatus = true;
    char access;
    string enterType, enterLogin, enterPassword;
    int actualId;
    int userEnter;
    int beingTreatedCount = 0;
    int wasTreatedCount = 0;
    int personalCount = 0;
    string strUserEnter;
    bool systemOn = true;
    
    while (systemOn == true) {  
        
        countTreatedPeople(data, peopleCount, beingTreatedCount, wasTreatedCount);
        personalCount = peopleCount - wasTreatedCount;
        
        cout << "Введите пожалуйста тип аккаунта:" << endl << endl << ">> ";
        while (typeStatus == false) {
            
            cin >> enterType;
            system("cls");
            
            enterType.erase(remove(enterType.begin(), enterType.end(), ' '), enterType.end()); //deleting possible accidental spaces from type
            
            if (isTypeCorrect(enterType, access)) {
                typeStatus = true;
            }
            else {
                cout << "Неверный тип аккаунта! Повторите еще раз: " << endl << endl << ">> ";
            }
        }
        
        while (loginStatus == false) {
            
            cout << "Введите логин: " << endl << ">> ";
            cin >> enterLogin;
            cout << "Введите пароль: " << endl << ">> ";
            cin >> enterPassword;
            system("cls");
            
            enterLogin.erase(remove(enterLogin.begin(), enterLogin.end(), ' '), enterLogin.end()); //deleting possible accidental spaces from login
            enterType.erase(remove(enterType.begin(), enterType.end(), ' '), enterType.end()); //deleting possible accidental spaces from password
            
            if (isLoginCorrect(enterType, enterLogin, enterPassword, data, peopleCount, actualId)) {
                loginStatus = true;
            }
            else {
                cout << "Неверный логин или пароль" << endl;
            }
            
        } 
        
        system("cls");
        cout << "Добро пожаловать в систему, " << data[actualId].surname << " " << data[actualId].name << "!" << endl;
        cout << "Ваш доступ: " << access << endl;

        switch(access) {
            case '2':  
            { 
                managerMenu(programStatus, data, userEnter, peopleCount, beingTreatedCount, strUserEnter, personalCount, diseases); 
                break; 
            }
            case '4':  
            { 
                patientMenu(programStatus, data, userEnter, peopleCount, beingTreatedCount, strUserEnter, personalCount, diseases, actualId, todaysDate); 
                break; 
            }
            default:
            {
                cout << "Error";
            }
        }
        system("pause");
    }
    return 0;
}