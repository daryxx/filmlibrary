//---------------------------------------------------------------------------
#include <String>
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

String genre;
String carrier;
bool clos=false;
bool clos1=true;


void repeat()
{
	if (Form2->ListBox1->ItemIndex==-1)
	{
		 Application->MessageBox(L"Выберете жанр",L"Предупреждение", MB_OK);
	}
	if (Form2->ListBox2->ItemIndex==-1)
	{
		 Application->MessageBox(L"Выберете вид носителя",L"Предупреждение", MB_OK);
	}
	if (Form2->Edit1->Text.IsEmpty())
	{
		 Application->MessageBox(L"Введите название фильма",L"Предупреждение", MB_OK);
		 Form2->Edit1->SetFocus();
	}
	if (Form2->Edit2->Text.IsEmpty())
	{
		 Application->MessageBox(L"Укажите режиссера",L"Предупреждение", MB_OK);
		 Form2->Edit2->SetFocus();
	}
	if (Form2->Edit3->Text.IsEmpty())
	{
		 Application->MessageBox(L"Введите главного/ых актера/ов",L"Предупреждение", MB_OK);
		 Form2->Edit3->SetFocus();
	}
	if (Form2->MaskEdit1->Text.IsEmpty())
	{
		 Application->MessageBox(L"Укажите год выпуска",L"Предупреждение", MB_OK);
		 Form2->MaskEdit1->SetFocus();
	}
	if (Form2->Edit4->Text.IsEmpty())
	{
		 Application->MessageBox(L"Укажите сколько минут длится фильм",L"Предупреждение", MB_OK);
		 Form2->Edit4->SetFocus();
	}
	return;
}

void choosegenre(TListBox *ListBox1)
{
	   if (ListBox1->ItemIndex==0)
		   genre="Комедия";
	else if (ListBox1->ItemIndex==1)
		   genre="Фантастика";
	else if (ListBox1->ItemIndex==2)
			genre="Фэнтези";
	else if (ListBox1->ItemIndex==3)
			genre="Блокбастер";
	else if (ListBox1->ItemIndex==4)
			genre="Триллер";
	else if (ListBox1->ItemIndex==5)
			genre="Анимация";
	else if (ListBox1->ItemIndex==6)
			genre="Драма";
	else if (ListBox1->ItemIndex==7)
			genre="Детектив";
	else if (ListBox1->ItemIndex==8)
			genre="Ужасы";
	else if (ListBox1->ItemIndex==9)
			genre="Другое";
}

void choosecarrier(TListBox *ListBox2)
{
	   if (ListBox2->ItemIndex==0)
		   carrier="Dvd";
	else if (ListBox2->ItemIndex==1)
		   carrier="Кассета";
	else if (ListBox2->ItemIndex==2)
			carrier="Flash-накопитель";
	else if (ListBox2->ItemIndex==3)
			carrier="Hdd";
	else if (ListBox2->ItemIndex==4)
			carrier="Облако";
	else if (ListBox2->ItemIndex==5)
			carrier="Другое";
}

void changing(String* text)
{
	String text1;
	text1=AnsiLowerCase(*text);   //в нижнем регистре

	String text2=AnsiUpperCase(text1[1]); //верхний и нижние

	for (int i=2; i <= text1.Length(); i++)
	{
	   if (text1[i-1]==' ')
	   {
		  text2=text2+AnsiUpperCase(text1[i]);
	   }
	   else
			text2=text2+text1[i];
	}

	*text=text2;
}


