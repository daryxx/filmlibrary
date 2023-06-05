//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include<fstream>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;

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

int pkmchoosegenre(String genre)
{
	   if (genre=="Комедия")
		   return 0;
	else if (genre=="Фантастика")
		   return 1;
	else if (genre=="Фэнтези")
			return 2;
	else if (genre=="Блокбастер")
			return 3;
	else if (genre=="Триллер")
			return 4;
	else if (genre=="Анимация")
			return 5;
	else if (genre=="Драма")
			return 6;
	else if (genre=="Детектив")
			return 7;
	else if (genre=="Ужасы")
			return 8;
	else if (genre=="Другое")
			return 9;
}

int pkmchoosecarrier(String carrier)
{
	   if (carrier=="Dvd")
		   return 0;
	else if (carrier=="Кассета")
		   return 1;
	else if (carrier=="Flash-накопитель")
			return 2;
	else if (carrier=="Hdd")
			return 3;
	else if (carrier=="Облако")
			return 4;
	else if (carrier=="Другое")
			return 5;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

	Form5 = new TForm5(Application);
	Form5->ShowModal();
	delete Form5;

	StringGrid1->Cells[0][0]="№";
	StringGrid1->Cells[1][0]="Название фильма";
	StringGrid1->Cells[2][0]="Режиссер";
	StringGrid1->Cells[3][0]="Главная роль";
	StringGrid1->Cells[4][0]="Год";
	StringGrid1->Cells[5][0]="Дл-ть,мин.";
	StringGrid1->Cells[6][0]="Жанр";
	StringGrid1->Cells[7][0]="Вид носителя";

	N3->Enabled=false;
	N4->Enabled=false;
	N11->Enabled=false;
	N12->Enabled=false;
	N13->Enabled=false;
	N14->Enabled=false;
	N19->Enabled=false;
	N20->Enabled=false;
	N21->Enabled=false;
	N45->Enabled=false;
	N46->Enabled=false;

	ToolButton1->ImageIndex=0;
	ToolButton2->ImageIndex=1;
	ToolButton3->ImageIndex=2;
	ToolButton4->ImageIndex=3;
	ToolButton6->ImageIndex=4;
	ToolButton7->ImageIndex=5;
	ToolButton8->ImageIndex=6;
	ToolButton10->ImageIndex=7;
	ToolButton11->ImageIndex=8;
	ToolButton12->ImageIndex=9;
	ToolButton13->ImageIndex=10;

	ToolButton2->Enabled=false;
	ToolButton3->Enabled=false;
	ToolButton7->Enabled=false;
	ToolButton8->Enabled=false;
	ToolButton10->Enabled=false;
	ToolButton11->Enabled=false;
	ToolButton12->Enabled=false;

    StatusBar1->Panels->Items[0]->Text="Пока нет открытых файлов";
	 StatusBar1->Panels->Items[1]->Text="Нет выделенной строки";
	 StatusBar1->Panels->Items[2]->Text="Нет выделенной ячейки";

}
//Очистка таблицы на 4 форме
void cleartab(){
	for(int i=0;i<Form4->StringGrid1->ColCount;i++) {
		for(int j=1; j<Form4->StringGrid1->RowCount;j++) {
			Form4->StringGrid1->Cells[i][j] = "";
	}
  }
  Form4->StringGrid1->RowCount=2;
}

//Сортировка-----------------------
void sort(int col, int ch){
	if (Form1->StringGrid1->Cells[0][2].IsEmpty())
	{
		ShowMessage("Слишком мало записей для сортировки!");
	}
	else
	{
	if (ch==1) {
	int i,j;
	 for (i=1; i < Form1->StringGrid1->RowCount-1; i++)
		for (j=i+1; j < Form1->StringGrid1->RowCount-1; j++)
		{
			if (AnsiCompareStr(Form1->StringGrid1->Cells[col][i],Form1->StringGrid1->Cells[col][j])>0)
			{
				 Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount]=Form1->StringGrid1->Rows[i];
				 Form1->StringGrid1->Rows[i]=Form1->StringGrid1->Rows[j];
				 Form1->StringGrid1->Rows[j]=Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount];
			}
		}
		for (j=1; j < Form1->StringGrid1->RowCount-1; j++)
			  Form1->StringGrid1->Cells[0][j]=IntToStr(j);
	}
	else
	{
	 int i,j;
	 for (i=1; i < Form1->StringGrid1->RowCount-1; i++)
		for (j=i+1; j < Form1->StringGrid1->RowCount-1; j++)
		{
			if (AnsiCompareStr(Form1->StringGrid1->Cells[col][i],Form1->StringGrid1->Cells[col][j])<0)
			{
				 Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount]=Form1->StringGrid1->Rows[i];
				 Form1->StringGrid1->Rows[i]=Form1->StringGrid1->Rows[j];
				 Form1->StringGrid1->Rows[j]=Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount];
			}
		}
		for (j=1; j < Form1->StringGrid1->RowCount-1; j++)
			  Form1->StringGrid1->Cells[0][j]=IntToStr(j);
	}
}

}

