#include <string>
#include <thread>
#include <iostream>
#include <functional>
#include <Windows.h>
#include <vector>
#include <fstream>
using namespace std;
class oficiant
{
public:
    oficiant()
    {
        of();
    }
    void of()
    {
        vector<string> status;
        string line;
        ifstream file_check("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\status2.txt");

        while (file_check >> line) {
            status.push_back(line);
        }
        // закрытие файла
        int slovo = 0;
        // анонимнвя функция 
        ([&]() {(status.begin(), status.end(), [](int a, int b) { return a > b; }); });

        for (int i = 0; i < status.size(); i++) {
            cout << status[i] << " ";
            slovo++;
        }
        int id = slovo - 1;
        ofstream fileclear("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\status2.txt");
        if (status[id] == "выдачу")
        {
            // статус меняем на выполнен
            fileclear << "выполнен" << endl;
            cout << "Заказ готов! " << endl;
        }
        else
        {
            cout << "Заказы не готовы" << endl;
        }
        file_check.close();
        fileclear.close();
    }
};
class Povar
{
    public:
    Povar()
    {
        po();
    }
    void po()
    {
        ifstream zakaz("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\zakazi2.txt");
        if (zakaz.peek() == ifstream::traits_type::eof()) {
            cout << "заказы сделаны, можете отдохнуть " << std::endl;
        }
        else {
            ofstream filestat("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\status2.txt");
            filestat << "В процессе приготовления" << endl;

            cout << "Заказы: " << endl;
            vector<string> history;
            string number;

            // чтение чисел из файла и добавление их в вектор
            while (zakaz >> number) {
                history.push_back(number);
            }
            int newid = 1;
            for (int i = 0; i < history.size(); i++) {
                cout << newid++ << "/" << history[i] << endl;
            }
            // закрытие файла
            int num;
            cout << "Введите номер элемента для приготовления" << endl;

            cin >> num;
            if (num <= history.size() && num >= 1)
            {
                history.erase(history.begin() + num - 1);
            }
            else
            {
                cout << "Введите корретктный индекс: " << endl;
                po();
            }
            zakaz.close();

            string lines;
            vector<string> newproduct;
            ifstream file2("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\menu2.txt");
            // чтение чисел из файла и добавление их в вектор
            while (file2 >> lines) {
                newproduct.push_back(lines);
            }
            // закрытие файла
            for (int i = 0; i < newproduct.size(); i++) {
                cout << newproduct[i] << endl;
            }
            cout << "Для приготовления строки повторите его строку из списка: " << endl;
            string information;
            cin >> information;
            auto it = find(newproduct.begin(), newproduct.end(), information);
            if (it != newproduct.end()) {
                cout << "Блюдо приготовлено" << endl;
                ofstream out;
                out.open("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\zakazi2.txt");
                if (out.is_open())
                {
                    for (int i = 0; i < history.size(); i++) {
                        out << history[i] << endl;
                    }
                }
                ofstream filestat2("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\status2.txt");

                filestat2 << "Передан официанту на выдачу" << endl;
                po();
                filestat2.close();
            }
            else {
                cout << "Блюдо не приготовлено, вы что-то сделали не так" << endl;
                po();
            }
            filestat.close();
        }
    }
};
    class Money
    {
    public:
        Money()
        {
            info_about_rest();
        }
        void info_about_rest()
        {
            // бухгалтер
            vector<string> info;
            string number;
            ifstream files("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\info.txt");
            while (files >> number) {
                info.push_back(number);
            }

            cout << "История заявок: " << endl;
            vector<string> history;
            string line;
            ifstream file("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\history2.txt");

            while (file >> line) {
                history.push_back(line);
            }
            // вывод вектора
            for (int i = 0; i < history.size(); i++) {
                cout << history[i] << endl;
            }
            file.close();

            cout << "счет ресторана:" << info[0] << endl;
            cout << "количество проданных блюд: " << info[1] << endl;
            cout << "заработок на блюдах: " << info[2] << endl;
            files.close();
        }
    };
    class Skladov
    {
    public:
        Skladov()
        {
            nado();
        }
        void nado()
        {
            int chose;
            cout << "1. Создание заявок" << endl << "2. Просмотр склада" << endl;
            cin >> chose;
            vector<string> spisok;
            string line;
            ifstream file("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\product2.txt");
            if (chose == 1)
            {
                cout << "Список товаров для закупки:" << endl;
                while (file >> line) {
                    string number2 = line.substr(line.find("-") + 1, (((line.find_first_of("-")), (line.find_last_of("-") - 2))));
                    spisok.push_back(number2);
                }
                for (int i = 0; i < spisok.size(); i++) {
                    string ln = spisok[i];
                    cout << ln.substr(ln.find("-") + 1, (((ln.find_first_of("-")), (ln.find_last_of("-") - 2)))) << endl;
                }
                // создание заявки
                cout << "Введите тип товара: " << endl;
                string type;

                cin >> type;
                vector<string> note;
                int quantity;
                cout << "Введите количество желаемого товара: " << endl;
                cin >> quantity;
                string quantity2 = to_string(quantity);
                string infile = type + "-" + quantity2;
                // поиск товара, сравнение
                auto il = find(spisok.begin(), spisok.end(), type);
                if (il == spisok.end()) {
                    cout << "Данного товара не существует в системе, обратитесь к админу" << endl;
                    nado();
                }
                else
                {
                    cout << "Заявка на товар создана" << endl;
                    note.push_back(infile);
                    // запись в два файла, заявки и история
                    ofstream histor("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\history2.txt", ios::app);
                    ofstream note2("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\zaivki2.txt", ios::app);
                    for (int i = 0; i < note.size(); i++)
                    {
                        histor << note[i] << endl;
                    }
                    histor.close();
                    for (int i = 0; i < note.size(); i++)
                    {
                        note2 << note[i] << endl;
                    }
                    note2.close();
                    nado();
                }

                file.close();

            }
            else if (chose == 2)
            {
                vector<string> sklad;
                string number;
                cout << "На складе сейчас: " << endl;
                ifstream file("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\quality2.txt");

                // чтение чисел из файла и добавление их в вектор
                while (file >> number) {

                    sklad.push_back(number);
                }
                for (int i = 0; i < sklad.size(); i++) {

                    cout << sklad[i] << endl;
                }
                nado();
            }
            else
            {
                cout << "Введите число от 1 до 2" << endl;
                nado();

            }
        }
    };
    class Provider
    {
    public:
        Provider()
        {
            SendMen();
        }
        void SendMen()
        {
            // роль поставщика
            int cislo;
            cout << "1. Посмотреть заявки" << endl << "2. Выслать продукты" << endl;
            cin >> cislo;
            ifstream file("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\zaivki2.txt");
            string line;
            ofstream out1;
            out1.open("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\zaivki2.txt");

            switch (cislo)
            {
            case 1:
                // показ заявок
                cout << " Все заявки: " << endl;
                while (getline(file, line))
                {
                    cout << line << endl;
                }
                file.close();
                SendMen();
            case 2:
                // отправка
                cout << "Товар отправлен" << endl;
                if (out1.is_open())
                {
                    out1 << "";
                }
                out1.close();
                SendMen();
            default:
                cout << "Введите число от 1 до 2" << endl;
                SendMen();
            }
        }
    };
    class Admin
    {
    public:
        Admin()
        {
            adm();
        }
        void adm()
        {
            cout << "1. Создание меню" << endl << "2.Создание пользователя" << endl << "3.Создания товара" << endl << "4. Журнал аудито " << endl;
            int point;
            cin >> point;
            if (point == 1)
            {
                cout << "введите наименование нового блюдо " << endl;
                string name;
                cin >> name;
                cout << "Введите вес блюда (в граммах)" << endl;
                int put;
                cin >> put;

                vector<string> products;
                string number;
                vector<string> push;

                // открытие файла для чтения
                ifstream file("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\product2.txt");

                // чтение чисел из файла и добавление их в вектор
                while (file >> number) {
                    products.push_back(number);
                }
                for (int i = 0; i < products.size(); i++) {
                    cout << products[i] << endl;
                }
                file.close();
                while (true)
                {
                    int id;
                    cout << "Введите id товара в чек " << endl << "0- чтобы завершить ";
                    cin >> id;
                    if (id == 0)
                    {
                        break;
                    }
                    else
                    {
                        number = products[id - 1];
                        push.push_back(number.substr(2));
                    }
                }
                // список продуктов
                string note;
                for (auto& simvol : push) {
                    note.append(simvol + "-");
                }

                cout << "введите описание блюда " << endl;
                string opisanie;
                cin >> opisanie;
                cout << "введите примерное время готовки" << endl;
                double time;
                cin >> time;
                cout << "введите цену блюда ";
                int cost;
                cin >> cost;

                string info;
                info = put + "-" + to_string(put) + "-" + opisanie + "-" + note + "-" + to_string(time) + "-" + to_string(cost);
                ofstream out;
                out.open("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\menu2.txt", ios::app);
                if (out.is_open())
                {
                    out << endl << info;
                }
                out.close();
                adm();
            }
            else if (point == 2)
            {
                cout << " Добавить пользователя" << endl;
                cout << "Введите логин: ";
                string login;
                cin >> login;
                cout << "Введите пароль: ";
                string password;
                cin >> password;

                cout << "Введите роль: admin, provider, skladskoi, povar, waiter, buchgalter" << endl;
                string role;
                cin >> role;
                cout << "Введите Фамилия: ";
                string famili;
                cin >> famili;
                cout << "Введите Имя: ";
                string names;
                cin >> names;
                cout << "Введите Отчество: ";
                string patronymic;
                cin >> patronymic;

                hash<string> hasher;
                size_t hash = hasher(password);
                int hashpassword;
                hashpassword = hash;
                string hashpassword2 = to_string(hashpassword);

                string users = login + "-" + hashpassword2;
                ofstream out;
                out.open("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\users2.txt", ios::app);
                if (out.is_open())
                {
                    out << endl << users;
                }
                out.close();

                string user_data = login + "-" + role;
                ofstream outdate;
                outdate.open("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\password2.txt", ios::app);
                if (outdate.is_open())
                {
                    outdate << endl << user_data;
                }
                outdate.close();

                string outs = login + "-" + famili + "-" + names + "-" + patronymic;
                ofstream outFIO;
                out.open("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\data_name2.txt", ios::app);
                if (out.is_open())
                {
                    out << endl << outs;
                }
                out.close();

                adm();
            }
            else if (point == 3)
            {
                cout << "Добавьте товар" << endl;

                vector<string> show;
                string number;
                vector<string> inf;
                ifstream file("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\product2.txt");

                // чтение чисел из файла 
                while (file >> number) {
                    show.push_back(number);
                }
                file.close();
                for (int i = 0; i < show.size(); i++) {
                    cout << show[i] << endl;
                }
                string product;
                cin >> product;
                cout << "Введите стоимость за еденицу товара" << endl;
                int cost;
                cin >> cost;

                int ids = 1;
                for (int i = 0; i < show.size(); i++) {
                    ids++;
                }
                string ids2 = to_string(ids);
                string cen = to_string(cost);
                show.push_back(ids2 + "-" + product + "-" + cen);

                ofstream file1("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\product2.txt");
                ofstream out("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\quality2.txt", ios::app);
                // запись количества
                out << product << "-0" << endl;

                for (int i = 0; i < show.size(); i++) {
                    file1 << inf[i] << endl;
                    cout << inf[i] << endl;
                }
                file1.close();
                adm();
            }
            else if (point == 4)
            {
                ifstream file("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\jurnal2.txt");
                string line;
                cout << "Журнал аудито " << endl;
                while (getline(file, line))
                {
                    cout << line << endl;
                }
                file.close();
                adm();
            }
            else
            {
                cout << "Введите число от 1 до 4" << endl;
                adm();
            }
        }
    };
    class Posetitel
    {
    public:
        Posetitel()
        {
            go();
        }
        void go()
        {
            int chose;
            cout << "1. Сделать заказ" << endl << "2. Отследить заказ" << endl;
            cin >> chose;
            switch (chose)
            {
            case 1:
                one();
                break;
            case 2:
                two();
                break;
            default:
                cout << "введите число от 1 до 2" << endl;
                go();
            }
        }
        void one()
        {
            cout << "Список блюд: " << endl;
            vector<string> menu;
            vector<string> stoimost;
            string lines;
            ifstream fil("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\menu2.txt");
            while (fil >> lines) {
                menu.push_back(lines.substr(0, lines.find("-")));
                stoimost.push_back(lines.substr(lines.find_last_of("-") + 1));
            }
            for (int i = 0; i < menu.size(); i++) {
                cout << menu[i] << endl;
                cout << stoimost[i] << endl;
            }
            fil.close();

            double plus = 0;
            while (1)
            {
                cout << "Введите наименование пункта меню, для добавления, '0' чтобы закончить заказ" << endl;
                string nam;
                cin >> nam;
                if (nam == "0")
                {
                    cout << "Заказ отправлен на кухню" << endl;
                    ofstream status_out;
                    status_out.open("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\status2.txt", ios::app);
                    if (status_out.is_open())
                    {
                        status_out << "\n" << "Оплачен и передан на кухню";
                    }
                    status_out.close();
                    break;
                }
                else
                {
                    auto items = find(menu.begin(), menu.end(), nam);
                    if (items == menu.end()) {
                        cout << "Данного товара не существует" << endl;
                    }
                    else
                    {
                        int id = distance(menu.begin(), items) + 1;
                        string str = to_string(id);
                        const char* char2 = str.c_str();

                        ofstream fileZ;
                        fileZ.open("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\zakazi2.txt", ios::app);
                        for (int i = 0; i < menu.size(); i++) {
                            plus += stoi(stoimost[id - 1]);

                        }
                        if (fileZ.is_open())
                        {
                            fileZ << nam << endl;
                        }
                        fileZ.close();

                        vector<string> info;
                        string lineR;
                        ifstream fileshow("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\info.txt");
                        while (fileshow >> lineR) {
                            info.push_back(lineR);
                        }
                        // изменение счета ресторана, количетсво блюд и заработанных денег
                        info[0] = to_string(stoi(info[0]) + plus);
                        info[1] = to_string(stoi(info[1]) + 1);
                        info[1] = to_string(stoi(info[2]) + plus);

                        ofstream filezapis("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\info.txt");
                        for (int i = 0; i < info.size(); i++) {
                            filezapis << info[i] << endl;
                        }
                        fileshow.close();
                        filezapis.close();
                    }
                }
            }
        }
        void two()
        {
            {
                cout << "Статус: ";
                ifstream file("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\status2.txt");

                string status;
                while (getline(file, status)) {
                    cout << status;
                }
                file.close();
            }
        }
    };
    class Role {
    public:
        Role(string name)
        {
            defenit(name);
        }
        void defenit(string name)
        {
            ifstream file("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\password2.txt");
            string role;
            if (file.is_open())
            {
                // поиск подстрок в файле
                while (getline(file, role)) {

                    ofstream out;
                    out.open("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\jurnal2.txt", ios::app);

                    if (string::npos != role.find(name + "-admin")) {
                        string info = name + " Админ зашел в систему";
                        if (out.is_open())
                        {
                            out << endl << info;
                        }
                        cout << "Вы вошли как админ " << endl;
                        Admin a;
                        a.adm();

                    }
                    else if (string::npos != role.find(name + "-provider")) {
                        string info2 = name + " Постовщик зашел в систему";
                        if (out.is_open())
                        {
                            out << endl << info2;
                        }
                        cout << "Вы вошли как поставщик " << endl;
                        Provider p;
                        p.SendMen();

                    }
                    else if (string::npos != role.find(name + "-sklad")) {
                        string info = name + " Складской зашел в систему";
                        if (out.is_open())
                        {
                            out << endl << info;
                        }
                        cout << "Вы вошли как складской " << endl;
                        Skladov s;
                        s.nado();
                    }
                    else if (string::npos != role.find(name + "-buchgalter")) {
                        string info = name + " Бухгалтер зашел в систему";
                        if (out.is_open())
                        {
                            out << endl << info;
                        }
                        cout << "Вы вошли как бухгалтер " << endl;

                        Money buch;
                        buch.info_about_rest();
                    }
                    else if (string::npos != role.find(name + "-waiter")) {

                        string info4 = name + " Официант зашел в систему";
                        if (out.is_open())
                        {
                            out << endl << info4;
                        }
                        cout << "Вы вошли как официант " << endl;
                        oficiant off;
                        off.of();

                    }
                    else if (string::npos != role.find(name + "-povar")) {

                        string info5 = name + " Повар зашел в систему";
                        if (out.is_open())
                        {
                            out << endl << info5;
                        }
                        cout << "Вы вошли как повар " << endl;
                        Povar p;
                        p.po();
                    }
                    out.close();
                }
            }
            file.close();
        }
    };


    int main()
    {
        SetConsoleCP(1251);
        setlocale(0, "");
        string login;
        string password;
        ifstream user("C:\\Users\\79671\\OneDrive\\Рабочий стол\\Техникум\\проект\\users2.txt");
        string line;
        while (1)
        {
            cout << "Введите имя: ";
            cin >> login;
            cout << "Введиет пароль: ";
            cin >> password;


            hash<string> hashh;
            size_t hash = hashh(password);
            int hashpassword;
            hashpassword = hash;
            auto hashpassword2 = to_string(hashpassword);
            // класс ролей
            while (getline(user, line)) {
                if (line.find(login + "-" + hashpassword2) != string::npos) {
                    unique_ptr<Role> defenition(new Role(login));
                    return 0;
                }
            }
            cout << "Добро пожаловать в наш рестаран!" << endl;
            // класс гость
            unique_ptr<Posetitel> bob(new Posetitel());
            break;
            user.close();
        }
    }

