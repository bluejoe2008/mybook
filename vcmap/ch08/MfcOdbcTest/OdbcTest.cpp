#include "stdafx.h"

#include <afx.h>
#include <afxdb.h>

int main()
{
	try
	{
		CDatabase db;

		//�����ݿ�
		db.Open(_T("hotel"));
		
		CRecordset rs(&db);
		//�򿪼�¼��
		rs.Open(CRecordset::forwardOnly, _T("select ID,NAME,AGE,GENDER,WORDS from PERSON"));

		//��������е���Ϣ
		for(int i = 0; i < rs.GetODBCFieldCount(); i++)
		{
			CODBCFieldInfo fieldInfo;
			rs.GetODBCFieldInfo(i, fieldInfo);
			printf("%s\t%d\r\n", fieldInfo.m_strName, fieldInfo.m_nSQLType);
		}

		//���ζ�ȡÿһ��
		while(!rs.IsEOF())
		{
			CString name, gender, words;
			int id = 0, age = 0;

			//�ı����͵Ķ�ȡ�Ƚϼ�
			rs.GetFieldValue(1, name);
			rs.GetFieldValue(3, gender);
			rs.GetFieldValue(4, words);

			//�������͵Ķ�ȡ��΢����Щ
			CDBVariant var;
			rs.GetFieldValue((short)0, var);
			id = var.m_iVal;
			rs.GetFieldValue(2, var);
			age = var.m_iVal;

			//���
			printf("%d\t%s\t%d\t%s\t%s\r\n", id, name, age, gender, words);
			rs.MoveNext();
		}
	}
	catch(CDBException * e)
	{
		printf(e->m_strError);
		e->Delete();
	}

	return 0;
}

