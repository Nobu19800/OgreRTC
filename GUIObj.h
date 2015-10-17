/*!
 * @file  GUIObj.h
 * @brief GUI関連のクラス
 *
 */

#ifndef GUIObj_H
#define GUIObj_H

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>

#include "ImageSetObj.h"
#include "FileStreamFunc.h"



/**
 * @class GUIObj
*@brief GUIの各種設定を行うクラス
*/

class GUIObj
{
public:
	/**
	*@brief コンストラクタ
	*/
	GUIObj();
	/**
	*@brief 色の変更
	* @param r 赤
	* @param g 緑
	* @param b 青
	*/
	void setColor(float r, float g, float b);
	/**
	*@brief 先頭のウインドウにする関数
	*/
	void moveToFront();
	/**
	*@brief 最後尾のウインドウにする関数
	*/
	void moveToBack();
	/**
	*@brief 特定のウインドウの前に移動する関数
	* @param mg 移動後にすぐ後ろに位置するウインドウ
	*/
	void moveInFront(GUIObj *mg);
	
	/**
	*@brief 特定のウインドウも後ろに移動する関数
	* @param mg 移動後にすぐ前に位置するウインドウ
	*/
	void moveBehind(GUIObj *mg);
	
	/**
	*@brief 位置設定の関数
	* @param x 位置(X)
	* @param y 位置(Y)
	*/
	void SetPosition( float x, float y);
	
	/**
	*@brief 大きさ設定の関数
	* @param sx サイズ(X)
	* @param sy サイズ(Y)
	*/
	void SetSize( float sx, float sy);
	
	/**
	*@brief テキスト設定の関数
	* @param t テキスト
	*/
	void SetText( const char* t);
	
	/**
	*@brief 表示、非表示設定の関数
	* @param v trueで表示、falseで非表示
	*/
	void SetVisible( bool v);
	
	/**
	*@brief フレームの表示、非表示設定の関数
	* @param v trueで表示、falseで非表示
	*/
	void SetFrameEnable( bool v);
	
	/**
	*@brief 背景の表示、非表示設定の関数
	* @param v trueで表示、falseで非表示
	*/
	void SetBackGroundEnable( bool v);
	
	/**
	*@brief フォントサイズ設定の関数
	* @param Size サイズ
	*/
	void SetFontSize( int Size);
	
	/**
	*@brief テキスト取得の関数
	* @return テキスト
	*/
	std::string GetText();
	
	/**
	*@brief コンボボックスのアイテム取得の関数
	* @return 現在選択中のアイテム
	*/
	std::string GetComboBoxItem();
	
	/**
	*@brief スライダーの値取得の関数
	* @return スライダーの値
	*/
	float GetSliderValue();

	/**
	*@brief スライダーの値設定の関数
	* @param val スライダーの値
	*/
	void SetSliderValue( float val);
	
	/**
	*@brief コンボボックスのアイテム追加の関数
	* @param t 追加するアイテム
	*/
	void AddComboBoxItem(const char *t);
	
	/**
	*@brief テキストの色設定の関数
	* @param r 赤
	* @param g 緑
	* @param b 青
	*/
	void SetTextColor(float r, float g, float b);
	
	/**
	*@brief 透明度設定の関数
	* @param val 透明度
	*/
	void SetAlpha( float val);
	
	/**
	*@brief 姿勢設定の関数
	* @param r ロール角
	* @param p ピッチ角
	* @param y ヨー角
	*/
	void SetRotatin( float r, float p, float y);
	/**
	*@brief 画像設定の関数
	* @param MIS イメージセットオブジェクト
	* @param n 名前
	*/
	void SetImage(ImageSetObj *MIS, const char *n);


	
	/**
	*@brief 親ウインドウ設定の関数
	* @param mg 親ウインドウ
	*/
	void SetWindow(GUIObj *mg);

	/**
	*@brief コンボボックスのアイテム削除の関数
	* @param index 削除するアイテムの番号
	*/
	void RemoveComboBoxItem(int index);
	
	/**
	*@brief リストボックスのアイテム追加の関数
	* @param t 追加するアイテム
	*/
	void AddListBoxItem(const char *t);
	
	/**
	*@brief リストボックスのアイテム削除の関数
	* @param index 削除するアイテムの番号
	*/
	void RemoveListBoxItem(int index);
	
	/**
	*@brief マルチコロンリストの行追加の関数
	*/
	void AddMultiColumnRow();
	
	/**
	*@brief マルチコロンリストの行削除の関数
	* @param index 削除する行の番号
	*/
	void RemoveMultiColumnRow(int index);
	
	/**
	*@brief マルチコロンリストの列削除の関数
	* @param index 削除する列の番号
	*/
	void RemoveMultiColumnCol(int index);
	
	/**
	*@brief マルチコロンリストのアイテム設定の関数
	* @param t アイテム名
	* @param row 列の番号
	* @param col 行の番号
	*/
	void AddMultiColumnItem(const char *t, int row, int col);
	
	/**
	*@brief プログレスバーの値設定の関数
	* @param val プログレスバーの値
	*/
	void SetProgressBarValue(float val);
	
	/**
	*@brief スクロールバーの値取得の関数
	* @return スクロールバーの値
	*/
	float GetScrollValue();
	
	/**
	*@brief スクロールバーの値設定の関数
	* @param val スクロールバーの値
	*/
	void SetScrollValue( float val);
	
	/**
	*@brief チェックボックスのチェック設定の関数
	* @param val trueでON、falseでOFF
	*/
	void SetCheckBox(bool val);
	
	/**
	*@brief チェックボックスのチェック取得の関数
	* @return trueでON、falseでOFF
	*/
	bool GetCheckBox();




	
	/**
	*@brief テキストの位置を上端に設定する関数
	*/
	void SetTextTopAligned();
	/**
	*@brief テキストの位置を下端に設定する関数
	*/
	void SetTextBottomAligned();
	/**
	*@brief テキストの位置を縦中央に設定する関数
	*/
	void SetTextVertCentred();
	/**
	*@brief テキストの位置を左端に設定する関数
	*単語の途中で改行する
	*/
	void SetTextWordWrapLeftAligned();
	/**
	*@brief テキストの位置を右端に設定する関数
	*単語の途中で改行する
	*/
	void SetTextWordWrapRightAligned();
	/**
	*@brief テキストの位置を中央に設定する関数
	*単語の途中で改行する
	*/
	void SetTextWordWrapCentred();
	/**
	*@brief テキストの位置を左端に設定する関数
	*/
	void SetTextLeftAligned();
	/**
	*@brief テキストの位置を右端に設定する関数
	*/
	void SetTextRightAligned();
	/**
	*@brief テキストの位置を横中央に設定する関数
	*/
	void SetTextHorzCentred();

	/**
	*@brief 設定初期化の関数
	*/
	void ClearProperties();

	
	/**
	*@brief 設定のファイル保存の関数
	* @param ofs2 ファイルストリーム
	*/
	void save(std::ofstream &ofs2);
	
	/**
	*@brief 設定のファイル読み込みの関数
	* @param ifs ファイルストリーム
	* @return trueで成功、falseで失敗
	*/
	bool openb(std::ifstream &ifs);

	CEGUI::Window *window;
	std::string name;
	float pos_x, pos_y;
	float size_x, size_y;
	float roll, pitch, yaw;
	std::string text;
	bool frame_visi;
	bool bg_visi;
	int font_size;
	std::string type;
	bool image_set;
	std::string image_name;
	float alpha;
	int text_type;
	bool visi;
	
	

};

#endif