//#include "adminData.h"
//void menuAdminData()
//{
//    cout << "�� ������ � ���� ��������������\n";
//    char ch = 0;
//    while(ch!=ESC)
//    { 
//        cout << "\n�������� �����\n1. ����� ��������������\n2. ����� ��������� ������\nESC-�����";
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
//    cout << "\n����� ��������������\n";
//    char ch = 0;
//    while (ch!=ESC)
//    {
//        cout << "\n1. ����������� ��� ������\n2. �������� ����� ������\n3. ��������������� ������\n4. ������� ������\nESC-�����\n";
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
//        cout << "\n1. ������������ ������\n2. ����� ������\n3. �������������� �������\nESC-�����\n";
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