#include "MyGUI.h"

#ifdef _WIN32
#include "UnicodeF.h"
#else
#endif

extern int str_size;

MyGUI::MyGUI()
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


std::string MyGUI::GetText()
{
	std::string text = window->getText().c_str();

	return text;
}

void MyGUI::AddComboBoxItem( const char *t)
{
	//static_cast<CEGUI::Combobox*>(label)->addItem(new MyListItem(name));
#ifdef _WIN32
	static_cast<CEGUI::Combobox*>(window)->addItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)CUnicodeF::sjis_to_utf8(t, &str_size)));
#else
	static_cast<CEGUI::Combobox*>(window)->addItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)t));
#endif
}

std::string MyGUI::GetComboBoxItem()
{
	CEGUI::Combobox* cbobox = static_cast<CEGUI::Combobox*>(window);

	
	return cbobox->getSelectedItem()->getText().c_str();
}

float MyGUI::GetSliderValue()
{
	float val = static_cast<CEGUI::Slider*>(window)->getCurrentValue();

	return val;
}

void MyGUI::SetSliderValue( float val)
{
	static_cast<CEGUI::Slider*>(window)->setCurrentValue(val);
}

void MyGUI::SetAlpha( float val)
{
	window->setAlpha(val);
	alpha = val;
}

void MyGUI::SetTextColor(float r, float g, float b)
{
	CEGUI::colour col = CEGUI::colour(r, g, b);
	CEGUI::ColourRect crect = CEGUI::ColourRect(col);
	window->setProperty("DisabledTextColour", CEGUI::PropertyHelper::colourRectToString(crect));
}

void MyGUI::SetRotatin( float r, float p, float y)
{
	window->setRotation(CEGUI::Vector3(r,p,y));
	roll = r;
	pitch = p;
	yaw = y;
}

void MyGUI::SetText( const char* t)
{
#ifdef _WIN32
	window->setText((CEGUI::utf8*)CUnicodeF::sjis_to_utf8(t, &str_size));
#else
	window->setText((CEGUI::utf8*)t);
#endif
	text = t;
}

void MyGUI::SetSize( float sx, float sy)
{
	window->setSize(CEGUI::UVector2(CEGUI::UDim(sx, 0), CEGUI::UDim(sy, 0)));
	size_x = sx;
	size_y = sy;
}

void MyGUI::SetPosition( float x, float y)
{
	window->setPosition(CEGUI::UVector2(CEGUI::UDim(x, 0),CEGUI::UDim(y, 0)));
	pos_x = x;
	pos_y = y;
}

void MyGUI::SetVisible( bool v)
{
	window->setVisible(v);
	visi = v;
}

void MyGUI::SetFrameEnable( bool v)
{
	if(v)window->setProperty("FrameEnabled","True");
	else window->setProperty("FrameEnabled","False");
	frame_visi = v;
}

void MyGUI::SetBackGroundEnable( bool v)
{
	if(v)window->setProperty("BackgroundEnabled","True");
	else window->setProperty("BackgroundEnabled","False");
	bg_visi = v;
}

void MyGUI::SetFontSize( int Size)
{
	CEGUI::Font *f = window->getFont ();
	f->setProperty ("PointSize",
                        CEGUI::PropertyHelper::intToString (
                            Size));
	font_size = Size;
}

void MyGUI::SetImage(MyImageSet *MIS, const char *n)
{
	image_set = true;
	window->setProperty("Image", CEGUI::PropertyHelper::imageToString(&MIS->imageSet->getImage(n)));
	image_name = MIS->name;
}


void MyGUI::ClearProperties()
{
	image_set = false;
	window->clearProperties();

	
}