//Сортировка для цифр

void sort2(int ch)
{
if (Form1->StringGrid1->Cells[0][2].IsEmpty())
	{
		ShowMessage("Слишком мало записей для сортировки!");
	}
	else
	{
	if (ch==1) {
	int i,j;
	 for (i=1; i < Form1->StringGrid1->RowCount-1; i++)
		for (j=i+1; j < Form1->StringGrid1->RowCount-1; j++)
		{
			if (StrToInt(Form1->StringGrid1->Cells[5][i])>StrToInt(Form1->StringGrid1->Cells[5][j]))
			{
				 Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount]=Form1->StringGrid1->Rows[i];
				 Form1->StringGrid1->Rows[i]=Form1->StringGrid1->Rows[j];
				 Form1->StringGrid1->Rows[j]=Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount];
			}
		}
		for (j=1; j < Form1->StringGrid1->RowCount-1; j++)
			  Form1->StringGrid1->Cells[0][j]=IntToStr(j);
	}
	else
	{
	 int i,j;
	 for (i=1; i < Form1->StringGrid1->RowCount-1; i++)
		for (j=i+1; j < Form1->StringGrid1->RowCount-1; j++)
		{
			if (StrToInt(Form1->StringGrid1->Cells[5][i])<StrToInt(Form1->StringGrid1->Cells[5][j]))
			{
				 Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount]=Form1->StringGrid1->Rows[i];
				 Form1->StringGrid1->Rows[i]=Form1->StringGrid1->Rows[j];
				 Form1->StringGrid1->Rows[j]=Form1->StringGrid1->Rows[Form1->StringGrid1->RowCount];
			}
		}
		for (j=1; j < Form1->StringGrid1->RowCount-1; j++)
			  Form1->StringGrid1->Cells[0][j]=IntToStr(j);
	}
}

}


