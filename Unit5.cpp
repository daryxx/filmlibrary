//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
	Timer1->Interval = 3000;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm5::Timer1Timer(TObject *Sender)
{
	Timer1->Enabled = false;
	ModalResult = mrOk;

}
//---------------------------------------------------------------------------
