//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit5.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

void repeat()
{
	if (Form3->Edit1->Text.IsEmpty())
	{
		 Application->MessageBox(L"Введите данные для поиска",L"Предупреждение", MB_OK);
		 Form3->Edit1->SetFocus();
	}
}
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------

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


void __fastcall TForm3::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key==VK_RETURN){
		Button1->SetFocus();
	}

	if( Key == VK_BACK )
		return;

	if (((Key >= 1040) && (Key <= 1105))||((Key >= '0') && (Key <= '9'))||(Key==45)||(Key==32)||( Key == 44 )||( Key == VK_RETURN )){
		return;
	}
	else{
		Application->MessageBox(L"Недопустимый символ",L"Предупреждение", MB_OK);
		Key = 0;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
	int prow = 0;
	if (Form3->Caption == "Поиск по названию фильма") {
		prow = 1;
	}
	if (Form3->Caption == "Поиск по режиссёру") {
		prow = 2;
	}
	if (Form3->Caption == "Поиск по исполнителю главной роли") {
		prow = 3;
	}
	if (Form3->Caption == "Поиск по году выпуска") {
		prow = 4;
	}
	if (Form3->Caption == "Поиск по длительности") {
		prow = 5;
	}

	bool control;
	String word = Form3 -> Edit1-> Text;
	if (Form1->StringGrid1->Cells[1][1].IsEmpty())
		ShowMessage("Список пока что пуст");
	else
	{
		bool control=false;
		for (int i=1; i < Form4->StringGrid1->RowCount; i++)
			for (int j=0; j < Form4->StringGrid1->ColCount; j++)
				Form4->StringGrid1->Cells[j][i]="";
		Form4->StringGrid1->RowCount=2;
		String word1;
		word1=AnsiLowerCase(word); //в нижнем регистре
		String word2=AnsiUpperCase(word1[1]); //верхний и нижние
		for (int i=2; i <= word1.Length(); i++)
		{
			word2=word2+word1[i];
		}
		int c=1;
		for (int i=1; i < Form1->StringGrid1->RowCount; i++)
		{
			if ((Form1->StringGrid1->Cells[prow][i].Pos(word1)==1)||(Form1->StringGrid1->Cells[prow][i].Pos(word2)==1))
			{
				Form4->StringGrid1->Cells[0][c]=c;
				Form4->StringGrid1->Cells[1][c]=Form1->StringGrid1->Cells[1][i];
				Form4->StringGrid1->Cells[2][c]=Form1->StringGrid1->Cells[2][i];
				Form4->StringGrid1->Cells[3][c]=Form1->StringGrid1->Cells[3][i];
				Form4->StringGrid1->Cells[4][c]=Form1->StringGrid1->Cells[4][i];
				Form4->StringGrid1->Cells[5][c]=Form1->StringGrid1->Cells[5][i];
				Form4->StringGrid1->Cells[6][c]=Form1->StringGrid1->Cells[6][i];
				Form4->StringGrid1->Cells[7][c]=Form1->StringGrid1->Cells[7][i];
				c++;
				Form4->StringGrid1->RowCount++;
				control=true;
			}
		}
		if (control==true)
			Form4->Show();
		else
			ShowMessage("По запросу ничего не найдено. Для успешного поиска убедитесь, что текст введен без лишних пробелов.");

	}

}

//---------------------------------------------------------------------------

