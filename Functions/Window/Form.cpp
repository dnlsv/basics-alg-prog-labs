#include <vcl.h>
#pragma hdrstop
#include "Form.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject* Sender)
{
	Edit1->Text = "2";
	Edit2->Text = "3";
	Edit3->Text = "0";
	Memo1->Clear();
	Memo1->Lines->Add("Лабораторная работа № 2");
	RadioGroup1->ItemIndex = 0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject* Sender)
{
	double x, y, z, u, a, b, o, p, r, s, t;
	a = StrToFloat(Edit1->Text);
	b = StrToFloat(Edit2->Text);
	z = StrToFloat(Edit3->Text);

	// Проверка состояния кнопки CheckBox1
	 /* if (CheckBox1->Checked){
				  x=1/(z*(z+2));
	  }
	  else {
	  x = 1-pow(z,3);
	  }
	*/
	if (z > 0) {
		x = 1 / (z * (z + 2));
	}
	else {
		x = 1 - pow(z, 3);
	}
	// Проверка номера нажатой кнопки и выбор соответствующей функции
	switch (RadioGroup1->ItemIndex) {
	case 0: u = 2 * x;
		//Memo1->Lines->Add("2*x= "+FloatToStrF(u,ffFixed,8,6));
		break;
	case 1: u = x * x;
		//Memo1->Lines->Add("x*x= "+FloatToStrF(u,ffFixed,8,6));
		break;
	case 2: u = x / 3;
		//Memo1->Lines->Add("x/3= "+FloatToStrF(u,ffFixed,8,6));
		break;
	}

	// Нахождение значения функции
	o = exp((-3) * x);
	p = 2.5 * a * o;
	r = 4 * b * x * x;
	s = log(fabs(x));
	y = (p - r) / (s + u);
	Memo1->Lines->Add("y= " + FloatToStrF(y, ffFixed, 8, 6));
}
//---------------------------------------------------------------------------
