#pragma once
#include "qstring.h"
class Utils
{
private:
	static QString data;
public:
	//�ļ���λ�ô��
	static QString getDataFolder();
	static QString getUIFolder();
	static QString getMapFolder();
	static QString getSettingsFolder();
};

