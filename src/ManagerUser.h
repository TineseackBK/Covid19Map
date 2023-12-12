#ifndef MANAGERUSER_H
#define MANAGERUSER_H


#pragma once
#include "Identity.h"
class ManagerUser :
    public Identity
{
public:
    ManagerUser()
    {

    }
    ManagerUser(QString name, QString password);

    virtual void OpenMenu();//显示菜单
    virtual void EnterMap();//展示地图
    virtual bool IsExist(QString name, QString password);//判断是否存在该联系人

    void AddPerson();//添加

    void ChangePerson();//修改

    void DeletePerson();//删除

    void ShowPerson();//显示

    void AddCode();//添加密钥

    void ChangeCode();//修改密钥

    void ShowCode();//显示密钥

    void DeleteCode();//删除密钥

    bool IsCodeExist(QString code);//判断是否存在该密钥

    void DeleteAll();//恢复出厂设置
};





#endif // MANAGERUSER_H
