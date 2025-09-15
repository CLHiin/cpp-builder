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
  object Label6: TLabel
    Left = 175
    Top = 28
    Width = 44
    Height = 15
    Caption = #19978#38480'100'
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
  object Button1: TButton
    Left = 8
    Top = 196
    Width = 89
    Height = 33
    Caption = #29983#25104#22320#22294
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button1Click
  end
  object PageControl1: TPageControl
    Left = 240
    Top = 0
    Width = 833
    Height = 712
    ActivePage = TabSheet1
    Align = alRight
    TabOrder = 6
    object TabSheet1: TTabSheet
      Caption = #22320#22294#38499#21015
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 593
        Height = 682
        Align = alLeft
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
      object StringGrid2: TStringGrid
        Left = 599
        Top = 0
        Width = 226
        Height = 682
        Align = alRight
        ColCount = 3
        RowCount = 3
        TabOrder = 1
        ExplicitTop = 3
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Kruskal '#28436#31639#27861
      ImageIndex = 2
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 825
        Height = 682
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitTop = -5
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Prim '#28436#31639#27861
      ImageIndex = 3
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 825
        Height = 682
        Align = alClient
        Lines.Strings = (
          'Memo2')
        TabOrder = 0
        ExplicitLeft = 336
        ExplicitTop = 296
        ExplicitWidth = 185
        ExplicitHeight = 89
      end
    end
    object TabSheet3: TTabSheet
      Caption = #26178#38291#22294#34920
      ImageIndex = 2
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 825
        Height = 682
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
  end
  object Button2: TButton
    Left = 8
    Top = 248
    Width = 145
    Height = 41
    Caption = 'Kruskal '#28436#31639#27861
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 303
    Width = 145
    Height = 41
    Caption = 'Prim '#28436#31639#27861
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = Button3Click
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 350
    Width = 113
    Height = 42
    Caption = #21360#20986#36942#31243
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
  end
  object CheckBox2: TCheckBox
    Left = 8
    Top = 398
    Width = 113
    Height = 42
    Caption = #21360#20986#26178#38291
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
  end
end