//Добавление---------------------------------------------------------------------------
void __fastcall TForm1::N10Click(TObject *Sender)
{
	Form2->Button1->Caption="Добавить";
	Form2->Caption="Добавление";
	Form2->Show();
	Form2->Edit1->SetFocus();

	N3->Enabled=true;
	N4->Enabled=true;
	N11->Enabled=true;
	N12->Enabled=true;
	N13->Enabled=true;
	N14->Enabled=true;
	N19->Enabled=true;
	N20->Enabled=true;
	N21->Enabled=true;
	N45->Enabled=true;
	N46->Enabled=true;

	ToolButton2->Enabled=true;
	ToolButton3->Enabled=true;
	ToolButton7->Enabled=true;
	ToolButton8->Enabled=true;
	ToolButton10->Enabled=true;
	ToolButton11->Enabled=true;
	ToolButton12->Enabled=true;

	if (StringGrid1->RowCount <= 2) {
		N3->Enabled=false;
		N4->Enabled=false;
		N11->Enabled=false;
		N12->Enabled=false;
		N13->Enabled=false;
		N14->Enabled=false;
		N19->Enabled=false;
		N20->Enabled=false;
		N21->Enabled=false;
        N45->Enabled=false;
		N46->Enabled=false;

		ToolButton2->Enabled=false;
		ToolButton3->Enabled=false;
		ToolButton7->Enabled=false;
		ToolButton8->Enabled=false;
		ToolButton10->Enabled=false;
		ToolButton11->Enabled=false;
		ToolButton12->Enabled=false;
	}

    save=false;
}
//Редактирование---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
    int nm = StringGrid1->Selection.Top;
	Form2->Button1->Caption="Редактировать";
	Form2->Caption="Редактирование";
	Form2->Edit1->Text=Form1->StringGrid1->Cells[1][nm];
	Form2->Edit2->Text=Form1->StringGrid1->Cells[2][nm];
	Form2->Edit3->Text=Form1->StringGrid1->Cells[3][nm];
	Form2->MaskEdit1->Text=Form1->StringGrid1->Cells[4][nm];
	Form2->Edit4->Text=Form1->StringGrid1->Cells[5][nm];

	if (Form2->ListBox1->ItemIndex==0) {
		StringGrid1->Cells[6][nm] = "Комедия";
	}
	if (Form2->ListBox1->ItemIndex==1) {
		StringGrid1->Cells[6][nm] = "Фантастика";
	}
	if (Form2->ListBox1->ItemIndex==2) {
		StringGrid1->Cells[6][nm] = "Фэнтези";
	}
	if (Form2->ListBox1->ItemIndex==3) {
		StringGrid1->Cells[6][nm] = "Блокбастер";
	}
	if (Form2->ListBox1->ItemIndex==4) {
		StringGrid1->Cells[6][nm] = "Триллер";
	}
	if (Form2->ListBox1->ItemIndex==5) {
		StringGrid1->Cells[6][nm] = "Анимация";
	}
	if (Form2->ListBox1->ItemIndex==6) {
		StringGrid1->Cells[6][nm] = "Драма/мелодрама";
	}
	if (Form2->ListBox1->ItemIndex==7) {
		StringGrid1->Cells[6][nm] = "Детектив";
	}
	if (Form2->ListBox1->ItemIndex==8) {
		StringGrid1->Cells[6][nm] = "Ужасы";
	}
	if (Form2->ListBox1->ItemIndex==9) {
		StringGrid1->Cells[6][nm] = "Другое";
	}

    if (Form2->ListBox1->ItemIndex==0) {
		StringGrid1->Cells[6][nm] = "DVD/Blu-ray";
	}
	if (Form2->ListBox1->ItemIndex==1) {
		StringGrid1->Cells[6][nm] = "Кассета";
	}
	if (Form2->ListBox1->ItemIndex==2) {
		StringGrid1->Cells[6][nm] = "flash-накопитель";
	}
	if (Form2->ListBox1->ItemIndex==3) {
		StringGrid1->Cells[6][nm] = "HDD/SDD";
	}
	if (Form2->ListBox1->ItemIndex==4) {
		StringGrid1->Cells[6][nm] = "Облако";
	}
	if (Form2->ListBox1->ItemIndex==5) {
		StringGrid1->Cells[6][nm] = "Другое";
	}

    save=false;
	Form2->Show();
	Form2->Edit1->SetFocus();

}
//Открыть---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
if (save==false)
{
   if (Application->MessageBox(L"Хотите сохранить изменения в текущем файле?",L"Предупреждение", MB_YESNO)==IDYES)
		{
		TForm1::N3Click(SaveDialog2);
		TForm1::N2Click(OpenDialog1);
		}
   else
   {
	   save=true;
	   TForm1::N2Click(OpenDialog1);
   }
}
else
{
	OpenDialog1->Filter = "Binary files (*.bin)|*.bin";
	OpenDialog1->DefaultExt = "bin";
	if (OpenDialog1->Execute())
	{

	for(int i=0;i<Form4->StringGrid1->ColCount;i++) {
		for(int j=1; j<Form1->StringGrid1->RowCount;j++) {
			Form1->StringGrid1->Cells[i][j] = "";
		}
	}
	Form1->StringGrid1->RowCount=2;

		std::ifstream inFile(OpenDialog1->FileName.c_str(), std::ios::in | std::ios::binary);
		if (!inFile)
		{
			ShowMessage("Ошибка при открытии файла");
		}
		else
		{
			filename = OpenDialog1->FileName; // Обновляем filename

			Films film;
			StringGrid1->RowCount = 2; // Заголовок и первая строка данных
			while (inFile.read((char*)&film, sizeof(Films)))
			{
				StringGrid1->Cells[0][StringGrid1->RowCount - 1] = IntToStr(film.id);
				StringGrid1->Cells[1][StringGrid1->RowCount - 1] = film.name;
				StringGrid1->Cells[2][StringGrid1->RowCount - 1] = film.director;
				StringGrid1->Cells[3][StringGrid1->RowCount - 1] = film.actors;
				StringGrid1->Cells[4][StringGrid1->RowCount - 1] = film.year;
				StringGrid1->Cells[5][StringGrid1->RowCount - 1] = film.time;
				StringGrid1->Cells[6][StringGrid1->RowCount - 1] = film.genre;
				StringGrid1->Cells[7][StringGrid1->RowCount - 1] = film.carrier;
				StringGrid1->RowCount++;
			}

			inFile.close();

			if (StringGrid1->RowCount > 2) {
				N3->Enabled=true;
				N4->Enabled=true;
				N11->Enabled=true;
				N12->Enabled=true;
				N13->Enabled=true;
				N14->Enabled=true;
				N19->Enabled=true;
				N20->Enabled=true;
				N21->Enabled=true;
				N45->Enabled=true;
				N46->Enabled=true;

				ToolButton2->Enabled=true;
				ToolButton3->Enabled=true;
				ToolButton7->Enabled=true;
				ToolButton8->Enabled=true;
				ToolButton10->Enabled=true;
				ToolButton11->Enabled=true;
				ToolButton12->Enabled=true;
			}

			first=1;
			save=true;
			StatusBar1->Panels->Items[0]->Text=filename;
	}
}


}
}
//сохранить---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
	SaveDialog2->Filter = "Binary files (*.bin)|*.bin";
	SaveDialog2->DefaultExt = "bin";

	std::ofstream outFile(filename.c_str(), std::ios::out | std::ios::binary);
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
		save=true;
		StatusBar1->Panels->Items[0]->Text=filename;
	}

}
//Сохранить как---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
	SaveDialog1->Filter = "Binary files (*.bin)|*.bin";
	SaveDialog1->DefaultExt = "bin";
	if (SaveDialog1->Execute())
{

	currentfilename = SaveDialog1->FileName; // Обновляем currentfilename

	if (first==0)
	{
		 filename=currentfilename;
		 StatusBar1->Panels->Items[0]->Text=filename;
	}

	if ((currentfilename==filename)&&(first==1))
	{
		 if (Application->MessageBox(L"Хотите перезаписать файл?", L"Предупреждение", MB_YESNO)==IDYES)
			TForm1::N3Click(SaveDialog2);
		 else
			 TForm1::N4Click(SaveDialog1);
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
		N3->Enabled=true;
		save=true;
	}
}
}


}
//Удаление---------------------------------------------------------------------------

