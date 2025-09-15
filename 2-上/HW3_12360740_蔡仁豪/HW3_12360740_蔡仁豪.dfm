object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 660
  ClientWidth = 960
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 8
    Top = 24
    Width = 84
    Height = 37
    Caption = #22823#23567#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 640
    Top = 8
    Width = 185
    Height = 140
    Caption = #36215#40670#19978'/'#26041#21521#20063#26377#24448#19978#13#10#36215#40670#19979'/'#26041#21521#20063#26377#24448#19979#13#10#36215#40670#24038'/'#26041#21521#20063#26377#24448#24038#13#10#36215#40670#21491'/'#26041#21521#20063#26377#24448#21491#13#10'*'#36889#31278#24773#27841#19979#37117#26371#27491#30906
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 98
    Top = 24
    Width = 93
    Height = 45
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = '3'
  end
  object Button1: TButton
    Left = 8
    Top = 85
    Width = 183
    Height = 45
    Caption = #22519#34892
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object GroupBox1: TGroupBox
    Left = 232
    Top = 8
    Width = 177
    Height = 122
    Caption = #26041#21521
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object RadioButton1: TRadioButton
      Left = 16
      Top = 40
      Width = 65
      Height = 17
      Caption = #24038#19978
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object RadioButton2: TRadioButton
      Left = 87
      Top = 40
      Width = 65
      Height = 17
      Caption = #21491#19978
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object RadioButton3: TRadioButton
      Left = 16
      Top = 77
      Width = 65
      Height = 17
      Caption = #24038#19979
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object RadioButton4: TRadioButton
      Left = 87
      Top = 77
      Width = 65
      Height = 17
      Caption = #21491#19979
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
  end
  object GroupBox2: TGroupBox
    Left = 440
    Top = 8
    Width = 177
    Height = 122
    Caption = #36215#40670
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    object RadioButton5: TRadioButton
      Left = 16
      Top = 40
      Width = 65
      Height = 17
      Caption = #19978#20013
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object RadioButton6: TRadioButton
      Left = 87
      Top = 40
      Width = 65
      Height = 17
      Caption = #19979#20013
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object RadioButton7: TRadioButton
      Left = 16
      Top = 77
      Width = 65
      Height = 17
      Caption = #24038#20013
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object RadioButton8: TRadioButton
      Left = 87
      Top = 77
      Width = 65
      Height = 17
      Caption = #21491#20013
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 154
    Width = 960
    Height = 506
    ActivePage = TabSheet1
    Align = alBottom
    TabOrder = 4
    object TabSheet1: TTabSheet
      Caption = #38499#21015#28165#21934
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 952
        Height = 476
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          'Memo1:')
        ParentFont = False
        TabOrder = 0
        ExplicitLeft = -424
        ExplicitWidth = 761
        ExplicitHeight = 462
      end
    end
    object TabSheet2: TTabSheet
      Caption = #32178#26684
      ImageIndex = 2
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 952
        Height = 476
        Align = alClient
        TabOrder = 0
      end
    end
  end
end
