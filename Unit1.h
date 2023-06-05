//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TStringGrid *StringGrid1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TMenuItem *N21;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TMenuItem *N22;
	TMenuItem *N28;
	TMenuItem *N29;
	TMenuItem *N30;
	TMenuItem *N31;
	TMenuItem *N32;
	TMenuItem *N33;
	TMenuItem *N34;
	TSaveDialog *SaveDialog2;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N23;
	TMenuItem *N24;
	TMenuItem *N25;
	TMenuItem *N26;
	TMenuItem *N27;
	TMenuItem *N35;
	TMenuItem *N36;
	TMenuItem *N38;
	TMenuItem *N39;
	TMenuItem *N40;
	TMenuItem *N41;
	TMenuItem *N42;
	TMenuItem *N43;
	TMenuItem *N44;
	TPopupMenu *PopupMenu1;
	TMenuItem *N37;
	TMenuItem *N45;
	TMenuItem *N46;
	TToolBar *ToolBar1;
	TImageList *ImageList1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TStatusBar *StatusBar1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N10Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N12Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N17Click(TObject *Sender);
	void __fastcall N18Click(TObject *Sender);
	void __fastcall N22Click(TObject *Sender);
	void __fastcall N28Click(TObject *Sender);
	void __fastcall N29Click(TObject *Sender);
	void __fastcall N30Click(TObject *Sender);
	void __fastcall N31Click(TObject *Sender);
	void __fastcall N32Click(TObject *Sender);
	void __fastcall N33Click(TObject *Sender);
	void __fastcall N34Click(TObject *Sender);
	void __fastcall N23Click(TObject *Sender);
	void __fastcall N24Click(TObject *Sender);
	void __fastcall N25Click(TObject *Sender);
	void __fastcall N35Click(TObject *Sender);
	void __fastcall N36Click(TObject *Sender);
	void __fastcall N26Click(TObject *Sender);
	void __fastcall N27Click(TObject *Sender);
	void __fastcall N38Click(TObject *Sender);
	void __fastcall N39Click(TObject *Sender);
	void __fastcall N40Click(TObject *Sender);
	void __fastcall N41Click(TObject *Sender);
	void __fastcall N42Click(TObject *Sender);
	void __fastcall N43Click(TObject *Sender);
	void __fastcall N44Click(TObject *Sender);
	void __fastcall N19Click(TObject *Sender);
	void __fastcall N20Click(TObject *Sender);
	void __fastcall N21Click(TObject *Sender);
	void __fastcall N37Click(TObject *Sender);
	void __fastcall N45Click(TObject *Sender);
	void __fastcall N46Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall OnMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall StringGrid1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
