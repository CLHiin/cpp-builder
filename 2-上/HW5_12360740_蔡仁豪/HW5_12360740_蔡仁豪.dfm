object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 610
  ClientWidth = 1011
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 21
  object Label2: TLabel
    Left = 12
    Top = 108
    Width = 90
    Height = 50
    Caption = #21069#24207#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 12
    Top = 188
    Width = 90
    Height = 50
    Caption = #24460#24207#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 12
    Top = 28
    Width = 90
    Height = 50
    Caption = #20013#24207#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 12
    Top = 245
    Width = 393
    Height = 21
    Caption = '*'#27794#26377#38450#21574#34389#29702'/'#36681#20013#24207#27794#26377#21435#38500#25324#34399'/'#36039#26009#37679#35492#26371#20986#20107
  end
  object Label5: TLabel
    Left = 12
    Top = 272
    Width = 925
    Height = 21
    Caption = '*'#21069#24207#36984#25799#30452#25509#21453#36681#20599#25078#65292#25152#20197#20687'A+B-C'#30340#26178#20505#65292#40664#35469#38918#24207#26371#35722#25104'A+(B-C)'#65292#38614#28982#36681#22238#21435#26377#21487#33021#26371#19981#19968#27171#65292#20294#21453#27491#21152#36215#20358#20063#27794#37679
  end
  object Edit2: TEdit
    Left = 108
    Top = 108
    Width = 629
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = '+*ab/^c+de+fg'
  end
  object Edit3: TEdit
    Left = 108
    Top = 188
    Width = 629
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = 'ab*cde+^fg+/+'
  end
  object Edit1: TEdit
    Left = 104
    Top = 28
    Width = 633
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = 'a*b+c^(d+e)/(f+g)'
  end
  object Button1: TButton
    Left = 760
    Top = 28
    Width = 89
    Height = 50
    Caption = #36681#21069
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 872
    Top = 28
    Width = 89
    Height = 50
    Caption = #36681#24460
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 760
    Top = 108
    Width = 89
    Height = 50
    Caption = #36681#20013
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 872
    Top = 108
    Width = 89
    Height = 50
    Caption = #36681#24460
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 760
    Top = 188
    Width = 89
    Height = 50
    Caption = #36681#21069
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 872
    Top = 188
    Width = 89
    Height = 50
    Caption = #36681#20013
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = Button6Click
  end
  object Memo1: TMemo
    Left = 12
    Top = 307
    Width = 949
    Height = 286
    Lines.Strings = (
      'Memo1')
    TabOrder = 9
  end
end
