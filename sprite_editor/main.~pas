unit main;

interface

uses
  SysUtils, Types, Classes, Variants, QGraphics, QControls, QForms, QDialogs,
  QExtCtrls, QMenus, QTypes, QStdCtrls, gfrect, QComCtrls;

type
  TformMain = class(TForm)
    ScrollBox: TScrollBox;
    imgSprite: TImage;
    MainMenu1: TMainMenu;
    Arquivo1: TMenuItem;
    Abririmagem1: TMenuItem;
    Salvarretngulos1: TMenuItem;
    N1: TMenuItem;
    Sair1: TMenuItem;
    Exibir1: TMenuItem;
    Ajuda1: TMenuItem;
    Sobre1: TMenuItem;
    OpenDlg: TOpenDialog;
    Retngulos1: TMenuItem;
    Panel1: TPanel;
    OptPonto: TRadioGroup;
    Panel2: TPanel;
    Button1: TButton;
    Button2: TButton;
    listaRects: TListBox;
    Ponto1: TMenuItem;
    N11: TMenuItem;
    N21: TMenuItem;
    N31: TMenuItem;
    N41: TMenuItem;
    sppowerlevel: TSpinEdit;
    chkdefense: TCheckBox;
    procedure Sair1Click(Sender: TObject);
    procedure Sobre1Click(Sender: TObject);
    procedure Retngulos1Click(Sender: TObject);
    procedure Abririmagem1Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure listaRectsClick(Sender: TObject);
    procedure FormPaint(Sender: TObject);
    procedure imgSpriteMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Salvarretngulos1Click(Sender: TObject);
    procedure N11Click(Sender: TObject);
    procedure N21Click(Sender: TObject);
    procedure N31Click(Sender: TObject);
    procedure N41Click(Sender: TObject);
    procedure chkdefenseClick(Sender: TObject);
    procedure sppowerlevelChanged(Sender: TObject; NewValue: Integer);
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
    actualRect: TgfRect;
    filename:	 string;
    bg_bitmap:  TPicture;
    procedure change_defense(value: boolean);
    procedure change_powerlevel(value: integer);
  public
    { Public declarations }
  end;

var
  formMain: TformMain;

implementation

{$R *.xfm}

uses frmTexto;

procedure TformMain.Sair1Click(Sender: TObject);
begin
        close;
end;

procedure TformMain.Sobre1Click(Sender: TObject);
begin
        ShowMessage('Este programa foi feito por Marcelo Elias Del Valle, veja http://mlinuxer.cjb.net para maiores detalhes.');
end;

procedure TformMain.Retngulos1Click(Sender: TObject);
var
        ftexto: TformTexto;
        I:		 integer;
        r:		 TgfRect;
begin
        ftexto := TformTexto.create(Self);
        ftexto.TextBox.Text := '';
        for i:= 0 to listaRects.Items.count-1 do begin
        	r := TgfRect(listaRects.items.objects[i]);
        	ftexto.TextBox.Text := ftexto.TextBox.Text +
         	IntToStr(r.xlt)+','+IntToStr(r.ylt)+';'+
            IntToStr(r.xrt)+','+IntToStr(r.yrt)+';'+
            IntToStr(r.xlb)+','+IntToStr(r.ylb)+';'+
            IntToStr(r.xrb)+','+IntToStr(r.yrb)+'; flip='+
            IntToStr(imgSprite.Width-r.xlt)+','+IntToStr(imgSprite.Height-r.ylt)+';'+
            IntToStr(imgSprite.Width-r.xrt)+','+IntToStr(imgSprite.Height-r.yrt)+';'+
            IntToStr(imgSprite.Width-r.xlb)+','+IntToStr(imgSprite.Height-r.ylb)+';'+
            IntToStr(imgSprite.Width-r.xrb)+','+IntToStr(imgSprite.Height-r.yrb)+'; '+
            IntToStr(r.powerlevel) + ';' +
            '0;0;0;0;'+IntToStr(Integer(r.defense))
            +'      #'+filename +' -rect ' +
            IntToStr(i) +#10;
        end;
        ftexto.showmodal;
        ftexto.free;
end;

procedure TformMain.Abririmagem1Click(Sender: TObject);
begin
	try
   	if (OpenDlg.execute) then begin
         filename := OpenDlg.FileName;
         imgSprite.Picture.LoadFromFile(FileName);
         imgSprite.Transparent := true;
         imgSprite.Transparent := false;
         bg_bitmap.assign(imgsprite.picture); 
      end;
   except

   end;
end;

procedure TformMain.Button1Click(Sender: TObject);
var
	newrect: TgfRect;
begin
	newrect := TgfRect.create;
   newrect.xlt := imgSprite.width div 10;
   newrect.ylt := imgSprite.height div 10;
   newrect.xlb := imgSprite.width div 10;
   newrect.ylb := 9*imgSprite.height div 10;
   newrect.xrb := 9*imgSprite.width div 10;
   newrect.yrb := 9*imgSprite.height div 10;
   newrect.xrt := 9*imgSprite.width div 10;
   newrect.yrt := imgSprite.height div 10;
   listaRects.Selected [
   listaRects.Items.AddObject('rect',newrect)
   ] := true;
   actualrect := newrect;
   change_defense(false);
   change_powerlevel(50);
end;

