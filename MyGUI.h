#ifndef MYGUI_H
#define MYGUI_H

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>

#include "MyImageSet.h"
#include "MyFileStream.h"


/*
* GUIのクラス
*/

class MyGUI
{
public:
	MyGUI();
	/*
	*色の変更
	*/
	void setColor(float r, float g, float b);
	/*
	*先頭のウインドウにする関数
	*/
	void moveToFront();
	/*
	*最後尾のウインドウにする関数
	*/
	void moveToBack();
	/*
	*ウインドウを前に移動する関数
	*/
	void moveInFront(MyGUI *mg);
	/*
	*ウインドウを後ろに移動する関数
	*/
	void moveBehind(MyGUI *mg);
	/*
	*位置設定の関数
	*/
	void SetPosition( float x, float y);
	/*
	*大きさ設定の関数
	*/
	void SetSize( float sx, float sy);
	/*
	*テキスト設定の関数
	*/
	void SetText( const char* t);
	/*
	*表示、非表示設定の関数
	*/
	void SetVisible( bool v);
	/*
	*フレームの表示、非表示設定の関数
	*/
	void SetFrameEnable( bool v);
	/*
	*背景の表示、非表示設定の関数
	*/
	void SetBackGroundEnable( bool v);
	/*
	*フォントサイズ設定の関数
	*/
	void SetFontSize( int Size);
	/*
	*テキスト取得の関数
	*/
	std::string GetText();
	/*
	*コンボボックスのアイテム取得の関数
	*/
	std::string GetComboBoxItem();
	/*
	*スライダーの値取得の関数
	*/
	float GetSliderValue();
	/*
	*スライダーの値設定の関数
	*/
	void SetSliderValue( float val);
	/*
	*コンボボックスのアイテム追加の関数
	*/
	void AddComboBoxItem(const char *t);
	/*
	*テキストの色設定の関数
	*/
	void SetTextColor(float r, float g, float b);
	/*
	*透明度設定の関数
	*/
	void SetAlpha( float val);
	/*
	*姿勢設定の関数
	*/
	void SetRotatin( float r, float p, float y);
	/*
	*画像設定の関数
	*/
	void SetImage(MyImageSet *MIS, const char *n);


	/*
	*ウインドウ設定の関数
	*/
	void SetWindow(MyGUI *mg);
	/*
	*コンボボックスのアイテム削除の関数
	*/
	void RemoveComboBoxItem(int index);
	/*
	*リストボックスのアイテム追加の関数
	*/
	void AddListBoxItem(const char *t);
	/*
	*リストボックスのアイテム削除の関数
	*/
	void RemoveListBoxItem(int index);
	/*
	*マルチコロンリストの行追加の関数
	*/
	void AddMultiColumnRow();
	/*
	*マルチコロンリストの行削除の関数
	*/
	void RemoveMultiColumnRow(int index);
	/*
	*マルチコロンリストの列削除の関数
	*/
	void RemoveMultiColumnCol(int index);
	/*
	*マルチコロンリストのアイテム設定の関数
	*/
	void AddMultiColumnItem(const char *t, int row, int col);
	/*
	*プログレスバーの値設定の関数
	*/
	void SetProgressBarValue(float val);
	/*
	*スクロールバーの値取得の関数
	*/
	float GetScrollValue();
	/*
	*スクロールバーの値設定の関数
	*/
	void SetScrollValue( float val);
	/*
	*チェックボックスのチェック設定の関数
	*/
	void SetCheckBox(bool val);
	/*
	*チェックボックスのチェック取得の関数
	*/
	bool GetCheckBox();




	/*
	*テキストの位置設定の関数
	*/
	void SetTextTopAligned();
	void SetTextBottomAligned();
	void SetTextVertCentred();
	void SetTextWordWrapLeftAligned();
	void SetTextWordWrapRightAligned();
	void SetTextWordWrapCentred();
	void SetTextLeftAligned();
	void SetTextRightAligned();
	void SetTextHorzCentred();
	/*
	*設定初期化の関数
	*/
	void ClearProperties();

	/*
	*設定のファイル保存の関数
	*/
	void save(std::ofstream &ofs2);
	/*
	*設定のファイル読み込みの関数
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