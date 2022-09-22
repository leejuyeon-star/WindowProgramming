#include "pch.h"
#include "CUserData.h"



CUserData::CUserData(CString name, CString Phone)
{
    m_strName = name;
    m_strPhone = Phone;
}

CString CUserData::GetName() { return m_strName; }
CString CUserData::GetPhone() { return m_strPhone; }

