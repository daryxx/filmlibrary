//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit4.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}

void repeat()
{
	if (Form6->ListBox1->ItemIndex==-1)
	{
		 Application->MessageBox(L"Выберете данные для поиска!",L"Предупреждение", MB_OK);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
	int prow = 6;
	String genre;


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

	int pr = 0;
	if (not(ListBox1->ItemIndex==-1)){

		int cnt = 1;
		int nrow = 1;

		for (int i = 1; i < Form1->StringGrid1->RowCount; i++){

			if (Form1->StringGrid1->Cells[prow][i] == genre) {
				pr++;

				Form4->StringGrid1->Cells[0][nrow]=nrow;
				Form4->StringGrid1->Cells[1][nrow]=Form1->StringGrid1->Cells[1][cnt];
				Form4->StringGrid1->Cells[2][nrow]=Form1->StringGrid1->Cells[2][cnt];
				Form4->StringGrid1->Cells[3][nrow]=Form1->StringGrid1->Cells[3][cnt];
				Form4->StringGrid1->Cells[4][nrow]=Form1->StringGrid1->Cells[4][cnt];
				Form4->StringGrid1->Cells[5][nrow]=Form1->StringGrid1->Cells[5][cnt];
				Form4->StringGrid1->Cells[6][nrow]=Form1->StringGrid1->Cells[6][cnt];
				Form4->StringGrid1->Cells[7][nrow]=Form1->StringGrid1->Cells[7][cnt];

				Form4->StringGrid1->RowCount++;
				nrow++;
				cnt++;
			}
			else{
				cnt++;
			}

		}

	}
	else{
		repeat();
	}

	if (pr!=0) {
		Form6->ListBox1->ItemIndex=-1;
		Form4->Show();
		Form6->Hide();
		Form4->Label2->Caption = pr;
	}else{
		Form6->ListBox1->SetFocus();
		Application->MessageBox(L"Ничего не найдено",L"Что-то пошло не так", MB_OK);
	}

}
//---------------------------------------------------------------------------
