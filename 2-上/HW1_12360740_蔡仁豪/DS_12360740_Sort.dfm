object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 561
  ClientWidth = 919
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 919
    Height = 561
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #36039#26009
      object Label1: TLabel
        Left = 40
        Top = 40
        Width = 60
        Height = 25
        Caption = #25976#37327#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 40
        Top = 80
        Width = 60
        Height = 25
        Caption = #31684#22285#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 640
        Top = 80
        Width = 60
        Height = 25
        Caption = #30446#27161#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 41
        Top = 17
        Width = 119
        Height = 17
        Caption = #25976#37327#24314#35696#65306'1~5'#33836
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Button1: TButton
        Left = 40
        Top = 140
        Width = 180
        Height = 40
        Caption = #29983#25104#38568#27231#25976
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 240
        Top = 140
        Width = 180
        Height = 40
        Caption = #36984#25799#25490#24207
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 440
        Top = 140
        Width = 180
        Height = 40
        Caption = #27683#27873#25490#24207
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 640
        Top = 140
        Width = 185
        Height = 40
        Caption = #25628#23563#25976#23383
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = Button4Click
      end
      object CheckBox1: TCheckBox
        Left = 240
        Top = 37
        Width = 121
        Height = 33
        Caption = #39023#31034#36039#26009
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
      end
      object CheckBox2: TCheckBox
        Left = 240
        Top = 77
        Width = 121
        Height = 33
        Caption = #30906#35469#25490#24207
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
      end
      object Edit1: TEdit
        Left = 100
        Top = 37
        Width = 100
        Height = 33
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
        Text = '10'
      end
      object Edit2: TEdit
        Left = 100
        Top = 80
        Width = 100
        Height = 33
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
        Text = '100'
      end
      object Edit3: TEdit
        Left = 700
        Top = 80
        Width = 100
        Height = 33
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 8
        Text = '50'
      end
      object Memo1: TMemo
        Left = 40
        Top = 200
        Width = 185
        Height = 300
        BiDiMode = bdLeftToRight
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          'Memo1'#65306)
        ParentBiDiMode = False
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 9
        StyleName = 'Windows'
      end
      object Memo2: TMemo
        Left = 240
        Top = 200
        Width = 185
        Height = 300
        BiDiMode = bdLeftToRight
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          'Memo2'#65306)
        ParentBiDiMode = False
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 10
      end
      object Memo3: TMemo
        Left = 440
        Top = 200
        Width = 185
        Height = 300
        BiDiMode = bdLeftToRight
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          'Memo3'#65306)
        ParentBiDiMode = False
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 11
      end
      object Memo4: TMemo
        Left = 640
        Top = 200
        Width = 185
        Height = 300
        BiDiMode = bdLeftToRight
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          'Memo4'#65306)
        ParentBiDiMode = False
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 12
      end
    end
    object TabSheet2: TTabSheet
      Caption = #22294#34920
      ImageIndex = 1
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 911
        Height = 531
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          21
          15
          21)
        ColorPaletteIndex = 13
      end
    end
  end
end
