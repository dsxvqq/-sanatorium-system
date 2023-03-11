#include "loginsystem.h"
#include "prices.h"

//first function of manager menu
void showClientList(vector<Account>& data, int userEnter, int peopleCount) {
    for (int i = 0; i < peopleCount; i++) {
        if (data[i].type == "patient" && data[i].client.beingTreated == true){
            cout << data[i].name << " " 
                << data[i].surname << endl
                << "Рост: " << data[i].height << " см " << endl
                << "Вес: " << data[i].weight << " кг " << endl
                << "Дата рождения: "<< data[i].birthday << endl << endl;
        }
    }
    cout << "Напишите 0 чтобы вернуться назад: " << endl << endl << ">> ";
    cin >> userEnter;
    if (userEnter == 0) {
        system("cls");
    }
    else {
        cout << "Чтобы вернуться назад, введите 0: " << endl << endl << ">> ";
    }
}

//second function of manager menu
void showClientCount(vector<Account>& data, int userEnter, int peopleCount, int beingTreatedCount) {
    cout << "Всего на данный момент лечящихся: " << beingTreatedCount  << endl << endl;
    cout << "Напишите 0 чтобы вернуться назад: " << endl << endl << ">> ";
    cin >> userEnter;
    if (userEnter == 0) {
        system("cls");
    }
    else {
        cout << "Чтобы вернуться назад, введите 0: " << endl << ">> ";
    }
}

//function for third function, that allow run recursion
void findFunction (vector<Account>& data, string &strUserEnter, int peopleCount) {
    int successFind = 0;
    for (int i = 0; i < peopleCount; i++) {
        if (data[i].name == strUserEnter) {
            successFind++;
            cout << endl << data[i].name << " " << data[i].surname << endl
            << "Рост: " << data[i].height << " см " << endl
            << "Вес: " << data[i].weight << " кг " << endl
            << "Дата рождения: "<< data[i].birthday << endl << endl
            << "Список болезней: " << endl;
            for (int j = 0; j < data[i].client.diseaseName.size(); j++) {
                cout << data[i].client.diseaseName[j] << endl;
            }
        }
    }
    if (successFind == 0) {
        cout << "Данный пользователь не найден! Попробуйте еще раз, или напишите 0, чтобы выйти в меню: " << endl << endl << ">> ";
    }
    else {
        cout << endl << "Чтобы узнать информацию о другом пользователе, напишите его имя. " << endl << "Если же вы хотите вернуться в главное меню, введите 0: " << endl << endl << ">> ";
    }
    cin >> strUserEnter;
    system("cls");
}

//third function of manager menu
void findClient(vector<Account>& data, string strUserEnter, int peopleCount) {
    cout << "Чтобы узнать всю информацию о пользователе, введите его имя: " << endl << ">> ";
    cin >> strUserEnter;
    system("cls");
    findFunction(data, strUserEnter, peopleCount);
    if (strUserEnter != "0") {
        while (strUserEnter != "0") {
            findFunction(data, strUserEnter, peopleCount);
        }
    }
}
//fourth function of manager menu
void showAllDiseases (vector <Diseases> &diseases, string &strUserEnter) {
    for (int i = 0; i < diseases.size(); i++) {
        cout << "Название:" << diseases[i].diseasesName << endl << "Цена: " << diseases[i].diseasesPrice << "$" << endl << endl;
    }
    cout << endl << "Чтобы вернуться в главное меню введите 0:" << endl << endl << ">> ";
    while (strUserEnter != "0") {
        cin >> strUserEnter;
        system("cls");
        if (strUserEnter != "0") {
            cout << "Введите 0, чтобы вернуться в главное меню: " << endl << endl << ">> ";
        }
    }
}

