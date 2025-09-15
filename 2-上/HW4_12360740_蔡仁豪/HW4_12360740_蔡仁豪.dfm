object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 672
  ClientWidth = 1096
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 21
  object Label1: TLabel
    Left = 29
    Top = 13
    Width = 145
    Height = 37
    Caption = #32769#40736#36208#36855#23470
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 29
    Top = 80
    Width = 92
    Height = 21
    Caption = #36855#23470#38263'x'#23532#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 169
    Top = 80
    Width = 7
    Height = 21
    Caption = 'x'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 29
    Top = 109
    Width = 191
    Height = 21
    Caption = '('#24314#35696'30'#20197#20839#65292#21029#36229#36942'100)'
  end
  object Label5: TLabel
    Left = 32
    Top = 296
    Width = 195
    Height = 84
    Caption = #31777#26131#35498#26126#65306#13#10#32043#33394'(-2)'#26159#32769#40736#31227#21205#30340#36335#24465#13#10#34253#33394'(-3)'#26159#32769#40736#30340#25152#22312#20301#32622#13#10#40643#33394'(-4)'#26159#32769#40736#36820#22238#30340#36335#24465
  end
  object Button1: TButton
    Left = 240
    Top = 80
    Width = 75
    Height = 25
    Caption = #30906#35469#35519#25972
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 127
    Top = 80
    Width = 36
    Height = 29
    TabOrder = 1
    Text = '0'
  end
  object Edit2: TEdit
    Left = 191
    Top = 80
    Width = 36
    Height = 29
    TabOrder = 2
    Text = '0'
  end
  object GroupBox1: TGroupBox
    Left = 25
    Top = 136
    Width = 290
    Height = 73
    Caption = #24067#32622#22320#22294
    TabOrder = 3
    object RadioButton1: TRadioButton
      Left = 10
      Top = 40
      Width = 60
      Height = 17
      Caption = #29254#22721
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 80
      Top = 40
      Width = 60
      Height = 17
      Caption = #36947#36335
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 150
      Top = 40
      Width = 60
      Height = 17
      Caption = #36215#40670
      TabOrder = 2
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 220
      Top = 40
      Width = 60
      Height = 17
      Caption = #32066#40670
      TabOrder = 3
      OnClick = RadioButton4Click
    end
  end
  object StringGrid1: TStringGrid
    Left = 353
    Top = 0
    Width = 743
    Height = 672
    Align = alRight
    DefaultColWidth = 32
    DefaultRowHeight = 32
    ScrollBars = ssNone
    TabOrder = 4
    OnClick = StringGrid1Click
    OnDrawCell = StringGrid1DrawCell
  end
  object Button2: TButton
    Left = 29
    Top = 224
    Width = 209
    Height = 49
    Caption = #38283#22987#25628#32034
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = Button2Click
  end
  object CheckBox1: TCheckBox
    Left = 250
    Top = 256
    Width = 97
    Height = 17
    Caption = #28187#24930#36895#24230
    TabOrder = 6
  end
end