void MyGUI::SetTextTopAligned()
{
	window->setProperty("VertFormatting", "TopAligned");
	text_type = 0;
}
void MyGUI::SetTextBottomAligned()
{
	window->setProperty("VertFormatting", "BottomAligned");
	text_type = 1;
}
void MyGUI::SetTextVertCentred()
{
	window->setProperty("VertFormatting", "VertCentred");
	text_type = 2;
}
void MyGUI::SetTextWordWrapLeftAligned()
{
	window->setProperty("HorzFormatting", "WordWrapLeftAligned");
	text_type = 3;
}
void MyGUI::SetTextWordWrapRightAligned()
{
	window->setProperty("HorzFormatting", "WordWrapRightAligned");
	text_type = 4;
}
void MyGUI::SetTextWordWrapCentred()
{
	window->setProperty("HorzFormatting", "WordWrapCentred");
	text_type = 5;
}
void MyGUI::SetTextLeftAligned()
{
	window->setProperty("HorzFormatting", "LeftAligned");
	text_type = 6;
}
void MyGUI::SetTextRightAligned()
{
	window->setProperty("HorzFormatting", "RightAligned");
	text_type = 7;
}
void MyGUI::SetTextHorzCentred()
{
	window->setProperty("HorzFormatting", "HorzCentred");
	text_type = 8;
}


bool MyGUI::openb(std::ifstream &ifs)
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

void MyGUI::save(std::ofstream &ofs2)
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



void MyGUI::SetWindow(MyGUI *mg)
{
	window->getParent()->removeChildWindow(window);
	mg->window->addChildWindow(window);
	
}

void MyGUI::RemoveComboBoxItem(int index)
{
	CEGUI::Combobox* mw = static_cast<CEGUI::Combobox*>(window);
	mw->removeItem(mw->getListboxItemFromIndex(index));
}

void MyGUI::AddListBoxItem(const char *t)
{
#ifdef _WIN32
	static_cast<CEGUI::Listbox*>(window)->addItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)CUnicodeF::sjis_to_utf8(t, &str_size)));
#else
	static_cast<CEGUI::Listbox*>(window)->addItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)t));
#endif
}

void MyGUI::RemoveListBoxItem(int index)
{
	CEGUI::Listbox* mw = static_cast<CEGUI::Listbox*>(window);
	mw->removeItem(mw->getListboxItemFromIndex(index));
}

void MyGUI::AddMultiColumnRow()
{
	static_cast<CEGUI::MultiColumnList*>(window)->addRow();
}

void MyGUI::RemoveMultiColumnRow(int index)
{
	static_cast<CEGUI::MultiColumnList*>(window)->removeRow(index);
}

void MyGUI::RemoveMultiColumnCol(int index)
{
	static_cast<CEGUI::MultiColumnList*>(window)->removeColumn(index);
}

void MyGUI::AddMultiColumnItem(const char *t, int row, int col)
{
#ifdef _WIN32
	static_cast<CEGUI::MultiColumnList*>(window)->setItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)CUnicodeF::sjis_to_utf8(t, &str_size)), row, col);
#else
	static_cast<CEGUI::MultiColumnList*>(window)->setItem(new CEGUI::ListboxTextItem((CEGUI::utf8*)t), row, col);
#endif
}

void MyGUI::SetProgressBarValue(float val)
{
	static_cast<CEGUI::ProgressBar*>(window)->setProgress(val);

}

float MyGUI::GetScrollValue()
{
	float val = static_cast<CEGUI::Scrollbar*>(window)->getScrollPosition();

	return val;
}

void MyGUI::SetScrollValue( float val)
{
	static_cast<CEGUI::Scrollbar*>(window)->setScrollPosition(val);

}

void MyGUI::SetCheckBox(bool val)
{
	static_cast<CEGUI::Checkbox*>(window)->setSelected(val);
}

bool MyGUI::GetCheckBox()
{
	return static_cast<CEGUI::Checkbox*>(window)->isSelected();
}

void MyGUI::moveToFront()
{
	window->moveToFront();
	
}

void MyGUI::moveToBack()
{
	window->moveToBack();
	
}

void MyGUI::moveInFront(MyGUI *mg)
{
	window->moveInFront(mg->window);
	
}

void MyGUI::moveBehind(MyGUI *mg)
{
	window->moveBehind(mg->window);
	
}

void MyGUI::setColor(float r, float g, float b)
{
	CEGUI::colour col = CEGUI::colour(r, g, b);
	CEGUI::ColourRect crect = CEGUI::ColourRect(col);
	window->setProperty("ImageColours", CEGUI::PropertyHelper::colourRectToString(crect));
	
}