//function for fifth function, that allow run recursion
void findDisease(vector <Diseases> &diseases, string &strUserEnter, int peopleCount) { 
    int tempId; 
    int tempInput; 
    bool successFind = false; 
    for (int i = 0; i < peopleCount; i++) { 
        if (strUserEnter == diseases[i].diseasesName)  { 
            tempId = i; 
            successFind = true; 
            system("cls"); 
            break; 
        } 
    } 
    if (successFind == true) { 
        cout << "Нынешняя цена процедуры " << diseases[tempId].diseasesName << " - " << diseases[tempId].diseasesPrice << "$" << endl << "Введите новую цену: " << endl 
        << "Если же вы хотите вернуться в главное меню, введите 0: "<< endl << endl << ">> "; 
        cin >> tempInput; 
        if (tempInput <= 0) { 
            strUserEnter = "0";  
            system("cls"); 
        } 
        else { 
            diseases[tempId].diseasesPrice = tempInput; 
            system("cls");
            cout << "Новая цена процедуры " << diseases[tempId].diseasesName << ": " << tempInput << "$" << endl 
            << "Если вы хотите изменить цену для другой процедуры, введите ее название: " << endl << "Или напишите 0 чтобы вернуться в главное меню: " << endl
            << endl << ">> ";
            cin >> strUserEnter;
            system("cls");
        } 
    } 
    else { 
        cout << "Данная процедура не найдена, попробуйте еще раз: " << endl << endl << ">> "; 
        cin >> strUserEnter;
        system("cls");
    } 
} 
 
//fifth function of manager menu
void changePrice(vector <Diseases> &diseases, string &strUserEnter, int peopleCount){ 
    cout << "Введите название процедуры, которой хотите изменить цену: " << endl << "Если же вы хотите вернуться в главное меню, введите 0: " << endl << endl << ">> "; 
    cin >> strUserEnter; 
    system("cls"); 
    while (strUserEnter!="0") { 
        findDisease(diseases, strUserEnter, peopleCount); 
    } 
}

void changeTime (vector<Account>& data, string &strUserEnter, int userEnter, int peopleCount) {

}

void changeProcedureName(vector <Diseases> &diseases, string &strUserEnter, int userEnter, int peopleCount) {
    int tempId; 
    bool successFind = false;
    system("cls");
    for (int i = 0; i < peopleCount; i++) {
        if (strUserEnter ==  diseases[i].diseasesName) {
            successFind = true;
            tempId = i;
            break;
        }
    }
    if (successFind == true) {
        cout << "Введите новое название для процедуры " << diseases[tempId].diseasesName << ": " << endl << "Если вы передумали, напишите 0:" << endl << endl << ">> ";
        cin >> strUserEnter;
        if (strUserEnter != "0") {
            diseases[tempId].diseasesName = strUserEnter;
            system("cls");
            cout << "Новое название процедуры было успешно установлено!" << endl << "Введите 0, если хотите вернуться в главное меню" << endl 
            << "Введите 1, если вы хотите сменить название другой процедуры: " << endl << endl << ">> ";
            while (userEnter != 0 || userEnter != 1) {
                cin >> userEnter;
                if (userEnter == 0) {
                    strUserEnter = "0";
                    break;
                }
                else if (userEnter == 1) {
                    strUserEnter = "null";
                    return ;
                }
                else {
                    cout << "Неверно введено число! Попробуйте еще раз: " << endl << endl << ">> ";
                }
            }
        }
        else {
            strUserEnter = "0";
            system("cls");
        }
    }
    else {
        if (strUserEnter == "null") {
            cin >> strUserEnter;
            system("cls");
        }
        else {
            cout << "Данная процедура не была найдена! Попробуйте еще раз: " << endl << "Или введите 0, чтобы вернуться в главное меню" << endl << endl << ">> ";
            cin >> strUserEnter;
            system("cls");
        }
    }
}

//sixth function of manager menu
void changeTimeOrProcedureName(vector<Account>& data, vector <Diseases> &diseases, string &strUserEnter, int userEnter, int peopleCount){
    while (strUserEnter != "0") {  
        cin >> userEnter;
        if (userEnter == 0) {
            system("cls");
            strUserEnter = "0";
        }
        else if (userEnter == 1) {
            system("cls");
        }
        else if (userEnter == 2) {
            system("cls");
            cout << "Введите название процедуры: " << endl << endl << ">> ";
            cin >> strUserEnter;
            system("cls");
            while (strUserEnter != "0") {
                changeProcedureName(diseases, strUserEnter, userEnter, peopleCount);
            }
        }
        else {
            cout << "Неверно введено число, попробуйте еще раз: " << endl << endl << ">> ";
        }
    }
}

