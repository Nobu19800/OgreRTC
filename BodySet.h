/*!
 * @file  BodySet.h
 * @brief ボディ設定用ウィンドウ
 *
 */

#ifndef BODYSET_H
#define BODYSET_H

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


/**
 * @class BodySetWidget
*@brief ボディ設定用ウィジェット
*/

class BodySetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	* @param parent 親ウィジェット
	*/
	BodySetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~BodySetWidget(void);

	OgreRTCApplication *EC;

signals:
	/**
	*@brief 3Dモデルを作成、削除したときのシグナル
	*/
	void UpdateBody();

public slots:
	/**
	*@brief 3Dモデルの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();
	/**
	*@brief マウスが動いた時のスロット
	* @param evt マウスイベント
	* @param dx 移動量(X)
	* @param dy 移動量(Y)
	*/
	void mouseMoveSlot(QMouseEvent*  evt, int dx, int dy);
	/**
	*@brief マウスのボタンを押したときのスロット
	* @param evt マウスイベント
	*/
	void mousePressSlot(QMouseEvent*  evt);
	/**
	*@brief マウスのボタンを離したときのスロット
	* @param evt マウスイベント
	*/
	void mouseReleaseSlot(QMouseEvent*  evt);

	

private slots:
	/**
	*@brief 作成ボタンを押したときのスロット
	*/
	void SetSlot();
	/**
	*@brief 名前コンボボックスの番号が変わったときのスロット
	* @param value 番号
	*/
	void NameSlot(int value);
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
	*@brief 色設定スピンボックスの値(赤)を変更したときのスロット
	* @param value 輝度(赤)
	*/
	void RedSlot(double value);
	/**
	*@brief 色設定スピンボックスの値(緑)を変更したときのスロット
	* @param value 輝度(緑)
	*/
	void GreenSlot(double value);
	/**
	*@brief 色設定スピンボックスの値(青)を変更したときのスロット
	* @param value 輝度(青)
	*/
	void BlueSlot(double value);
	/**
	*@brief 透明度設定スピンボックスの値を変更したときのスロット
	* @param value 透明度
	*/
	void AlphaSlot(double value);
	/**
	*@brief アニメーション時間変更スピンボックスの値を変更したときのスロット
	* @param value 時間
	*/
	void AnimationSlot(double value);
	/**
	*@brief 表示設定ボタンを押したときのスロット
	*/
	void VisibleSlot();
	/**
	*@brief 非表示設定ボタンを押したときのスロット
	*/
	void unVisibleSlot();
	/**
	*@brief アニメーション設定ボタンを押したときのスロット
	*/
	void SetAnimationSlot();
	/**
	*@brief アニメーションのリセットボタンを押したときのスロット
	*/
	void ResetAnimationSlot();
	/**
	*@brief 削除ボタンを押したときのスロット
	*/
	void DestroySlot();
	/**
	*@brief 影の表示ボタンを押したときのスロット
	*/
	void SetShadowSlot();
	/**
	*@brief 影の非表示ボタンを押したときのスロット
	*/
	void RemoveShadowSlot();
	/**
	*@brief バウンディングボックスの表示ボタンを押したときのスロット
	*/
	void SetBoundingBoxSlot();
	/**
	*@brief バウンディングボックスの非表示ボタンを押したときのスロット
	*/
	void RemoveBoundingBoxSlot();

	//void MaterialSlot();


	/**
	*@brief マテリアル設定ボタンを押したときのスロット
	*/
	void SetMaterialSlot();

	

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
	*@brief 色設定スピンボックスの値を反映する関数
	*/
	void UpdateColor();
	
	/**
	*@brief 表示設定ボタンを反映する関数
	* @param visi trueで表示、falseで非表示
	*/
	void UpdateVisi(bool visi);
	
	/**
	*@brief 影の表示設定ボタンを反映する関数
	* @param visi trueで表示、falseで非表示
	*/
	void UpdateShadow(bool visi);
	
	/**
	*@brief バウンディングボックスの表示設定ボタンを反映する関数
	* @param visi trueで表示、falseで非表示
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