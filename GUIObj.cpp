/*!
 * @file  GUIObj.cpp
 * @brief GUI関連のクラス
 *
 */

#include "GUIObj.h"

#include <coil/stringutil.h>

#ifdef _WIN32
#include "UnicodeF.h"
#else
#endif

extern int str_size;


/**
*@brief GUIの各種設定を行うクラスのコンストラクタ
*/
GUIObj::GUIObj()
{
	pos_x = 0;
	pos_y = 0;
	size_x = 0;
	size_y = 0;
	roll = 0;
	pitch = 0;
	yaw = 0;
	frame_visi = true;
	bg_visi = true;
	font_size = 30;
	image_set = false;
	image_name = "";
	alpha = 1;
	text_type = 0;
	text = "";
	visi = true;
}

/**
*@brief テキスト取得の関数
* @return テキスト
*/
std::string GUIObj::GetText()
{
	std::string text = window->getText().c_str();

	return text;
}


/**
*@brief コンボボックスのアイテム追加の関数
* @param t 追加するアイテム
*/
void GUIObj::AddComboBoxItem( const char *t)
{
	//static_cast<CEGUI::Combobox*>(label)->addItem(new MyListItem(name));
#ifdef _WIN32
	static_cast<CEGUI::Combobox*>(window)->addItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)CUnicodeF::sjis_to_utf8(t, &str_size)));
#else
	static_cast<CEGUI::Combobox*>(window)->addItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)t));
#endif
}


/**
*@brief コンボボックスのアイテム取得の関数
* @return 現在選択中のアイテム
*/
std::string GUIObj::GetComboBoxItem()
{
	CEGUI::Combobox* cbobox = static_cast<CEGUI::Combobox*>(window);

	
	return cbobox->getSelectedItem()->getText().c_str();
}


/**
*@brief スライダーの値取得の関数
* @return スライダーの値
*/
float GUIObj::GetSliderValue()
{
	float val = static_cast<CEGUI::Slider*>(window)->getCurrentValue();

	return val;
}

/**
*@brief スライダーの値設定の関数
* @param val スライダーの値
*/
void GUIObj::SetSliderValue( float val)
{
	static_cast<CEGUI::Slider*>(window)->setCurrentValue(val);
}

/**
*@brief 透明度設定の関数
* @param val 透明度
*/
void GUIObj::SetAlpha( float val)
{
	window->setAlpha(val);
	alpha = val;
}


/**
*@brief テキストの色設定の関数
* @param r 赤
* @param g 緑
* @param b 青
*/
void GUIObj::SetTextColor(float r, float g, float b)
{
	CEGUI::Colour col = CEGUI::Colour(r, g, b);
	CEGUI::ColourRect crect = CEGUI::ColourRect(col);
	window->setProperty("DisabledTextColour", CEGUI::PropertyHelper<CEGUI::ColourRect>::toString(crect));
}


/**
*@brief 姿勢設定の関数
* @param r ロール角
* @param p ピッチ角
* @param y ヨー角
*/
void GUIObj::SetRotatin( float r, float p, float y)
{
	CEGUI::Quaternion rot;
	//window->setRotation(CEGUI::Vector3<float>(r,p,y));
	window->setRotation(rot.eulerAnglesRadians(r,p,y));
	roll = r;
	pitch = p;
	yaw = y;
}

/**
*@brief テキスト設定の関数
* @param t テキスト
*/
void GUIObj::SetText( const char* t)
{
#ifdef _WIN32
	window->setText((CEGUI::utf8*)CUnicodeF::sjis_to_utf8(t, &str_size));
#else
	window->setText((CEGUI::utf8*)t);
#endif
	text = t;
}


/**
*@brief 大きさ設定の関数
* @param sx サイズ(X)
* @param sy サイズ(Y)
*/
void GUIObj::SetSize( float sx, float sy)
{
	window->setSize(CEGUI::USize(CEGUI::UDim(sx, 0), CEGUI::UDim(sy, 0)));
	size_x = sx;
	size_y = sy;
}