void __fastcall TForm1::N12Click(TObject *Sender)
{
	int nc=StringGrid1->Row;
	wchar_t buff[200];


	if (MessageBoxW(0,StringToWideChar(("Уверены, что хотите удалить <<"+StringGrid1->Cells[1][nc]+">> ?"),buff,200),L"Предупреждение",MB_YESNO)==IDYES){
		int ARow=1,i,j;
		for (i=ARow+1;i<StringGrid1->RowCount;i++)
			for (j=0;j<StringGrid1->ColCount;j++)
				StringGrid1->Cells[j][i-1]=StringGrid1->Cells[j][i];
		for (i=0;i<StringGrid1->ColCount;i++)
			StringGrid1->Cells[i][StringGrid1->RowCount-1]="";
		StringGrid1->RowCount--;
        save = false;
	}

	if (StringGrid1->RowCount == 2) {
		N3->Enabled=false;
		N4->Enabled=false;
		N11->Enabled=false;
		N12->Enabled=false;
		N13->Enabled=false;
		N14->Enabled=false;
		N19->Enabled=false;
		N20->Enabled=false;
		N21->Enabled=false;
		N45->Enabled=false;
		N46->Enabled=false;

		ToolButton2->Enabled=false;
		ToolButton3->Enabled=false;
		ToolButton7->Enabled=false;
		ToolButton8->Enabled=false;
		ToolButton10->Enabled=false;
		ToolButton11->Enabled=false;
		ToolButton12->Enabled=false;
	}

}
//Выход---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
    if ((Application->MessageBox(L"Вы уверены, что хотите выйти?", L"Предупреждение", MB_YESNO)==IDYES))
	{
		if (!save)
		{

			 if (Application->MessageBox(L"Хотите сохранить текущий файл?", L"Предупреждение", MB_YESNO)==IDYES)
			 {
				if (first==1)
				   TForm1::N3Click(SaveDialog2);
				else
					TForm1::N4Click(SaveDialog1);
			 }
			 Form1->Close();
		}
		else
			Form1->Close();
	}

}
//Задание---------------------------------------------------------------------------

void __fastcall TForm1::N17Click(TObject *Sender)
{
	Application->MessageBox(L"Вариант 10. Составить программу «Фильмотека». Структура исходных данных: название фильма, режиссер, исполнители главных ролей, год выпуска, длительность, жанр, вид носителя (кассета, DVD, MP 4). Организовать поиск фильмов по жанру, исполнителю главной роли. Рассчитать сколько фильмов этого года есть в вашей фильмотеке. Определить, фильмов какого режиссера в вашей фильмотеке больше. Найти самого разнопланового актера (актрису), т.е. снявшегося в наибольшем количестве фильмов разного жанра.",L"Задание", MB_OK);

	}