//seventh function of manager menu
void showMaxPersonVisits(vector<Account>& data, int &userEnter, int peopleCount, int personalCount){
    int maxVisits = data[personalCount].client.visitHistory.size();
    int tempInt;
    for (int i = 0; i < peopleCount; i++) {
        if (data[i].type == "patient" && maxVisits < data[i].client.visitHistory.size()) {
            maxVisits = data[i].client.visitHistory.size();
            tempInt = i;
        }
    }
    if (userEnter != 0) {
        while (userEnter != 0) {
            system("cls");
            cout << "Наибольшее количество посещений у пользователя " << data[tempInt].name  << " " << data[tempInt].surname << endl << "Всего посещений: " << maxVisits << endl << endl
                << "Чтобы вернуться в главное меню, напишите 0: " << endl << ">> ";
            cin >> userEnter;
            system ("cls");
        } 
    }
}

//eighth function of manager menu
void showMinPersonVisits(vector<Account>& data, int &userEnter, int peopleCount, int personalCount){
    int minVisits = data[personalCount].client.visitHistory.size();
    int tempInt;
    for (int i = 7; i < peopleCount; i++) {
        if (data[i].type == "patient" && minVisits > data[i].client.visitHistory.size()) {
            minVisits = data[i].client.visitHistory.size();
            tempInt = i;
        }
    }
    if (userEnter != 0) {
        while (userEnter != 0) {
            system("cls");
            cout << "Наименьшее количество посещений у пользователя " << data[tempInt].name  << " " << data[tempInt].surname << endl << "Всего посещений: " << minVisits << endl << endl
                << "Чтобы вернуться в главное меню, напишите 0: " << endl << ">> ";
            cin >> userEnter;
            system ("cls");
        } 
    }
}

//main manager menu
void managerMenu(bool programStatus, vector<Account>& data, int userEnter, int peopleCount, int beingTreatedCount, string strUserEnter, int personalCount, vector<Diseases> &diseases) {
    while(programStatus) {
        system("cls");

        strUserEnter = "null";
        userEnter = 0;

        cout << "Пожалуйста наберите номер меню для работы с программой: " << endl
        << "1. Показать список посетителей" << endl //(Показывает список посетителей, которые получают на данный момент свое лечение)
        << "2. Показать количество посетителей" << endl 
        << "3. Поиск посетителя" << endl 
        << "4. Показать все процедуры" << endl
        << "5. Изменить цену для процедур" << endl 
        << "6. Изменить время/название процедур" << endl 
        << "7. Показать посетителя с максимальным количеством посещений" << endl
        << "8. Показать посетителя с минимальным количеством посещений" << endl 
        << "9. Выход" << endl << endl << ">> ";
        
        cin >> userEnter; 

        if ((userEnter >= 1) && (userEnter <= 9)) {
            userEnter = userEnter;
        }
        else {
            userEnter = 9;
        }

        switch(userEnter) {
            case 0:
            {

            }
            case 1: 
            {
                system("cls");
                showClientList(data, userEnter, peopleCount);
                break;
            }
            case 2:
            {
                system("cls");
                showClientCount(data, userEnter, peopleCount, beingTreatedCount);
                break;
            }
            case 3:
            {
                system("cls");
                findClient(data, strUserEnter, peopleCount); //for now does not work with russian names
                break;
            }
            case 4:
            {
                system("cls");
                showAllDiseases (diseases, strUserEnter);
                break;
            }
            case 5:  
            { 
                system("cls"); 
                changePrice(diseases, strUserEnter, peopleCount); 
                break;
            }
            case 6:  
            { 
                system("cls"); 
                cout << "Введите 1, чтобы изменить время процедуры:" << endl << "Введите 2, чтобы изменить название процедуры: " << endl 
                << "Введите 0, чтобы вернуться в главное меню: " << endl << endl << ">> ";
                changeTimeOrProcedureName(data, diseases, strUserEnter, userEnter, peopleCount); 
                break;
            }
            case 7:
            {
                system("cls");
                showMaxPersonVisits(data, userEnter, peopleCount, personalCount);
                break;
            }
            case 8:
            {
                system("cls");
                showMinPersonVisits(data, userEnter, peopleCount, personalCount);
                break;                
            }
            case 9:
            {
                programStatus = false;
                break;
            }
            default:
            {
                cout << "Error";
            }
        }
    }
}