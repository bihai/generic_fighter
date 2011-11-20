program spreditor;

uses
  QForms,
  main in 'main.pas' {formMain},
  frmTexto in 'frmTexto.pas' {formTexto},
  gfRect in 'gfRect.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TformMain, formMain);
  Application.Run;
end.
