#pragma once
#include <afx.h>

class CUserData : public CObject
{
public:
    CUserData(CString name, CString Phone);
    CString GetName(void);
    CString GetPhone(void);

private:
    CString m_strName;
    CString m_strPhone;
};

