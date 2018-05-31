#include "stdafx.h"
#include <afx.h>
#include <afxdao.h>

int main()
{
	try
	{
		CDaoDatabase db;
		//�����ݿ�
		db.Open(_T("..\\..\\hotel.mdb"));
		
		CDaoRecordset rs(&db);
		//�򿪼�¼��
		rs.Open(AFX_DAO_USE_DEFAULT_TYPE, _T("select ID,NAME,AGE,GENDER,WORDS from PERSON"), dbForwardOnly);

		//���ζ�ȡÿһ��
		while(!rs.IsEOF())
		{
			//ʹ��COleVariant��ȡ����
			COleVariant var;
			CStringA name, gender, words;
			int id = 0, age = 0;

			//�ı�CStringA
			rs.GetFieldValue(1, var);
			name = (BSTR)var.pbstrVal;
			rs.GetFieldValue(3, var);
			gender = (BSTR)var.pbstrVal;
			rs.GetFieldValue(4, var);
			words = (BSTR)var.pbstrVal;

			//��ֵ
			rs.GetFieldValue((short)0, var);
			id = var.intVal;
			rs.GetFieldValue(2, var);
			age = var.intVal;

			//���
			printf("%d\t%s\t%d\t%s\t%s\r\n", id, name, age, gender, words);
			rs.MoveNext();
		}

		//������еı����ֶ�
		for(int i = 0; i < db.GetTableDefCount(); i++)
		{
			CDaoTableDefInfo tableInfo;
			db.GetTableDefInfo(i, tableInfo);

			//�������
			printf("%ls\r\n", tableInfo.m_strName);
			CDaoTableDef table(&db);
			table.Open(tableInfo.m_strName);

			//����ֶ���
			for(int j = 0; j < table.GetFieldCount(); j++)
			{
				CDaoFieldInfo fieldInfo;
				table.GetFieldInfo(j, fieldInfo);

				printf("\t%ls\r\n", fieldInfo.m_strName);
			}
		}
	}
	catch(CException * e)
	{
		e->ReportError();
		e->Delete();
	}

	AfxDaoTerm();
	return 0;
}