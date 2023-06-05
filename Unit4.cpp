//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include<fstream>
#include "Unit4.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

String currentfilename;
String filename;
bool save=true;
int first = 0;

struct Films
{
	int id;
	char name[30];
	char director[30];
	char actors[30];
	char year[30];
	char time[30];
	char genre[30];
	char carrier[30];
};

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0]="№";
	StringGrid1->Cells[1][0]="Название фильма";
	StringGrid1->Cells[2][0]="Режиссер";
	StringGrid1->Cells[3][0]="Главная роль";
	StringGrid1->Cells[4][0]="Год";
	StringGrid1->Cells[5][0]="Дл-ть,мин.";
	StringGrid1->Cells[6][0]="Жанр";
	StringGrid1->Cells[7][0]="Вид носителя";
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{

	SaveDialog1->Filter = "Binary files (*.bin)|*.bin";
	SaveDialog1->DefaultExt = "bin";
	if (SaveDialog1->Execute())
{

	currentfilename = SaveDialog1->FileName; // Обновляем currentfilename

	if (first==0)
	{
		 filename=currentfilename;
	}

	if ((currentfilename==filename)&&(first==1))
	{

	}
	else
	{
	std::ofstream outFile(currentfilename.c_str(), std::ios::out | std::ios::binary);
	if (!outFile) {
	ShowMessage("Ошибка при сохранении файла");
	}
	else
	{
		Films film;
		int op=1;
		for (int i = 1; i < StringGrid1->RowCount-1; i++)
		{ // Начинаем с 1, чтобы пропустить заголовок
			film.id=op;
			op++;
			strncpy(film.name, AnsiString(StringGrid1->Cells[1][i]).c_str(), sizeof(film.name));
			strncpy(film.director, AnsiString(StringGrid1->Cells[2][i]).c_str(), sizeof(film.director));
			strncpy(film.actors, AnsiString(StringGrid1->Cells[3][i]).c_str(), sizeof(film.actors));
			strncpy(film.year, AnsiString(StringGrid1->Cells[4][i]).c_str(), sizeof(film.year));
			strncpy(film.time, AnsiString(StringGrid1->Cells[5][i]).c_str(), sizeof(film.time));
			strncpy(film.genre, AnsiString(StringGrid1->Cells[6][i]).c_str(), sizeof(film.genre));
			strncpy(film.carrier, AnsiString(StringGrid1->Cells[7][i]).c_str(), sizeof(film.carrier));
			outFile.write((char*)&film, sizeof(Films));
		}
		outFile.close();
		ShowMessage("Файл успешно сохранен");
		first=1;
		save=true;
	}
	}
}
}
//---------------------------------------------------------------------------


