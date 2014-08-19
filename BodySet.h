#ifndef BODYSET_H
#define BODYSET_H

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
class QLayout;
class QPushButton;
class QSpinBox;
class QVBoxLayout;
class Compiler;
class QTextCursor;
class QTreeWidget;
class QDoubleSpinBox;
class QComboBox;
QT_END_NAMESPACE


/*
* 3Dモデル作成、設定用ウィジェット
*/

class BodySetWidget : public QWidget
{
	Q_OBJECT

public:
	BodySetWidget(QWidget *parent = 0);
	~BodySetWidget(void);

	OgreRTCApplication *EC;

signals:
	/*
	* 3Dモデルを作成、削除したときのシグナル
	*/
	void UpdateBody();

public slots:
	/*
	*3Dモデルの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();
	/*
	* マウスが動いた時のスロット
	*/
	void mouseMoveSlot(QMouseEvent*  evt, int dx, int dy);
	/*
	* マウスのボタンを押したときのスロット
	*/
	void mousePressSlot(QMouseEvent*  evt);
	/*
	* マウスのボタンを離したときのスロット
	*/
	void mouseReleaseSlot(QMouseEvent*  evt);

	

private slots:
	/*
	*作成ボタンを押したときのスロット
	*/
	void SetSlot();
	/*
	*名前コンボボックスの番号が変わったときのスロット
	*/
	void NameSlot(int value);
	/*
	*位置設定スピンボックスの値を変更したときのスロット
	*/
	void PosXSlot(double value);
	void PosYSlot(double value);
	void PosZSlot(double value);
	/*
	*拡大率設定スピンボックスの値を変更したときのスロット
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	void ScaleZSlot(double value);
	/*
	*姿勢設定スピンボックスの値を変更したときのスロット
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
	/*
	*色設定スピンボックスの値を変更したときのスロット
	*/
	void RedSlot(double value);
	void GreenSlot(double value);
	void BlueSlot(double value);
	/*
	*透明度設定スピンボックスの値を変更したときのスロット
	*/
	void AlphaSlot(double value);
	/*
	*アニメーション時間変更スピンボックスの値を変更したときのスロット
	*/
	void AnimationSlot(double value);
	/*
	*表示、非表示設定ボタンを押したときのスロット
	*/
	void VisibleSlot();
	void unVisibleSlot();
	/*
	*アニメーション設定ボタンを押したときのスロット
	*/
	void SetAnimationSlot();
	/*
	*アニメーションのリセットボタンを押したときのスロット
	*/
	void ResetAnimationSlot();
	/*
	*削除ボタンを押したときのスロット
	*/
	void DestroySlot();
	/*
	*影の表示、非表示ボタンを押したときのスロット
	*/
	void SetShadowSlot();
	void RemoveShadowSlot();
	/*
	*バウンディングボックスの表示、非表示ボタンを押したときのスロット
	*/
	void SetBoundingBoxSlot();
	void RemoveBoundingBoxSlot();

	void MaterialSlot();

	/*
	*マテリアル設定ボタンを押したときのスロット
	*/
	void SetMaterialSlot();

	

private:
	bool up_flag;
	
	/*
	* 位置設定スピンボックスの値を反映する関数
	*/
	void UpdatePos();
	/*
	* 拡大率設定スピンボックスの値を反映する関数
	*/
	void UpdateScale();
	/*
	* 姿勢設定スピンボックスの値を反映する関数
	*/
	void UpdateRot();
	/*
	* 色設定スピンボックスの値を反映する関数
	*/
	void UpdateColor();
	/*
	* 表示設定ボタンを反映する関数
	*/
	void UpdateVisi(bool visi);
	/*
	* 影の表示設定ボタンを反映する関数
	*/
	void UpdateShadow(bool visi);
	/*
	* バウンディングボックスの表示設定ボタンを反映する関数
	*/
	void UpdateBound(bool visi);


	QTextCodec* tc;
	QComboBox *NameEdit;
	QComboBox *FileNameEdit;
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;
	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *ScaleZspinBox;
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;
	QDoubleSpinBox *RedspinBox;
	QDoubleSpinBox *GreenspinBox;
	QDoubleSpinBox *BluespinBox;
	QDoubleSpinBox *AlphaspinBox;
	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;
	QComboBox *AnimationEdit;
	QDoubleSpinBox *AnimationspinBox;
	QPushButton *SetAnimationButton;
	QPushButton *ResetAnimationButton;
	QPushButton *DestroyButton;
	QPushButton *SetShadowButton;
	QPushButton *RemoveShadowButton;
	QPushButton *SetBoundingBoxButton;
	QPushButton *RemoveBoundingBoxButton;
	QComboBox *MaterialEdit;
	QPushButton *SetMaterialButton;
	
	

	



protected:
	




};

#endif