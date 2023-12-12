
#include "ManagerUser.h"/*
ManagerUser::ManagerUser(QString name, QString password)
{
    this->m_UserName = name;
    this->m_UserPassword = password;
}*/

//void EnterRegionalMap(GuangZhouMap* gzmap ,int select);

//void UpdateTheData(int pagecode);

/*void ManagerUser::EnterMap()
{
    system("cls");
    char choose = '0';
    int select = 0;
    CovidMap* cmap = new GuangZhouMap();
    GuangZhouMap* gzmap = (GuangZhouMap*)cmap;
    int pagecode = 2;
    GuangZhouMap* Gzmap = NULL;

    while (1)//进入广州市级疫情地图
    {
    A:
        cmap->ShowMapInfomation();
        cmap->ShowMapMenu();
        cin >> choose;
        switch (choose)
        {
        case '1'://修改确诊人数
            gzmap->ChangeConfirmedCases();
            break;

        case '2'://修改境外输入人数
            gzmap->ChangeAboardConfirmedCases();
            break;

        case '3'://修改境内输入人数
            gzmap->ChangeInternalConfirmedCases();
            break;

        case '4'://修改本地输入人数
            gzmap->ChangeLocalConfirmedCases();
            break;

        case '5'://修改气候
            gzmap->ChangeWeather();
            break;

        case '6'://进入地区级地图
            while (1)
            {
                system("cls");
                gzmap->ShowRegionalMenu();
                cin >> select;
                switch (select)
                {
                case 1://天河区
                    EnterRegionalMap(Gzmap, select);
                    break;

                case 2://白云区
                    EnterRegionalMap(Gzmap, select);
                    break;

                case 3://番禺区
                    EnterRegionalMap(Gzmap, select);
                    break;

                case 4://越秀区
                    EnterRegionalMap(Gzmap, select);
                    break;

                case 5://花都区
                    EnterRegionalMap(Gzmap, select);
                    break;

                case 6://从化区
                    EnterRegionalMap(Gzmap, select);
                    break;

                case 7://海珠区
                    EnterRegionalMap(Gzmap, select);
                    break;

                case 8://黄浦区
                    EnterRegionalMap(Gzmap, select);
                    break;

                case 9://增城区
                    EnterRegionalMap(Gzmap, select);
                    break;

                case 10://南沙区
                    EnterRegionalMap(Gzmap, select);
                    break;

                case 11://荔湾区
                    EnterRegionalMap(Gzmap, select);
                    break;

                case 0://退出选择
                    cout << "欢迎下次使用！" << endl;
                    system("pause");
                    system("cls");
                    goto A;
                    break;

                default:
                    cout << "您的输入有误，请重新输入！" << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            }
            break;

        case '7'://刷新
            UpdateTheData(pagecode);
            return;
            break;

        case '0'://退出地图
            cout << "欢迎下次使用!" << endl;
            system("pause");
            system("cls");
            return;
            break;

        default:
            cout << "您的输入有误，请重新输入！" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}
//展示地图
*/
/*
void ManagerUser::AddPerson()
{
    QFile file;
    file.open(ManagerFile,QIODevice::WriteOnly|QIODevice::Append);
    QTextStream ofs(&file);
    QString name, password;
    cout << "请输入姓名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> password;
    ofs << name << " " << password << " " << endl;
    cout << "添加成功！" << endl;
    system("pause");
    system("cls");
    file.flush();
    file.close();
}
//添加

void ManagerUser::ShowPerson()
{
    char select = '0';
    cout << "请输入想要展示的账号列表：" << endl << "1.用户" << endl << "2.管理员" << endl << "3.全部" << endl;
    QFile file;
    QTextStream ifs(&file);
    QTextStream ofs(&file);
    QString name, password;
    cin >> select;
    switch (select)
    {
    case '1':
        file.open(OrdinaryFile,QIODevice::ReadOnly);
        cout << "用户账号显示如下：" << endl;
        while (ifs >> name >> password)
        {
            cout << name << " " << password << endl;
        }
        file.flush();
        file.close();
        system("pause");
        system("cls");
        return;
        break;

    case '2':
        file.open(ManagerFile,QIODevice::ReadOnly);
        cout << "管理员账号显示如下：" << endl;
        while (ifs >> name >> password)
        {
            cout << name << " " << password << endl;
        }
        file.flush();
        file.close();
        system("pause");
        system("cls");
        return;
        break;

    case '3':
        file.open(OrdinaryFile,QIODevice::ReadOnly);
        cout << "用户账号显示如下：" << endl;
        while (ifs >> name >> password)
        {
            cout << name << " " << password << endl;
        }
        file.flush();
        file.close();
        file.open(ManagerFile,QIODevice::ReadOnly);
        cout << "管理员账号显示如下：" << endl;
        while (ifs >> name >> password)
        {
            cout << name << " " << password << endl;
        }
        file.flush();
        file.close();
        system("pause");
        system("cls");
        return;
        break;

    default:
        cout << "您的输入有误，请重新输入！" << endl;
        system("pause");
        system("cls");
        return;
        break;
    }
}
//显示

bool ManagerUser::IsExist(QString name, QString password)
{
    QFile file;
    QTextStream ifs(&file);
    file.open(ManagerFile,QIODevice::ReadOnly);
    QString fname, fpassword;
    while (ifs >> fname >> fpassword)
    {
        if (fname == name && fpassword == password)
        {
            file.flush();
            file.close();
            return true;
        }
    }
    file.flush();
    file.close();
    return false;
}
//判断是否存在该联系人

void ManagerUser::ChangePerson()
{
    QFile file;
    QFile file1;
    QTextStream ifs(&file);
    QTextStream ofs(&file);
    file.open(ManagerFile,QIODevice::ReadOnly);
    QString name, password, str, estr;
    cout << "请输入要修改前的姓名：" << endl;
    cin >> name;
    cout << "请输入要修改前的密码：" << endl;
    cin >> password;
    if (!IsExist(name, password))
    {
        QString fname, fpassword;
        QTextStream ofss(&file1);
        file1.open(ManagerChangeFile,QIODevice::WriteOnly);
        while (ifs >> fname >> fpassword)
        {
            int a = fname.compare(name);
            int b = fpassword.compare(password);
            if (fabs(a) || fabs(b))
            {
                ofss << fname << " " << fpassword << " " << endl;
            }
        }
        file.flush();
        file.close();
        file1.flush();
        file1.close();
        QTextStream ifss(&file1);
        file1.open(ManagerChangeFile,QIODevice::ReadOnly);
        file.open(ManagerFile,QIODevice::WriteOnly|QIODevice::Truncate);
        while (ifss >> fname >> fpassword)
        {
            ofs << fname << " " << fpassword << " " << endl;
        }
        file.flush();
        file.close();
        file1.flush();
        file1.close();
        file.open(ManagerFile,QIODevice::WriteOnly|QIODevice::Append);
        cout << "请输入要修改后的姓名：" << endl;
        cin >> name;
        cout << "请输入要修改后的密码：" << endl;
        cin >> password;
        ofs << name << " " << password << " " << endl;
        file.flush();
        file.close();
        cout << "修改成功！" << endl;
    }
    else
    {
        cout << "账号不存在或密码错误！" << endl;
    }
    system("pause");
    system("cls");
    return;
}
//修改

void ManagerUser::DeletePerson()
{
    ofstream ofs;
    ifstream ifs;
    ifs.open(ManagerFile, ios::in);
    QString name, password;
    cout << "请输入要删除前的姓名：" << endl;
    cin >> name;
    cout << "请输入要删除前的密码：" << endl;
    cin >> password;
    if (!IsExist(name, password))
    {
        QString fname, fpassword;
        ofstream ofss;
        ofss.open(ManagerChangeFile, ios::out);
        while (ifs >> fname >> fpassword)
        {
            int a = fname.compare(name);
            int b = fpassword.compare(password);
            if (fabs(a) || fabs(b))
            {
                ofss << fname << " " << fpassword << " " << endl;
            }
        }
        ofss.close();
        ifs.close();
        ifstream ifss(ManagerChangeFile, ios::in);
        ofs.open(ManagerFile, ios::out | ios::trunc);
        while (ifss >> fname >> fpassword)
        {
            ofs << fname << " " << fpassword << " " << endl;
        }
        ifss.close();
        ofs.close();
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "账号不存在或密码错误！" << endl;
    }
    system("pause");
    system("cls");
    return;
}
//删除

void  ManagerUser::AddCode()
{
    ofstream ofs;
    ofs.open(SecertCodeFile, ios::out | ios::app);
    QString code;
    cout << "请输入密钥：" << endl;
    cin >> code;
    ofs << code << endl;
    cout << "添加成功！" << endl;
    system("pause");
    system("cls");
    ofs.close();
}
//添加密钥

void ManagerUser::ChangeCode()
{
    ifstream ifs;
    ofstream ofs;
    ifs.open(SecertCodeFile, ios::in);
    QString code;
    cout << "请输入要修改前的密钥：" << endl;
    cin >> code;
    if (!IsCodeExist(code))
    {
        QString fcode;
        ofstream ofss;
        ofss.open(SecertchangeFile, ios::out);
        while (ifs >> fcode)
        {
            int a = fcode.compare(code);
            if (fabs(a))
            {
                ofss << fcode << endl;
            }
        }
        ofss.close();
        ifs.close();
        ifstream ifss(SecertchangeFile, ios::in);
        ofs.open(SecertCodeFile, ios::out | ios::trunc);
        while (ifss >> fcode)
        {
            ofs << fcode << endl;
        }
        ifss.close();
        ofs.close();
        ofs.open(SecertCodeFile, ios::out | ios::app);
        cout << "请输入要修改后的密钥：" << endl;
        cin >> code;
        ofs << code << endl;
        ofs.close();
        cout << "修改成功！" << endl;
    }
    else
    {
        cout << "密钥不存在或密钥错误！" << endl;
    }
    system("pause");
    system("cls");
    return;
}
//修改密钥

void ManagerUser::ShowCode()
{
    ifstream ifs;
    ifs.open(SecertCodeFile, ios::in);
    QString code;
    cout << "密钥显示如下：" << endl;
    while (ifs >>code)
    {
        cout << code << endl;
    }
    ifs.close();
    system("pause");
    system("cls");
    return;
}
//显示密钥

void ManagerUser::DeleteCode()
{
    ifstream ifs;
    ofstream ofs;
    ifs.open(SecertCodeFile, ios::in);
    QString code;
    cout << "请输入要删除前的密钥：" << endl;
    cin >> code;
    if (!IsCodeExist(code))
    {
        QString fcode;
        ofstream ofss;
        ofss.open(SecertchangeFile, ios::out);
        while (ifs >> fcode)
        {
            int a = fcode.compare(code);
            if (fabs(a))
            {
                ofss << fcode << endl;
            }
        }
        ofss.close();
        ifs.close();
        ifstream ifss(SecertchangeFile, ios::in);
        ofs.open(SecertCodeFile, ios::out | ios::trunc);
        while (ifss >> fcode)
        {
            ofs << fcode << endl;
        }
        ifss.close();
        ofs.close();
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "密钥不存在或密钥错误！" << endl;
    }
    system("pause");
    system("cls");
    return;
}
//删除密钥

bool ManagerUser::IsCodeExist(QString code)
{
    ifstream ifs;
    ifs.open(SecertCodeFile, ios::in);
    QString fcode;
    while (ifs >> fcode)
    {
        if (fcode == code)
        {
            return true;
        }
    }
    return false;
}
//判断是否存在该密钥

void InitUsers();

void ManagerUser::DeleteAll()
{
    cout << "======================欢迎管理员 " << this->m_UserName << " ====================" << endl;
    cout << "请选择你的操作：" << endl;
    cout << "\t\t-------------------------------" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|    1.恢复用户账号出厂设置   |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|   2.恢复管理员账号出厂设置  |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|      3.恢复密钥出厂设置     |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|      4.恢复全部出厂设置     |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|            5.退出           |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t-------------------------------" << endl;
    cout << "请输入你的选择：" << endl;
    char selete = '0';
    cin >> selete;
    cout << "请您再次确认您的选择，这个选择将不可恢复！" << endl << "1.确认" << endl << "2.退出" << endl;
    char choose = '0';
    cin >> choose;
    ofstream ofs;
    if (choose == '1')
    {
        switch (selete)
        {
        case'1':
            ofs.open(OrdinaryFile, ios::out);
            ofs << "ordiaryuser 000000" << endl;
            ofs.close();//初始化普通用户
            break;

        case'2':
            ofs.open(ManagerFile, ios::out);
            ofs << "manageruser 000000" << endl;
            ofs.close();//初始化管理员
            break;

        case'3':
            ofs.open(SecertCodeFile, ios::out);
            ofs << "000000" << endl;
            ofs.close();//初始化密钥
            break;

        case'4':
            ofs.open(SecertCodeFile, ios::out);
            ofs << "000000" << endl;
            ofs.close();//初始化密钥
            ofs.open(ManagerFile, ios::out);
            ofs << "manageruser 000000" << endl;
            ofs.close();//初始化管理员
            ofs.open(OrdinaryFile, ios::out);
            ofs << "ordiaryuser 000000" << endl;
            ofs.close();//初始化普通用户
            break;

        case'5':

            break;
        default:
            cout << "您的输入有误，请输入五个选项编号之一！" << endl;
            break;
        }
        system("pause");
        system("cls");
        return;
    }
    else if (choose == '2')
    {
        system("pause");
        system("cls");
        return;
    }
}
//恢复出厂设置

void ManagerUser::OpenMenu()
{
    cout << "======================欢迎管理员 " << this->m_UserName << " ====================" << endl;
    cout << "请选择你的操作：" << endl;
    cout << "\t\t-------------------------------" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          1.添加账号         |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          2.修改账号         |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          3.删除账号         |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          4.显示账号         |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          5.添加密钥         |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          6.修改密钥         |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          7.删除密钥         |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          8.显示密钥         |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|        9.恢复出厂设置       |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          10.打开地图        |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          0.注销账号         |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t-------------------------------" << endl;
    cout << "请输入你的选择：" << endl;
}
//显示菜单
*/
