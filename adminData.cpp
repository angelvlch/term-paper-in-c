//#include "adminData.h"
//void menuAdminData()
//{
//    cout << "Вы попали в меню администратора\n";
//    char ch = 0;
//    while(ch!=ESC)
//    { 
//        cout << "\nВыберите режим\n1. Режим редактирования\n2. Режим обработки данных\nESC-назад";
//        if (ch == '1')
//            editData();
//        else if (ch == '2')
//            processData();
//        else if (ch != ESC)
//            cout << error;
//    }
//}
//void editData() {
//    vector<plane> vec = loadInVector();
//    cout << "\nРежим редактирования\n";
//    char ch = 0;
//    while (ch!=ESC)
//    {
//        cout << "\n1. Просмотреть все записи\n2. Добавить новую запись\n3. Отредактировать запись\n4. Удалить запись\nESC-назад\n";
//        ch = _getch();
//        switch (ch)
//        {
//        case '1':
//            show(vec, vec.size());
//            break;
//        case '2':
//            add(vec); 
//            break;
//        case '3':
//            edit(vec); 
//            break;
//        case '4':
//            delet(vec);
//            break;
//        case 27:
//            break;
//        default:
//            cout << error;
//        }
//        fromVectorToFile(vec);
//    }
//}
//void processData() {
//    vector<plane> vec = loadInVector();
//    char ch = 0;
//    while (ch != ESC)
//    {
//
//        cout << "\n1. Осортировать записи\n2. Поиск записи\n3. Индивидуальное задание\nESC-Назад\n";
//        ch = _getche();
//        switch (ch)
//        {
//        case '1':
//            menuSort(vec); 
//            break;
//        case '2':
//            searchMenu(vec);
//            break;
//            //case '3':solveTask(vec); break;//
//        case 27: 
//            break;
//        default:
//            cout << error;
//        }
//        fromVectorToFile(vec);
//    }
//}