//Справка---------------------------------------------------------------------------

void __fastcall TForm1::N18Click(TObject *Sender)
{
	String fn = L"D:\\универ\\курсач\\Новая папка (2)\\Справка.txt"; // тут путь к файлу
	ShellExecute(0, L"open", fn.c_str(), NULL, 0, SW_SHOWNORMAL);

}
//О программе---------------------------------------------------------------------------

void __fastcall TForm1::N22Click(TObject *Sender)
{
	Application->MessageBox(L"Версия продукта 1.0. Последние изменения внесены 30.05.2023. Автор: darya.svinina03@mail.ru",L"О программе", MB_OK);
}
//Поиск по названию фильма-------------------------------------------------------------

void __fastcall TForm1::N28Click(TObject *Sender)
{
	cleartab();
	Form3->Caption = "Поиск по названию фильма";
	Form3->Show();
	//Form4->Label1->Caption = "Результаты поиск по названию фильма";

}
//Поиск по режиссёру---------------------------------------------------------------------------

void __fastcall TForm1::N29Click(TObject *Sender)
{
	cleartab();
	Form3->Caption = "Поиск по режиссёру";
	Form3->Show();
	Form3->Edit1->SetFocus();
	//Form4->Label1->Caption = "Результаты поиск по режиссёру";

}
//Поиск по исп-лю гл. роли---------------------------------------------------------------------------

void __fastcall TForm1::N30Click(TObject *Sender)
{
	cleartab();
	Form3->Caption = "Поиск по исполнителю главной роли";
	Form3->Show();
	Form3->Edit1->SetFocus();
	//Form4->Label1->Caption = "Результаты поиск по исполнителю главной роли";

}
//Поиск по году выпуска---------------------------------------------------------------------------

void __fastcall TForm1::N31Click(TObject *Sender)
{
	cleartab();
	Form3->Caption = "Поиск по году выпуска";
	Form3->Show();
	Form3->Edit1->SetFocus();
	//Form4->Label1->Caption = "Результаты поиск по году выпуска";

}
//Поиск по длительности---------------------------------------------------------------------------

void __fastcall TForm1::N32Click(TObject *Sender)
{
	cleartab();
	Form3->Caption = "Поиск по длительности";
	Form3->Show();
	Form3->Edit1->SetFocus();
	//Form4->Label1->Caption = "Результаты поиск по длительности";

}
//Поиск по жанру---------------------------------------------------------------------------

void __fastcall TForm1::N33Click(TObject *Sender)
{
	cleartab();
	Form6->Caption = "Поиск по жанру";
	Form6->Show();
	Form6->ListBox1->SetFocus();
	//Form4->Label1->Caption = "Результаты поиск по жанру";

}
//Поиск по носителю---------------------------------------------------------------------------

void __fastcall TForm1::N34Click(TObject *Sender)
{
	cleartab();
	Form7->Caption = "Поиск по носителю";
	Form7->Show();
	Form7->ListBox1->SetFocus();
	//Form4->Label1->Caption = "Результаты поиск по носителю";

}
//Сортировки от А до Я
//по названию---------------------------------------------------------------------------

void __fastcall TForm1::N23Click(TObject *Sender)
{
	sort(1, 1);
	save = false;
}
//по реж---------------------------------------------------------------------------

void __fastcall TForm1::N24Click(TObject *Sender)
{
	sort(2, 1);
	save = false;
}
//по актеру---------------------------------------------------------------------------

void __fastcall TForm1::N25Click(TObject *Sender)
{
	sort(3, 1);
	save = false;
}
//по жанру---------------------------------------------------------------------------

void __fastcall TForm1::N35Click(TObject *Sender)
{
	sort(6, 1);
	save = false;
}
//по носителю---------------------------------------------------------------------------

void __fastcall TForm1::N36Click(TObject *Sender)
{
	sort(7, 1);
	save = false;
}
//по году---------------------------------------------------------------------------

void __fastcall TForm1::N26Click(TObject *Sender)
{
	sort(4, 1);
	save = false;
}
//Длит---------------------------------------------------------------------------

void __fastcall TForm1::N27Click(TObject *Sender)
{
	sort2(1);
	save = false;
}
//---------------------------------------------------------------------------
//Сортировки от Я до А
//По названию------------------------------------------------------------------
void __fastcall TForm1::N38Click(TObject *Sender)
{
	sort(1, 0);
	save = false;
}
//Режис---------------------------------------------------------------------------