/**
*@brief 位置設定の関数
* @param x 位置(X)
* @param y 位置(Y)
*/
void GUIObj::SetPosition( float x, float y)
{
	window->setPosition(CEGUI::UVector2(CEGUI::UDim(x, 0),CEGUI::UDim(y, 0)));
	pos_x = x;
	pos_y = y;
}


/**
*@brief 表示、非表示設定の関数
* @param v trueで表示、falseで非表示
*/
void GUIObj::SetVisible( bool v)
{
	window->setVisible(v);
	visi = v;
}

/**
*@brief フレームの表示、非表示設定の関数
* @param v trueで表示、falseで非表示
*/
void GUIObj::SetFrameEnable( bool v)
{
	if(v)window->setProperty("FrameEnabled","True");
	else window->setProperty("FrameEnabled","False");
	frame_visi = v;
}

/**
*@brief 背景の表示、非表示設定の関数
* @param v trueで表示、falseで非表示
*/
void GUIObj::SetBackGroundEnable( bool v)
{
	if(v)window->setProperty("BackgroundEnabled","True");
	else window->setProperty("BackgroundEnabled","False");
	bg_visi = v;
}

/**
*@brief フォントサイズ設定の関数
* @param Size サイズ
*/
void GUIObj::SetFontSize( int Size)
{
	CEGUI::Font *f = CEGUI::System::getSingleton().getDefaultGUIContext().getDefaultFont();
	//CEGUI::Font *f = window->getFont();
	f->setProperty ("PointSize",
                        CEGUI::PropertyHelper<int>::toString (
                            Size));
	font_size = Size;
}

/**
*@brief 画像設定の関数
* @param MIS イメージセットオブジェクト
* @param n 名前
*/
void GUIObj::SetImage(ImageSetObj *MIS, const char *n)
{
	image_set = true;
	//window->setProperty("Image", CEGUI::PropertyHelper<CEGUI::Image *>::toString(&MIS->Image->getImage(n)));
	
	coil::vstring va = coil::split(MIS->filename, ".");
	
	//window->setProperty("Image", tn);
	if(va[1] == "imageset")
	{
		std::string tn = MIS->name + "/";
		tn = tn + n;
		window->setProperty("Image", tn);
	}
	else
	{
		
		window->setProperty("Image", MIS->name);
	}
	image_name = MIS->name;
}

/**
*@brief 設定初期化の関数
*/
void GUIObj::ClearProperties()
{
	image_set = false;
	window->clearProperties();

	
}


/**
*@brief テキストの位置を上端に設定する関数
*/
void GUIObj::SetTextTopAligned()
{
	window->setProperty("VertFormatting", "TopAligned");
	text_type = 0;
}

/**
*@brief テキストの位置を下端に設定する関数
*/
void GUIObj::SetTextBottomAligned()
{
	window->setProperty("VertFormatting", "BottomAligned");
	text_type = 1;
}

/**
*@brief テキストの位置を縦中央に設定する関数
*/
void GUIObj::SetTextVertCentred()
{
	window->setProperty("VertFormatting", "VertCentred");
	text_type = 2;
}

/**
*@brief テキストの位置を左端に設定する関数
*単語の途中で改行する
*/
void GUIObj::SetTextWordWrapLeftAligned()
{
	window->setProperty("HorzFormatting", "WordWrapLeftAligned");
	text_type = 3;
}

/**
*@brief テキストの位置を右端に設定する関数
*単語の途中で改行する
*/
void GUIObj::SetTextWordWrapRightAligned()
{
	window->setProperty("HorzFormatting", "WordWrapRightAligned");
	text_type = 4;
}

/**
*@brief テキストの位置を中央に設定する関数
*単語の途中で改行する
*/
void GUIObj::SetTextWordWrapCentred()
{
	window->setProperty("HorzFormatting", "WordWrapCentred");
	text_type = 5;
}

/**
*@brief テキストの位置を左端に設定する関数
*/
void GUIObj::SetTextLeftAligned()
{
	window->setProperty("HorzFormatting", "LeftAligned");
	text_type = 6;
}

