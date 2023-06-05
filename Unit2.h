//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TButton *Button1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TListBox *ListBox1;
	TListBox *ListBox2;
	TMaskEdit *MaskEdit1;
	TLabel *Label8;
	TEdit *Edit4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