void __fastcall TForm1::N39Click(TObject *Sender)
{
	sort(2, 0);
	save = false;
}
//Актер---------------------------------------------------------------------------

void __fastcall TForm1::N40Click(TObject *Sender)
{
	sort(3, 0);
	save = false;
}
//Год---------------------------------------------------------------------------

void __fastcall TForm1::N41Click(TObject *Sender)
{
	sort(4, 0);
	save = false;
}
//Длит---------------------------------------------------------------------------

void __fastcall TForm1::N42Click(TObject *Sender)
{
	sort2(0);
	save = false;
}
//Жанр---------------------------------------------------------------------------

void __fastcall TForm1::N43Click(TObject *Sender)
{
	sort(6, 0);
	save = false;
}
//Носит---------------------------------------------------------------------------

void __fastcall TForm1::N44Click(TObject *Sender)
{
 	sort(7, 0);
	save = false;
}
//Сколько фильмов этого года есть---------------------------------------------------------------------------

void __fastcall TForm1::N19Click(TObject *Sender)
{
	cleartab();
	int year = 2023;
	int nrow = 1;
	int pr = 0;
    Form4->Label1->Caption = "Количество фильмов этого года:";
	Form4->Caption = "Фильмы этого года";

	for (int i = 1; i < Form1->StringGrid1->RowCount-1; i++) {
		if (StrToInt(Form1->StringGrid1->Cells[4][i]) == year){
			pr++;

			Form4->StringGrid1->Cells[0][nrow]=nrow;
			Form4->StringGrid1->Cells[1][nrow]=Form1->StringGrid1->Cells[1][i];
			Form4->StringGrid1->Cells[2][nrow]=Form1->StringGrid1->Cells[2][i];
			Form4->StringGrid1->Cells[3][nrow]=Form1->StringGrid1->Cells[3][i];
			Form4->StringGrid1->Cells[4][nrow]=Form1->StringGrid1->Cells[4][i];
			Form4->StringGrid1->Cells[5][nrow]=Form1->StringGrid1->Cells[5][i];
			Form4->StringGrid1->Cells[6][nrow]=Form1->StringGrid1->Cells[6][i];
			Form4->StringGrid1->Cells[7][nrow]=Form1->StringGrid1->Cells[7][i];

			Form4->StringGrid1->RowCount++;
			nrow++;
		}

	}

	if (pr!=0) {
		Form4->Label2->Caption = pr;
		Form4->Show();
	}
	else
		Application->MessageBox(L"Не найдено фильмов этого года!",L"Количество фильмов этого года", MB_OK);

	

}
//Фильмов какого режиссёра больше---------------------------------------------------------------------------