/**
*@brief テキストの位置を右端に設定する関数
*/
void GUIObj::SetTextRightAligned()
{
	window->setProperty("HorzFormatting", "RightAligned");
	text_type = 7;
}

/**
*@brief テキストの位置を横中央に設定する関数
*/
void GUIObj::SetTextHorzCentred()
{
	window->setProperty("HorzFormatting", "HorzCentred");
	text_type = 8;
}



/**
*@brief 設定のファイル読み込みの関数
* @param ifs ファイルストリーム
* @return trueで成功、falseで失敗
*/
bool GUIObj::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);
	type = ReadString(ifs);
	ifs.read( (char*)&pos_x, sizeof(pos_x) );
	ifs.read( (char*)&pos_y, sizeof(pos_y) );

	ifs.read( (char*)&roll, sizeof(roll) );
	ifs.read( (char*)&pitch, sizeof(pitch) );
	ifs.read( (char*)&yaw, sizeof(yaw) );


	ifs.read( (char*)&size_x, sizeof(size_x) );
	ifs.read( (char*)&size_y, sizeof(size_y) );

	text = ReadString(ifs);

	ifs.read( (char*)&frame_visi, sizeof(frame_visi) );
	ifs.read( (char*)&bg_visi, sizeof(bg_visi) );

	ifs.read( (char*)&font_size, sizeof(font_size) );
	
	ifs.read( (char*)&image_set, sizeof(image_set) );
	
	image_name = ReadString(ifs);

	ifs.read( (char*)&alpha, sizeof(alpha) );
	ifs.read( (char*)&text_type, sizeof(text_type) );
	ifs.read( (char*)&visi, sizeof(visi) );

	//std::cout << name << "\t" << text << "\t" << image_name << std::endl;

	return true;
}


/**
*@brief 設定のファイル保存の関数
* @param ofs2 ファイルストリーム
*/
void GUIObj::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	WriteString(type , ofs2 );
	ofs2.write( (char*)&pos_x, sizeof(pos_x) );
	ofs2.write( (char*)&pos_y, sizeof(pos_y) );

	ofs2.write( (char*)&roll, sizeof(roll) );
	ofs2.write( (char*)&pitch, sizeof(pitch) );
	ofs2.write( (char*)&yaw, sizeof(yaw) );

	ofs2.write( (char*)&size_x, sizeof(size_x) );
	ofs2.write( (char*)&size_y, sizeof(size_y) );


	WriteString(text , ofs2 );

	ofs2.write( (char*)&frame_visi, sizeof(frame_visi) );
	ofs2.write( (char*)&bg_visi, sizeof(bg_visi) );

	ofs2.write( (char*)&font_size, sizeof(font_size) );
	
	ofs2.write( (char*)&image_set, sizeof(image_set) );
	WriteString(image_name , ofs2 );
	ofs2.write( (char*)&alpha, sizeof(alpha) );

	ofs2.write( (char*)&text_type, sizeof(text_type) );
	ofs2.write( (char*)&visi, sizeof(visi) );
}


/**
*@brief 親ウインドウ設定の関数
* @param mg 親ウインドウ
*/
void GUIObj::SetWindow(GUIObj *mg)
{
	window->getParent()->removeChild(window);
	mg->window->addChild(window);
	
}

/**
*@brief コンボボックスのアイテム削除の関数
* @param index 削除するアイテムの番号
*/
void GUIObj::RemoveComboBoxItem(int index)
{
	CEGUI::Combobox* mw = static_cast<CEGUI::Combobox*>(window);
	mw->removeItem(mw->getListboxItemFromIndex(index));
}


/**
*@brief リストボックスのアイテム追加の関数
* @param t 追加するアイテム
*/
void GUIObj::AddListBoxItem(const char *t)
{
#ifdef _WIN32
	static_cast<CEGUI::Listbox*>(window)->addItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)CUnicodeF::sjis_to_utf8(t, &str_size)));
