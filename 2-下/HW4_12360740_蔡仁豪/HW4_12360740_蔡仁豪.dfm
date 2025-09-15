object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 712
  ClientWidth = 1073
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 89
    Height = 25
    Caption = #22320#22294#22823#23567': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 52
    Width = 89
    Height = 25
    Caption = #38568#27231#27402#37325': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 88
    Width = 89
    Height = 25
    Caption = #36899#25509#27161#28310': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 124
    Width = 89
    Height = 25
    Caption = #28961#36899#25509#20540': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 160
    Width = 89
    Height = 25
    Caption = #36215#40670#32232#34399': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 103
    Top = 13
    Width = 66
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = '5'
  end
  object Edit2: TEdit
    Left = 103
    Top = 49
    Width = 66
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = '100'
  end
  object Edit3: TEdit
    Left = 103
    Top = 85
    Width = 66
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = '100'
  end
  object Edit4: TEdit
    Left = 103
    Top = 121
    Width = 66
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Text = '99999'
  end
  object Edit5: TEdit
    Left = 103
    Top = 157
    Width = 66
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    Text = '0'
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 208
    Width = 89
    Height = 17
    Caption = #26377#21521#22294
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object PageControl1: TPageControl
    Left = 360
    Top = 0
    Width = 713
    Height = 712
    ActivePage = TabSheet3
    Align = alRight
    TabOrder = 6
    object TabSheet1: TTabSheet
      Caption = #22320#22294#38499#21015
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 705
        Height = 682
        Align = alClient
        GradientEndColor = clYellow
        GradientStartColor = 16744576
        TabOrder = 0
        RowHeights = (
          24
          24
          24
          24
          24)
      end
    end
    object TabSheet2: TTabSheet
      Caption = #30446#27161#36317#38626#38499#21015
      ImageIndex = 1
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 705
        Height = 682
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = #20840#37096#36317#38626#38499#21015
      ImageIndex = 3
      object StringGrid3: TStringGrid
        Left = 0
        Top = 0
        Width = 705
        Height = 321
        Align = alTop
        TabOrder = 0
      end
      object StringGrid4: TStringGrid
        Left = 0
        Top = 319
        Width = 705
        Height = 363
        Align = alBottom
        TabOrder = 1
      end
    end
    object TabSheet3: TTabSheet
      Caption = #36664#20986
      ImageIndex = 2
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 705
        Height = 682
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
  object Button1: TButton
    Left = 103
    Top = 201
    Width = 89
    Height = 33
    Caption = #29983#25104#22320#22294
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 240
    Width = 145
    Height = 33
    Caption = #30446#27161#36317#38626#38499#21015
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = But
  end
  object Button3: TButton
    AlignWithMargins = True
    Left = 159
    Top = 240
    Width = 145
    Height = 33
    Caption = #30446#27161#36317#38626#36664#20986
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 279
    Width = 145
    Height = 33
    Caption = #20840#37096#36317#38626#38499#21015
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 159
    Top = 279
    Width = 145
    Height = 33
    Caption = #20840#37096#36317#38626#36664#20986
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = Button5Click
  end
end
