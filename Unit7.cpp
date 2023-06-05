//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit6.h"
#include "Unit4.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
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
void __fastcall TForm7::Button1Click(TObject *Sender)
{
	int prow = 7;
	String carrier;

	   if (ListBox1->ItemIndex==0)
		   carrier="Dvd";
	else if (ListBox1->ItemIndex==1)
		   carrier="Кассета";
	else if (ListBox1->ItemIndex==2)
			carrier="Flash-накопитель";
	else if (ListBox1->ItemIndex==3)
			carrier="Hdd";
	else if (ListBox1->ItemIndex==4)
			carrier="Облако";
	else if (ListBox1->ItemIndex==5)
			carrier="Другое";

	int pr = 0;
	if (not(ListBox1->ItemIndex==-1)){

		int cnt = 1;
		int nrow = 1;

		for (int i = 1; i < Form1->StringGrid1->RowCount; i++){

			if (Form1->StringGrid1->Cells[prow][i] == carrier) {
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
		Form7->ListBox1->ItemIndex=-1;
		Form4->Show();
		Form7->Hide();
		Form4->Label2->Caption = pr;
	}else{
		Form7->ListBox1->SetFocus();
		Application->MessageBox(L"Ничего не найдено",L"Что-то пошло не так", MB_OK);
	}
}
//---------------------------------------------------------------------------