#else
	static_cast<CEGUI::Listbox*>(window)->addItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)t));
#endif
}


/**
*@brief リストボックスのアイテム削除の関数
* @param index 削除するアイテムの番号
*/
void GUIObj::RemoveListBoxItem(int index)
{
	CEGUI::Listbox* mw = static_cast<CEGUI::Listbox*>(window);
	mw->removeItem(mw->getListboxItemFromIndex(index));
}


/**
*@brief マルチコロンリストの行追加の関数
*/
void GUIObj::AddMultiColumnRow()
{
	static_cast<CEGUI::MultiColumnList*>(window)->addRow();
}

/**
*@brief マルチコロンリストの行削除の関数
* @param index 削除する行の番号
*/
void GUIObj::RemoveMultiColumnRow(int index)
{
	static_cast<CEGUI::MultiColumnList*>(window)->removeRow(index);
}


/**
*@brief マルチコロンリストの列削除の関数
* @param index 削除する列の番号
*/
void GUIObj::RemoveMultiColumnCol(int index)
{
	static_cast<CEGUI::MultiColumnList*>(window)->removeColumn(index);
}


/**
*@brief マルチコロンリストのアイテム設定の関数
* @param t アイテム名
* @param row 列の番号
* @param col 行の番号
*/
void GUIObj::AddMultiColumnItem(const char *t, int row, int col)
{
#ifdef _WIN32
	static_cast<CEGUI::MultiColumnList*>(window)->setItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)CUnicodeF::sjis_to_utf8(t, &str_size)), row, col);
#else
	static_cast<CEGUI::MultiColumnList*>(window)->setItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)t), row, col);
#endif
}

/**
*@brief プログレスバーの値設定の関数
* @param val プログレスバーの値
*/
void GUIObj::SetProgressBarValue(float val)
{
	static_cast<CEGUI::ProgressBar*>(window)->setProgress(val);

}


/**
*@brief スクロールバーの値取得の関数
* @return スクロールバーの値
*/
float GUIObj::GetScrollValue()
{
	float val = static_cast<CEGUI::Scrollbar*>(window)->getScrollPosition();

	return val;
}

/**
*@brief スクロールバーの値設定の関数
* @param val スクロールバーの値
*/
void GUIObj::SetScrollValue( float val)
{
	static_cast<CEGUI::Scrollbar*>(window)->setScrollPosition(val);

}

/**
*@brief チェックボックスのチェック設定の関数
* @param val trueでON、falseでOFF
*/
void GUIObj::SetCheckBox(bool val)
{
	static_cast<CEGUI::ToggleButton*>(window)->setSelected(val);
}

/**
*@brief チェックボックスのチェック取得の関数
* @return trueでON、falseでOFF
*/
bool GUIObj::GetCheckBox()
{
	return static_cast<CEGUI::ToggleButton*>(window)->isSelected();
}

/**
*@brief 先頭のウインドウにする関数
*/
void GUIObj::moveToFront()
{
	window->moveToFront();
	
}


/**
*@brief 最後尾のウインドウにする関数
*/
void GUIObj::moveToBack()
{
	window->moveToBack();
	
}

/**
*@brief 特定のウインドウの前に移動する関数
* @param mg 移動後にすぐ後ろに位置するウインドウ
*/
void GUIObj::moveInFront(GUIObj *mg)
{
	window->moveInFront(mg->window);
	
}

/**
*@brief 特定のウインドウも後ろに移動する関数
* @param mg 移動後にすぐ前に位置するウインドウ
*/
void GUIObj::moveBehind(GUIObj *mg)
{
	window->moveBehind(mg->window);
	
}

/**
*@brief 色の変更
* @param r 赤
* @param g 緑
* @param b 青
*/
void GUIObj::setColor(float r, float g, float b)
{
	CEGUI::Colour col = CEGUI::Colour(r, g, b);
	CEGUI::ColourRect crect = CEGUI::ColourRect(col);
	window->setProperty("ImageColours", CEGUI::PropertyHelper<CEGUI::ColourRect>::toString(crect));
	
}