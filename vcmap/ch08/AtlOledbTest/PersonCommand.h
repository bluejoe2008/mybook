// PersonCommand.h : CPersonCommand ������

#pragma once

// ���������� 2009��2��7��, 20:04

class CPersonCommandAccessor
{
public:
	LONG m_ID;
	TCHAR m_NAME[51];
	LONG m_AGE;
	TCHAR m_GENDER[2];
	// ISequentialStream* m_WORDS;
	TCHAR m_WORDS[8000];

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶε�״ֵ̬��
	// ����ʹ����Щֵ�������ݿⷵ�ص� NULL ֵ���ڱ���������
	// ����ʱ���������Ϣ���й����ʹ��
	//��Щ�ֶε���ϸ��Ϣ��
	// ��μ� Visual C++ �ĵ��е�
	//�������ɵķ������е��ֶ�״̬���ݳ�Ա����
	// ע��: ������/��������ǰ�����ʼ����Щ�ֶ�!

	DBSTATUS m_dwIDStatus;
	DBSTATUS m_dwNAMEStatus;
	DBSTATUS m_dwAGEStatus;
	DBSTATUS m_dwGENDERStatus;
	DBSTATUS m_dwWORDSStatus;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶεĳ���ֵ��
	// ע��: �Ա䳤�У�����������/����
	//       ����ǰ��ʼ����Щ�ֶ�!

	DBLENGTH m_dwIDLength;
	DBLENGTH m_dwNAMELength;
	DBLENGTH m_dwAGELength;
	DBLENGTH m_dwGENDERLength;
	DBLENGTH m_dwWORDSLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		// pPropSet->AddProperty(DBPROP_ISequentialStream, true);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
		hr = _db.OpenFromInitializationString(L"Provider=MSDASQL.1;Persist Security Info=False;Data Source=hotel;");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	DEFINE_COMMAND_EX(CPersonCommandAccessor, L" \
	SELECT \
		ID, \
		NAME, \
		AGE, \
		GENDER, \
		WORDS \
		FROM PERSON")

// �ñ�/�����������ͨ�� ISequentialStream �ӿ�
// ���ʵ��С�Ȼ�������������ṩ����֧�ִ˹��ܣ�
// ��ʹ��Щȷʵ֧�ִ˹��ܵ��ṩ����ͨ��Ҳ����Ϊ
// ÿ���м�ֻ��һ�� ISequentialStream��
// ���ϣ���ڴ˷�������ʹ��������ʹ�����´����
// ʾ���У����� DBPROP_ISequentialStream �м���
// ������Ϊ True��Ȼ��Ϳ���ʹ�� Read() ������
// ȡ���ݻ�ʹ�� Write()����д������(ע��˲���
// Ҫ�� STGM_READ �����Ը���Ϊ STGM_WRITE �� 
// STGM_READWRITE)���й� ISequentialStream ��
// ����ϸ��Ϣ����μ��ĵ�

	// Ϊ���ĳЩ�ṩ������������⣬���´��������
	// ��ͬ���ṩ�����������˳��������

	BEGIN_COLUMN_MAP(CPersonCommandAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_ID, m_dwIDLength, m_dwIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_NAME, m_dwNAMELength, m_dwNAMEStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_AGE, m_dwAGELength, m_dwAGEStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_GENDER, m_dwGENDERLength, m_dwGENDERStatus)
		// BLOB_ENTRY_LENGTH_STATUS(5, IID_ISequentialStream, STGM_READ, m_WORDS, m_dwWORDSLength, m_dwWORDSStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_WORDS, m_dwWORDSLength, m_dwWORDSStatus)
	END_COLUMN_MAP()
};

class CPersonCommand : public CCommand<CAccessor<CPersonCommandAccessor> >
{
public:
	HRESULT OpenAll()
	{
		HRESULT hr;
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		__if_exists(GetRowsetProperties)
		{
			CDBPropSet propset(DBPROPSET_ROWSET);
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
					propset.AddProperty(DBPROP_IRowsetLocate, true);
			}
			GetRowsetProperties(&propset);
			return OpenRowset(&propset);
		}
		__if_not_exists(GetRowsetProperties)
		{
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
				{
					CDBPropSet propset(DBPROPSET_ROWSET);
					propset.AddProperty(DBPROP_IRowsetLocate, true);
					return OpenRowset(&propset);
				}
			}
		}
		return OpenRowset();
	}

	HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)
	{
		HRESULT hr = Open(m_session, NULL, pPropSet);
#ifdef _DEBUG
		if(FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	void CloseAll()
	{
		Close();
		ReleaseCommand();
		CloseDataSource();
	}
};