procedure TformMain.FormCreate(Sender: TObject);
begin
	bg_bitmap := TPicture.Create;
   bg_bitmap.Assign(ImgSprite.Picture);
	imgSprite.Canvas.Pen.Color := clRed;
	actualRect := nil;
   filename := '';
end;

procedure TformMain.listaRectsClick(Sender: TObject);
var
	i: integer;
begin
	for i := 0 to listaRects.items.count -1 do begin
   	if (listaRects.selected[i]) then begin
      	actualRect := TgfRect(listaRects.items.objects[i]);
         Paint;
      end;
   end;
   if (actualrect = nil) then exit;
   change_defense(actualrect.defense);
   change_powerlevel(actualrect.powerlevel);
end;


procedure TformMain.FormPaint(Sender: TObject);
begin
	if (actualRect = nil) then exit;
   with imgsprite.canvas do begin
	   Pen.Color := clBlack;
      Pen.Color := clRed;
   	Draw(0,0,bg_bitmap.Graphic);
      refresh;
		MoveTo(actualrect.xlt, actualrect.ylt);
		LineTo(actualrect.xrt, actualrect.yrt);
		LineTo(actualrect.xrb, actualrect.yrb);
		LineTo(actualrect.xlb, actualrect.ylb);
		LineTo(actualrect.xlt, actualrect.ylt);
   end;

end;

procedure TformMain.imgSpriteMouseDown(Sender: TObject;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
	if (X<0) then exit;
 	if (Y<0) then exit;
   if (X>imgSprite.width) then exit;
   if (Y>imgSprite.height) then exit;
   if (actualrect=nil) then exit;
	if (optPonto.ItemIndex<0) then exit;
   case optPonto.ItemIndex of
   0: begin
   	actualrect.xlt :=X;
      actualrect.ylt :=Y;
   end;
   1: begin
   	actualrect.xrt :=X;
      actualrect.yrt :=Y;
   end;
   2: begin
   	actualrect.xlb :=X;
      actualrect.ylb :=Y;
   end;
   3: begin
   	actualrect.xrb :=X;
      actualrect.yrb :=Y;
   end;
   end;
   Paint;
end;

procedure TformMain.Salvarretngulos1Click(Sender: TObject);
var
        ftexto: TformTexto;
        I:		 integer;
        r:		 TgfRect;
begin
        ftexto := TformTexto.create(Self);
        ftexto.TextBox.Text := '';
        for i:= 0 to listaRects.Items.count-1 do begin
        	r := TgfRect(listaRects.items.objects[i]);
        	ftexto.TextBox.Text := ftexto.TextBox.Text +
         	IntToStr(r.xlt)+','+IntToStr(r.ylt)+';'+
            IntToStr(r.xrt)+','+IntToStr(r.yrt)+';'+
            IntToStr(r.xlb)+','+IntToStr(r.ylb)+';'+
            IntToStr(r.xrb)+','+IntToStr(r.yrb)+'; flip='+
            IntToStr(imgSprite.Width-r.xlt)+','+IntToStr(imgSprite.Height-r.ylt)+';'+
            IntToStr(imgSprite.Width-r.xrt)+','+IntToStr(imgSprite.Height-r.yrt)+';'+
            IntToStr(imgSprite.Width-r.xlb)+','+IntToStr(imgSprite.Height-r.ylb)+';'+
            IntToStr(imgSprite.Width-r.xrb)+','+IntToStr(imgSprite.Height-r.yrb)+'; '+
            IntToStr(r.powerlevel) + ';' +
            '0;0;0;0;'+IntToStr(Integer(r.defense))
            +'      #'+filename +' -rect ' +
            IntToStr(i) +#10;

        end;
        ftexto.TextBox.Lines.SaveToFile(filename +'.rect');
        beep;
//        ftexto.show;
        ftexto.free;
end;

procedure TformMain.N11Click(Sender: TObject);
begin
	OptPonto.ItemIndex:=0;
end;

procedure TformMain.N21Click(Sender: TObject);
begin
OptPonto.ItemIndex:=1;
end;

procedure TformMain.N31Click(Sender: TObject);
begin
OptPonto.ItemIndex:=2;
end;

procedure TformMain.N41Click(Sender: TObject);
begin
OptPonto.ItemIndex:=3;
end;

procedure TFormmain.change_defense(value: boolean);
begin
	if (actualrect=nil) then exit;
   actualrect.defense := value;
   chkDefense.checked := value;
end;

procedure TFormmain.change_powerlevel(value: integer);
begin
	if (actualrect=nil) then exit;
   actualrect.powerlevel := value;
   spPowerlevel.value := value;
end;

procedure TformMain.chkdefenseClick(Sender: TObject);
begin
	if (actualrect = nil) then exit;
   change_defense(chkDefense.checked);
end;

procedure TformMain.sppowerlevelChanged(Sender: TObject;
  NewValue: Integer);
begin
	if (actualrect = nil) then exit;
   change_powerlevel(spPowerLevel.value);

end;

procedure TformMain.Button2Click(Sender: TObject);
var
	i: integer;
begin
	for i := 0 to listaRects.items.count -1 do begin
   	if (listaRects.selected[i]) then begin
      	actualRect := TgfRect(listaRects.items.objects[i]);
         actualRect.Free;
         listaRects.items.Delete(i);
         break;
      end;
   end;

end;

end.
