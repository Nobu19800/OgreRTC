/*!
 * @file  ParticleSet.h
 * @brief パーティクル設定用ウィンドウ
 *
 */

#ifndef PARTICLESET_H
#define PARTICLESET_H

#include <QtWidgets>
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



/**
 * @class ParticleSetWidget
*@brief パーティクル作成、設定用ウィジェット
*/

class ParticleSetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	* @param parent 親ウィジェット
	*/
	ParticleSetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~ParticleSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	/**
	*@brief パーティクルを作成、削除したときのスロット
	*/
	void UpdateList();
	

signals:
	
	/**
	*@brief パーティクルを作成、削除したときのシグナル
	*/
	void UpdateParticle();

private slots:
	
	/**
	*@brief 作成ボタンを押したときのスロット
	*/
	void SetSlot();
	/**
	*@brief 位置設定スピンボックスの値(X座標)を変更したときのスロット
	* @param value 位置(X)
	*/
	void PosXSlot(double value);
	/**
	*@brief 位置設定スピンボックスの値(Y座標)を変更したときのスロット
	* @param value 位置(Y)
	*/
	void PosYSlot(double value);
	/**
	*@brief 位置設定スピンボックスの値(Z座標)を変更したときのスロット
	* @param value 位置(Z)
	*/
	void PosZSlot(double value);
	/**
	*@brief 拡大率設定スピンボックスの値(X軸方向)を変更したときのスロット
	* @param value 拡大率(X)
	*/
	void ScaleXSlot(double value);
	/**
	*@brief 拡大率設定スピンボックスの値(Y軸方向)を変更したときのスロット
	* @param value 拡大率(Y)
	*/
	void ScaleYSlot(double value);
	/**
	*@brief 拡大率設定スピンボックスの値(Z軸方向)を変更したときのスロット
	* @param value 拡大率(Z)
	*/
	void ScaleZSlot(double value);
	/**
	*@brief 姿勢設定スピンボックスの値(ロール角)を変更したときのスロット
	* @param value 角度(ロール)
	*/
	void RollSlot(double value);
	/**
	*@brief 姿勢設定スピンボックスの値(ピッチ角)を変更したときのスロット
	* @param value 角度(ピッチ)
	*/
	void PitchSlot(double value);
	/**
	*@brief 姿勢設定スピンボックスの値(ヨー角)を変更したときのスロット
	* @param value 角度(ヨー)
	*/
	void YawSlot(double value);
	
	/**
	*@brief 表示設定ボタンを押したときのスロット
	*/
	void VisibleSlot();
	/**
	*@brief 非表示設定ボタンを押したときのスロット
	*/
	void unVisibleSlot();
	
	/**
	*@brief 削除ボタンを押したときのスロット
	*/
	void DestroySlot();
	
	/**
	*@brief 名前コンボボックスの番号が変わったときのスロット
	* @param value 番号
	*/
	void NameSlot(int value);

	



private:
	bool up_flag;

	
	/**
	*@brief 位置設定スピンボックスの値を反映する関数
	*/
	void UpdatePos();
	
	/**
	*@brief 拡大率設定スピンボックスの値を反映する関数
	*/
	void UpdateScale();
	
	/**
	*@brief 姿勢設定スピンボックスの値を反映する関数
	*/
	void UpdateRot();
	
	/**
	*@brief 表示設定ボタンを反映する関数
	* @param visi trueで表示、falseで非表示
	*/
	void UpdateVisi(bool visi);


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
	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;
	QPushButton *DestroyButton;

	

	

	



protected:
	




};

#endif