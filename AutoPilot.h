#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AutoPilot.h"
#include "Model.h"

class AutoPilot : public QMainWindow
{
    Q_OBJECT

public:
	AutoPilot(QWidget *parent = Q_NULLPTR);
	autopilot::Model* model;
	void updateSettingsUI(); //��model�����趨ֵ
	void updateModelFromSettingsUI(); //��UI�����趨ֵ��model
	void updateAutoPilot();
	void updateCarControl();
	void updateCV();
	void updateBlueToothSerial();
	void updateCarBlueTooth();
private:
	Ui::MainWindow ui;
	QString mapFolderPath;
	QString testFolderPath;
	QString cacheFolderPath;
	QString settingsFilePath;
	void chooseMapFolder();
	void chooseTestFolder();
	void chooseCacheFolder();
	void chooseSettingsFile();
	void connectCarBluetoothSerial();
	void bufferTextUpdate();
	QTimer* bufferUpdateTimer = nullptr;
};
