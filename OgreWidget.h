/*!
 * @file  OgreWidget.h
 * @brief Ogre3Dのレンダリング表示ウィンドウ
 *
 */

#ifndef OGREWIDGET_H
#define OGREWIDGET_H

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
QT_END_NAMESPACE


/**
 * @class OgreWidget
*@brief Ogre3Dのレンダリングの表示のウィジェット
*/
class OgreWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	* @param parent 親ウィジェット
	*/
	OgreWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~OgreWidget(void);

	
	/**
	*@brief レンダリング初期化
	*/
	void initOgre();

	OgreRTCApplication *mOgreRTCApplication;

signals:
	
	/**
	*@brief マウス移動時のシグナル
	* @param evt マウスイベント
	* @param dx 移動量(X)
	* @param dy 移動量(Y)
	*/
	void  mouseMoveSignal(QMouseEvent*  evt, int dx, int dy);
	
	/**
	*@brief マウスのボタンを押した時のシグナル
	* @param evt マウスイベント
	*/
	void  mousePressSignal(QMouseEvent*  evt);
	
	/**
	*@brief マウスのボタンを離した時のシグナル
	* @param evt マウスイベント
	*/
	void  mouseReleaseSignal(QMouseEvent*  evt);


private:
	
	/**
	*@brief 周期的に呼び出される関数
	* @param evt タイマーイベント
	*/
	void timerEvent (QTimerEvent *evt);
	
	/**
	*@brief 描画時に呼び出される関数
	* @param evt ペイントイベント
	*/
	void paintEvent (QPaintEvent *evt);
	
	QPaintEngine *paintEngine() const { return 0;}

	
	

	//QTextCodec* tc;

	



protected:
	
	/**
	*@brief マウスが動いたときに呼び出される関数
	* @param evt マウスイベント
	*/
	void  mouseMoveEvent(QMouseEvent*  evt);
	
	/**
	*@brief マウスのボタンを押したときに呼び出される関数
	* @param evt マウスイベント
	*/
	void  mousePressEvent(QMouseEvent*  evt);
	
	/**
	*@brief マウスのボタンを離したときに呼び出される関数
	* @param evt マウスイベント
	*/
	void  mouseReleaseEvent(QMouseEvent*  evt);
	
	/**
	*@brief キーを押した時に呼び出される関数
	* @param evt キーイベント
	*/
	void  keyPressEvent(QKeyEvent*  evt);
	
	/**
	*@brief キーを離した時に呼び出される関数
	* @param evt キーイベント
	*/
	void  keyReleaseEvent(QKeyEvent*  evt);
	/**
	*@brief テキストを入力した場合等に呼び出される関数
	* @param evt インプットメソッドイベント
	*/
	void inputMethodEvent(QInputMethodEvent *evt);




};

#endif