//---------------------------------------------------------------------------

#ifndef FormH
#define FormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel* Label1;
	TEdit* Edit1;
	TLabel* Label2;
	TEdit* Edit2;
	TLabel* Label3;
	TEdit* Edit3;
	TMemo* Memo1;
	TButton* Button1;
	TRadioGroup* RadioGroup1;
	void __fastcall FormCreate(TObject* Sender);
	void __fastcall Button1Click(TObject* Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif
