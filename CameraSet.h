#ifndef CAMERASET_H
#define CAMERASET_H

#include <QtGui>
#include "OgreRTCApplication.h"


QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
class QTextEdit;
class QLineEdit;
class QTreeView;
class QLabel;
class QStandardItemModel;
class QCheckBox;
class QGridLayout;
class QGroupBox;
class QHBoxLayout;
class QLabel;
class QPushButton;
class QSpinBox;
class QVBoxLayout;
class Compiler;
class QTextCursor;
class QTreeWidget;
class QComboBox;
QT_END_NAMESPACE


/*
* �J�����ݒ�p�E�B�W�F�b�g
*/

class CameraSetWidget : public QWidget
{
	Q_OBJECT

public:
	CameraSetWidget(QWidget *parent = 0);
	~CameraSetWidget(void);

	OgreRTCApplication *EC;
public slots:
	/*
	*�J�����ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
	*/
	void UpdateList();
	/*
	* �}�E�X�����������̃X���b�g
	*/
	void mouseMoveSlot(QMouseEvent*  evt, int dx, int dy);
	/*
	* �}�E�X�̃{�^�����������Ƃ��̃X���b�g
	*/
	void mousePressSlot(QMouseEvent*  evt);
	/*
	* �}�E�X�̃{�^���𗣂����Ƃ��̃X���b�g
	*/
	void mouseReleaseSlot(QMouseEvent*  evt);

private slots:
	/*
	*�����̈ʒu�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void LightXSlot(double value);
	void LightYSlot(double value);
	void LightZSlot(double value);
	/*
	*�e�̐F�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void ShadowRSlot(double value);
	void ShadowGSlot(double value);
	void ShadowBSlot(double value);
	/*
	*�ʒu�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void PosXSlot(double value);
	void PosYSlot(double value);
	void PosZSlot(double value);
	/*
	*�p���ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
	/*
	*�����ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void LenSlot(double value);

private:
	bool up_flag;

	void UpdatePos();
	void UpdateRot();
	/*
	* �e�̐F�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdateColor();
	/*
	* �����̈ʒu�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdateLightPos();
	/*
	* �ʒu�A�p���A�����ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdatePQ();

	QDoubleSpinBox *LightXspinBox;
	QDoubleSpinBox *LightYspinBox;
	QDoubleSpinBox *LightZspinBox;

	QDoubleSpinBox *ShadowRspinBox;
	QDoubleSpinBox *ShadowGspinBox;
	QDoubleSpinBox *ShadowBspinBox;

	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;

	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;

	QDoubleSpinBox *LenspinBox;
	

	QTextCodec* tc;

	

	



protected:
	




};

#endif