void __fastcall TForm1::N20Click(TObject *Sender)
{
	cleartab();
	int m1 = 0;
	int m2 = 0;
	int z;

	for(int i=1; i<Form1->StringGrid1->RowCount;i++) {
		m1 = 0;
		for(int j=1; j<Form1->StringGrid1->RowCount;j++){
			if (AnsiCompareStr(Form1->StringGrid1->Cells[2][j], Form1->StringGrid1->Cells[2][i]) == 0) {
				m1++;
			}

		}
		if (m1>m2) {
			m2=m1;
			z=i;
		}
	}

	int nrow = 1;

	for (int i = 1; i < Form1->StringGrid1->RowCount-1; i++) {
		if (AnsiCompareStr(Form1->StringGrid1->Cells[2][i], Form1->StringGrid1->Cells[2][z]) == 0) {

			Form4->StringGrid1->Cells[0][nrow]=nrow;
			Form4->StringGrid1->Cells[1][nrow]=Form1->StringGrid1->Cells[1][i];
			Form4->StringGrid1->Cells[2][nrow]=Form1->StringGrid1->Cells[2][i];
			Form4->StringGrid1->Cells[3][nrow]=Form1->StringGrid1->Cells[3][i];
			Form4->StringGrid1->Cells[4][nrow]=Form1->StringGrid1->Cells[4][i];
			Form4->StringGrid1->Cells[5][nrow]=Form1->StringGrid1->Cells[5][i];
			Form4->StringGrid1->Cells[6][nrow]=Form1->StringGrid1->Cells[6][i];
			Form4->StringGrid1->Cells[7][nrow]=Form1->StringGrid1->Cells[7][i];

			Form4->StringGrid1->RowCount++;
			nrow++;
		}

	}
	Form4->Label1->Caption = "Больше всего фильмов режиссёра:";
	Form4->Label2->Caption = Form1->StringGrid1->Cells[2][z];
	Form4->Show();

}
//Самый разноплановый актер/актриса---------------------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
   	cleartab();
	int act;
	int g;
	int cntf = 1;
	int cntm = 0;
	int cntr = -1;

	for (int i = 1; i < Form1->StringGrid1->RowCount-1; i++) {
		for (int j = 1; j < Form1->StringGrid1->RowCount-1; j++) {
			if (AnsiCompareStr(Form1->StringGrid1->Cells[3][i], Form1->StringGrid1->Cells[3][j]) == 0) {
				if (not(AnsiCompareStr(Form1->StringGrid1->Cells[6][i], Form1->StringGrid1->Cells[6][j]) == 0)) {
					cntf++;

				}

			}

		}
		if (cntf > cntm) {
			act = i;
			cntm = cntf;
		}
		if (cntf == cntm){
			if (AnsiCompareStr(Form1->StringGrid1->Cells[3][act], Form1->StringGrid1->Cells[3][i]) == 0){
			}
			else {
            	cntr = cntf;
            }
		}
	}

	if (cntm==1) {
		Application->MessageBox(L"Не определён. Нет фильмов с одинаковыми актёрами.",L"Самый разноплановый актёр", MB_OK);
	}
	else if(cntr==cntm){
	Application->MessageBox(L"Не определён. Есть несколько актёров, снявшихся в одинаковом количестве фильмов разного жанра.",L"Самый разнопланновый актёр", MB_OK);
	}
	else{
		int nrow = 1;
        for (int i = 1; i < Form1->StringGrid1->RowCount-1; i++) {
			if (AnsiCompareStr(Form1->StringGrid1->Cells[3][act], Form1->StringGrid1->Cells[3][i]) == 0) {

				Form4->StringGrid1->Cells[0][nrow]=nrow;
				Form4->StringGrid1->Cells[1][nrow]=Form1->StringGrid1->Cells[1][i];
				Form4->StringGrid1->Cells[2][nrow]=Form1->StringGrid1->Cells[2][i];
				Form4->StringGrid1->Cells[3][nrow]=Form1->StringGrid1->Cells[3][i];
				Form4->StringGrid1->Cells[4][nrow]=Form1->StringGrid1->Cells[4][i];
				Form4->StringGrid1->Cells[5][nrow]=Form1->StringGrid1->Cells[5][i];
				Form4->StringGrid1->Cells[6][nrow]=Form1->StringGrid1->Cells[6][i];
				Form4->StringGrid1->Cells[7][nrow]=Form1->StringGrid1->Cells[7][i];

				Form4->StringGrid1->RowCount++;
				nrow++;
			}

		}
		Form4->Label1->Caption = "Самый разноплановый актёр: ";
		Form4->Label2->Caption = Form1->StringGrid1->Cells[3][act];
		Form4->Show();
    }

}

//ПКМ добавить---------------------------------------------------------------------------

void __fastcall TForm1::N37Click(TObject *Sender)
{
    save=false;
	Form2->Button1->Caption="Добавить";
	Form2->Caption="Добавление";
	Form2->Show();
	Form2->Edit1->SetFocus();

	if (Form1->StringGrid1->RowCount >= 2){

		N45->Enabled=true;
		N46->Enabled=true;

		ToolButton2->Enabled=true;
		ToolButton3->Enabled=true;
		ToolButton7->Enabled=true;
		ToolButton8->Enabled=true;
		ToolButton10->Enabled=true;
		ToolButton11->Enabled=true;
		ToolButton12->Enabled=true;

		N3->Enabled=true;
		N4->Enabled=true;
		N11->Enabled=true;
		N12->Enabled=true;
		N13->Enabled=true;
		N14->Enabled=true;
		N19->Enabled=true;
		N20->Enabled=true;
		N21->Enabled=true;
		N45->Enabled=true;
		N46->Enabled=true;
	}

}
//ПКМ редактировать---------------------------------------------------------------------------

