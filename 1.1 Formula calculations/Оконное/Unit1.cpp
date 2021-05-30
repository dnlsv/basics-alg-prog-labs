#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
Edit1->Text = "6,251";
Edit2->Text = "0,827";
Edit3->Text = "25,001";
Memo1->Clear();
Memo1->Lines->Add("Лабораторная работа № 1");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  double x, y, z, a, b ,c, d, e, p, q, r, w, t, f, g, rez;
x = StrToFloat(Edit1->Text);
y = StrToFloat(Edit2->Text);
z = StrToFloat(Edit3->Text);
a = fabs(x);
b = pow(a,1./3);
c = pow(y,b);
d = fabs(x-y);
e = pow(sin(z),2);
p = sqrt(x+y);
q = 1+e/p;
r = exp(d);
w = x/2;
t = d*q/(r+w);
g = pow(cos(y),3);
f = g*t;
rez = c+f;
Memo1->Lines->Add("При х = "+FloatToStrF(x,ffFixed,7,3)
         + "; y = "+FloatToStrF(y,ffFixed,7,3)+"; z = "+FloatToStrF(z,ffFixed,7,3));
Memo1->Lines->Add("Результат = "+FloatToStr(rez));
}
//---------------------------------------------------------------------------

