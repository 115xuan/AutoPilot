#pragma once
/*��̨�߼��ӿ�*/
#include <qstring.h>
#include <string>
#include <vector>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "ViewItemCar.h"
#include "ViewImage.h"
namespace autopilot {
	/*���ӽǱ任�л�ԭ��λ���ƶ���Ϣ*/
	struct viewVector {
		float x; //ˮƽ�ƶ�����
		float y; //��ֱ�ƶ�����
		float center; //���ķ�������
	};
	class Model
	{
	public:
		/*С������*/
		float rotateAngle = 360.0; //��λ��ת�Ƕ�
		float moveSpeed = 10.0; //ǰ�������ٶ�

		/*�Զ�����*/
		QString mapFolderPath; //��ͼ����ļ���
		bool isLoadTestMapWhenStart = false; //�Ƿ��������ʱ��򿪲��Ե�ͼ

		/*��������*/
		bool connectBlueToothSerial();
		bool getCarSerialStatus();
		bool isCarSerialPortActivated = false;
		//char incomingData[MAX_DATA_LENGTH];
		int baudRate = 9600;
		int portNum = 6;
		//SerialPort* arduino = nullptr;
		std::string getPortName();
		void setPortName(int num);
		void listenOnce();
		/*������Ϣ��ʾ*/
		long bufferSize = 10000;
		int bufferUpdateFrequency = 115200;
		QString getBufferText();

		/*ͼ��ʶ��*/
		QString testFolder;
		QString cacheFolder; //ʵʱͼƬ�洢���ļ�
		int cameraSamplingFrequency = 10; //����Ƶ��������Ƶ��
		int compressedWidth = 300; //ѹ����ͼƬ���
		int compressedHeight = 400; //ѹ����ͼƬ�߶�
		bool isTranslateToBW = false;//�Ƿ�ѹ���ɻҶ�ͼ
		viewVector SURF(float matchThreshold, std::string leftFilePath, std::string rightFilePath);
		void SURFTest(float matchThreshold, std::vector<std::string> leftFiles, std::vector<std::string> rightFiles);
		void IPCameraTest();

		/*�����ļ�*/
		QString settingPath; //�����ļ���·��
		void readSettings(); //�������ļ��е����ݶ�ȡ��������
		void writeSettings(); //����������ݱ��浽�����ļ���
		void setSettingPath(QString settingPath); //�ı������ļ���·��

		/*�켣��ʾ��ʵʱ���*/
		ViewItemCar* car;
		QVector<ViewImage*> images;
		void ViewInit(QWidget* window); //��ʼ��UI����
		void addViewImage(); //����һ��ͼƬ����ͼ��
		QGraphicsView* pView;
		Model(QGraphicsView* view, QWidget* window);
	};
}