void __fastcall TForm1::N45Click(TObject *Sender)
{
	int nm = StringGrid1->Row;
	int nl = StringGrid1->Col;

	if ((StringGrid1->Cells[0][nm]) == "№")
	{
		ShowMessage("Заголовок редактировать нельзя!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("Строка пуста!");
	}
	else if (nm==0)
	{
		 ShowMessage("Для редактирования выделите строку!");
	}
	else
	{
	Form2->Button1->Caption="Редактировать";
	Form2->Caption="Редактирование";

	Form2->Edit1->Text=Form1->StringGrid1->Cells[1][nm];
	Form2->Edit2->Text=Form1->StringGrid1->Cells[2][nm];
	Form2->Edit3->Text=Form1->StringGrid1->Cells[3][nm];
	Form2->MaskEdit1->Text=Form1->StringGrid1->Cells[4][nm];
	Form2->Edit4->Text=Form1->StringGrid1->Cells[5][nm];

	Form2->ListBox1->ItemIndex=pkmchoosegenre(Form1->StringGrid1->Cells[6][nm]);
	Form2->ListBox2->ItemIndex=pkmchoosecarrier(Form1->StringGrid1->Cells[7][nm]);

	Form2->Show();
	Form2->Edit1->SetFocus();
	}
	save=false;

}
//ПКМ удалить---------------------------------------------------------------------------

void __fastcall TForm1::N46Click(TObject *Sender)
{
	int nm = StringGrid1->Row;
	wchar_t buff[200];

	if (StringGrid1->Cells[0][nm]=="№")
	{
		ShowMessage("Заголовок удалять нельзя!");
	}
	else if (StringGrid1->Cells[0][nm].IsEmpty())
	{
		 ShowMessage("Строка пуста!");
	}
	else if (nm==0)
	{
		 ShowMessage("Для удаления выделите строку!");
	}
	else if (MessageBoxW(0,StringToWideChar(("Уверены, что хотите удалить <<"+StringGrid1->Cells[1][nm]+">> ?"),buff,200),L"Предупреждение",MB_YESNO)==IDYES)
	{
		for (int i=nm+1; i < StringGrid1->RowCount; i++)
			 for (int j=0; j < StringGrid1->ColCount; j++)
				   StringGrid1->Cells[j][i-1]=StringGrid1->Cells[j][i];
		StringGrid1->RowCount--;
	 for (int i=1; i < StringGrid1->RowCount-1; i++)
			 StringGrid1->Cells[0][i]=IntToStr(i);
	save=false;
	}

	if (Form1->StringGrid1->RowCount == 2) {
		N45->Enabled=false;
		N46->Enabled=false;

		ToolButton2->Enabled=false;
		ToolButton3->Enabled=false;
		ToolButton7->Enabled=false;
		ToolButton8->Enabled=false;
		ToolButton10->Enabled=false;
		ToolButton11->Enabled=false;
		ToolButton12->Enabled=false;

		N3->Enabled=false;
		N4->Enabled=false;
		N11->Enabled=false;
		N12->Enabled=false;
		N13->Enabled=false;
		N14->Enabled=false;
		N19->Enabled=false;
		N20->Enabled=false;
		N21->Enabled=false;
		N45->Enabled=false;
		N46->Enabled=false;
	}

}
//Закрытие программы---------------------------------------------------------------------------


void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if ((Application->MessageBox(L"Вы уверены, что хотите выйти?", L"Предупреждение", MB_YESNO)==IDYES))
	{
		if (save==true)
		{
			CanClose=true;
		}
		else{
			 if (Application->MessageBox(L"Хотите сохранить текущий файл?", L"Предупреждение", MB_YESNO)==IDYES)
			 {
				if (first==0)
				{
				   TForm1::N4Click(SaveDialog1);
				   CanClose=true;
				}
				else
				{
					TForm1::N3Click(SaveDialog2);
					CanClose=true;
				}
			 }

		}
	}
	else
		CanClose=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OnMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
	ToolButton1->Hint="Открыть";
	ToolButton2->Hint="Сохранить";
	ToolButton3->Hint="Сохранить как";
	ToolButton4->Hint="Выход";
	ToolButton6->Hint="Добавить";
	ToolButton7->Hint="Редактировать";
	ToolButton8->Hint="Удалить";
	ToolButton10->Hint="Сортировка";
	ToolButton11->Hint="Поиск";
	ToolButton12->Hint="Фильмы этого года";
	ToolButton13->Hint="Справка";
}
//StatusBar---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1Click(TObject *Sender)
{
	int nm = StringGrid1->Row;
	StatusBar1->Panels->Items[1]->Text="Работа с "+IntToStr(nm)+" строкой";
	int nc=StringGrid1->Col;
	StatusBar1->Panels->Items[2]->Text="Выделена ячейка ["+IntToStr(nm)+";"+IntToStr(nc)+"]";
}
//---------------------------------------------------------------------------