//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
};
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if (not(Edit1->Text.IsEmpty())&&not(Edit2->Text.IsEmpty())&&not(Edit3->Text.IsEmpty())&&not(MaskEdit1->Text.IsEmpty())&&not(Edit4->Text.IsEmpty())&&(Form2->ListBox1->ItemIndex!=-1)&&(Form2->ListBox2->ItemIndex!=-1))
	{
		int nrow;      //запись в таблицу

		if (Form2->Caption=="Добавление")
		{
			nrow=Form1->StringGrid1->RowCount-1;

			Form1->StringGrid1->Cells[0][nrow]=IntToStr(Form1->StringGrid1->RowCount-1);
			++Form1->StringGrid1->RowCount;
		}
		else
		{
		  nrow=Form1->StringGrid1->Selection.Top;
		}

		String fn=Edit1->Text;
		changing(&fn);
		Edit1->Text=fn;

		fn=Edit2->Text;
		changing(&fn);
		Edit2->Text=fn;

		fn=Edit3->Text;
		changing(&fn);
		Edit3->Text=fn;

		Form1->StringGrid1->Cells[0][nrow]=nrow;
		Form1->StringGrid1->Cells[1][nrow]=Edit1->Text;
		Form1->StringGrid1->Cells[2][nrow]=Edit2->Text;
		Form1->StringGrid1->Cells[3][nrow]=Edit3->Text;
		Form1->StringGrid1->Cells[4][nrow]=MaskEdit1->Text;
		Form1->StringGrid1->Cells[5][nrow]=Edit4->Text;

		choosegenre(ListBox1);
		Form1->StringGrid1->Cells[6][nrow]=genre;

		choosecarrier(ListBox2);
		Form1->StringGrid1->Cells[7][nrow]=carrier;

		Form2->Edit1->Clear();   // очистка формы ввода
		Form2->Edit2->Clear();
		Form2->Edit3->Clear();
		Form2->MaskEdit1->Clear();
		Form2->Edit4->Clear();
		Form2->ListBox1->ItemIndex=-1;
		Form2->ListBox2->ItemIndex=-1;

		Form1->Show();
		Form2->Hide();

		clos=true;
		clos1=true;

	}
	else
	{
		repeat();
		clos=false;
		clos1=false;
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN){

			if (Sender==Edit1){
				Edit2 -> SetFocus();
			}

			if (Sender==Edit2){
				Edit3 -> SetFocus();
			}

			if (Sender==Edit3){
				MaskEdit1 -> SetFocus();
			}

			if (Sender==MaskEdit1){
				Edit4 -> SetFocus();
			}

			if (Sender==Edit4){
				ListBox1 -> SetFocus();
			}

			if (Sender==ListBox1){
				ListBox2 -> SetFocus();
			}

			if (Sender==ListBox2){
				Button1 -> SetFocus();
			}
	}

	if ((Sender== Edit4)||(Sender== MaskEdit1)) {
		if( Key == VK_BACK ) // клавиша <Backspace>
			return;

		if (((Key >= '0') && (Key <= '9'))||( Key == VK_RETURN )){
			return;

		}
		else{
			Application->MessageBox(L"Недопустимый символ",L"Предупреждение", MB_OK);
			Key = 0 ; // не отображать символ
		}
	}
	else
	{
		if( Key == VK_BACK )
			return;

		if (Sender== Edit1) {
			if( Key == VK_BACK )
				return;
			if ( ( (Key >= 1040) && (Key <= 1105) )|| (Key==45) || ( Key == VK_RETURN ) || ( Key == VK_SPACE ) || ( Key == 44 ) || ((Key >= '0') && (Key <= '9')) ){
				return;
			}
			else{
				Application->MessageBox(L"Недопустимый символ",L"Предупреждение", MB_OK);
				Key = 0 ; // не отображать символ
			}
		}
		else{

			if ( ( (Key >= 1040) && (Key <= 1105) )|| (Key==45) || ( Key == VK_RETURN ) || ( Key == VK_SPACE ) || ( Key == 44 ) ){
				return;
			}
			else{
				Application->MessageBox(L"Недопустимый символ",L"Предупреждение", MB_OK);
				Key = 0 ; // не отображать символ
			}
		}
	}
		if (VK_RETURN == Key) // клавиша <Enter>
		{

			if (Sender==Edit1) {
				Edit2 -> SetFocus();
			}

			if ((Sender==Edit1)&&(!Edit1->Text.IsEmpty())){
				String fn=Edit1->Text;
				changing(&fn);
				Edit1->Text=fn;
			}

			if ((Sender==Edit2)&&(!Edit2->Text.IsEmpty())){
				String fn=Edit2->Text;
				changing(&fn);
				Edit2->Text=fn;
			}

			if ((Sender==Edit3)&&(!Edit3->Text.IsEmpty())){
				String fn=Edit3->Text;
				changing(&fn);
				Edit3->Text=fn;
			}

		}
}



//Закрытие формы---------------------------------------------------------------------------

void __fastcall TForm2::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if ((clos==true)&&(clos1==true))
	{
		CanClose=true;
	}
	else{
		 if (Form2->Caption=="Добавление")
		 {
			if ((Application->MessageBox(L"Вы уверены, что хотите закрыть окно ? Данные не будут добавлены!", L"Предупреждение", MB_YESNO)==IDYES))
			{
				CanClose=true;

				Form2->Edit1->Clear();   // очистка формы ввода
				Form2->Edit2->Clear();
				Form2->Edit3->Clear();
				Form2->MaskEdit1->Clear();
				Form2->Edit4->Clear();
				Form2->ListBox1->ItemIndex=-1;
				Form2->ListBox2->ItemIndex=-1;

				Form1->Show();
			}
			else
				CanClose=false;
		 }
		 else
		 {

		 if ((Application->MessageBox(L"Вы уверены, что хотите закрыть окно ? Изменения не будут сохранены!", L"Предупреждение", MB_YESNO)==IDYES))
		  {
				CanClose=true;

				Form2->Edit1->Clear();   // очистка формы ввода
				Form2->Edit2->Clear();
				Form2->Edit3->Clear();
				Form2->MaskEdit1->Clear();
				Form2->Edit4->Clear();
				Form2->ListBox1->ItemIndex=-1;
				Form2->ListBox2->ItemIndex=-1;

				Form1->Show();
		  }
		  else
				CanClose=false;
		 }
	}
	  clos=false;
	  clos1=true;

}

//---------------------------------------------------------------------------

