#include "stdafx.h"
#include "AdoTest.h"
#include <afx.h>
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "adoEOF")

int main()
{
	CoInitialize(NULL);

	try
	{
		//����
		_ConnectionPtr pConn("ADODB.Connection");
		//��¼��
		_RecordsetPtr pRs("ADODB.Recordset");

		//�����ݿ�
		pConn->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=E:\\study\\keys\\hotel.mdb",  "", "", adConnectUnspecified);

		//�򿪼�¼��
		pRs->Open("select * from PERSON", _variant_t((IDispatch *)pConn,true), adOpenForwardOnly, adLockReadOnly, adCmdUnknown);

		//���ζ�ȡÿһ��
		while(!pRs->adoEOF)
		{
			//ʹ��_variant_t��ȡ����
			CStringA name, gender, words;
			int id = 0, age = 0;
			_variant_t var;
			
			var = pRs->GetCollect(_variant_t("ID"));
			var.ChangeType(VT_I2);
			id = var.iVal;

			var = pRs->GetCollect(_variant_t("NAME"));
			var.ChangeType(VT_BSTR);
			name = var.bstrVal;

			var = pRs->GetCollect(_variant_t("AGE"));
			var.ChangeType(VT_I2);
			age = var.iVal;

			var = pRs->GetCollect(_variant_t("GENDER"));
			var.ChangeType(VT_BSTR);
			gender = var.bstrVal;

			var = pRs->GetCollect(_variant_t("WORDS"));
			var.ChangeType(VT_BSTR);
			words = var.bstrVal;

			//���
			printf("%d\t%s\t%d\t%s\t%s\r\n", id, name, age, gender, words);
			pRs->MoveNext();
		}
	}
	catch(CException * e)
	{
		e->ReportError();
		e->Delete();
	}

	CoUninitialize();
	return 0;
}